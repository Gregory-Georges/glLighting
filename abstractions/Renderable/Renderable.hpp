#ifndef RENDERABLE_HPP
#define RENDERABLE_HPP

//Standart headers
#include <string>
#include <stdexcept>

//Graphic headers
#include <GL/glew.h>
#include <GLFW/glfw3.h>

//glmath
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

//Other
#include <ModelData/ModelData.hpp>



/**
 * Contains the data necessary for rendering a complete object on screen / generating a matrix
 * - Position
 * - Rotation
 * - Scale
 *
 * - Buffer information
 *  -Index buffer
 *  -Vertex buffer
 *  -Reference to textures
 */
class Renderable
{
    private:

        ModelData md;
};

#endif // RENDERABLE_HPP
