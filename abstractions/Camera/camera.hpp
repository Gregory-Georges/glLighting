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

    glm::vec3 camPos;
    glm::vec3 camDirection;
    glm::vec3 camRight;
    glm::vec3 camUp;

    float FoV;
    double pitch;
    double yaw;
    double roll;



public:

////////////////////////////////////////////
// Constructor / destructor
////////////////////////////////////////////

    Camera();






////////////////////////////////////////////
// Setters
////////////////////////////////////////////

    void setPosition(glm::vec3 position);
    void setX(double x);
    void setY(double y);
    void setZ(double z);

    void addPosition(glm::vec3 position);
    void addX(double X);
    void addY(double Y);
    void addZ(double Z);

    void addPitch(double deg);
    void addYaw(double deg);
    void addRoll(double deg);

    void addFoV(float vFoV);

    void moveFront(double distance);
    void moveForward(double distance);
    void moveRight(double distance);
    void moveWorldUp(double distance);






///////////////////////////////////////////
// Getters
///////////////////////////////////////////

    glm::vec3 getPosition();
    double getX();
    double getY();
    double getZ();

    glm::vec3 getAngle();
    double getAngleX();
    double getAngleY();
    double getAngleZ();

    double getPitch();
    double getYaw();
    double getRoll();

    float getFoV();






///////////////////////////////////////////
// Others
///////////////////////////////////////////

    void calculateDirection();
    void regenUpRight();
    glm::mat4 genViewMatrix();
    void simpleControl(Keyboard KB, float moveSpeed, float turnSpeed);
};

#endif // CAMERA_HPP
