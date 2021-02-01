#include "FieldEvents.h"
#include <iostream>

FieldEvents::FieldEvents()
{
    //ctor
}

float FieldEvents::performanceCalculator(std::string event_name, int strength)
{


    float distance;


    if(event_name == "Discus throw")
    {
        distance = 50+(strength*0.1);

    }
    else if(event_name == "F2")
    {

        distance = 10 + (strength*0.1);

    }
    else
    {

        distance = 60+(strength*0.1);
    }
    return distance;


}

