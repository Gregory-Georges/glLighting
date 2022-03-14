#ifndef BUFFER_HPP
#define BUFFER_HPP

//Standart headers
#include <iostream>
#include <string>

//Graphic headers
#include <GL/glew.h>
#include <GLFW/glfw3.h>

//Utility
#include "include_useful.hpp"



/**
 * Contains a glBuffer object
 */
class Buffer
{

protected:

    unsigned int id;            /**< Name of the buffer object */
    unsigned int bufferType;    /**< The type of the buffer object */






public:

    //////////////////////////////////
    // Constructor / destructor
    //////////////////////////////////

    Buffer();               /**< Constructs an empty buffer object */
    virtual ~Buffer();      /**< Destroys a buffer object */

    Buffer(unsigned int bufferType, void* Data, unsigned int size, unsigned int usage);    /**< Constructs a filled buffer object. Binds the buffer */
    Buffer(const Buffer &buf);      /**< Copy constructor */






    //////////////////////////////////
    // Getters
    //////////////////////////////////

    unsigned int getID();           /**< Returns the name of the buffer object */
    unsigned int getBufferType();   /**< Returns the buffer type of the object */






    //////////////////////////////////
    // Data
    //////////////////////////////////

    void setType(unsigned int bufferType);      /**< Gives a type to the buffer object */
    void bind();                                /**< Binds the buffer object */
    void setData(void* Data, unsigned int size, unsigned int usage);                      /**< Gives data to the buffer */
};

#endif // BUFFER_HPP
