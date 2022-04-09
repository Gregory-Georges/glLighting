#include "Init.hpp"



//////////////////////////////////
// Initialization
//////////////////////////////////

    //Initializes a new context while initializing GLEW and GLFW
    Window Init::initContext(int x, int y, std::string title)
    {
        //Start windowed context
        initGLFW();
        Window wind(x, y, title);
        initGLEW();

        //Init other components
        glEnable(GL_DEPTH_TEST);    //Depth, for rendering with depth

        //Return context
        return wind;
    }



    //Initializes GLEW
    void Init::initGLEW()
    {
        if(glewInit() != GLEW_OK)
        {
            std::string err_string = "GLEW could not be initialized\n";
            throw std::runtime_error(err_string);
        }
    }



    //Initializes GLF
    void Init::initGLFW()
    {
        if(glfwInit() != GLFW_TRUE)
        {
            std::string err_string = "GLFW could not be initialized\n";
            throw std::runtime_error(err_string);
        }
    }









//////////////////////////////////
// End
//////////////////////////////////

    //Ends a context
    void Init::endContext(Window win)
    {
        glfwDestroyWindow(win.getWindow());
        glfwTerminate();
    }
