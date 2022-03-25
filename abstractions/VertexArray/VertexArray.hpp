#ifndef VERTEXARRAY_HPP
#define VERTEXARRAY_HPP

//Standart headers
#include <iostream>

//Graphic headers
#include <GL/glew.h>
#include <GLFW/glfw3.h>



/**
 * Contains a glVertexArray object
 */
class VertexArray
{
private:

    unsigned int id;            /**< Name of the VA object */






public:

    //////////////////////////////////
    // Constructor / destructor
    //////////////////////////////////

    VertexArray();          /**< Constructs a va object */
    ~VertexArray();         /**< Destroys a va object */






    //////////////////////////////////
    // Getters
    //////////////////////////////////

    unsigned int getID();           /**< Returns the name of the va object */






    //////////////////////////////////
    // Data
    //////////////////////////////////

    void bind();                                                                                /**< Binds the va object */
    void enableAttribute(unsigned int index, int type, int size, int stride, int offset);       /**< Gives a shader attribute to the va object */
    void disableAttribute(unsigned int index);                                                  /**< Removes a shader attibute from the va object */
};

#endif // VERTEXARRAY_HPP
