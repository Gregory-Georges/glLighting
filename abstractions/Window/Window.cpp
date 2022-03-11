#include "Window.hpp"



//////////////////////////////////
// Constructor / destructor
//////////////////////////////////

//Creates a window object
Window::Window(int x, int y, std::string title)
{
    this->title = title;
    wind = glfwCreateWindow(x, y, title.c_str(), NULL, NULL);

    //Throw an exception if the window is invalid
    if(wind == nullptr)
    {
        std::string error_string = "The window (" + std::to_string(x) + ", " + std::to_string(y) + ", " + title + ") could not be created\n";
        throw std::runtime_error(error_string);
    }

    //Make the window's context current by default
    makeCurrentContext();
}



//Destroys a window object
Window::~Window()
{
    glfwDestroyWindow(wind);
}









//////////////////////////////////
// Getters
//////////////////////////////////

//Returns the window pointer
GLFWwindow* Window::getWindow()
{
    return wind;
}



//Returns the width of the window
int Window::getWidth()
{
    int width = 0;
    glfwGetWindowSize(wind, &width, nullptr);
    return width;
}



//Returns the height of the window
int Window::getHeight()
{
    int height = 0;
    glfwGetWindowSize(wind, nullptr, &height);
    return height;
}



//Returns the title of the window
std::string Window::getTitle()
{
    return title;
}



//Returns the x-axis position
int Window::getPosX()
{
    int posX;
    glfwGetWindowPos(wind, &posX, nullptr);
    return posX;
}



//Returns the y-axis position
int Window::getPosY()
{
    int posY;
    glfwGetWindowPos(wind, nullptr, &posY);
    return posY;
}









//////////////////////////////////
// Setters
//////////////////////////////////

//Ajusts the size of the window
void Window::setSize(unsigned int width, unsigned int height)
{
    glfwSetWindowSize(wind, width, height);
}



//Ajusts the title of the window
void Window::setTitle(std::string title)
{
    glfwSetWindowTitle(wind, title.c_str());
}



//Ajusts the position of the window
void Window::setPos(unsigned int x, unsigned int y)
{
    glfwSetWindowPos(wind, x, y);
}









//////////////////////////////////
// Commands
//////////////////////////////////

//Makes the window the current contrext for drawing
void Window::makeCurrentContext()
{
    glfwMakeContextCurrent(wind);
}



//Swaps the window's buffer's
void Window::swapBuffers()
{
    glfwSwapBuffers(wind);
}



//Returns if the window should close
bool Window::shouldClose()
{
    return glfwWindowShouldClose(wind);
}
