#ifndef MODEL_HPP
#define MODEL_HPP

//Sttandard headers
#include <string>
#include <fstream>
#include <stdexcept>
#include <iostream>

//Buffer headers
#include "Buffer/IndexBuffer/indexbuffer.hpp"
#include "Buffer/VertexBuffer/vertexbuffer.hpp"

//Useful headers
#include "string_loading/string_loading.hpp"



/**
 * Contains data necessary to render a model
 */
struct Model
{
    VertexBuffer VB;
    IndexBuffer IB;

    int nbVertex;

    std::string name;
    std::string path;

    bool valid;

    /////////////////////////
    // Functions
    /////////////////////////

    void bind();
};






//////////////////////////////////
// Functions
//////////////////////////////////

Model loadModel(std::string path);        /**< Loads a model based on the path */

/*
A modl file is organized as follows :

#name
OBJECTNAME
#name_end

#vertex
-0.5, -0.5,
 0.5, -0.5,
-0.5,  0.5,
 0.5,  0.5,
#vertex_end

#index
 0, 1, 2,
 0, 3, 2,
#index_end
*/



#endif // MODEL_HPP
