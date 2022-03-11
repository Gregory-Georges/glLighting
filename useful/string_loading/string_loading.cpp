#include "string_loading.hpp"



//////////////////////////////////
// Analyse file name and validity
//////////////////////////////////

//Returns if the file's extension is the same as the parameter
bool checkExtension(std::string filename, std::string extension) { return getExtension(filename) == extension; }

//Returns the extension of the file
std::string getExtension(std::string filename) { return filename.substr(filename.find_last_of(".") + 1); }

//Returns if the file exists
bool exists(std::string filename)
{
    std::fstream file;
    file.open(filename);
    return file.is_open();
}









//////////////////////////////////
// Load
//////////////////////////////////

//Returns the content of the file
std::string loadFile(std::string filename)
{
    std::string out = "";
    std::string temp;

    if(exists(filename))
    {
        //Open file
        std::fstream file;
        file.open(filename);

        //Extract file
        while(std::getline(file, temp))
            out += temp + "\n";
    }

    //Return
    return out;
}









//////////////////////////////////
// Get values
//////////////////////////////////

//Retrieves all int values from string
std::vector<int> getIntValues(std::string str)
{
    //Return
    std::vector<int> values;

    //Temporary value
    std::string temp;

    //Scan through every character
    for(int n = 0; n < int(str.size()); ++n)
    {
        //Check if is a number
        if((str.at(n) <= '9' && str.at(n) >= '0') || str.at(n) == '-') { temp += str.at(n); }

        //If not a number and string is not empty, convert and add to array
        else if(temp != "")
        {
            values.push_back(std::stoi(temp));
            temp = "";
        }
    }

    //Return
    return values;
}



//Retrieves all float values from string
std::vector<float> getFloatValues(std::string str)
{
    //Return
    std::vector<float> values;

    //Temporary value
    std::string temp;

    //Scan through every character
    for(int n = 0; n < int(str.size()); ++n)
    {
        //Check if is a number or a point
        if((str.at(n) <= '9' && str.at(n) >= '0') || str.at(n) == '.' || str.at(n) == '-') { temp += str.at(n); }

        //If not a number and string is not empty, convert and add to array
        else if(temp != "")
        {
            values.push_back(std::stof(temp));
            temp = "";
        }
    }

    //Return
    return values;
}









//////////////////////////////////
// Division
//////////////////////////////////

std::string divideString(std::string str, std::string start, std::string end)
{
    unsigned int START = str.find(start);
    unsigned int END = str.find(end);

    //Return substring in between
    return str.substr(START + start.size(), END - START - 6); //-6 for some reason dunno why
}
