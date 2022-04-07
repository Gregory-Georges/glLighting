#include "Uniform.hpp"



//////////////////////////////////
// Constructor / destructor
//////////////////////////////////

    //Constructs an uniform based in a shader
    Uniform::Uniform(GLenum uniformType, unsigned int shd, std::string ufName)
    {
        //Assign variables
        this->uniformType = uniformType;
        attachedShader = shd;
        this->ufName = ufName;
        uniformData = nullptr;

        //Get uniform
        id = glGetUniformLocation(attachedShader, ufName.c_str());
        validate();
    }



    Uniform::Uniform(GLenum uniformType, unsigned int shd, std::string ufName, float* data)
    {
        //Assign variables
        this->uniformType = uniformType;
        attachedShader = shd;
        this->ufName = ufName;
        uniformData = data;

        //Get uniform
        id = glGetUniformLocation(attachedShader, ufName.c_str());
        validate();

        //Give data
        update();
    }









//////////////////////////////////
// Getters
//////////////////////////////////

    //Returns the id of the uniform
    unsigned int Uniform::getID() { return id; }

    //Returns the uniform's name
    std::string Uniform::getName() { return ufName; }









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
        uniformData = uniformValue;

        if(isSupportedUniformType(uniformType))
            switch(uniformType)
            {
            //Float value vectors
            //vec3 Vector
            case GL_FLOAT_VEC3 :
                glUniform3fv(id, 1, uniformValue);
                break;

            //vec4 Vector
            case GL_FLOAT_VEC4 :
                glUniform4fv(id, 1, uniformValue);
                break;


            //Float value matrices
            //Mat3 Matrix
            case GL_FLOAT_MAT3 :
                glUniformMatrix3fv(id, 1, GL_FALSE, uniformValue);
                break;

            //Mat4 Matrix
            case GL_FLOAT_MAT4 :
                glUniformMatrix4fv(id, 1, GL_FALSE, uniformValue);
                break;

            //Invalid uniform
            default :
                throwError("Uniform type of " + ufName + " is invalid for function data");
            }

        else
            throwError("Uniform type of " + ufName + " is invalid for function data");
    }



    void Uniform::update()
    {
        if(uniformData != nullptr)
            data(uniformData);
        else
            throw std::runtime_error("Attempt to update uniform " + ufName + " without it being set\n");
    }
