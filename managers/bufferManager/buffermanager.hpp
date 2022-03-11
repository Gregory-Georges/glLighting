#ifndef BUFFERMANAGER_HPP
#define BUFFERMANAGER_HPP

//Standart headers
#include <string>
#include <vector>
#include <iterator>

//Model headers
#include "Buffer/Model/model.hpp"

//Manager header
#include "manager.hpp"

//File loader
#include "string_loading/string_loading.hpp"



/**
 * Manages buffer loading and ressource requests for buffer
 */
class BufferManager
{
private :

    Manager<Model> modelList;           //Contains the models that will be used
    Model defaultModel;                 //Default return model if no other model is found






public :

    //////////////////////////////////
    // Constructor
    //////////////////////////////////

    BufferManager(Model defaultModel);






    //////////////////////////////////
    // Getters
    //////////////////////////////////

    Model& get(std::string name);






    //////////////////////////////////
    // Loader
    //////////////////////////////////

    void load(std::string path);






    //////////////////////////////////
    // Bind / use
    //////////////////////////////////

    void bind(std::string name);
};

#endif // BUFFERMANAGER_HPP
