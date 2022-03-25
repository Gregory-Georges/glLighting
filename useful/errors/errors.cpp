#include "errors.hpp"



/////////////////////////////////
// Functions
/////////////////////////////////

//Polls the gl errors
void pollglErrors()
{
    //Out string
    std::string err_str = "";

    //Get all errors and types
    while(int error = glGetError())
    {
        err_str += "";

        //Get error type
        switch(error)
        {
            case GL_NO_ERROR :                          err_str += "GL_NO_ERROR\n"; break;
            case GL_INVALID_ENUM :                      err_str += "INVALID_ENUM\n"; break;
            case GL_INVALID_VALUE :                     err_str += "GL_INVALID_VALUE\n"; break;
            case GL_INVALID_OPERATION :                 err_str += "GL_INVALID_OPERATION\n"; break;
            case GL_INVALID_FRAMEBUFFER_OPERATION :     err_str += "GL_INVALID_FRAMEBUFFER_OPERATION\n"; break;
            case GL_OUT_OF_MEMORY :                     err_str += "GL_OUT_OF_MEMORY\n"; break;
            case GL_STACK_UNDERFLOW :                   err_str += "GL_STACK_UNDERFLOW\n"; break;
            case GL_STACK_OVERFLOW :                    err_str += "GL_STACK_OVERFLOW\n"; break;
            default :                                   err_str += "UNKNOWN_ERROR_TYPE\n";
        }
    }

    //Out if there was an error
    if(err_str != "")
        throwError("OpenGL error : " + err_str);
}



//Throws an error with the message
void throwError(std::string errorMessage)
{
    throw std::runtime_error(errorMessage.c_str());
}

