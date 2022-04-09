#ifndef KEYBOARD_HPP
#define KEYBOARD_HPP

//Graphics headers
#include <GL/glew.h>
#include <GLFW/glfw3.h>

//Abstractions headers
#include "Window/Window.hpp"



/**
 * Handles keyboard inputs inside a glfw window
 */
class Keyboard
{
private:

    GLFWwindow* associatedWindow;     /**< Name of the associated window */






public:

    //////////////////////////////////
    // Constructor / destructor
    //////////////////////////////////

    Keyboard(Window& win);   /**< Constructs a new keyboard object based on a window */






    //////////////////////////////////
    // Initialize
    //////////////////////////////////

    void init(Window& win);     /**< Initializes the keyboard object onto a new window */
    bool isValid();             /**< Checks wether the associated window object still exists */






    //////////////////////////////////
    // Getters
    //////////////////////////////////

    int getKeyState(int keyCode);       /**< Returns the state of the entered GLFW_KEY */
    bool isKeyPressed(int keyCode);     /**< Returns true if the key is pressed, false otherwise */
};

#endif // KEYBOARD_HPP
