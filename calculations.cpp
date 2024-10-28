//
// Created by Alex Nolen on 10/21/24.
//
// calculations.cpp
#include "calculations.h"

double Calculations::calculateBMI(double weight, double height) {
    return 703 * (weight / (height * height)); //calc bmi
}

double Calculations::calculateBMR(double weight, double height, int age) {
    return (4.536 * weight) + (15.88 * height) - (5 * age) + 5; //calc the male bmr
}

double Calculations::calculateStrength(int bench, int squat, double weight) {
    return ((bench + squat) / (135 + (2 * weight))) * 20; //calc streangth
}

double Calculations::calculateVitality(int age, int sprint, double height) { //calc a vitaility stat
    float vitality = 40.0;
    if (age > 30) {
        vitality += (age - 30) * 0.5;
    }
    float whtr = sprint / height;
    if (whtr > 0.5) {
        vitality -= (whtr - 0.5) * 50;
    }
    return vitality;
}

double Calculations::calculateAgility(double weight, double height, double sprint) { //calc an agility stat
    float agility = 20.0;
    if (weight > 250 && height < 68) {
        agility += (weight - 200) * 0.5;
    }
    agility += (agility / sprint);
    return agility;
}

//give the user a score
char Calculations::calculateScore(double weight, double height, int bench, int squat, int sprint) {
    char value = 0;
    value += (height + weight + bench + squat) / ((135 + (2 * weight)) + 72 + 197) * 50;

    if (value > 95) return 'S';
    if (value > 85) return 'A';
    if (value > 70) return 'B';
    if (value > 60) return 'C';
    if (value > 50) return 'D';
    return 'E';
}
