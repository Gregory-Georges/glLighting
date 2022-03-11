#include "Shader.hpp"



//////////////////////////////////
// Constructor / destructor
//////////////////////////////////

Shader::Shader()
{
    id = glCreateProgram();
}



Shader::~Shader()
{
    glDeleteProgram(id);
}



Shader::Shader(std::string vertexShd, std::string fragmentShd)
{
    id = glCreateProgram();
    compile(vertexShd, fragmentShd);
    use();
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
    int result = GL_FALSE;
    glGetProgramiv(id, GL_VALIDATE_STATUS, &result);
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
