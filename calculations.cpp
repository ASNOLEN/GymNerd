//
// Created by Alex Nolen on 10/21/24.
//
// calculations.cpp
#include "calculations.h"

double Calculations::calculateBMI(double weight, double height) {
    return 703 * (weight / (height * height));//weight in lb and height in inch
}

double Calculations::calculateBMR(double weight, double height, int age) {
    return (4.536 * weight) + (15.88 * height) - (5 * age) + 5; //bmr for men
}

double Calculations::calculateStrength(int bench, int squat, double weight) {
    return ((bench + squat) - weight) / 4.0;
}

double Calculations::calculateVitality(int age, int waist, double height) {
    float vitality = 40.0;
    if (age > 30) {
        vitality += (age - 30) * 0.5;
    }
    float whtr = waist / height; //a calculation to make vitality stat
    if (whtr > 0.5) {
        vitality -= (whtr - 0.5) * 50;
    }
    return vitality;
}

double Calculations::calculateAgility(double weight, double height) {
    return (height * 2) - weight;
}

char Calculations::calculateScore(double value) {
    if (value > 95) return 'S';
    if (value > 85) return 'A';
    if (value > 70) return 'B';
    if (value > 60) return 'C';
    if (value > 50) return 'D';
    return 'E';
}