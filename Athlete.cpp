#include "Athlete.h"

Athlete::Athlete()
{
    //ctor
}

/*Athlete::~Athlete()
{
    //dtor
}*/


Athlete::Athlete(const Athlete &a)
{

    name = a.name;
    gender = a.gender;
    isInjured = a.isInjured;
    readiness = a.readiness;
    strength = a.strength;
    speed = a.speed;
    isTired = a.isTired;
    stress_level = a.stress_level;
    score_TE1 = a.score_TE1;
    score_TE2 = a.score_TE2;
    score_TE3 = a.score_TE3;
    score_TE4 = a.score_TE4;
    score_FE1 = a.score_FE1;
    score_FE2 = a.score_FE2;
    score_FE3 = a.score_FE3;
    score_FE4 = a.score_FE4;
    total_score = a.total_score;
    season_score = a.season_score;
}
