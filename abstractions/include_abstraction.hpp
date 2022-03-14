#ifndef INCLUDE_ABSTRACTION_HPP_INCLUDED
#define INCLUDE_ABSTRACTION_HPP_INCLUDED



/*
 * Folder abstractions must be defined as an include directory
 */



//Graphic headers
#include <GL/glew.h>
#include <GLFW/glfw3.h>

//Gl math headers and constants
#include <glm/glm.hpp>
#include <glm/gtc/type_ptr.hpp>
#include <glm/gtc/matrix_transform.hpp>

//Abstractions
#include "Init/Init.hpp"                // Init
#include "Window/Window.hpp"            // Window
#include "Buffer/Buffer.hpp"            // Buffer
    #include "Buffer/IndexBuffer/indexbuffer.hpp"       // Index buffer
    #include "Buffer/VertexBuffer/vertexbuffer.hpp"     // Vertex buffer
    #include "Buffer/Model/model.hpp"                   // Contains model info
#include "Shader/Shader.hpp"            // Shader
#include "Texture/Texture.hpp"          // Texture
#include "VertexArray/VertexArray.hpp"  // VertexArray
#include "Uniform/Uniform.hpp"          // Uniform
#include "Timer/timer.hpp"              // Timer
#include "Constants/Constants.hpp"      // Constant values

//Controls
#include "Keyboard/Keyboard.hpp"        // Keyboard
#include "Mouse/Mouse.hpp"              // Mouse

//Models and rendering
#include "ModelData/ModelData.hpp"      //Model information
#include "Camera/camera.hpp"            //Camera abstraction
#include "Renderable/Renderable.hpp"    //Renderble data



#endif // INCLUDE_ABSTRACTION_HPP_INCLUDED
