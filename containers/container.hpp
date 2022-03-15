#ifndef CONTAINER_HPP
#define CONTAINER_HPP

//Standard headers
#include <vector>       //Contain data
#include <stdexcept>    //Throw errors




//
// Problem :
// - Trying to put data in a vector without the use of a copy constructor
// - Avoid copy constructor calls
//
//
//
// Chosen  solution :
// - Make derived class for every type that is going to be used in a container
//      Pros :
//          - Objects can only be created in the container using the methods of the derived class
//          - No copies
//          - Methods can be personnalized to the contained object
//      Cons :
//          - Gotta rewrite some stuff every time a new object needs to be contained
//
//
//
// Potential solutions :
// - Put pointers in the vector instead of directly putting objects
//      Pros :
//          - Objects can be put in a vector and not destroyed
//      Cons :
//          - Objects must be destroyed manually when container is destroyed
//          - If all objects are constructed in vector, then no problem
//
//
//
// Impossible solutions :
// - Put references to objects in the vector
//      Impossible :
//          - Vector can't contain references
//
//  - Pass an element in add only as an l-value reference
//      Pros :
//          - Object is located only in vector, nowhere else
//      Impossible :
//          - Vector constructs a copy in vector.push_back anyways
//





///////////////////////////////////
// Class declaration
///////////////////////////////////

/**
 * Object container class. Define necessary components in specilized class before use, such as :
 * - Personnalized adders
 * - Personnalized getters
 * - Other personnalized methods
 */
template<class T> class Container
{
    protected:

        //Container vector
        std::vector<T*> container;



    public:

        ///////////////////////////////////
        // Constructor and destructor
        ///////////////////////////////////

        Container();                        /**< Build a container */
        ~Container();                       /**< Destroy the container and it's elements */
        Container(const Container &con);    /**< Call to copy constructor is illegal */



        ///////////////////////////////////
        // Getters
        ///////////////////////////////////

        T& get(int index);                  /**< Returns the element at said index */
        int getSize(void);                  /**< Returns the size of the container */



        ///////////////////////////////////
        // Add
        ///////////////////////////////////

        void add(T* obj);                   /**< Adds l-value to the container */



        ///////////////////////////////////
        // Clear
        ///////////////////////////////////

        void clear();                       /**< Deletes every object in the container */
};









///////////////////////////////////
// Constructor and destructor
///////////////////////////////////

template<class T> Container<T>::Container()
{
    container.reserve(10);
}


template<class T> Container<T>::~Container()
{
    clear();
}



template<class T> Container<T>::Container(const Container &con)
{
    throw(std::runtime_error("Copy constructor call is illegal on container class"));
}









///////////////////////////////////
// Getters
///////////////////////////////////

template<class T> T& Container<T>::get(int index)
{
    return *container.at(index);
}



template<class T> int Container<T>::getSize(void)
{
    return container.size();
}









///////////////////////////////////
// Add
///////////////////////////////////

//Adding l-values
template<class T> void Container<T>::add(T* obj)
{
    container.push_back(obj);
}









///////////////////////////////////
// Clear
///////////////////////////////////

template<class T> void Container<T>::clear()
{
    //Make sure to delete every element before deleting pointer targets
    for(T* i : container)
        delete i;

    //Empty all pointers
    container.clear();
}



#endif // CONTAINER_HPP
