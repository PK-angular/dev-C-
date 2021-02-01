#ifndef EVENTS_H
#define EVENTS_H
#include<string>

class Events
{
    public:
        std::string name_of_event;
        std::string type_of_event;

        virtual float performanceCalculator(std::string event_name, int speed)=0;
};

#endif // EVENTS_H
