#include "Texture.hpp"



//////////////////////////////////
// Constructor / destructor
//////////////////////////////////



//Destroys a texture
Texture::~Texture()
{
    std::cout << "Texture destructor called\n";
    glDeleteTextures(1, &id);
}



Texture::Texture(std::string Path, unsigned int textureType)
{
    //Create new texture
    glGenTextures(1, &id);

    //Load image
    this->textureType = textureType;
    texPath = Path;
    unsigned char* Image = loadImgRgb(Path, &x, &y);

    load(Path, textureType);

    //Put image in texture
    setData(Image, textureType, x, y);

    //Free image
    freeImgRgb(Image);
}



Texture::Texture(const Texture &tex)
{
    //Create new texture
    glGenTextures(1, &id);

    //Retrieve data
    textureType = tex.textureType;
    texPath = tex.texPath;
    unsigned char* Image = loadImgRgb(texPath, &x, &y);

    //Give data
    setData(Image, textureType, x, y);

    //Free image
    freeImgRgb(Image);

    //Warning
    std::cout << "Warning : texture copy constructor called\n";
}









//////////////////////////////////
// Getters
//////////////////////////////////

//Returns the name of the object
unsigned int Texture::getID() { return id; }

//Returns the type of the texture
unsigned int Texture::getTextureType() { return textureType; }

//Returns the path to the loaded texture image
const std::string& Texture::getPath() { return texPath; }

//Returns the coordinates of the texture
int Texture::getX() { return x; }
int Texture::getY() { return y; }









//////////////////////////////////
// Data
//////////////////////////////////

//Binds the texture object
void Texture::bind() { glBindTexture(textureType, id); }



//Gives data to the texture object
void Texture::setData(unsigned char* data, unsigned int textureType, int x, int y)
{
    //Assign
    this->textureType = textureType;
    this->x = x;
    this->y = y;

    bind();
    glTexImage2D(textureType, 0, GL_RGB, x, y, 0, GL_RGB, GL_UNSIGNED_BYTE, data);

    //Set default parameters
    setDefault();
}



//Loads a texture depensing on a path
void Texture::load(std::string path, unsigned int textureType)
{
    //Bind texture
    this->textureType = textureType;
    bind();

    //Load img
    texPath = path;
    unsigned char* Image = loadImgRgb(path, &x, &y);

    //Give data to texture
    setData(Image, textureType, x, y);

    //Free image
    freeImgRgb(Image);
}









//////////////////////////////////
// Parameterize
//////////////////////////////////

//Generates the texture's mipmaps
void Texture::genMipmap()
{
    bind();
    glGenerateMipmap(textureType);
}



//Parameterizes the texture object
void Texture::parameteri(unsigned int param, unsigned int value)
{
    bind();
    glTexParameteri(textureType, param, value);
}



//Sets to default the parameters of the texture
void Texture::setDefault()
{
    //Bind texture
    bind();

    //Generate mipmaps
    genMipmap();

    //Clamp to edge
    parameteri(GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE);
    parameteri(GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE);

    //Sampling
    parameteri(GL_TEXTURE_MIN_FILTER, GL_LINEAR);
    parameteri(GL_TEXTURE_MAG_FILTER, GL_NEAREST);

    //Mipmap
    parameteri(GL_TEXTURE_MIN_FILTER, GL_LINEAR_MIPMAP_LINEAR);
}
