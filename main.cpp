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
    Shader lightshd(getSource("shaders/light/lightvertex.shd"), getSource("shaders/light/lightfragment.shd"));









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
    texMan.add(Texture("media/images/colors.jpg", GL_TEXTURE_2D));
    texMan.get(1).bind();











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
    Uniform objectColorUni(UNIFORM_VEC_4_FV, shd, "objectColor");
    Uniform lightColorUni(UNIFORM_VEC_4_FV, shd, "lightColor");

    //setup data
    glm::vec4 objectColor = glm::vec4(1.0, 1.0, 1.0, 1.0);
    glm::vec4 lightColor = glm::vec4(1.0, 1.0, 1.0, 1.0);

    //Give data to shader
    objectColorUni.data(glm::value_ptr(objectColor));
    lightColorUni.data(glm::value_ptr(lightColor));









    ///////////////////////////////
    // Create buffer
    ///////////////////////////////

    // Our vertices. Three consecutive floats give a 3D vertex; Three consecutive vertices give a triangle.
    // A cube has 6 faces with 2 triangles each, so this makes 6*2=12 triangles, and 12*3 vertices
    //Times 2 faces
    int indices = 2 * 3 * 6;
    float square[] =
    {
        //Coordinates         //Texture pos
        -1.0f, -1.0f, -1.0f,  0.0f, 0.0f,     //Face 1
         1.0f, -1.0f, -1.0f,  1.0f, 0.0f,
         1.0f,  1.0f, -1.0f,  1.0f, 1.0f,
        -1.0f, -1.0f, -1.0f,  0.0f, 0.0f,
        -1.0f,  1.0f, -1.0f,  0.0f, 1.0f,
         1.0f,  1.0f, -1.0f,  1.0f, 1.0f,

        -1.0f, -1.0f,  1.0f,  0.0f, 0.0f,     //Face 2
         1.0f, -1.0f,  1.0f,  1.0f, 0.0f,
         1.0f,  1.0f,  1.0f,  1.0f, 1.0f,
        -1.0f, -1.0f,  1.0f,  0.0f, 0.0f,
        -1.0f,  1.0f,  1.0f,  0.0f, 1.0f,
         1.0f,  1.0f,  1.0f,  1.0f, 1.0f,

        -1.0f, -1.0f, -1.0f,  0.0f, 0.0f,     //Face 3
        -1.0f, -1.0f,  1.0f,  1.0f, 0.0f,
        -1.0f,  1.0f,  1.0f,  1.0f, 1.0f,
        -1.0f, -1.0f, -1.0f,  0.0f, 0.0f,
        -1.0f,  1.0f, -1.0f,  0.0f, 1.0f,
        -1.0f,  1.0f,  1.0f,  1.0f, 1.0f,

         1.0f, -1.0f, -1.0f,  0.0f, 0.0f,     //Face 4
         1.0f, -1.0f,  1.0f,  1.0f, 0.0f,
         1.0f,  1.0f,  1.0f,  1.0f, 1.0f,
         1.0f, -1.0f, -1.0f,  0.0f, 0.0f,
         1.0f,  1.0f, -1.0f,  0.0f, 1.0f,
         1.0f,  1.0f,  1.0f,  1.0f, 1.0f,

        -1.0f,  1.0f, -1.0f,  0.0f, 0.0f,     //Face 5
        -1.0f,  1.0f,  1.0f,  1.0f, 0.0f,
         1.0f,  1.0f,  1.0f,  1.0f, 1.0f,
        -1.0f,  1.0f, -1.0f,  0.0f, 0.0f,
         1.0f,  1.0f, -1.0f,  0.0f, 1.0f,
         1.0f,  1.0f,  1.0f,  1.0f, 1.0f,

        -1.0f, -1.0f, -1.0f,  0.0f, 0.0f,     //Face 6
        -1.0f, -1.0f,  1.0f,  1.0f, 0.0f,
         1.0f, -1.0f,  1.0f,  1.0f, 1.0f,
        -1.0f, -1.0f, -1.0f,  0.0f, 0.0f,
         1.0f, -1.0f, -1.0f,  0.0f, 1.0f,
         1.0f, -1.0f,  1.0f,  1.0f, 1.0f
    };

    //Generate vertex buffer
    VertexBuffer VB(square, sizeof(square), GL_STATIC_DRAW);
    VB.bind();









    ///////////////////////////////
    // Generate vertex arrays
    ///////////////////////////////

    //Normal VA
    VertexArray VA;
    VA.enableAttribute(0, GL_FLOAT, 3, sizeof(float) * 5, 0);
    VA.enableAttribute(1, GL_FLOAT, 2, sizeof(float) * 5, sizeof(float) * 3);

    //Light VA
    VertexArray lightVA;
    lightVA.enableAttribute(0, GL_FLOAT, 3, sizeof(float) * 5, 0);









    ///////////////////////////////
    // Generate object world data
    ///////////////////////////////

    ModelData object;
    ModelData light;

    //Object
    object.setPos(glm::vec3(0.0, 0.0, -2.5));

    //Light
    light.setPos(glm::vec3(0.0, 2.0, 0.0));
    light.setScale(glm::vec3(0.5));









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
        if(int(time / interval) % 3 == 0)
            texMan.get(0).bind();
        if(int(time / interval) % 3 == 1)
            texMan.get(1).bind();
        if(int(time / interval) % 3 == 2)
            texMan.get(2).bind();






        ///////////////////////////////
        // Controls
        ///////////////////////////////

        const double moveSpeed = 0.02;
        const double turnSpeed = 1;
        cam.simpleControl(KB, moveSpeed, turnSpeed);
        view = cam.genViewMatrix();
        viewUni.data(glm::value_ptr(view));






        ///////////////////////////////
        // Draw
        ///////////////////////////////

        //Clear screen
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

        //Draw box
        modl = object.CalculateMatrix();
        modlUni.data(glm::value_ptr(modl));
        VA.bind();
        //shd.use();
        VB.bind();
        glDrawArrays(GL_TRIANGLES, 0, indices);
        std::cout << "Normal binded : \n";
        printBindedElements();

        //Draw light
        modl = light.CalculateMatrix();
        modlUni.data(glm::value_ptr(modl));
        lightVA.bind();
        lightshd.use();
        VB.bind();
        glDrawArrays(GL_TRIANGLES, 0, indices);
        std::cout << "Light binded : \n";
        printBindedElements();

        //Display changes
        win.swapBuffers();
    }









    ///////////////////////////////
    // End
    ///////////////////////////////

    Init::endContext(win);
    return 0;
}
