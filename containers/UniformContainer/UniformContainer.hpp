#ifndef UNIFORMCONTAINER_HPP
#define UNIFORMCONTAINER_HPP

//Uniforms
#include "Uniform/Uniform.hpp"

//Container
#include "container.hpp"



class UniformContainer : public Container<Uniform>
{
    public:

    //////////////////////////////////
    // Constructor / destructor
    //////////////////////////////////

        UniformContainer();



    //////////////////////////////////
    // Getters
    //////////////////////////////////

        Uniform& find(const std::string& name);
};

#endif // UNIFORMCONTAINER_HPP
