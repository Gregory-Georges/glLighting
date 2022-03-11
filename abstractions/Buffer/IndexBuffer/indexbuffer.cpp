#include "indexbuffer.hpp"



//////////////////////////////////
// Constructor / destructor
//////////////////////////////////

//Constructs an index buffer
IndexBuffer::IndexBuffer()
{
    bufferType = GL_ELEMENT_ARRAY_BUFFER;
}



//Destroys an index buffer
IndexBuffer::~IndexBuffer()
{
    glDeleteBuffers(1, &id);
}



//Constructs and fills an index buffer
IndexBuffer::IndexBuffer(void* Data, unsigned int size, unsigned int usage)
{
    glGenBuffers(1, &id);
    this->bufferType = GL_ELEMENT_ARRAY_BUFFER;
    setData(Data, size, usage);
}
