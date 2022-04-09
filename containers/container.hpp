#ifndef CONTAINER_HPP
#define CONTAINER_HPP

//Standard headers
#include <vector>       //Contain data
#include <utility>

//Project headers
#include "errors/errors.hpp"



///////////////////////////////////
// Class declaration
///////////////////////////////////

/**
 * Template class for a container containing objects
 */
template<class T> class Container
{
    protected:

        //Container vector
        std::vector<T> container;



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

        void add(T&& obj);                  /**< Adds r-value to the container */



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
        throwError("Copy constructor call is illegal on container class");
    }









///////////////////////////////////
// Getters
///////////////////////////////////

    template<class T> T& Container<T>::get(int index)
    {
        return container.at(index);
    }



    template<class T> int Container<T>::getSize(void)
    {
        return container.size();
    }









///////////////////////////////////
// Add
///////////////////////////////////

    //Adding l-values
    template<class T> void Container<T>::add(T&& obj)
    {
        container.push_back(std::move(obj));
    }









///////////////////////////////////
// Clear
///////////////////////////////////

    template<class T> void Container<T>::clear()
    {
        container.clear();
    }



#endif // CONTAINER_HPP
