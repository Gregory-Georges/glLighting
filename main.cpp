//Standart headers
#include <iostream>

//Graphical headers
#include <GL/glew.h>
#include <GLFW/glfw3.h>

//user-defined
#include "include_abstraction.hpp"
#include "include_containers.hpp"
#include "include_useful.hpp"






/**
 * To do list :
 * - Create copy constructors for openGL classes
 * Done : Buffers
 * Done : Shaders
 */
int main()
{
    ///////////////////////////////
    // Create window
    ///////////////////////////////

    Window win = Init::initContext(480, 360, "glCube");
    Keyboard KB(win);









    ///////////////////////////////
    // Generate vertex arrays
    ///////////////////////////////

    VertexArray VA;
    VertexArray lightVA;









    ///////////////////////////////
    // Compile shaders
    ///////////////////////////////

    Shader shd(getSource("shaders/normal/vertex.shd"), getSource("shaders/normal/fragment.shd"));
    Shader lightshd(getSource("shaders/light/lightvertex.shd"), getSource("shaders/light/lightfragment.shd"));
    printShaderUniformList(shd.getID());
    printShaderUniformList(lightshd.getID());










    ///////////////////////////////
    // Setup camera
    ///////////////////////////////

    Camera cam;
    cam.setPosition(glm::vec3(0.0, 0.0, 4.0));









    ///////////////////////////////
    // Setup texture
    ///////////////////////////////

    TextureContainer texMan("media/images/testscreen.jpg", GL_TEXTURE_2D);
    texMan.add(Texture("media/images/box.jpg", GL_TEXTURE_2D));
    texMan.add(Texture("media/images/place_m.jpg", GL_TEXTURE_2D));
    texMan.add(Texture("media/images/colors.jpg", GL_TEXTURE_2D));









    ///////////////////////////////
    // Generate object world data
    ///////////////////////////////

    ModelData object;
    ModelData light;

    //Object
    object.setPos(glm::vec3(0.0, 0.0, 0.0));

    //Light
    light.setPos(glm::vec3(-2.0, 0.0, -2.0));
    light.setScale(glm::vec3(0.25));











    ///////////////////////////////
    // Setup matrices uniforms
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
    // Setup light uniforms
    ///////////////////////////////

    //Get uniforms
    Uniform lightColorUni(UNIFORM_VEC_4_FV, shd, "lightColor");
    Uniform lightPosUni(UNIFORM_VEC_3_FV, shd, "lightPos");

    //setup data
    glm::vec4 lightColor = glm::vec4(1.0, 1.0, 1.0, 1.0);
    glm::vec3 lightPos = light.getPos();

    //Give data to shader
    lightColorUni.data(glm::value_ptr(lightColor));
    lightPosUni.data(glm::value_ptr(lightPos));









    ///////////////////////////////
    // Create buffer
    ///////////////////////////////

    // Our vertices. Three consecutive floats give a 3D vertex; Three consecutive vertices give a triangle.
    // A cube has 6 faces with 2 triangles each, so this makes 6*2=12 triangles, and 12*3 vertices
    //Times 2 faces
    int indices = 2 * 3 * 6;
    float square[] =
    {
        //Coordinates         //Texture pos //Normals
        -1.0f, -1.0f, -1.0f,  0.0f, 0.0f,   0.0f,  0.0f, -1.0f,     //Face 1
         1.0f, -1.0f, -1.0f,  1.0f, 0.0f,   0.0f,  0.0f, -1.0f,
         1.0f,  1.0f, -1.0f,  1.0f, 1.0f,   0.0f,  0.0f, -1.0f,
        -1.0f, -1.0f, -1.0f,  0.0f, 0.0f,   0.0f,  0.0f, -1.0f,
        -1.0f,  1.0f, -1.0f,  0.0f, 1.0f,   0.0f,  0.0f, -1.0f,
         1.0f,  1.0f, -1.0f,  1.0f, 1.0f,   0.0f,  0.0f, -1.0f,

        -1.0f, -1.0f,  1.0f,  0.0f, 0.0f,   0.0f,  0.0f,  1.0f,     //Face 2
         1.0f, -1.0f,  1.0f,  1.0f, 0.0f,   0.0f,  0.0f,  1.0f,
         1.0f,  1.0f,  1.0f,  1.0f, 1.0f,   0.0f,  0.0f,  1.0f,
        -1.0f, -1.0f,  1.0f,  0.0f, 0.0f,   0.0f,  0.0f,  1.0f,
        -1.0f,  1.0f,  1.0f,  0.0f, 1.0f,   0.0f,  0.0f,  1.0f,
         1.0f,  1.0f,  1.0f,  1.0f, 1.0f,   0.0f,  0.0f,  1.0f,

        -1.0f, -1.0f, -1.0f,  0.0f, 0.0f,  -1.0f,  0.0f,  0.0f,     //Face 3
        -1.0f, -1.0f,  1.0f,  1.0f, 0.0f,  -1.0f,  0.0f,  0.0f,
        -1.0f,  1.0f,  1.0f,  1.0f, 1.0f,  -1.0f,  0.0f,  0.0f,
        -1.0f, -1.0f, -1.0f,  0.0f, 0.0f,  -1.0f,  0.0f,  0.0f,
        -1.0f,  1.0f, -1.0f,  0.0f, 1.0f,  -1.0f,  0.0f,  0.0f,
        -1.0f,  1.0f,  1.0f,  1.0f, 1.0f,  -1.0f,  0.0f,  0.0f,

         1.0f, -1.0f, -1.0f,  0.0f, 0.0f,   1.0f,  0.0f,  0.0f,     //Face 4
         1.0f, -1.0f,  1.0f,  1.0f, 0.0f,   1.0f,  0.0f,  0.0f,
         1.0f,  1.0f,  1.0f,  1.0f, 1.0f,   1.0f,  0.0f,  0.0f,
         1.0f, -1.0f, -1.0f,  0.0f, 0.0f,   1.0f,  0.0f,  0.0f,
         1.0f,  1.0f, -1.0f,  0.0f, 1.0f,   1.0f,  0.0f,  0.0f,
         1.0f,  1.0f,  1.0f,  1.0f, 1.0f,   1.0f,  0.0f,  0.0f,

        -1.0f,  1.0f, -1.0f,  0.0f, 0.0f,   0.0f,  1.0f,  0.0f,     //Face 5
        -1.0f,  1.0f,  1.0f,  1.0f, 0.0f,   0.0f,  1.0f,  0.0f,
         1.0f,  1.0f,  1.0f,  1.0f, 1.0f,   0.0f,  1.0f,  0.0f,
        -1.0f,  1.0f, -1.0f,  0.0f, 0.0f,   0.0f,  1.0f,  0.0f,
         1.0f,  1.0f, -1.0f,  0.0f, 1.0f,   0.0f,  1.0f,  0.0f,
         1.0f,  1.0f,  1.0f,  1.0f, 1.0f,   0.0f,  1.0f,  0.0f,

        -1.0f, -1.0f, -1.0f,  0.0f, 0.0f,   0.0f, -1.0f,  0.0f,     //Face 6
        -1.0f, -1.0f,  1.0f,  1.0f, 0.0f,   0.0f, -1.0f,  0.0f,
         1.0f, -1.0f,  1.0f,  1.0f, 1.0f,   0.0f, -1.0f,  0.0f,
        -1.0f, -1.0f, -1.0f,  0.0f, 0.0f,   0.0f, -1.0f,  0.0f,
         1.0f, -1.0f, -1.0f,  0.0f, 1.0f,   0.0f, -1.0f,  0.0f,
         1.0f, -1.0f,  1.0f,  1.0f, 1.0f,   0.0f, -1.0f,  0.0f
    };

    //Generate vertex buffer
    VertexBuffer VB(square, sizeof(square), GL_STATIC_DRAW);
    VB.bind();









    ///////////////////////////////
    // Give attributes to VA
    ///////////////////////////////

    //Normal VA
    VA.enableAttribute(0, GL_FLOAT, 3, sizeof(float) * 8, 0);
    VA.enableAttribute(1, GL_FLOAT, 2, sizeof(float) * 8, sizeof(float) * 3);
    VA.enableAttribute(2, GL_FLOAT, 3, sizeof(float) * 8, sizeof(float) * 5);

    //Light VA
    lightVA.enableAttribute(0, GL_FLOAT, 3, sizeof(float) * 8, 0);









    ///////////////////////////////
    // Program loop
    ///////////////////////////////

    while(!win.shouldClose())
    {
        ///////////////////////////////
        //Poll events
        ///////////////////////////////

        glfwPollEvents();






        ///////////////////////////////
        // Switch texture every 1.5 second because why not
        ///////////////////////////////

        Timer tmr;
        static double time;
        static double interval = 1.5;
        time = tmr.getTime();
        if(int(time / interval) % 4 == 0)
            texMan.getDefault().bind();
        if(int(time / interval) % 4 == 1)
            texMan.get(0).bind();
        if(int(time / interval) % 4 == 2)
            texMan.get(1).bind();
        if(int(time / interval) % 4 == 3)
            texMan.get(2).bind();






        ///////////////////////////////
        // Move light
        ///////////////////////////////

        static double x = 0.0;
        light.setPos(glm::vec3(glm::sin(x) * 2, 0.0, glm::cos(x) * 2));
        x += 0.03;
        lightPos = light.getPos();






        ///////////////////////////////
        // Controls
        ///////////////////////////////

        const double moveSpeed = 0.02;
        const double turnSpeed = 1;
        cam.simpleControl(KB, moveSpeed, turnSpeed);
        view = cam.genViewMatrix();






        ///////////////////////////////
        // Draw
        ///////////////////////////////

        //Clear screen
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

        //Bind normal
        VA.bind();
        shd.use();
        //Update uniforms
        modl = object.CalculateMatrix();
        modlUni.data(glm::value_ptr(modl));
        viewUni.data(glm::value_ptr(view));
        projUni.data(glm::value_ptr(proj));
        lightColorUni.data(glm::value_ptr(lightColor));
        lightPosUni.data(glm::value_ptr(lightPos));
        //Draw
        glDrawArrays(GL_TRIANGLES, 0, indices);

        //Bind light
        lightVA.bind();
        lightshd.use();
        //Update uniforms
        modl = light.CalculateMatrix();
        modlUni.data(glm::value_ptr(modl));
        viewUni.data(glm::value_ptr(view));
        projUni.data(glm::value_ptr(proj));
        lightColorUni.data(glm::value_ptr(lightColor));
        //Draw
        glDrawArrays(GL_TRIANGLES, 0, indices);

        //Display changes
        win.swapBuffers();
    }









    ///////////////////////////////
    // End
    ///////////////////////////////

    Init::endContext(win);
    return 0;
}
