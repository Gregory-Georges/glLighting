#ifndef INDEXBUFFER_HPP
#define INDEXBUFFER_HPP

//Inheritance
#include "../Buffer.hpp"



/**
 * Contains an index buffer
 */
class IndexBuffer : public Buffer
{
    public:

    //////////////////////////////////
    // Constructor / destructor
    //////////////////////////////////

        IndexBuffer();                                                      /**< Constructs an empty IndexBuffer */

        IndexBuffer(void* Data, unsigned int size, unsigned int usage);     /**< Constructs a filled IndexBuffer. Binds the buffer */
};

#endif // INDEXBUFFER_HPP
