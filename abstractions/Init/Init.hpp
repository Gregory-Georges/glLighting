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
 * Contient les fonctions pour initialiser un contexte
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
};

#endif // INIT_HPP
