#include "ModelData.hpp"



//////////////////////////////////
// Constructor / destructor
//////////////////////////////////

    //Constructs a renderable
    ModelData::ModelData()
    {
        pos = glm::vec3(0.0);   //Default values for a generic spawned-in attribute
        scl = glm::vec3(1.0);
        angl = glm::vec3(0.0);

        CalculateMatrix();
    }









//////////////////////////////////
// Calculate matrices
//////////////////////////////////

    glm::mat4 ModelData::CalculateMatrix()
    {
        //Reset matrix
        modl = glm::mat4(1.0);


        //Calculate translation
        modl = glm::translate(modl, pos);

        //Calculate rotation on all axis
        modl = glm::rotate(modl, angl.x, glm::vec3(1.0, 0.0, 0.0));     //Pitch
        modl = glm::rotate(modl, angl.y, glm::vec3(0.0, 1.0, 0.0));     //Yaw
        modl = glm::rotate(modl, angl.z, glm::vec3(0.0, 0.0, 1.0));     //Roll

        //Calculate scale
        modl = glm::scale(modl, scl);


        //Return matrix
        return modl;
    }









//////////////////////////////////
// Modifiers
//////////////////////////////////

    void ModelData::addRotate(glm::vec3 rotate)
    {
        addRotateX(rotate.x);
        addRotateX(rotate.y);
        addRotateX(rotate.z);
    }

    //Usage of fmod to prevent values from going out of range
    void ModelData::addRotateX(float angle)
    {
        angl.x += angle;
        angl.x = fmod(angl.x, 2 * PI);
    }

    void ModelData::addRotateY(float angle)
    {
        angl.y += angle;
        angl.y = fmod(angl.y, 2 * PI);
    }

    void ModelData::addRotateZ(float angle)
    {
        angl.z += angle;
        angl.z = fmod(angl.z, 2 * PI);
    }

    void ModelData::addScale(glm::vec3 scale) { scl += scale; }
    void ModelData::addPos(glm::vec3 vpos) { pos += vpos; }



    void ModelData::setRotate(glm::vec3 rotate)
    {
        angl.x = fmod(rotate.x, 2 * PI);
        angl.y = fmod(rotate.y, 2 * PI);
        angl.z = fmod(rotate.z, 2 * PI);
    }

    void ModelData::SetRotateX(float angle) { angl.x = fmod(angle, 2 * PI); }
    void ModelData::SetRotateY(float angle) { angl.y = fmod(angle, 2 * PI); }
    void ModelData::SetRotateZ(float angle) { angl.z = fmod(angle, 2 * PI); }



    void ModelData::setScale(glm::vec3 scale) { scl = scale; }
    void ModelData::setPos(glm::vec3 vpos) { pos = vpos; }









//////////////////////////////////
// Getters
//////////////////////////////////

    glm::vec3 ModelData::getPos() { return pos; }
    glm::vec3 ModelData::getRotation() { return angl; }
    glm::vec3 ModelData::getScale() { return scl; }
