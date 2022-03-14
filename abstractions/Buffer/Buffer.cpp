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



//Constructs a filled buffer object
Buffer::Buffer(unsigned int bufferType, void* data, unsigned int size, unsigned int usage)
{
    glGenBuffers(1, &id);
    this->bufferType = bufferType;
    setData(data, size, usage);
}



//Copy constructor
Buffer::Buffer(const Buffer &buf)
{
    //Check glVersion before executing, must be at least 3.1
    checkGlVersion(3, 1, "Buffer copy constructor");
    //Gen new buffer
    glGenBuffers(1, &id);
    bufferType = buf.bufferType;
    //Bind buffers to copy locations
    glBindBuffer(buf.bufferType, buf.id);
    glBindBuffer(GL_COPY_WRITE_BUFFER, id);
    //Get copy size
    int bufSize;
    glGetBufferParameteriv(buf.bufferType, GL_BUFFER_SIZE, &bufSize);
    //Transfer buffer data
    glCopyBufferSubData(buf.bufferType, GL_COPY_WRITE_BUFFER, 0, 0, bufSize);
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
