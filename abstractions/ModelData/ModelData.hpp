#ifndef MODELDATA_HPP
#define MODELDATA_HPP

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
#include "Constants/Constants.hpp"



/**
 * Contains the data necessary for generating a matrix on screen
 * - Position
 * - Rotation
 * - Scale
 */
class ModelData
{
protected:

    glm::mat4 modl;     /**< Renderable's model matrix */

    glm::vec3 pos;      /**< The position of the object */
    glm::vec3 angl;     /**< The object's rotation in each of the axis in radians */
    glm::vec3 scl;      /**< The scale of the object */






public:

    //////////////////////////////////
    // Constructor
    //////////////////////////////////

    ModelData();        /**< Constructs an object to position 0 */






    //////////////////////////////////
    // Calculate matrices
    //////////////////////////////////

    virtual glm::mat4 CalculateMatrix();       /**< Calculates a model matrix based on the model's position */






    //////////////////////////////////
    // Modifiers
    //////////////////////////////////

    virtual void addRotate(glm::vec3 rotate);       /**< Adds to the rotation of the object */
    virtual void addRotateX(float angle);           /**< Pitch control */
    void addRotateY(float angle);                   /**< Yaw conttrol */
    void addRotateZ(float angle);                   /**< Roll control */

    void addScale(glm::vec3 scale);                 /**< Adds to the scale of the objects */

    void setRotate(glm::vec3 rotate);               /**< Sets the rotation of the object */
    void SetRotateX(float angle);                   /**< Pitch control */
    void SetRotateY(float angle);                   /**< Yaw control */
    void SetRotateZ(float angle);                   /**< Roll control */

    void setScale(glm::vec3 scale);                 /**< Sets the scale of the object */

    void setPos(glm::vec3 vpos);                    /**< Sets the position of the object */
    void addPos(glm::vec3 vpos);                    /**< Adds to the position of the object */






    //////////////////////////////////
    // Getters
    //////////////////////////////////

    glm::vec3 getScale();                   /**< Returns the scale of the object */
    glm::vec3 getRotation();                /**< Returns rhe vector containing the rotation angles of the object */
    glm::vec3 getPos();                     /**< Returns the position of the object */
};

#endif // MODELDATA_HPP
