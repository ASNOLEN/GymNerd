//
// Created by Alex Nolen on 10/21/24.
//

// calculations.h
#ifndef CALCULATIONS_H
#define CALCULATIONS_H

class Calculations {
public:
    static double calculateBMI(double weight, double height);
    static double calculateBMR(double weight, double height, int age);
    static double calculateStrength(int bench, int squat, double weight);
    static double calculateVitality(int age, int waist, double height);
    static double calculateAgility(double weight, double height);
    static char calculateScore(double value);
};

#endif //GYMNERD_CALCULATIONS_H
