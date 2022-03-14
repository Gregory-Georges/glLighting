#include "Shader.hpp"



//////////////////////////////////
// Constructor / destructor
//////////////////////////////////

//Constructs an empty shader object
Shader::Shader()
{
    id = glCreateProgram();
}



//Destroys a shader object
Shader::~Shader()
{
    glDeleteProgram(id);
}



//Constructs an usable shader object
Shader::Shader(std::string vertexShd, std::string fragmentShd)
{
    id = glCreateProgram();
    compile(vertexShd, fragmentShd);
    use();
}



//Copy constructor
Shader::Shader(const Shader &shd)
{
    std::string errStr = "";
    errStr += "Error : Shader program copy constructor called. ";
    throwError(errStr);
}









//////////////////////////////////
// Getters
//////////////////////////////////

unsigned int Shader::getID()
{
    return id;
}



int Shader::getValid()
{
    //Get if shader program is valid
    int result;
    glGetProgramiv(id, GL_VALIDATE_STATUS, &result);

    //If shader is invalid, get error log
    if(result != GL_TRUE)
    {
        //Get error string
        int logLength;
        glGetProgramiv(id, GL_INFO_LOG_LENGTH, &logLength);
        char err_str[logLength];
        glGetProgramInfoLog(id, logLength, &logLength, err_str);

        //Throw error
        throw std::runtime_error(err_str);
    }

    //Return if valid
    return result;
}









//////////////////////////////////
// Data
//////////////////////////////////

void Shader::use()
{
    if(getValid() == GL_TRUE)
        glUseProgram(id);
}



void Shader::compile(std::string vertexShd, std::string fragmentShd)
{
    //Compile shaders
    unsigned int vert = compileShader(vertexShd, GL_VERTEX_SHADER);
    unsigned int frag = compileShader(fragmentShd, GL_FRAGMENT_SHADER);

    //Link shaders to program
    glAttachShader(id, vert);
    glAttachShader(id, frag);
    glLinkProgram(id);
    glValidateProgram(id);

    //Delete shaders
    glDeleteShader(vert);
    glDeleteShader(frag);

    //Validate linkage
    int result = 0;
    result = getValid();
    if(result != GL_TRUE)
    {
        //Get shader errors
        std::string err = "Failed to compile shaders : \n" + vertexShd + "\n" + fragmentShd;
        throw std::runtime_error(err);
    }
}
