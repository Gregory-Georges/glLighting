#include "vertexbuffer.hpp"



//////////////////////////////////
// Constructor / destructor
//////////////////////////////////

//Constructs an index buffer
VertexBuffer::VertexBuffer()
{
    bufferType = GL_ARRAY_BUFFER;
}



//Destroys an index buffer
VertexBuffer::~VertexBuffer()
{
    glDeleteBuffers(1, &id);
}



//Constructs and fills a vertex buffer
VertexBuffer::VertexBuffer(void* Data, unsigned int size, unsigned int usage)
{
    glGenBuffers(1, &id);
    this->bufferType = GL_ARRAY_BUFFER;
    setData(Data, size, usage);
}
