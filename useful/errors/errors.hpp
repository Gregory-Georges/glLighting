#ifndef ERRORS_HPP
#define ERRORS_HPP

//Standart headers
#include <iostream>
#include <stdexcept>

//Graphics headers
#include <GL/glew.h>
#include <GLFW/glfw3.h>



void pollglErrors();                            //Checks if any openGL error has been thrown and throws error if yes
void throwError(std::string errorMessage);      //Returns a runtime error with the message



#endif // ERRORS_HPP
