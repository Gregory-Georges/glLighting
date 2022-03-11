#include "VertexArray.hpp"

//////////////////////////////////
// Constructor / destructor
//////////////////////////////////

//Constructs a va object
VertexArray::VertexArray()
{
    glGenVertexArrays(1, &id);
}



//Destroys a va object
VertexArray::~VertexArray()
{
    glDeleteVertexArrays(1, &id);
}









//////////////////////////////////
// Getters
//////////////////////////////////

//Returns the name of te va object
unsigned int VertexArray::getID()
{
    return id;
}









//////////////////////////////////
// Data
//////////////////////////////////

//Binds the va object
void VertexArray::bind()
{
    glBindVertexArray(id);
}



//Gives a shader attribute to the va
void VertexArray::enableAttribute(unsigned int index, int type, int size, int stride, int offset)
{
    bind();
    glVertexAttribPointer(index, size, type, GL_FALSE, stride, (void*)(offset));
    glEnableVertexAttribArray(index);
}



//Removes a shader attribute from the va
void VertexArray::disableAttribute(unsigned int index)
{
    bind();
    glDisableVertexAttribArray(index);
}
