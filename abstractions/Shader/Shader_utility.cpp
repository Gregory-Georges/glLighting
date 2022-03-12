#include "Shader_utility.hpp"



//////////////////////////////////
// Definitions
//////////////////////////////////

//Compile and returns a valid shader object
unsigned int compileShader(std::string shaderSource, unsigned int shaderType)
{
    //Create shader
    unsigned int shd = glCreateShader(shaderType);

    //Give source to shader
    const char* str = shaderSource.c_str();
    glShaderSource(shd, 1, &str, NULL);

    //Compile shader
    glCompileShader(shd);

    //Check whether shader is compiled correctly or not
    int result = GL_FALSE;
    glGetShaderiv(shd, GL_COMPILE_STATUS, &result);

    if(result != GL_TRUE)
    {
        //Get error string
        int logLength;
        glGetShaderiv(shd, GL_INFO_LOG_LENGTH, &logLength);
        char err_str[logLength];
        glGetShaderInfoLog(shd, logLength, &logLength, err_str);

        //Throw error
        throw std::runtime_error(err_str);
    }

    return shd;
}



//Gets the source contents of a specified file
std::string getSource(std::string path)
{
    //Open file
    std::fstream file;
    file.open(path);
    std::string out = "", temp;

    //Extract every line
    if(file.is_open())
    {
        while(std::getline(file, temp))
            out += temp + "\n";
    }
    else
    {
        throw std::runtime_error("File " + path + " could not be opened\n");
    }

    //Return
    return out;
}



//Gets a string and prints the list of uniforms in the program
void printShaderUniformList(unsigned int ShaderID)
{
    int i;
    int count;
    int size; // size of the variable
    GLenum type; // type of the variable (float, vec3 or mat4, etc)
    const GLsizei bufSize = 16; // maximum name length
    char name[bufSize]; // variable name in GLSL
    int length; // name length

    glGetProgramiv(ShaderID, GL_ACTIVE_UNIFORMS, &count);
    std::cout << "Active Uniforms: " << count << "\n";
    for (i = 0; i < count; i++)
    {
        glGetActiveUniform(ShaderID, (GLuint)i, bufSize, &length, &size, &type, name);
        std::cout << i << ". Uniform type : " << type << " Name : " << name << "\n";
    }
}
