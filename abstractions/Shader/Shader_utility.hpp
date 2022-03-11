#ifndef SHADER_UTILITY_HPP_INCLUDED
#define SHADER_UTILITY_HPP_INCLUDED

//Standart headers
#include <iostream>
#include <string>
#include <stdexcept>
#include <fstream>

//Graphic headers
#include <GL/glew.h>
#include <GLFW/glfw3.h>



//////////////////////////////////
// Declaration
//////////////////////////////////

unsigned int compileShader(std::string shaderSource, unsigned int shaderType);      /**< Returns a compiled glShader object */
std::string getSource(std::string path);                                            /**< Returns the source of the file specifid at path */






#endif // SHADER_UTILITY_HPP_INCLUDED
