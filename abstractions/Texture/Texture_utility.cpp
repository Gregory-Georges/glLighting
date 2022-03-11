#define STB_IMAGE_IMPLEMENTATION
#include "Texture_utility.hpp"



//////////////////////////////////
// Definitions
//////////////////////////////////

unsigned char* loadImgRgb(std::string path, int* x, int* y)
{
    //Conserve color profile just in case I dunno
    int profile;

    //Parameterize stb
    stbi_set_flip_vertically_on_load(true);

    //load the image
    unsigned char* out = stbi_load(path.c_str(), x, y, &profile, 0);

    //Check if the image is valid
    if(out == nullptr)
    {
        std::string err_str = "image " + path + " could not be loaded\n";
        throw std::runtime_error(err_str.c_str());
    }

    //Return the image
    return out;
}



//Frees the previously loaded image from memory
void freeImgRgb(unsigned char* imgRgb)
{
    stbi_image_free(imgRgb);
}
