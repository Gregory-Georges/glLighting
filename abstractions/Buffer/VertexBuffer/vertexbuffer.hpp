#ifndef VERTEXBUFFER_HPP
#define VERTEXBUFFER_HPP

//Inheritance
#include "../Buffer.hpp"



/**
 * Contains an vertex buffer
 */
class VertexBuffer : public Buffer
{
    public:
        VertexBuffer();
        virtual ~VertexBuffer();

        VertexBuffer(void* Data, unsigned int size, unsigned int usage);
};

#endif // VERTEXBUFFER_HPP
