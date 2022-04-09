#include "Keyboard.hpp"



//////////////////////////////////
// Constructor / destructor
//////////////////////////////////

    //Constructs a new keyboard object based on a window
    Keyboard::Keyboard(Window& win)
    {
        init(win);
    }









//////////////////////////////////
// Initialize
//////////////////////////////////

    //Initializes the keyboard object on a new window
    void Keyboard::init(Window& win)
    {
        associatedWindow = win.getWindow();
    }



    //Checks whether the associated window object is still valid
    bool Keyboard::isValid()
    {
        return true;
    }









//////////////////////////////////
// Getters
//////////////////////////////////

    //Returns the state of the entered key
    int Keyboard::getKeyState(int keyCode)
    {
        return glfwGetKey(associatedWindow, keyCode);
    }



    //Returns true if the key is pressed, false otherwise
    bool Keyboard::isKeyPressed(int keyCode)
    {
        return glfwGetKey(associatedWindow, keyCode) == GLFW_PRESS;
    }
