#ifndef GLSTATE_
#define GLSTATE_

//Standart headers
#include <iostream>

//Graphical headers
#include <GL/glew.h>
#include <GLFW/glfw3.h>






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



#endif // GLSTATE_
