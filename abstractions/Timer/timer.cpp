#include "timer.hpp"



//////////////////////////////////
// Constructor / destructor
//////////////////////////////////

Timer::Timer()
{
    lastTime = glfwGetTime();
}






//////////////////////////////////
// Getters
//////////////////////////////////

double Timer::getTime()
{
    return glfwGetTime();
}






//////////////////////////////////
// Interval
//////////////////////////////////

void Timer::setInterval()
{
    lastTime = glfwGetTime();
}



double Timer::getInterval()
{
    double currentTime = glfwGetTime();
    double returnTime = currentTime - lastTime;
    lastTime = currentTime;

    return returnTime;
}
