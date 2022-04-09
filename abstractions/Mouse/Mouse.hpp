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

    Mouse(Window& win);         /**< Constructs a new keyboard object based on a window */






    //////////////////////////////////
    // Initialize
    //////////////////////////////////

    void init(Window& win);     /**< Initializes the mouse object onto a new window */
    bool isValid();             /**< Checks wether the associated window object still exists */






    //////////////////////////////////
    // Getters
    //////////////////////////////////

    double getMousePosX();      /**< Returns the position of the mouse on the x axis */
    double getMousePosY();      /**< Returns the position of the mouse on the y axis */

    bool isLeftPressed();       /**< Returns if the left mouse button is pressed */
    bool isRightPressed();      /**< Returns if the right mouse button is pressed */
};

#endif // MOUSE_HPP
