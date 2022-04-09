#ifndef VERTEXBUFFER_HPP
#define VERTEXBUFFER_HPP

//Inheritance
#include "../Buffer.hpp"



/**
 * Contains a VertexBuffer
 */
class VertexBuffer : public Buffer
{
    public:

    //////////////////////////////////
    // Constructor / destructor
    //////////////////////////////////

        VertexBuffer();                                                     /**< Constructs an empty VertexBuffer */

        VertexBuffer(void* Data, unsigned int size, unsigned int usage);    /**< Constructs a filled VertexBuffer. Binds the buff4er */
};

#endif // VERTEXBUFFER_HPP
