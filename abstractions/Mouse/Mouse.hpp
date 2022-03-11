#ifndef MOUSE_HPP
#define MOUSE_HPP

//Graphics headers
#include <GL/glew.h>
#include <GLFW/glfw3.h>

//Abstractions headers
#include "Window/Window.hpp"



/**
 * Handles mouse inputs inside an openned glfw window
 */
class Mouse
{
private:

    GLFWwindow* associatedWindow;       /**< Name of the associated window */






public:

    //////////////////////////////////
    // Constructor / destructor
    //////////////////////////////////

    Mouse(Window& win);            /**< Constructs a new keyboard object based on a window */






    //////////////////////////////////
    // Initialize
    //////////////////////////////////

    void init(Window& win);     /**< Initializes the keyboard object onto a new window */
    bool isValid();             /**< Checks wether the associated window object still exists */






    //////////////////////////////////
    // Getters
    //////////////////////////////////

    double getMousePosX();
    double getMousePosY();

    bool isLeftPressed();
    bool isRightPressed();
};

#endif // MOUSE_HPP
