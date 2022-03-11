#ifndef TEXTURE_HPP
#define TEXTURE_HPP

//Standart headers
#include <string>

//Graphic headers
#include <GL/glew.h>
#include <GLFW/glfw3.h>

//Ressource loader
#include <stb/stb_image.h>

//Other header
#include "Texture_utility.hpp"



/**
 * Contains a glTexture object
 */
class Texture
{
private:

    unsigned int id;            /**< Name of the texture object */
    unsigned int textureType;   /**< The type of the texture object */
    int x;                      /**< The width of the texture */
    int y;                      /**< The height of the texture */
    std::string texPath;        /**< The path of the loaded texture */






public:

    //////////////////////////////////
    // Constructor / destructor
    //////////////////////////////////

    ~Texture();                                                             /**< Destroys a texture object */
    Texture(std::string Path, unsigned int textureType);                    /**< Loads said image into texture */
    Texture(const Texture &tex);                                            /**< Copy constructor */






    //////////////////////////////////
    // Getters
    //////////////////////////////////

    unsigned int getID();               /**< Returns the name of the texture object */
    unsigned int getTextureType();      /**< Returns the buffer type of the object */
    std::string getPath();              /**< Returns the path of the texture */
    int getX();                         /**< Returns the lenght of the texture */
    int getY();                         /**< Returns the height of the texture */






    //////////////////////////////////
    // Data
    //////////////////////////////////

    void bind();                                                                    /**< Binds the texture object */
    void setData(unsigned char* data, unsigned int textureType, int x, int y);      /**< Gives data to the texture */
    void load(std::string path, unsigned int textureType);                          /**< Directly loads a texture object based on the image path */






    //////////////////////////////////
    // Parameterize
    //////////////////////////////////

    void genMipmap();                                               /**< Generates a texture's mipmaps */
    void parameteri(unsigned int param, unsigned int value);        /**< Sets a texture parameter */
    void setDefault();                                              /**< Sets the texture to the default parameter */
};

#endif // TEXTURE_HPP
