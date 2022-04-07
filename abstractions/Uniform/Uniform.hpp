#ifndef UNIFORM_HPP
#define UNIFORM_HPP

//Standart headers
#include <iostream>
#include <string>

//Graphic headers
#include <GL/glew.h>
#include <GLFW/glfw3.h>

//GLM
#include <glm/glm.hpp>
#include <glm/gtc/type_ptr.hpp>
#include <glm/gtc/matrix_transform.hpp>

//Utilitu
#include "Uniform_utility.hpp"
#include "errors/errors.hpp"



/**
 * Contains a uniform object
 */
class Uniform
{

private :

    unsigned int id;                /**< Contains the id of the uniform */
    unsigned int attachedShader;    /**< Contains the attached shader object */
    GLenum uniformType;             /**< Contains the type of the uniform object */
    std::string ufName;             /**< Contains the name of the uniform */

    float* uniformData;             /**< Contains a pointer to the uniform's value */






public:

    //////////////////////////////////
    // Constructor / destructor
    //////////////////////////////////

    Uniform(GLenum uniformType, unsigned int shd, std::string ufName);               /**< Constructs an uniform of said type */
    Uniform(GLenum uniformType, unsigned int shd, std::string ufName, float* data);  /**< Constructs an uniform and gives it data */






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
