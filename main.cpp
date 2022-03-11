//Standart headers
#include <iostream>

//Graphical headers
#include <GL/glew.h>
#include <GLFW/glfw3.h>

//user-defined
#include "include_abstraction.hpp"
#include "include_managers.hpp"
#include "include_useful.hpp"






int main()
{
    ///////////////////////////////
    // Create window
    ///////////////////////////////

    Window win = Init::initContext(480, 360, "glCube");
    Keyboard KB(win);









    ///////////////////////////////
    // Compile shaders
    ///////////////////////////////

    Shader shd(getSource("shaders/normal/vertex.shd"), getSource("shaders/normal/fragment.shd"));
    Shader lightshd(getSource("shaders/light/vertex.shd"), getSource("shaders/light/fragment.shd"));
    shd.use();









    ///////////////////////////////
    // Setup camera
    ///////////////////////////////

    Camera cam;









    ///////////////////////////////
    // Setup texture
    ///////////////////////////////

    Manager<Texture> texMan;
    texMan.add(Texture("media/images/box.jpg", GL_TEXTURE_2D));
    texMan.add(Texture("media/images/place_m.jpg", GL_TEXTURE_2D));
    texMan.get(0).bind();











    ///////////////////////////////
    // Setup matrices
    ///////////////////////////////

    //Get uniforms
    Uniform modlUni(UNIFORM_MAT_4_FV, shd, "modl");
    Uniform viewUni(UNIFORM_MAT_4_FV, shd, "view");
    Uniform projUni(UNIFORM_MAT_4_FV, shd, "proj");

    //Generate matrices
    glm::mat4 modl(1.0);
    glm::mat4 view(1.0);
    glm::mat4 proj(1.0);

    //Assign matrices
    view = cam.genViewMatrix();
    proj = glm::perspective(45.0, double(win.getWidth()) / double(win.getHeight()), 0.01, 100.0);

    //Give data to shader
    modlUni.data(glm::value_ptr(modl));
    viewUni.data(glm::value_ptr(view));
    projUni.data(glm::value_ptr(proj));









    ///////////////////////////////
    // Create buffer
    ///////////////////////////////

    // Our vertices. Three consecutive floats give a 3D vertex; Three consecutive vertices give a triangle.
    // A cube has 6 faces with 2 triangles each, so this makes 6*2=12 triangles, and 12*3 vertices
    int indices = 2 * 3;
    float square[] =
    {
        //Coordinates       //Texture pos
        -1.0f,-1.0f,-1.0f,  0.0f, 0.0f,
         1.0f,-1.0f,-1.0f,  1.0f, 0.0f,
         1.0f, 1.0f,-1.0f,  1.0f, 1.0f,
        -1.0f,-1.0f,-1.0f,  0.0f, 0.0f,
        -1.0f, 1.0f,-1.0f,  0.0f, 1.0f,
         1.0f, 1.0f,-1.0f,  1.0f, 1.0f
    };

    //Generate vertex buffer
    VertexBuffer VB(square, sizeof(square), GL_STATIC_DRAW);
    VB.bind();

    //Generate vertex array
    VertexArray VA;
    VA.enableAttribute(0, GL_FLOAT, 3, sizeof(float) * 5, 0);
    VA.enableAttribute(1, GL_FLOAT, 2, sizeof(float) * 5, sizeof(float) * 3);









    ///////////////////////////////
    // Program loop
    ///////////////////////////////

    while(!win.shouldClose())
    {
        //Poll events
        glfwPollEvents();

        //Controls
        const double moveSpeed = 0.02;
        const double turnSpeed = 1;
        if(KB.isKeyPressed(GLFW_KEY_W))             //WASD movement
            cam.moveForward(moveSpeed);
        if(KB.isKeyPressed(GLFW_KEY_S))
            cam.moveForward(-moveSpeed);
        if(KB.isKeyPressed(GLFW_KEY_A))
            cam.moveRight(-moveSpeed);
        if(KB.isKeyPressed(GLFW_KEY_D))
            cam.moveRight(moveSpeed);
        if(KB.isKeyPressed(GLFW_KEY_I))             //IJKL turn movement
            cam.addPitch(turnSpeed);
        if(KB.isKeyPressed(GLFW_KEY_K))
            cam.addPitch(-turnSpeed);
        if(KB.isKeyPressed(GLFW_KEY_J))
            cam.addYaw(-turnSpeed);
        if(KB.isKeyPressed(GLFW_KEY_L))
            cam.addYaw(turnSpeed);
        if(KB.isKeyPressed(GLFW_KEY_SPACE))         //Up down movement
            cam.moveWorldUp(moveSpeed);
        if(KB.isKeyPressed(GLFW_KEY_LEFT_SHIFT))
            cam.moveWorldUp(-moveSpeed);
        //Update camera matrix
        view = cam.genViewMatrix();
        viewUni.data(glm::value_ptr(view));


        //Draw
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
        glDrawArrays(GL_TRIANGLES, 0, indices);
        win.swapBuffers();
    }
}
