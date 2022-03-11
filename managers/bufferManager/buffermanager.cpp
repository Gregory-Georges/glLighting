#include "buffermanager.hpp"



//////////////////////////////////
// Constructor
//////////////////////////////////

BufferManager::BufferManager(Model defaultModel) { this->defaultModel = defaultModel; }









//////////////////////////////////
// Getters
//////////////////////////////////

Model& BufferManager::get(std::string name)
{
    //Find matching buffer
    for(Model Modl : modelList.getContainer())
        if(Modl.name == name)
            return Modl;

    //In case there is no matching option
    std::cout << "Could not find model " << name << ". Returning default model\n";
    return defaultModel;
}









//////////////////////////////////
// Loader
//////////////////////////////////

void BufferManager::load(std::string path)
{
    //Load model
    Model mdl = loadModel(path);

    //If model is valid
    if(mdl.valid)
        modelList.add(mdl);

    //if not
    else
        std::cout << "Model " << path << " could not be loaded\n";
}









//////////////////////////////////
// Bind / use
//////////////////////////////////

void BufferManager::bind(std::string name)
{

}
