#include "camera.hpp"



////////////////////////////////////////////
// Constructor / destructor
////////////////////////////////////////////

Camera::Camera()
{
    pitch = 0.0;
    yaw = 0.0;
    roll = 0.0;
    camPos = glm::vec3(0.0);
    FoV = 45.0f;

    calculateDirection();
    regenUpRight();
}









////////////////////////////////////////////
// Setters
////////////////////////////////////////////

void Camera::setPosition(glm::vec3 position) { camPos = position; }
void Camera::setX(double x) { camPos.x = x; }
void Camera::setY(double y) { camPos.y = y; }
void Camera::setZ(double z) { camPos.z = z; }


void Camera::addPosition(glm::vec3 position) { camPos += position; }
void Camera::addX(double x) { camPos.x += x; }
void Camera::addY(double y) { camPos.y += y; }
void Camera::addZ(double z) { camPos.z += z; }


void Camera::addPitch(double deg)
{
    pitch += deg;
    if(pitch >= 90.0)
        pitch = 89.99;
    else if(pitch < -89.99)
        pitch = -89.9;
}

void Camera::addYaw(double deg)
{
    yaw += deg;
    if(yaw > 360.0 || yaw < 0.0)
        yaw = fmod(yaw, 360.0);
}

void Camera::addRoll(double deg)
{
    roll += deg;
    if(roll > 360.0 || roll < 0.0)
        roll = fmod(roll, 360.0);
}

void Camera::addFoV(float vFoV)
{
    FoV += vFoV;
    if(FoV > 45.0)
        FoV = 45.0;
    else if(FoV < 1.0)
        FoV = 1.0;
}


void Camera::moveFront(double distance)
{
    addX(camDirection.x * distance);
    addY(camDirection.y * distance);
    addZ(camDirection.z * distance);
}

void Camera::moveForward(double distance)
{
    addX(-glm::sin(-glm::radians(yaw)) * distance);
    addZ(-glm::cos(-glm::radians(yaw)) * distance);
}

void Camera::moveRight(double distance)
{
    regenUpRight();
    addX(camRight.x * distance);
    addY(camRight.y * distance);
    addZ(camRight.z * distance);
}

void Camera::moveWorldUp(double distance)
{
    addY(distance);
}



///////////////////////////////////////////
// Getters
///////////////////////////////////////////

glm::vec3 Camera::getPosition() { return camPos; }
double Camera::getX() { return camPos.x; }
double Camera::getY() { return camPos.y; }
double Camera::getZ() { return camPos.z; }

glm::vec3 Camera::getAngle() { return camDirection; }
double Camera::getAngleX() { return camDirection.x; }
double Camera::getAngleY() { return camDirection.y; }
double Camera::getAngleZ() { return camDirection.z; }

double Camera::getPitch() { return pitch; }
double Camera::getYaw() { return yaw; }
double Camera::getRoll() { return roll; }

float Camera::getFoV() { return FoV; }



///////////////////////////////////////////
// Others
///////////////////////////////////////////

void Camera::calculateDirection()
{
    //Generates a direction vector based on pitch, yaw and roll
    camDirection.x = glm::cos(glm::radians(pitch)) * glm::sin(glm::radians(yaw));
    camDirection.y = glm::sin(glm::radians(pitch));
    camDirection.z = -glm::cos(glm::radians(pitch)) * glm::cos(glm::radians(yaw));
}

void Camera::regenUpRight()
{
    //Generates the Camera's right and up vector for matrix gen
    camRight = glm::normalize(glm::cross(-glm::vec3(0.0, 1.0, 0.0), camDirection));
    camUp = glm::cross(camRight, camDirection);
}

glm::mat4 Camera::genViewMatrix()
{
    calculateDirection();
    regenUpRight();
    return glm::lookAt(camPos, camPos + camDirection, camUp);
}

void Camera::simpleControl(Keyboard KB, float moveSpeed, float turnSpeed)
{
    if(KB.isKeyPressed(GLFW_KEY_W))             //WASD movement
        moveForward(moveSpeed);
    if(KB.isKeyPressed(GLFW_KEY_S))
        moveForward(-moveSpeed);
    if(KB.isKeyPressed(GLFW_KEY_A))
        moveRight(-moveSpeed);
    if(KB.isKeyPressed(GLFW_KEY_D))
        moveRight(moveSpeed);
    if(KB.isKeyPressed(GLFW_KEY_I))             //IJKL turn movement
        addPitch(turnSpeed);
    if(KB.isKeyPressed(GLFW_KEY_K))
        addPitch(-turnSpeed);
    if(KB.isKeyPressed(GLFW_KEY_J))
        addYaw(-turnSpeed);
    if(KB.isKeyPressed(GLFW_KEY_L))
        addYaw(turnSpeed);
    if(KB.isKeyPressed(GLFW_KEY_SPACE))         //Up down movement
        moveWorldUp(moveSpeed);
    if(KB.isKeyPressed(GLFW_KEY_LEFT_SHIFT))
        moveWorldUp(-moveSpeed);
}
