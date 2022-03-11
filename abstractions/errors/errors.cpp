#include "errors.hpp"



/////////////////////////////////
// Functions
/////////////////////////////////

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
