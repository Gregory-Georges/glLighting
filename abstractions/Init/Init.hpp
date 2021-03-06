#ifndef INIT_HPP
#define INIT_HPP

//Standart headers
#include <iostream>

//Graphic headers
#include <GL/glew.h>
#include <GLFW/glfw3.h>

//Abstactions
#include "../Window/Window.hpp"



/**
 * Contains functions to initialize an openGL context
 */
class Init
{

public:

    //////////////////////////////////
    // Initialization
    //////////////////////////////////

    static Window initContext(int x, int y, std::string title);     /**< Initializes a valid context */
    static void initGLEW();                                         /**< Initializes GLEW */
    static void initGLFW();                                         /**< Initializes GLFW */



    //////////////////////////////////
    // End
    //////////////////////////////////

    static void endContext(Window win);                             /**< Ends an active context */
};

#endif // INIT_HPP
