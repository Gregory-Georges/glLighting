#include "glState.hpp"



//////////////////////////////////
// Get binded
//////////////////////////////////

void printBindedElements()
{
    int value;

    glGetIntegerv(GL_ARRAY_BUFFER_BINDING, &value);
    std::cout << "Binded vertex buffer : " << value << "\n";

    glGetIntegerv(GL_ELEMENT_ARRAY_BUFFER_BINDING, &value);
    std::cout << "Binded index buffer : " << value << "\n";

    glGetIntegerv(GL_VERTEX_ARRAY_BINDING, &value);
    std::cout << "Binded vertex array : " << value << "\n";

    glGetIntegerv(GL_CURRENT_PROGRAM, &value);
    std::cout << "Using program : " << value << "\n";

    glGetIntegerv(GL_TEXTURE_BINDING_2D, &value);
    std::cout << "Binded GL_TEXTURE_2D : " << value << "\n";
}









//////////////////////////////////
// Check gl version
//////////////////////////////////

void checkGlVersion(int req1, int req2, std::string functionnality)
{
    //Get version string
    const unsigned char* versionStr = glGetString(GL_VERSION);

    //Extract the 2 version characters
    int versionNo1 = int(versionStr[0]) - 48;
    int versionNo2 = int(versionStr[2]) - 48;

    //Compare values
    if(versionNo1 < req1 || versionNo1 == req1 && versionNo2 < req2)
    {
        std::string errorMsg = "";
        errorMsg += "Attempt to use functionnality " + functionnality + ". ";
        errorMsg += "OpenGL version " + std::to_string(versionNo1) + "." + std::to_string(versionNo2) + " not supported. ";
        errorMsg += "Supported version : " + std::to_string(req1) + "." + std::to_string(req2) + "\n";
        throwError(errorMsg);
    }

    //else everything is valid
    return;
}
