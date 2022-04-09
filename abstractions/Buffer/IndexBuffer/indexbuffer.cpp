#include "indexbuffer.hpp"



//////////////////////////////////
// Constructor / destructor
//////////////////////////////////

    //Constructs an index buffer
    IndexBuffer::IndexBuffer()
    {
        bufferType = GL_ELEMENT_ARRAY_BUFFER;
    }



    //Constructs and fills an index buffer
    IndexBuffer::IndexBuffer(void* Data, unsigned int size, unsigned int usage)
    {
        this->bufferType = GL_ELEMENT_ARRAY_BUFFER;
        setData(Data, size, usage);
    }
