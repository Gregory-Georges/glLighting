#ifndef SHADER_HPP
#define SHADER_HPP

//Standart headers
#include <string>

//Graphic headers
#include <GL/glew.h>
#include <GLFW/glfw3.h>

//Abstractions
#include "Shader_utility.hpp"

//Useful
#include "errors/errors.hpp"



/**
 * Contains a glShader object
 * Allows to manage uniforms
 */
class Shader
{
private:

    unsigned int id;        /**< The name of the shader object */






public:

    //////////////////////////////////
    // Constructor / destructor
    //////////////////////////////////

    Shader();       /**< Constructs an empty shader object */
    ~Shader();      /**< Destroys the shader object */

    Shader(std::string vertexShd, std::string fragmentShd);     /**< Constructs a usable shader object */
    Shader(const Shader& shd);                                  /**< Copies a shader object */






    //////////////////////////////////
    // Getters
    //////////////////////////////////

    unsigned int getID();       /**< Returns the name of the shader object */
    int getValid();             /**< Returns if the shader is valid */






    //////////////////////////////////
    // Data
    //////////////////////////////////

    void use();                                                         /**< Binds the shader object */
    void compile(std::string vertexShd, std::string fragmentShd);       /**< Compiles the shader object */
};

#endif // SHADER_HPP
