#ifndef TEXTURECONTAINER_HPP
#define TEXTURECONTAINER_HPP

//Standart headers
#include <string>
#include <stdexcept>

//Container header
#include "container.hpp"

//Teextures
#include "Texture/Texture.hpp"



class TextureContainer : public Container<Texture>
{
    private:

        Texture defaultTexture;



    public:

    //////////////////////////////////
    // Constructor / destructor
    //////////////////////////////////

        TextureContainer(std::string defaultPath, int defaulType);



    //////////////////////////////////
    // Getters
    //////////////////////////////////

        Texture& getDefault();
        Texture& find(const std::string& Path);
};

#endif // TEXTURECONTAINER_HPP
