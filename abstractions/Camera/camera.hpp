#ifndef CAMERA_HPP
#define CAMERA_HPP

//Standard headers
#include <iostream>

//Graphic headers
#include <GL/glew.h>
#include <GLFW/glfw3.h>

//GLM headers
#include <glm/glm.hpp>
#include <glm/gtc/type_ptr.hpp>
#include <glm/gtc/matrix_transform.hpp>

//Abstraction headers
#include "Keyboard/Keyboard.hpp"



/**
 * Contains a camera. Allows to calculate view matrix
 */
class Camera
{

private:

    glm::vec3 camPos;           /**< The position of the camera */
    glm::vec3 camDirection;     /**< The direction of the camera. Calculated with pitch, yaw and roll */
    glm::vec3 camRight;         /**< The right direction of the camera. Calculated with direction vector */
    glm::vec3 camUp;            /**< The upwards direction of the camera. Is necessary to generate a view matrix */

    float FoV;                  /**< The field of view */
    double pitch;               /**< The pitch value of the camera */
    double yaw;                 /**< The yaw value of the camera */
    double roll;                /**< The roll value of the camera */



public:

////////////////////////////////////////////
// Constructor / destructor
////////////////////////////////////////////

    Camera();






////////////////////////////////////////////
// Setters
////////////////////////////////////////////

    void setPosition(glm::vec3 position);       /**< Sets the position of the camera */
    void setX(double x);                        /**< Sets the position of the camera */
    void setY(double y);                        /**< Sets the position of the camera */
    void setZ(double z);                        /**< Sets the position of the camera */

    void addPosition(glm::vec3 position);       /**< Adds to the position of the camera */
    void addX(double X);                        /**< Adds to the position of the camera */
    void addY(double Y);                        /**< Adds to the position of the camera */
    void addZ(double Z);                        /**< Adds to the position of the camera */

    void addPitch(double deg);                  /**< Adds to the pitch value */
    void addYaw(double deg);                    /**< Adds to the yaw value */
    void addRoll(double deg);                   /**< Adds to the roll value */

    void addFoV(float vFoV);                    /**< Adds to the field of view value */

    void moveFront(double distance);            /**< Moves the camera to it's front vector */
    void moveForward(double distance);          /**< Moves the camera forwards along the x and z axis */
    void moveRight(double distance);            /**< Moves the camera right along the x and z axis */
    void moveWorldUp(double distance);          /**< Moves the camera along the y axis */






///////////////////////////////////////////
// Getters
///////////////////////////////////////////

    glm::vec3 getPosition();                    /**< Returns the camera's position */
    double getX();                              /**< Returns the camera's X position */
    double getY();                              /**< Returns the camera's Y position */
    double getZ();                              /**< Returns the camera's Z position */

    glm::vec3 getAngle();                       /**< Returns the camera's direction */
    double getAngleX();                         /**< Returns the camera's direction's x component */
    double getAngleY();                         /**< Returns the camera's direction's y component */
    double getAngleZ();                         /**< Returns the camera's direction's z component */

    double getPitch();                          /**< Returns the pitch */
    double getYaw();                            /**< Returns the yaw */
    double getRoll();                           /**< Returns the roll */

    float getFoV();                             /**< Returns the field of view of the camera */






///////////////////////////////////////////
// Others
///////////////////////////////////////////

    void calculateDirection();                                          /**< Calculate the direction vector based on pitch, yaw and roll values */
    void regenUpRight();                                                /**< Re-calculates the up and right vectors based on the direction */
    glm::mat4 genViewMatrix();                                          /**< Calculates a view matrix based on the camera object's data */
    void simpleControl(Keyboard KB, float moveSpeed, float turnSpeed);  /**< Controls the camera */
};

#endif // CAMERA_HPP
