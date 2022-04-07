#ifndef SHADER_HPP
#define SHADER_HPP

//Standart headers
#include <string>

//Graphic headers
#include <GL/glew.h>
#include <GLFW/glfw3.h>

//Abstractions
#include "Shader_utility.hpp"

//Container
#include "UniformContainer/UniformContainer.hpp"

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
    UniformContainer uc;    /**< Contains the uniforms of thhe program */






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

    unsigned int getID();                           /**< Returns the name of the shader object */
    Uniform& getUniform(std::string uniformName);    /**< Returns a uniform of said name */
    int getValid();                                 /**< Returns if the shader is valid */






    //////////////////////////////////
    // Data
    //////////////////////////////////

    void use();                                                         /**< Binds the shader object */
    void compile(std::string vertexShd, std::string fragmentShd);       /**< Compiles the shader object */
    void gatherUniforms();                                              /**< Gets the uniforms in the compiled shader */
};

#endif // SHADER_HPP
