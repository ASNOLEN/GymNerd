//calculations.cpp
//calculations for the users stats
#include "calculations.h"

//constructure for user class
User::User(int userAge, double userWeight, double userHeight)
        : age(userAge), weight(userWeight), height(userHeight) {}

//bmi
double User::calcBMI() const {
    return 703 * (weight / (height * height));
}

//male subclass constructor with its own calculations
Male::Male(int userAge, double userWeight, double userHeight)
        : User(userAge, userWeight, userHeight) {}
//calc stats
double Male::calcBMR() const {
    return (4.536 * weight) + (15.88 * height) - (5 * age) + 5;
}

int Male::calcStrength(double bench, double squat) const {
    return static_cast<int>(((bench + squat) / (135 + (2 * weight))) * 20);
}

int Male::calcVitality(double sprintTime) const {
    int vitality = 40;
    vitality += (age > 30) ? (age - 30) * 0.5 : 0;
    vitality -= (sprintTime / height > 0.5) ? (sprintTime / height - 0.5) * 50 : 0;
    return vitality;
}


int Male::calcAgility(double sprintTime) const {
    int agility = 20;
    agility += (weight > 250 && height < 68) ? (weight - 200) * 0.5 : 0;
    agility += static_cast<int>(agility / sprintTime);
    return agility;
}

//scoring the male inputs with average to give rank
char Male::calcRank(double bench, double squat, double sprintTime) const {

    double scoreh = ((height - 69) / 69) * 100;
    double scorew = ((weight - 200) / 200) * 100;
    double scoreb = ((bench - 250) / 250) * 100;
    double scores = ((squat - 400) / 400) * 100;
    double scorest = ((13 - sprintTime) / 13) * 100;

    double scorecomb = (scoreh + scorew + scoreb + scores + scorest) / 5;
    scorecomb += 50;
    double score = 1 + ((scorecomb + 100) / 200) * 99;

    if (score > 95) return 'S';
    if (score > 85) return 'A';
    if (score > 70) return 'B';
    if (score > 60) return 'C';
    if (score > 50) return 'D';
    return 'E';
}

//female subclass constructor with its own calculations
Female::Female(int userAge, double userWeight, double userHeight)
        : User(userAge, userWeight, userHeight) {}
//calc stats
double Female::calcBMR() const {
    return (4.536 * weight) + (15.88 * height) - (5 * age) - 161;
}

int Female::calcStrength(double bench, double squat) const {
    return static_cast<int>(((bench + squat) / (90 + (1.6 * weight))) * 20);
}

int Female::calcVitality(double sprintTime) const {
    int vitality = 35;
    vitality += (age > 30) ? (age - 30) * 0.5 : 0;
    vitality -= (sprintTime / height > 0.5) ? (sprintTime / height - 0.5) * 45 : 0;
    return vitality;
}

int Female::calcAgility(double sprintTime) const {
    int agility = 18;
    agility += (weight > 200 && height < 64) ? (weight - 160) * 0.4 : 0;
    agility += static_cast<int>(agility / sprintTime);
    return agility;
}
//scoring the male inputs with average to give rank
char Female::calcRank(double bench, double squat, double sprintTime) const {
    double scoreh = ((height - 64) / 64) * 100;
    double scorew = ((weight - 170) / 170) * 100;
    double scoreb = ((bench - 150) / 150) * 100;
    double scores = ((squat - 300) / 300) * 100;
    double scorest = ((sprintTime - 14) / 14) * 100;

    double scorecomb = ((scoreh + scorew + scoreb + scores + scorest) / 5);
    scorecomb += 50;
    double score = 1 + ((scorecomb + 100) / 200) * 99;;

    if (score > 90) return 'S';
    if (score > 80) return 'A';
    if (score > 65) return 'B';
    if (score > 55) return 'C';
    if (score > 45) return 'D';
    return 'E';
}
