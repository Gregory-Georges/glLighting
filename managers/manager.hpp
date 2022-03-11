#ifndef MANAGER_HPP
#define MANAGER_HPP

//Standart headers
#include <vector>


/**
 * Allows to contain, load and manage ressources
 */
template<class T>
class Manager
{

private:

    std::vector<T> container;   /**< Contains the ressources to manage */



public:

//////////////////////////////////
// Constructor / Destructor
//////////////////////////////////

    Manager() {}
    ~Manager() { container.clear(); }






//////////////////////////////////
// Edit contents
//////////////////////////////////

    void add(T object) { container.push_back(object); }
    void remove(int index) { container.erase(container.begin + index); }






//////////////////////////////////
// Getter
//////////////////////////////////

    T& get(int index) { return container[index]; }
    int getSize() { return container.size(); }
    std::vector<T> &getContainer() { return container; }






//////////////////////////////////
// Clear
//////////////////////////////////

    void clear() { container.clear(); }
};

#endif // MANAGER_HPP
