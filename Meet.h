#ifndef MEET_H
#define MEET_H
#include <string>

class Meet
{
public :

    static const int duration_of_meet = 2;

    std::string location_of_meet;
    int date_of_meet;
    //random
    std::string weather_for_meet;
    std::string special_feature_of_location;
    int location_special_feature_impact;
    int weather_impact;


    Meet();

    //  Meet(std::string,std::string,std::string);
};

#endif // MEET_H
