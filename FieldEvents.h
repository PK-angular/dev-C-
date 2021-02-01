#ifndef FIELDEVENTS_H
#define FIELDEVENTS_H
#include "Events.h"
#include <string>

class FieldEvents : public Events
{
public:
    FieldEvents();
    float spatial_distance;
    float performanceCalculator(std::string event_name, int speed);

};

#endif // FIELDEVENTS_H
