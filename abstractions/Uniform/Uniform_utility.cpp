#include "Uniform_utility.hpp"



//////////////////////////////////
// Definitions
//////////////////////////////////

bool isSupportedUniformType(GLenum UniformType)
{
    return
    (
        //Vectors
        UniformType == GL_FLOAT_VEC3 ||
        UniformType == GL_FLOAT_VEC4 ||

        //Matrices
        UniformType == GL_FLOAT_MAT3 ||
        UniformType == GL_FLOAT_MAT4
    );
}
