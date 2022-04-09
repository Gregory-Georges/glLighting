#include "vertexbuffer.hpp"



//////////////////////////////////
// Constructor / destructor
//////////////////////////////////

    //Constructs a vertex buffer
    VertexBuffer::VertexBuffer()
    {
        bufferType = GL_ARRAY_BUFFER;
    }



    //Constructs and fills a vertex buffer
    VertexBuffer::VertexBuffer(void* Data, unsigned int size, unsigned int usage)
    {
        this->bufferType = GL_ARRAY_BUFFER;
        setData(Data, size, usage);
    }
