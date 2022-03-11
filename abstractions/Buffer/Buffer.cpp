#include "Buffer.hpp"



//////////////////////////////////
// Constructor / destructor
//////////////////////////////////

//Constructs an empty buffer object
Buffer::Buffer()
{
    glGenBuffers(1, &id);
    bufferType = GL_ARRAY_BUFFER;
}



//Destroys a buffer object
Buffer::~Buffer()
{
    glDeleteBuffers(1, &id);
}



//Constructs and filled buffer object
Buffer::Buffer(unsigned int bufferType, void* data, unsigned int size, unsigned int usage)
{
    glGenBuffers(1, &id);
    this->bufferType = bufferType;
    setData(data, size, usage);
}









//////////////////////////////////
// Getters
//////////////////////////////////

//Returns the name of the buffer
unsigned int Buffer::getID()
{
    return id;
}



//Returns the type of the buffer
unsigned int Buffer::getBufferType()
{
    return bufferType;
}









//////////////////////////////////
// Data
//////////////////////////////////

//Sets the type of the buffer
void Buffer::setType(unsigned int bufferType)
{
    this->bufferType = bufferType;
}



//Binds the buffer
void Buffer::bind()
{
    glBindBuffer(bufferType, id);
}



//Gives data to the buffer
void Buffer::setData(void* data, unsigned int size, unsigned int usage)
{
    bind();
    glBufferData(bufferType, size, data, usage);
}
