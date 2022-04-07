#include "UniformContainer.hpp"



//////////////////////////////////
// Constructor / destructor
//////////////////////////////////

    UniformContainer::UniformContainer() {}






//////////////////////////////////
// Getters
//////////////////////////////////

    Uniform& UniformContainer::find(const std::string& name)
    {
        int size = container.size();

        for(int i = 0; i < size; ++i)
            if(container.at(i).getName() == name)
                return container.at(i);
    }
