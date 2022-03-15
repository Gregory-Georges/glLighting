#include "TextureContainer.hpp"



//////////////////////////////////
// Constructor / destructor
//////////////////////////////////

TextureContainer::TextureContainer(std::string defaultPath) : defaultTexture(defaultPath, GL_TEXTURE_2D) {}









//////////////////////////////////
// Adders
//////////////////////////////////

    void TextureContainer::add(std::string Path, unsigned int textureType)
    {
        Texture* obj = new Texture(Path, textureType);
        Container::add(obj);
    }






//////////////////////////////////
// Getters
//////////////////////////////////

    Texture TextureContainer::find(const std::string& Path)
    {
        for(Texture *tex : container)
            if(tex->getPath() == Path)
                return *tex;

        return defaultTexture;
    }
