#include "errors.hpp"



/////////////////////////////////
// Functions
/////////////////////////////////

//Polls the gl errors
void pollglErrors()
{
    //Out string
    std::string err_str = "";

    //Get all errors
    while(unsigned int error = glGetError())
    {
        err_str += error + " ";
    }

    //Out
    if(err_str != "")
        throw std::runtime_error("OpenGL error : " + err_str);
}



//Throws an error with the message
void throwError(std::string errorMessage)
{
    throw std::runtime_error(errorMessage.c_str());
}

