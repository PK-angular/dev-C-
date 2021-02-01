#include "TrackEvents.h"
#include <iostream>


TrackEvents::TrackEvents()
{
    //ctor
}

float TrackEvents::performanceCalculator(std::string event_name, int speed)
{

    float time;


    if(event_name == "100m Race")
    {

        speed = (speed*0.2);
        time = 100/speed;
    }
    else if(event_name == "1500 metre running race")
    {

        time = 1500/speed;
    }
    else if(event_name == "T1")
    {
        speed = (speed*0.1);
        time = 110/speed;

    }
    else if(event_name == "T2")
    {


        time = 500/speed;

    }
    return time;


}
