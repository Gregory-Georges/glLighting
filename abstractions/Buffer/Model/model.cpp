#include "model.hpp"



//////////////////////////////////
// Functions
//////////////////////////////////

void Model::bind()
{
    VB.bind();
    IB.bind();
}



Model loadModel(std::string path)
{
        //Create return
        Model modl;

        //Get file
        if(exists(path))
        {
            //Load file in string
            std::string fileStr = loadFile(path);

            //Get name and path
            modl.name = divideString(fileStr, "#name", "#name_end");
            modl.path = path;

            //Get number of index and vertices
            modl.nbVertex = std::stoi(divideString(fileStr, "#vertex_count", "#vertex_count_end"));

            //Get vertices
            std::vector<float> verticesVec = getFloatValues(divideString(fileStr, "#vertex", "#vertex_end"));
            float* verticesArr = verticesVec.data();
            modl.VB.setData(verticesArr, verticesVec.size(), GL_STATIC_DRAW);

            //Get index
            std::vector<int> indexVec = getIntValues(divideString(fileStr, "#index", "#index_end"));
            int* indexArr = indexVec.data();
            modl.IB.setData(indexArr, indexVec.size(), GL_STATIC_DRAW);

            //Assign to model
            modl.valid = true;
        }

        //Error - no file
        else
        {
            modl.valid = false;
            std::cout << "Model at : " << path << " does not exist\n";
        }

        //Return
        return modl;
}
