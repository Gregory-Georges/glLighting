#ifndef STRING_LOADING_HPP
#define STRING_LOADING_HPP

//Standart headers
#include <iostream>
#include <string>
#include <fstream>
#include <vector>



/*
 * Contains functions meant to facilitate file reading
 */



//////////////////////////////////
// Analyse file name and validity
//////////////////////////////////

bool checkExtension(std::string filename, std::string extension);       /**< Returns true if extension is the same */
std::string getExtension(std::string filename);                         /**< Returns the extension type if present */
bool exists(std::string filename);                                      /**< Returns true if the file exists */






//////////////////////////////////
// Load
//////////////////////////////////

std::string loadFile(std::string path);         /**< Returns the contents of the file */






//////////////////////////////////
// Get values
//////////////////////////////////

std::vector<int> getIntValues(std::string str);         /**< Returns an array of int values */
std::vector<float> getFloatValues(std::string str);     /**< Returns an array of float values */






//////////////////////////////////
// Division
//////////////////////////////////

std::string divideString(std::string str, std::string start, std::string end);  /**< Returns a substring from limits */



#endif // STRING_LOADING_HPP
