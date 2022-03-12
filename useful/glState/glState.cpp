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
