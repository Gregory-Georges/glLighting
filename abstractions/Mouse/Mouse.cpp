#include "Mouse.hpp"



//////////////////////////////////
// Constructor / destructor
//////////////////////////////////

//Constructs a new keyboard object based on a window
Mouse::Mouse(Window& win)
{
    init(win);
}









//////////////////////////////////
// Initialize
//////////////////////////////////

//Initializes the keyboard object on a new window
void Mouse::init(Window& win)
{
    associatedWindow = win.getWindow();
}



//Checks whether the associated window object is still valid
bool Mouse::isValid()
{
    return true;
}









//////////////////////////////////
// Getters
//////////////////////////////////

//Return the cursor's x position
double Mouse::getMousePosX()
{
    double mouseX;
    glfwGetCursorPos(associatedWindow, &mouseX, nullptr);
    return mouseX;
}


//Return the cursor's y position
double Mouse::getMousePosY()
{
    double mouseY;
    glfwGetCursorPos(associatedWindow, nullptr, &mouseY);
    return mouseY;
}



bool Mouse::isLeftPressed()
{
    return glfwGetMouseButton(associatedWindow, GLFW_MOUSE_BUTTON_LEFT) == GLFW_PRESS;
}



bool Mouse::isRightPressed()
{
    return glfwGetMouseButton(associatedWindow, GLFW_MOUSE_BUTTON_RIGHT) == GLFW_PRESS;
}
