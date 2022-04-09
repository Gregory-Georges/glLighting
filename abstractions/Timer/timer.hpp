#ifndef TIMER_HPP
#define TIMER_HPP

//Graphic headers
#include <GL/glew.h>
#include <GLFW/glfw3.h>



/**
 * Timer class. Allows to control and be aware of time in the program
 */
class Timer
{
    private:

        double lastTime;    /**< Last measured time */






    public:

    //////////////////////////////////
    // Constructor / destructor
    //////////////////////////////////

        Timer();






    //////////////////////////////////
    // Getters
    //////////////////////////////////

        double getTime();           /**< Returns the time */






    //////////////////////////////////
    // Interval
    //////////////////////////////////

        void setInterval();         /**< Sets the interval time */
        double getInterval();       /**< Returns the time passed since last call to setInterval */
};

#endif // TIMER_HPP
