#ifndef GLSTATE_
#define GLSTATE_

//Standart headers
#include <iostream>

//Graphical headers
#include <GL/glew.h>
#include <GLFW/glfw3.h>

//Useful
#include "errors/errors.hpp"






//Contains functions meant to gather the currrent state of OpenGL






//////////////////////////////////
// Get binded
//////////////////////////////////

/**
 * Check which :
 * -Index buffer is binded
 * -Vertex buffer is binded
 * -VA is binded
 * -Program is binded
 * -Texture is binded
 */
void printBindedElements();






//////////////////////////////////
// Check gl version
//////////////////////////////////

/**
 * Checks wether the openGL version is supported or not. Throws
 * an error if not
 */
void checkGlVersion(int req1, int req2, std::string functionnality);



#endif // GLSTATE_
