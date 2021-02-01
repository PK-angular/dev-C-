#ifndef ATHLETE_H
#define ATHLETE_H
#include "Team.h"

class Athlete : public Team
{
public:
    Athlete();
    Athlete(const Athlete &a);
    std::string name;
    std::string gender;

    bool isInjured;
    int readiness;
    int strength;
    int speed;
    bool isTired;

    int stress_level;

    int score_TE1;
    int score_TE2;
    int score_TE3;
    int score_TE4;
    int score_FE1;
    int score_FE2;
    int score_FE3;
    int score_FE4;
    int total_score;
    int season_score;

};

#endif // ATHLETE_H
