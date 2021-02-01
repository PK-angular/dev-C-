#include <iostream>
#include <time.h>
#include <random>
#include <algorithm>


#include "Team.h"
#include "Athlete.h"
#include "Meet.h"
#include "TrackEvents.h"
#include "FieldEvents.h"


using namespace std;
//function declaration
string getSpecialFeatureOfLocation(string location);
int readinessOfAthlete(int strength, int speed,bool injured, bool tired);
void checkValue(int number);
int generateRandomNumber(int max_num, int min_num);
int gapBetweenMeets();
void calculatingAthletePerformanceForImpact(Athlete athlete_f[],Athlete athlete_m[],int impactValue);
int trackEventFormula(float time,string event);
int fieldEventFormula(float distance_covered,string event);
void calculatingPointsForTrackEvent(string event_name,Athlete athlete_f[],Athlete athlete_m[]);
void calculatingPointsForFieldEvent(string event_name,Athlete athlete_f[],Athlete athlete_m[]);
bool checkingForInjury(int initial_value, int final_value);
void calculatingImpactForTrackEvent(Athlete athlete_f[],Athlete athlete_m[]);
void calculatingImpactForFieldEvent(Athlete athlete_f[],Athlete athlete_m[]);
void calculateTotalScore(Athlete athlete_f[],Athlete athlete_m[]);
void sortingMeetInDescendingOrder(Athlete athlete_f[],Athlete athlete_m[]);
void sortingSeasonScore(Athlete athlete_f[],Athlete athlete_m[]);
void medalDistributionForMeet(Athlete athlete_m[]);
void overallSeasonTrophy(Athlete athlete_f[],Athlete athlete_m[]);
void teamMemberImpactAfterMeet(Athlete athlete_f[],Athlete athlete_m[]);
void getSeasonDetails(int dateArray[],string locationNameArray[],string featureArray[]);
void getTeamMembers(Team teams[], Athlete athlete_female[], Athlete athlete_male[]);
void printTeamDetails(Team teams[], Athlete athlete_female[], Athlete athlete_male[]);

int i;
int n,m;
Meet day1;
Meet day2;

TrackEvents trackObj,trackEvent1,trackEvent2,trackEvent3,trackEvent4;
FieldEvents obj,fieldEvent1,fieldEvent2,fieldEvent3,fieldEvent4;

string sports_Pshycologists_name[8] =
{"Dr. Flyod","Dr. Ram", "Dr. Sham","Dr. Joe", "Dr. Charlie", "Dr.Alan","Dr.Jake","Dr. Rahul"};

string physiotherapist_name[8] = {"Dr. Zee","Dr. Kiya","Dr. Riya","Dr. Penny","Dr. Sheldon","Dr. Rohan","Dr. Batman","Dr. Kem"};

string field_trainer_name[8] = {"Mr. Kiyabh","Mr. Zeeshan","Mr. Potato","Ms. Meet","Mr. Anand","Mr. Dock","Ms. K","Ms.H"};

string event_trainer_name[8] = {"Ms. Khayli","Ms. Adi","Mr. Amrinder","Mr. Mass","Mr. Zebra","Mr. Lion","Mr. Blue","Mr. Orangget"};

string male_athlete_name[8] = {"Mr. Ashok","Mr. Christopher",
                               "Mr. GD", "Mr. MDH","Mr. Haldiram", "Mr. Milkha", "Mr. Bhagat", "Mr. Arun"
                              };

string female_athlete_name[8] = {"Ms. Ashley","Ms. Alan",
                                 "Ms. Boyke", "Ms. Mecdonalds","Ms. Haley", "Ms. Mili", "Ms. Bluey", "Ms. Alex"
                                };

string team_manager_name[] = {"Ms. Jazz","Ms. Piku",
                              "Mr. Boles", "Ms. Mecassy","Mr. Howard", "Mr. Leonard", "Ms. Becky", "Ms. Alexandria"
                             };
string meet_locations[4] = {"Albion Park", "Dapto","Bombo","Conniston"};

string special_feature[4] = {"Plain Track","Low Steep Track","Moderate Steep Track","High Steep Track"};

string weather[4] = {"Rainy","Sunny","Cold"};

//getting special feature
string getSpecialFeatureOfLocation(string location)
{
    int x =0;
    while( meet_locations[x]!=location)
    {
        x++;
    }
    return special_feature[x];
}


//checking for readiness of athlete
int readinessOfAthlete(int strength, int speed,bool injured, bool tired)
{

    int readiness;
    if(!(injured && tired))
    {
        readiness = (strength + speed)/2;
    }
    else
    {
        readiness = (strength + speed)/2;
        readiness = (readiness*0.2) - readiness ;

    }

    return readiness;
}

//for checking the number of teams and meets should be in 1-8 range inclusive
void checkValue(int number)
{

    if(!(number<=8 && number>=1))
    {

        cout<<"The number should be in range of 1-8 inclusive"<<endl;
        exit(0);
    }

}

//generating random number
int generateRandomNumber(int max_num, int min_num)
{
    int number;

    number =( rand() % max_num) + min_num;
//    cout<<"number"<<number<<endl;

    return number;

}

//deciding gap between two meets
int gapBetweenMeets()
{

    int date_of_new_meet = ( generateRandomNumber(7,5) % (7 - 5 + 1) ) + 5;

    return date_of_new_meet;
}


//reducing athletes performance paramter with weather
void calculatingAthletePerformanceForImpact(Athlete athlete_f[],Athlete athlete_m[],int impactValue)
{


    for(int a=0; a<i; a++)
    {
        cout<<" The athelete named "<<athlete_f[a].name<<"   Speed of female athlete before impact"<<athlete_f[a].speed;
        athlete_f[a].speed = athlete_f[a].speed - ((impactValue*athlete_f[a].speed)/100);
        cout<<" after impact "<<athlete_f[a].speed<<"reduced by"<<impactValue<<"%\n"<<endl;

        cout<<" The athelete named "<<athlete_f[a].name<<" Strength of female athlete before impact"<<athlete_f[a].strength;
        athlete_f[a].strength = (athlete_f[a].strength - ((impactValue*athlete_f[a].strength)/100));
        cout<<" after impact "<<athlete_f[a].strength<<"reduced by"<<impactValue<<"%\n"<<endl;

        cout<<" The athelete named "<<athlete_m[a].name<<" Speed of male athlete before impact"<<athlete_m[a].speed;
        athlete_m[a].speed = athlete_m[a].speed -((impactValue*athlete_m[a].speed)/100);
        cout<<" after impact "<<athlete_m[a].speed<<"reduced by"<<impactValue<<"%\n"<<endl;

        cout<<" The athelete named "<<athlete_m[a].name<<" Strength of male athlete before impact"<<athlete_m[a].strength;
        athlete_m[a].strength = athlete_m[a].strength -  ((impactValue*athlete_m[a].strength)/100);
        cout<<" after impact "<<athlete_m[a].strength<<"reduced by"<<impactValue<<"%\n"<<endl;
        cout<<"\n\n";

    }


}


int trackEventFormula(float time,string event)
{
    float a,b,c;

    if(event == "100m Race")
    {

        a=25.4347,b=18,c=1.81;
    }
    else if(event == "1500 metre running race")
    {
        a=0.03768,b=480,c=1.85;
    }
    else if(event == "T2")
    {
        //500 m
        a=1.53775,b=82,c=1.81;
    }
    else
    {
        //110m hurdle
        a=5.74352,b=28.5,c=1.92;
    }

    int points = (pow((b-time),c))*a;


    return points;

}

//calculations for field events
int fieldEventFormula(float distance_covered,string event)
{

    int points;
    float a,b,c;
    if(event == "Discus throw")
    {

        a=12.91,b=4.0,c=1.1;
    }
    else if(event == "High jump")
    {
        a=0.8465,b=75,c=1.42;
    }
    else if(event == "F1")
    {

        //shot put
        a = 51.39, b=1.5,c=1.05;
    }
    else
    {

        //javelin throw
        a= 10.14,b=7,c=1.08;
    }

    points = (pow((distance_covered - b),c))*a;

    return points;

}



//function for calculating points for track event
void calculatingPointsForTrackEvent(string event_name,Athlete athlete_f[],Athlete athlete_m[])
{
    float time_taken;
    int points, event_points=0;

    cout<<"*******************Track Event "<<event_name<<"Points************************"<<"\n";

//calculating points for female
    for(int z=0; z<i; z++)
    {

        time_taken = trackObj.performanceCalculator(event_name,athlete_f[z].speed);
        points = trackEventFormula(time_taken,event_name);
        if(event_name=="100m Race")
        {
            athlete_f[z].score_TE1 = points;
            event_points = athlete_f[z].score_TE1;
        }
        else if(event_name == "T1")
        {
            athlete_f[z].score_TE2 = points;
            event_points = athlete_f[z].score_TE2;
        }
        else if(event_name == "T2")
        {
            athlete_f[z].score_TE3 = points;
            event_points = athlete_f[z].score_TE3;
        }
        else if(event_name == "1500 metre running race")
        {
            athlete_f[z].score_TE4 = points;
            event_points = athlete_f[z].score_TE4;
        }

        cout<<"Points of athlete named "<<athlete_f[z].name<<"in event "<<event_name<<" with speed "<<athlete_f[z].speed<<"points : "<<event_points<<"\n";

        time_taken = trackObj.performanceCalculator(event_name,athlete_m[z].speed);
        points = trackEventFormula(time_taken,event_name);
        if(event_name=="100m Race")
        {
            athlete_m[z].score_TE1 = points;
            event_points = athlete_m[z].score_TE1;
        }
        else if(event_name == "T1")
        {
            athlete_m[z].score_TE2 = points;
            event_points = athlete_m[z].score_TE2;
        }
        else if(event_name == "T2")
        {
            athlete_m[z].score_TE3 = points;
            event_points = athlete_m[z].score_TE3;
        }
        else if(event_name == "1500 metre running race")
        {
            athlete_m[z].score_TE4 = points;
            event_points = athlete_m[z].score_TE4;
        }
        cout<<"Points of athlete named "<<athlete_m[z].name<<"in event "<<" with speed "<<athlete_m[z].speed<<"points : "<<event_points<<"\n";

    }



}
//caculating points for field event
void calculatingPointsForFieldEvent(string event_name,Athlete athlete_f[],Athlete athlete_m[])
{
    float spatial_distance;
    int points,score_in_event;

    cout<<"*******************Field Event "<<event_name<<"Points************************"<<"\n";

    for(int z=0; z<i; z++)
    {

        spatial_distance = obj.performanceCalculator(event_name,athlete_f[z].strength);
        points = fieldEventFormula(spatial_distance,event_name);

        if(event_name=="Discus throw")
        {
            athlete_f[z].score_FE1 = points;
            score_in_event = athlete_f[z].score_FE1;
        }
        else if(event_name == "F1")
        {
            athlete_f[z].score_FE2 = points;
            score_in_event = athlete_f[z].score_FE2;

        }
        else if(event_name == "F2")
        {

            athlete_f[z].score_FE3 = points;
            score_in_event = athlete_f[z].score_FE3;
        }
        else if(event_name == "High Jump")
        {

            athlete_f[z].score_FE4 = points;
            score_in_event = athlete_f[z].score_FE4;
        }

        cout<<"Points of athlete named "<<athlete_f[z].name<<"in event "<<event_name<<" with strength "<<athlete_f[z].strength<<"points : "<<score_in_event<<"\n";

        spatial_distance = obj.performanceCalculator(event_name,athlete_m[z].strength);
        points = fieldEventFormula(spatial_distance,event_name);
        if(event_name=="Discus throw")
        {
            athlete_m[z].score_FE1 = points;
            score_in_event = athlete_m[z].score_FE1;
        }
        else if(event_name == "F1")
        {
            athlete_m[z].score_FE2 = points;
            score_in_event = athlete_m[z].score_FE2;

        }
        else if(event_name == "F2")
        {

            athlete_m[z].score_FE3 = points;
            score_in_event = athlete_m[z].score_FE3;
        }
        else if(event_name == "High Jump")
        {

            athlete_m[z].score_FE4 = points;
            score_in_event = athlete_m[z].score_FE4;
        }

        cout<<"Points of athlete named "<<athlete_m[z].name<<"in event "<<" with strength "<<athlete_m[z].strength<<"points : "<<score_in_event<<"\n";

    }



}
//chck for injury
bool checkingForInjury(int initial_value, int final_value)
{

    bool injury;

    float decrease = initial_value - final_value;

    if(decrease>15.00)
    {
        injury = true;
    }
    else
    {
        injury = false;
    }

    return injury;
}

//calculating impact of track event
void calculatingImpactForTrackEvent(Athlete athlete_f[],Athlete athlete_m[])
{

    int speed_before,speed_after,score_in_event;
    cout<<"\n****************impact of event******************"<<"\n\n";
    cout<<"Due to tiredness the speed of athletes will be impacted"<<"\n\n";

    for(int z=0; z<i; z++)
    {
        cout<<"Average speed before the event : "<< athlete_f[z].speed;
        speed_before = athlete_f[z].speed;

        //due to the event playe dthe player can be tired and will not have same speed for second event
        speed_after = speed_before - ((speed_before* (generateRandomNumber(10,1))/100));

        //updating the value in object
        athlete_f[z].speed = speed_after;
        cout<<" Speed after event : "<< athlete_f[z].speed<<"\n\n";
        athlete_f[z].isInjured =checkingForInjury(speed_before,speed_after);
        if(athlete_f[z].isInjured)
        {
            athlete_f[z].stress_level = athlete_f[z].stress_level +generateRandomNumber(1,5);
            cout<<"The athlete "<<athlete_f[z].name<<"has been injured "<<"\n\n";

        }

        cout<<"Average speed before the event : "<< athlete_m[z].speed;


        speed_before = athlete_m[z].speed;

        //due to the event playe dthe player can be tired and will not have same speed for second event
        speed_after = speed_before - ((speed_before* (generateRandomNumber(10,1))/100));

        //updating the value in object
        athlete_m[z].speed = speed_after;
        cout<<" Speed after event : "<< athlete_m[z].speed<<"\n\n";

        athlete_m[z].isInjured =checkingForInjury(speed_before,speed_after);
        if(athlete_m[z].isInjured)
        {
            athlete_m[z].stress_level = athlete_m[z].stress_level +generateRandomNumber(1,5);
            cout<<"The athlete "<<athlete_m[z].name<<"has been injured "<<"\n\n";

        }
    }

}

void calculatingImpactForFieldEvent(Athlete athlete_f[],Athlete athlete_m[])
{

    int strength_before,strength_after,score_in_event;
    cout<<"****************impact of event******************"<<"\n\n";
    cout<<"Due to tiredness the strength of athletes will be impacted"<<"\n\n";

    for(int z=0; z<i; z++)
    {
        cout<<"Average strength for"<<athlete_f[z].name<<" before the event : "<< athlete_f[z].strength;

        strength_before = athlete_f[z].strength;

        //due to the event playe dthe player can be tired and will not have same speed for second event
        strength_after = strength_before - ((strength_before* (generateRandomNumber(10,1))/100));

        athlete_f[z].strength = strength_after;

        cout<<" Strength after event : "<< athlete_f[z].strength<<"\n\n";

        athlete_f[z].isInjured =checkingForInjury(strength_before,strength_after);
        if(athlete_f[z].isInjured)
        {
            athlete_f[z].stress_level = athlete_f[z].stress_level +generateRandomNumber(1,5);
            cout<<"The athlete "<<athlete_f[z].name<<"has been injured "<<"\n\n";

        }

        cout<<"Average strength for "<<athlete_m[z].name<<" before the event : "<< athlete_m[z].strength;

        strength_before = athlete_m[z].strength;

        //due to the event playe dthe player can be tired and will not have same speed for second event
        strength_after = strength_before - ((strength_before* (generateRandomNumber(10,1))/100));

        athlete_m[z].strength = strength_after;

        cout<<" Strength after event : "<< athlete_m[z].strength<<"\n\n";

        // cout<<"athlete_f[z] : "<<athlete_f[z].physiotherapistImpactValue<<endl;
        athlete_m[z].isInjured =checkingForInjury(strength_before,strength_after);
        if(athlete_m[z].isInjured)
        {
            athlete_m[z].stress_level = athlete_m[z].stress_level +generateRandomNumber(1,5);
            cout<<"The athlete "<<athlete_m[z].name<<"has been injured "<<"\n\n";

            // teamMemberImpact(speed_after,speed_before,athlete_f[z]);
        }


    }

}

//calculating total scores for athletes for a meet
void calculateTotalScore(Athlete athlete_f[],Athlete athlete_m[])
{

    for(int z=0; z<i; z++)
    {
        athlete_f[z].total_score = athlete_f[z].score_TE1+ athlete_f[z].score_TE2 + athlete_f[z].score_TE3 + athlete_f[z].score_TE4 + athlete_f[z].score_FE1 +
                                   athlete_f[z].score_FE2 + athlete_f[z].score_FE3 + athlete_f[z].score_FE4;

        athlete_f[z].season_score=athlete_f[z].season_score+athlete_f[z].total_score;

        athlete_m[z].total_score = athlete_m[z].score_TE1+ athlete_m[z].score_TE2 + athlete_m[z].score_TE3 + athlete_m[z].score_TE4 + athlete_m[z].score_FE1 +
                                   athlete_m[z].score_FE2 + athlete_m[z].score_FE3 + athlete_m[z].score_FE4;

        athlete_m[z].season_score=athlete_m[z].season_score+athlete_m[z].total_score;

    }
}

//sorting in descending order for total points for a meet
void sortingMeetInDescendingOrder(Athlete athlete_f[],Athlete athlete_m[])
{

    bool swapVal = true;
    while(swapVal)
    {
        swapVal = false;
        Athlete dummy;
        for(int y =1; y<i; y++)
        {

            if(athlete_f[y].total_score>athlete_f[y-1].total_score)
            {
                dummy=athlete_f[y];
                athlete_f[y]=athlete_f[y-1];
                athlete_f[y-1]=dummy;
                swapVal=true;
            }
            if(athlete_m[y].total_score>athlete_m[y-1].total_score)
            {
                dummy=athlete_m[y];
                athlete_m[y]=athlete_m[y-1];
                athlete_m[y-1]=dummy;
                swapVal=true;
            }

        }
    }
    for(int z=0; z<i; z++)
    {

        cout<<"The total score for female athlete : "<<athlete_f[z].name<<" points : "<<athlete_f[z].total_score<<"\n";
        cout<<"The total score for male athlete : "<<athlete_m[z].name<<" points : "<<athlete_m[z].total_score<<"\n";

    }
}

void sortingSeasonScore(Athlete athlete_f[],Athlete athlete_m[])
{

    bool swapVal = true;
    while(swapVal)
    {
        swapVal = false;
        Athlete dummy;
        for(int y =1; y<i; y++)
        {

            if(athlete_f[y].season_score>athlete_f[y-1].season_score)
            {
                dummy=athlete_f[y];
                athlete_f[y]=athlete_f[y-1];
                athlete_f[y-1]=dummy;
                swapVal=true;
            }
            if(athlete_m[y].season_score > athlete_m[y-1].season_score)
            {
                dummy=athlete_m[y];
                athlete_m[y]=athlete_m[y-1];
                athlete_m[y-1]=dummy;
                swapVal=true;
            }

        }
    }
    cout<<"\n***************Accumulated Points for season***********************\n";

    for(int z=0; z<i; z++)
    {
        cout<<"\nThe season score for female athlete : "<<athlete_f[z].name<<" points : "<<athlete_f[z].season_score;
        cout<<"\nThe season score for male athlete : "<<athlete_m[z].name<<" points : "<<athlete_m[z].season_score;

    }

}

//providing medals based on the meet scores
void medalDistributionForMeet(Athlete athlete_m[])
{

    int gold =0, silver =0, bronze=0,k=0;

//count total gold winners
    {
        while(athlete_m[k].total_score==athlete_m[k+1].total_score && k < (i-1))
        {

            k++;
        }
        k++;
        gold = k;

    }
//count total silver winners
    if(gold<2&&i>1)
    {
        while(athlete_m[k].total_score==athlete_m[k+1].total_score && k < (i-1))
        {
            silver++;
            k++;
        }
        silver++;
        k++;
    }
//count total bronze winners
    if(((gold<3&&silver==0)||(gold==1&&silver==1))&& i>2)
    {
        while(athlete_m[k].total_score==athlete_m[k+1].total_score && k < (i-1))
        {
            bronze++;
            k++;
        }
        k++;
        bronze++;
    }

//print gold winners
    cout<<"\n\n below are gold winners\n\n";
    for(k=0; k<gold; k++)
    {
        cout<<athlete_m[k].name<<" : "<<athlete_m[k].total_score<<" : gender = "<<athlete_m[k].gender;
    }
    cout<<"\n\n below are silver winners\n\n";
    silver=silver+k;
    for(; k<silver; k++)
    {
        cout<<athlete_m[k].name<<" : "<<athlete_m[k].total_score<<" : gender = "<<athlete_m[k].gender;
    }
    cout<<"\n\n below are bronze winners\n\n";
    bronze=bronze+k;
    for(; k<bronze; k++)
    {
        cout<<athlete_m[k].name<<" : "<<athlete_m[k].total_score<<" : gender = "<<athlete_m[k].gender;
    }

}

void overallSeasonTrophy(Athlete athlete_f[],Athlete athlete_m[])
{
    int z=0;

    cout<<"\n*****************Overall Trophies For Season*********************";
    cout<<"\nThe overall trophy for female athlete : "<<athlete_f[z].name<<" season points : "<<athlete_f[z].season_score<<"\n";
    cout<<"The overall trophy for male athlete : "<<athlete_m[z].name<<" season points : "<<athlete_m[z].season_score<<"\n";

}

//team member impact after meet

void teamMemberImpactAfterMeet(Athlete athlete_f[],Athlete athlete_m[])
{

    cout<<"\n\n*****************Recovery of female athletes***********************\n";


    for(int z=0; z<i; z++)
    {
        cout<<"Readiness of athlete "<<athlete_f[z].name<<" before recovery : "<<readinessOfAthlete(athlete_f[z].strength,athlete_f[z].speed,athlete_f[z].isInjured, athlete_f[z].isTired);
        athlete_f[z].speed = athlete_f[z].speed +athlete_f[z].sportsPshycologistImpactValue+
                             athlete_f[z].physiotherapistImpactValue + athlete_f[z].eventTrainerImpactValue;

        athlete_f[z].strength = athlete_f[z].strength + athlete_f[z].sportsPshycologistImpactValue +
                                athlete_f[z].physiotherapistImpactValue + athlete_f[z].fieldTrainerImapctValue;


        cout<<" after recovery : "<<readinessOfAthlete(athlete_f[z].strength,athlete_f[z].speed,athlete_f[z].isInjured, athlete_f[z].isTired)<<endl;

        cout<<"After recovery "<<athlete_f[z].name<<" speed : "<<athlete_f[z].speed<<" and strength : "<<athlete_f[z].strength<<"\n";
        cout<<"Athlete "<<athlete_f[z].name<<" stress level before recovery : "<<athlete_f[z].stress_level;
        if((athlete_f[z].sportsPshycologistImpactValue >= athlete_f[z].stress_level) || (athlete_f[z].stress_level == 0))
            athlete_f[z].stress_level = 0;
        else
            athlete_f[z].stress_level=athlete_f[z].stress_level - athlete_f[z].sportsPshycologistImpactValue;
        cout<<" after recovery :  "<<athlete_f[z].stress_level<<endl;
    }

    cout<<"\n*****************Recovery of male athletes***********************\n";
    for(int z=0; z<i; z++)
    {
        cout<<"Readiness of athlete "<<athlete_m[z].name<<" before recovery : "<<readinessOfAthlete(athlete_m[z].strength,athlete_m[z].speed,athlete_m[z].isInjured, athlete_m[z].isTired);


        athlete_m[z].speed = athlete_m[z].speed +athlete_m[z].sportsPshycologistImpactValue+
                             athlete_m[z].physiotherapistImpactValue + athlete_m[z].eventTrainerImpactValue;

        athlete_m[z].strength = athlete_m[z].strength + athlete_m[z].sportsPshycologistImpactValue +
                                athlete_m[z].physiotherapistImpactValue + athlete_m[z].fieldTrainerImapctValue;

        cout<<" after recovery : "<<readinessOfAthlete(athlete_m[z].strength,athlete_m[z].speed,athlete_m[z].isInjured, athlete_m[z].isTired)<<endl;

        cout<<"After recovery athlete "<<athlete_m[z].name<<" has speed : "<<athlete_m[z].speed<<" and strength : "<<athlete_m[z].strength<<"\n";

        cout<<"Athlete "<<athlete_m[z].name<<" stress level before recovery : "<<athlete_m[z].stress_level;
        if(athlete_m[z].sportsPshycologistImpactValue>= athlete_m[z].stress_level)
            athlete_m[z].stress_level = 0;
        else
            athlete_m[z].stress_level=athlete_m[z].stress_level - athlete_m[z].sportsPshycologistImpactValue;
        cout<<" after recovery :  "<<athlete_m[z].stress_level<<endl;
    }


}

void getSeasonDetails(int dateArray[],string locationNameArray[],string featureArray[])
{

    int date=2;
    int dateIndex=2;
    dateArray[0]=1;
    dateArray[1]=2;
    string temp;

    for(int jj=0; jj<(m*2); jj++)
    {

        if(jj%2==0)
        {


            temp=meet_locations[generateRandomNumber(3,0)];


        }
        else
        {
            string loc=meet_locations[generateRandomNumber(3,0)];
            while(temp==loc)
            {
                loc=meet_locations[generateRandomNumber(3,0)];
            }
            temp=loc;

        }


        locationNameArray[jj]=temp;
        featureArray[jj]=getSpecialFeatureOfLocation(locationNameArray[jj]);

        if(jj!=0&&jj%2==0)
        {
            dateArray[jj]=dateArray[jj-1]+gapBetweenMeets();
            dateIndex++;
        }
        else if(jj>2)
        {
            dateArray[jj]=dateArray[jj-1]+1;
            dateIndex++;
        }



    }


    cout<<"\n\n\n*********Season Details***********\n\n";
    for(int pk=0; pk<(m*2); pk++)
    {

        cout<<"\n\nThe meet will be held on meet date: "<<dateArray[pk];
        cout<<"\n\n at location name: "<<locationNameArray[pk];
        cout<<"\n\n special feature of location is :  "<<featureArray[pk]<<"\n";
    }
    cout<<"\n\n\n*********************************\n\n";

}

//initialising team members
void getTeamMembers(Team teams[], Athlete athlete_female[], Athlete athlete_male[])
{

    for(i=0; i<n; i++)
    {
        //intialising team objects

        teams[i].team_number = i+1;
        teams[i].teamManagerName = team_manager_name[generateRandomNumber(7,0)];
        teams[i].sportsPshycologistName = sports_Pshycologists_name[generateRandomNumber(7,0)];
        teams[i].physiotherapistName = physiotherapist_name[generateRandomNumber(7,0)];
        teams[i].fieldTrainerName = field_trainer_name[generateRandomNumber(7,0)];
        teams[i].eventTrainerName = event_trainer_name[generateRandomNumber(7,0)];


        athlete_female[i].gender = "Female";
        athlete_female[i].name = female_athlete_name[generateRandomNumber(7,0)];



        athlete_female[i].isInjured = false;
        athlete_female[i].strength = generateRandomNumber(200,100);
        athlete_female[i].speed = generateRandomNumber(200,100);
        athlete_female[i].isTired = false;
        athlete_female[i].readiness = readinessOfAthlete(athlete_female[i].strength,athlete_female[i].speed,athlete_female[i].isInjured,athlete_female[i].isTired);


        //at the begining the athletes have low stress level and more excitement
        athlete_female[i].stress_level = generateRandomNumber(5,0);

        athlete_female[i].sportsPshycologistImpactValue = generateRandomNumber(5,1);
        athlete_female[i].physiotherapistImpactValue = generateRandomNumber(5,1);
        athlete_female[i].eventTrainerImpactValue = generateRandomNumber(5,1);
        athlete_female[i].fieldTrainerImapctValue = generateRandomNumber(5,1);



        athlete_female[i].total_score = 0;
        athlete_female[i].season_score = 0;

        athlete_male[i].gender = "Male";
        athlete_male[i].name = male_athlete_name[generateRandomNumber(7,0)];



        athlete_male[i].isInjured = false;
        athlete_male[i].strength = generateRandomNumber(200,100);
        athlete_male[i].speed = generateRandomNumber(200,100);
        athlete_male[i].isTired = false;
        athlete_male[i].readiness = readinessOfAthlete(athlete_male[i].strength,athlete_male[i].speed,athlete_male[i].isInjured,athlete_male[i].isTired);


        //at the begining the athletes have low stress level and more excitement
        athlete_male[i].stress_level = generateRandomNumber(5,0);

        athlete_male[i].sportsPshycologistImpactValue = generateRandomNumber(5,1);
        athlete_male[i].physiotherapistImpactValue = generateRandomNumber(5,1);
        athlete_male[i].eventTrainerImpactValue = generateRandomNumber(5,1);
        athlete_male[i].fieldTrainerImapctValue = generateRandomNumber(5,1);


        athlete_male[i].total_score =0;
        athlete_male[i].season_score =0;



    }

}

//print Team Details

void printTeamDetails(Team teams[], Athlete athlete_female[], Athlete athlete_male[])
{

    for(int j=0; j<n; j++)
    {
        //cout<<"************Team Details****************"<<"\n";
        cout<<"Team Number : "<<teams[j].team_number<<endl;
        cout<<"Team Manager Name : "<<teams[j].teamManagerName<<endl;
        cout<<"Pshycologist Name : "<<teams[j].sportsPshycologistName<<endl;
        cout<<"Pshycologist Impact Value : "<<teams[j].sportsPshycologistImpactValue<<endl;
        cout<<"Physiotherapist Name : "<<teams[j].physiotherapistName<<endl;
        cout<<"Physiotherapist Impact Value : "<<teams[j].physiotherapistImpactValue<<endl;
        cout<<"field Trainer Name : "<<teams[j].fieldTrainerName<<endl;
        cout<<"field Trainer Imapct Value : "<<teams[j].fieldTrainerImapctValue<<endl;
        cout<<"event Trainer Name : "<<teams[j].eventTrainerName<<endl;
        cout<<"event Trainer Impact Value : "<<teams[j].eventTrainerImpactValue<<endl;

        cout<<"\n";
        cout<<"********** Male Athlete Details****************"<<"\n";
        cout<<"Athlete Name : " <<athlete_male[j].name<<endl;
        cout<<"Athlete gender : "<<athlete_male[j].gender<<endl;
        cout<<"Athlete strength : "<<athlete_male[j].strength<<endl;
        cout<<"Athlete speed : "<<athlete_male[j].speed<<endl;
        cout<<"Athlete Readiness : "<<athlete_male[j].readiness<<endl;
        cout<<"Athlete Stress Level : "<<athlete_male[j].stress_level<<endl;
        cout<<"********** Female Athlete Details****************"<<"\n";
        cout<<"Athlete Name : " <<athlete_female[j].name<<endl;
        cout<<"Athlete gender : "<<athlete_female[j].gender<<endl;
        cout<<"Athlete strength : "<<athlete_female[j].strength<<endl;
        cout<<"Athlete speed : "<<athlete_female[j].speed<<endl;
        cout<<"Athlete Readiness : "<<athlete_female[j].readiness<<endl;
        cout<<"Athlete Stress Level : "<<athlete_female[j].stress_level<<endl;
        cout<<"**************************************************************"<<"\n";


    }

}

string checkInputArguments(int arguments)
{
    string status = "";

    if(arguments == 3)
    {
        status = "Valid Arguments";
    }
    else if(arguments > 3)
    {
        status = "Arguments too long";
    }
    else if(arguments < 3)
    {
        status = "Arguments too short";
    }
    return status;
}

int main(int argc, char *argv[])
{

    string status = checkInputArguments(argc);

    if(status=="Valid Arguments")
    {
        n=atoi(argv[1]);
        m=atoi(argv[2]);
        checkValue(n);
        checkValue(m);
    }
    else
    {
        cout<<status<<endl;
        return 0;
    }


    srand ( time(NULL) );

    Team teams[n];
    Athlete athlete_male[n];
    Athlete athlete_female[n];
    getTeamMembers(teams, athlete_female, athlete_male);
    printTeamDetails(teams, athlete_female, athlete_male);

    int dateArray[m*2];
    string locationNameArray[m*2];
    string featureArray[m*2];

    getSeasonDetails(dateArray,locationNameArray,featureArray);

    //Print season details
    int previous_meet_date = 0;
    int index=0;
    for(int k=0; k<m; k++)
    {



        day1.location_of_meet = locationNameArray[index];
        day1.special_feature_of_location = featureArray[index];
        day1.weather_for_meet = weather[generateRandomNumber(2,0)];
        day1.date_of_meet=dateArray[index];
        index++;

        cout<<"\n\n**********************Meet Day 1*******************\n";

        cout<<"*************Location Impact Report******************"<<endl;
        //location impact on athlete's performance

        if(day1.special_feature_of_location =="Plain Track")
        {
            calculatingAthletePerformanceForImpact( athlete_female,athlete_male,1);
        }
        else if(day1.special_feature_of_location=="Low Steep Track")
        {
            calculatingAthletePerformanceForImpact(athlete_female,athlete_male,2);
        }
        else if(day1.special_feature_of_location=="Moderate Steep Track")
        {
            calculatingAthletePerformanceForImpact(athlete_female,athlete_male,3);
        }
        else if(day1.special_feature_of_location=="High Steep Track")
        {
            calculatingAthletePerformanceForImpact(athlete_female,athlete_male,4);
        }


        cout<<"*************************************************"<<endl;

        cout<<"Weather for the meet is : "<<day1.weather_for_meet<<endl;
        cout<<"*************Weather Impact Report******************"<<endl;
        if(day1.weather_for_meet == "Sunny")
        {
            cout<<"The weather will have low impact on athlete's performance"<<endl;
            calculatingAthletePerformanceForImpact(athlete_female,athlete_male,1);
        }
        else if(day1.weather_for_meet == "Cold")
        {
            cout<<"The weather will have moderate impact on athlete's performance"<<endl;
            calculatingAthletePerformanceForImpact(athlete_female,athlete_male,2);
        }
        else if(day1.weather_for_meet == "Rainy")
        {
            cout<<"The weather will have high impact on athlete's performance"<<endl;
            calculatingAthletePerformanceForImpact(athlete_female,athlete_male,5);
        }

        cout<<"*************************************************"<<endl;

        //doubt the name of self created event should be T1, T2 and F1 and F2?

        //start the events for the meet day1
        //declaring objects of events
        trackEvent1.name_of_event = "100m Race";
        trackEvent2.name_of_event ="T1";
        fieldEvent1.name_of_event = "Discus throw";
        fieldEvent2.name_of_event = "F1";

        //create a function that traverse the athlete and creates points for every athlete
        calculatingPointsForTrackEvent(trackEvent1.name_of_event,athlete_female,athlete_male);
        calculatingImpactForTrackEvent(athlete_female,athlete_male);

        calculatingPointsForFieldEvent(fieldEvent1.name_of_event,athlete_female,athlete_male);
        calculatingImpactForFieldEvent(athlete_female,athlete_male);

        calculatingPointsForFieldEvent(fieldEvent2.name_of_event,athlete_female,athlete_male);
        calculatingImpactForFieldEvent(athlete_female,athlete_male);

        calculatingPointsForTrackEvent(trackEvent2.name_of_event,athlete_female,athlete_male);
        calculatingImpactForTrackEvent(athlete_female,athlete_male);

        cout<<"\n\n********************** 1st Day of Meet "<<k<<"*************************"<<"ends\n";



        //Meet day2;

        cout<<"\n\n**********************Meet Day 2*******************\n";

        day2.location_of_meet = locationNameArray[index];
        day2.special_feature_of_location = featureArray[index];
        day2.weather_for_meet = weather[generateRandomNumber(2,0)];
        day2.date_of_meet=dateArray[index];
        index++;



        previous_meet_date = day2.date_of_meet;

        cout<<"*************Location Impact Report******************"<<endl;


        //int gap = gapBetweenMeets(day2.date_of_meet);
        if(day2.special_feature_of_location =="Plain Track")
        {
            calculatingAthletePerformanceForImpact( athlete_female,athlete_male,1);
        }
        else if(day2.special_feature_of_location=="Low Steep Track")
        {
            calculatingAthletePerformanceForImpact(athlete_female,athlete_male,2);
        }
        else if(day2.special_feature_of_location=="Moderate Steep Track")
        {
            calculatingAthletePerformanceForImpact(athlete_female,athlete_male,3);
        }
        else if(day2.special_feature_of_location=="High Steep Track")
        {
            calculatingAthletePerformanceForImpact(athlete_female,athlete_male,4);
        }


        cout<<"*************************************************"<<endl;



        cout<<"Weather for the meet is : "<<day2.weather_for_meet<<endl;
        cout<<"*************Weather Impact Report******************"<<endl;
        if(day2.weather_for_meet == "Sunny")
        {
            cout<<"The weather will have low impact on athlete's performance"<<endl;
            calculatingAthletePerformanceForImpact(athlete_female,athlete_male,1);
        }
        else if(day2.weather_for_meet == "Cold")
        {
            cout<<"The weather will have moderate impact on athlete's performance"<<endl;
            calculatingAthletePerformanceForImpact(athlete_female,athlete_male,2);
        }
        else if(day2.weather_for_meet == "Rainy")
        {
            cout<<"The weather will have high impact on athlete's performance"<<endl;
            calculatingAthletePerformanceForImpact(athlete_female,athlete_male,5);
        }

        cout<<"*************************************************"<<endl;


        //start events for day2
        //declaring objects of events
        trackEvent3.name_of_event = "T2";
        fieldEvent3.name_of_event ="F2";
        fieldEvent4.name_of_event = "High Jump";
        trackEvent4.name_of_event = "1500 metre running race";

        //calculating performance of athletes in events
        //create a function that traverse the athlete and creates points for every athlete
        calculatingPointsForTrackEvent(trackEvent3.name_of_event,athlete_female,athlete_male);
        calculatingImpactForTrackEvent(athlete_female,athlete_male);

        calculatingPointsForFieldEvent(fieldEvent3.name_of_event,athlete_female,athlete_male);
        calculatingImpactForFieldEvent(athlete_female,athlete_male);

        calculatingPointsForFieldEvent(fieldEvent4.name_of_event,athlete_female,athlete_male);
        calculatingImpactForFieldEvent(athlete_female,athlete_male);

        calculatingPointsForTrackEvent(trackEvent4.name_of_event,athlete_female,athlete_male);
        calculatingImpactForTrackEvent(athlete_female,athlete_male);


        cout<<"\n\n********************** 2nd Day of Meet "<<k<<"*************************"<<"ends\n";

        //calculating total score for meet
        calculateTotalScore(athlete_female,athlete_male);

        //sorting meet scores
        sortingMeetInDescendingOrder(athlete_female,athlete_male);

        //Medal distribution for meet score
        cout<<"\n\n Medal Distribution for female below:\n";
        medalDistributionForMeet(athlete_female);
        cout<<"\n\n Medal Distribution for male below:\n";
        medalDistributionForMeet(athlete_male);

        //sorting season score
        sortingSeasonScore(athlete_female,athlete_male);


        //recovery of athletes during gap
        cout<<"\n\n*******************Recovery during gap***************************\n";
        teamMemberImpactAfterMeet(athlete_female,athlete_male);

    }

    //providing season trophy
    overallSeasonTrophy(athlete_female,athlete_male);
    return 0;


}


