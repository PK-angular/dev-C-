#ifndef TRACKEVENTS_H
#define TRACKEVENTS_H
#include "Events.h"
#include <string>
class TrackEvents : public Events
{
public:
    TrackEvents();
    float time_taken;
    float performanceCalculator(std::string event_name, int speed);

};

#endif // TRACKEVENTS_H
