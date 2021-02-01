#ifndef TEAM_H
#define TEAM_H
#include <string>

class Team
{
public:
    Team();

    int team_number;;

    std::string teamManagerName;

    std::string sportsPshycologistName;
    int sportsPshycologistImpactValue;

    std::string physiotherapistName;
    int physiotherapistImpactValue;

    std::string fieldTrainerName;
    int fieldTrainerImapctValue;

    std::string eventTrainerName;
    int eventTrainerImpactValue;

};

#endif // TEAM_H
