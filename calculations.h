#ifndef GYMNERDS_USER_H
#define GYMNERDS_USER_H

//base class for a user in our fitness app
class User {
public:
    User (int userAge, double userWeight, double userHeight);//Constructor for User
    virtual double calcBMR() const = 0;
    virtual double calcBMI() const;
    virtual int calcStrength(double bench, double squat) const = 0;
    virtual int calcVitality(double sprintTime) const = 0;
    virtual int calcAgility(double sprintTime) const = 0;
    virtual char calcRank(double bench, double squat, double sprintTime) const = 0;
    virtual ~User() = default;

protected:
    int age;
    double weight;
    double height;
};

//male subclass
class Male : public User {
public:
    Male(int userAge, double userWeight, double userHeight);
    double calcBMR() const override;
    int calcStrength(double bench, double squat) const override;
    int calcVitality(double sprintTime) const override;
    int calcAgility(double sprintTime) const override;
    char calcRank(double bench, double squat, double sprintTime) const override;
};

//female subclass
class Female : public User {
public:
    Female(int userAge, double userWeight, double userHeight);
    double calcBMR() const override;
    int calcStrength(double bench, double squat) const override;
    int calcVitality(double sprintTime) const override;
    int calcAgility(double sprintTime) const override;
    char calcRank(double bench, double squat, double sprintTime) const override;
};

#endif // GYMNERDS_USER_H
