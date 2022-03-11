#include "Uniform.hpp"



//////////////////////////////////
// Constructor / destructor
//////////////////////////////////

//Constructs an uniform based in a shader
Uniform::Uniform(uniformType ut, Shader shd, std::string ufName)
{
    this->ut = ut;
    attachedShader = shd.getID();
    this->ufName = ufName;

    id = glGetUniformLocation(attachedShader, ufName.c_str());
    validate();
}









//////////////////////////////////
// Getters
//////////////////////////////////

//Returns the id of the uniform
unsigned int Uniform::getID()
{
    return id;
}

//Returns the uniform's name
std::string Uniform::getName()
{
    return ufName;
}









//////////////////////////////////
// Validate
//////////////////////////////////

//Checks if the uniform is valid
void Uniform::validate()
{
    if(id == -1) //id is -1 when uniform is no instantiated correctly
        throw std::runtime_error("Uniform " + ufName + " is invalid");
}









//////////////////////////////////
// Data
////////////////////////////////// string? - OpenGL - Khronos Forums

//Assigns data to the uniform
void Uniform::data(float* uniformValue)
{
    //Bind attached
    glUseProgram(attachedShader);

    switch(ut)
    {
    //Mat3 Matrix
    case UNIFORM_MAT_3_FV :
        glUniformMatrix3fv(id, 1, GL_FALSE, uniformValue);
        break;

    //Mat4 Matrix
    case UNIFORM_MAT_4_FV :
        glUniformMatrix4fv(id, 1, GL_FALSE, uniformValue);
        break;

    //Invalid uniform
    default :
        throw std::runtime_error("Uniform type of " + ufName + " is invalid");
    }
}
