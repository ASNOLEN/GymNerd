//
// Created by Alex Nolen on 10/21/24.
//

// calculations.h
#ifndef GYMNERD_CALCULATIONS_H
#define GYMNERD_CALCULATIONS_H

// Class for fitness calculations
class Calculations {
public:
    static double calculateBMI(double weight, double height);
    static double calculateBMR(double weight, double height, int age);
    static double calculateStrength(int bench, int squat, double weight);
    static double calculateVitality(int age, int waist, double height);
    static double calculateAgility(double weight, double height, double sprint);
    static char calculateScore(double weight, double height, int bench, int squat, int sprint);
};

#endif // GYMNERD_CALCULATIONS_H
