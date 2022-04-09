#ifndef UNIFORMCONTAINER_HPP
#define UNIFORMCONTAINER_HPP

//Uniforms
#include "Uniform/Uniform.hpp"

//Container
#include "container.hpp"



/**
 * Container containg uniforms
 */
class UniformContainer : public Container<Uniform>
{
    public:

    //////////////////////////////////
    // Constructor / destructor
    //////////////////////////////////

        UniformContainer();                         /**< Constructs an empty uniform container */



    //////////////////////////////////
    // Getters
    //////////////////////////////////

        Uniform& find(const std::string& name);     /**< Finds a loaded uniform with the same name */
};

#endif // UNIFORMCONTAINER_HPP
