#include "TextureContainer.hpp"



//////////////////////////////////
// Constructor / destructor
//////////////////////////////////

TextureContainer::TextureContainer(std::string defaultPath, int defaultType) : defaultTexture(defaultPath, defaultType) {}






//////////////////////////////////
// Getters
//////////////////////////////////

    Texture& TextureContainer::getDefault() { return defaultTexture; }

    Texture& TextureContainer::find(const std::string& Path)
    {
        for(Texture tex : container)
            if(tex.getPath() == Path)
                return tex;

        return defaultTexture;
    }
