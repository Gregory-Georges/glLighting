#ifndef TEXTURE_UTILITY_HPP
#define TEXTURE_UTILITY_HPP

//Standart headers
#include <string>
#include <stdexcept>

//Image loader
#include <stb/stb_image.h>



//////////////////////////////////
// Declaration
//////////////////////////////////

unsigned char* loadImgRgb(std::string path, int* x, int* y);    /**< Returns a series of chars that contains a loaded image */
void freeImgRgb(unsigned char* imgRgb);                         /**< Frees the previously loaded image */






#endif // TEXTURE_UTILITY_HPP
