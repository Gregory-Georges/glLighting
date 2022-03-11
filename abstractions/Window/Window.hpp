#ifndef WINDOW_HPP
#define WINDOW_HPP

//Standart headers
#include <string>
#include <stdexcept>

//Graphic headers
#include <GL/glew.h>
#include <GLFW/glfw3.h>



/**
 * Contains information for creating and using a window
 */
class Window
{
private:

    GLFWwindow* wind;       /**< Contains the GLFW window object pointer */
    std::string title;      /**< The title of the window */






public:

    //////////////////////////////////
    // Constructor / destructor
    //////////////////////////////////

    Window(int x, int y, std::string title);        /**< Creates a window object */
    ~Window();                                      /**< Destroys the window object */






    //////////////////////////////////
    // Getters
    //////////////////////////////////

    GLFWwindow* getWindow();    /**< Returns the pointer to the GLFWwindow object */
    int getWidth();             /**< Returns the width of the window */
    int getHeight();            /**< Returns the height of the window */
    std::string getTitle();     /**< Returns the title of the window */
    int getPosX();              /**< Returns the x-axis position of the window */
    int getPosY();              /**< Returns the y-axis position of the window */






    //////////////////////////////////
    // Setters
    //////////////////////////////////

    void setSize(unsigned int width, unsigned int height);      /**< Sets the size of the window */
    void setTitle(std::string title);                           /**< Sets the title of the window */
    void setPos(unsigned int x, unsigned int y);                /**< Sets the position of the window */






    //////////////////////////////////
    // Commands
    //////////////////////////////////

    void makeCurrentContext();      /**< Makes the window the current target for rendering */
    void swapBuffers();             /**< Swaps the window's rendering buffers */
    bool shouldClose();             /**< Returns if the window should close */
};

#endif // WINDOW_HPP
