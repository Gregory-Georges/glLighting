#ifndef TEXTURECONTAINER_HPP
#define TEXTURECONTAINER_HPP

//Standart headers
#include <string>
#include <stdexcept>

//Container header
#include "container.hpp"

//Teextures
#include "Texture/Texture.hpp"



/**
 * Container containing textures
 */
class TextureContainer : public Container<Texture>
{
private:

    Texture defaultTexture;






public:

    //////////////////////////////////
    // Constructor / destructor
    //////////////////////////////////

    TextureContainer(std::string defaultPath, int defaulType);      /**< Constructs a texture container object */



    //////////////////////////////////
    // Getters
    //////////////////////////////////

    Texture& getDefault();                                          /**< Returns the set default texture */
    Texture& find(const std::string& Path);                         /**< Returns a loaded texture of the parameter name */
};

#endif // TEXTURECONTAINER_HPP
