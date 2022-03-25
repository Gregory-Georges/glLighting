#ifndef UNIFORM_HPP
#define UNIFORM_HPP

//Standart headers
#include <iostream>
#include <string>
#include <stdexcept>

//Graphic headers
#include <GL/glew.h>
#include <GLFW/glfw3.h>

//GLM
#include <glm/glm.hpp>
#include <glm/gtc/type_ptr.hpp>
#include <glm/gtc/matrix_transform.hpp>

//Abstractions
#include "Shader/Shader.hpp"



/**
 * Represents the uniform type of an uniform
 */
enum uniformType
{
    //Float value uniform vectors
    UNIFORM_VEC_3_FV,   /**< Uniform 3 element values vector */
    UNIFORM_VEC_4_FV,   /**< Uniform 4 element values vector */

    //Float value uniform matrices
    UNIFORM_MAT_3_FV,   /**< Uniform 3D float values matrix */
    UNIFORM_MAT_4_FV,   /**< Uniform 4D float values matrix */

    //Invalid
    UNIFORM_INVALID     /**< Uniform is invalid */
};



/**
 * Contains a uniform object
 */
class Uniform
{

private :

    unsigned int id;                /**< Contains the id of the uniform */
    unsigned int attachedShader;    /**< Contains the attached shader object */
    uniformType ut;                 /**< Contains the type of the uniform object */
    std::string ufName;             /**< Contains the name of the uniform */

    float* uniformData;             /**< Contains a pointer to the uniform's value */






public:

    //////////////////////////////////
    // Constructor / destructor
    //////////////////////////////////

    Uniform(uniformType ut, Shader &shd, std::string ufName);               /**< Constructs an uniform of said type */
    Uniform(uniformType ut, Shader &shd, std::string ufName, float* data);  /**< Constructs an uniform and gives it data */






    //////////////////////////////////
    // Getters
    //////////////////////////////////

    unsigned int getID();           /**< Returns the name of the uniform */
    std::string getName();          /**< Returns the uniform's name */






    //////////////////////////////////
    // Validate
    //////////////////////////////////

    void validate();        /**< Throws an error if the uniform is invalid */






    //////////////////////////////////
    // Data
    //////////////////////////////////

    void data(float* uniformValue);     /**< Gives data to the uniform */
    void update();                      /**< Uses predefined pointer to give data */
};

#endif // UNIFORM_HPP
