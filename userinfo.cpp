//the cpp of the userinfo window. it takes in
//the users information in order to create stats for the user
//------------------------------------------------------------
#include "userinfo.h"
#include "ui_userinfo.h"
#include "BackgroundWidget.h"
#include "statscreen.h"
#include "calculations.h"
#include <QJsonObject>
#include <QJsonArray>
#include <QFile>
#include <QJsonDocument>

userinfo::userinfo(QWidget *parent) :
        QWidget(parent),
        ui(new Ui::userinfo),
        backgroundWidget(new BackgroundWidget(this)),
        isMetric(true)  //imperial is default
{
    ui->setupUi(this);

    //add a border, similar to MainWindow
    backgroundWidget->setGeometry(this->rect());
    backgroundWidget->raise();

    //connect the button to the next screen
    connect(ui->continuebutton, &QPushButton::clicked, this, &userinfo::processUserData);

    //connect radio buttons to unit selection functions
    connect(ui->male, &QRadioButton::clicked, this, &userinfo::onImperialSelected);
    connect(ui->female, &QRadioButton::clicked, this, &userinfo::onMetricSelected);
}

void userinfo::resizeEvent(QResizeEvent *event) {
    QWidget::resizeEvent(event);
    backgroundWidget->setGeometry(this->rect());
}

userinfo::~userinfo() {
    delete ui;
    delete backgroundWidget;
}

void userinfo::onMetricSelected() {
    isMetric = true;
    ui->label_3->setText("Weight (kg) :");
    ui->label_4->setText("Height (cm) :");
}

void userinfo::onImperialSelected() {
    isMetric = false;
    ui->label_3->setText("Weight (lb) :");
    ui->label_4->setText("Height (in) :");
}

void userinfo::processUserData() {
    //collect user input
    QString name = ui->username->toPlainText();
    int age = ui->age->text().toInt();
    double weight = ui->weightuser->text().toDouble();
    double height = ui->heightuser->text().toDouble();
    double sprint = ui->sprintuser->text().toDouble();
    double maxBench = ui->benchm->text().toDouble();
    double maxSquat = ui->squatm->text().toDouble();

    //create a user object based on gender and calculate metrics
    User *user = nullptr;  //select gender for user calculations
    if (ui->female->isChecked()) {
        user = new Female(age, weight, height);
    } else if (ui->male->isChecked()) {
        user = new Male(age, weight, height);
    } else {
        return;
    }

    //perform calculations using the user object
    double bmi = user->calcBMI();
    double bmr = user->calcBMR();
    int strength = user->calcStrength(maxBench, maxSquat);
    int vitality = user->calcVitality(sprint);
    int agility = user->calcAgility(sprint);
    char rank = user->calcRank(maxBench, maxSquat, sprint);

    //create stats screen to show user data
    statscreen *statsScreen = new statscreen();
    statsScreen->setStats(name, bmi, bmr, strength, vitality, agility);
    statsScreen->setRank(QString(rank));
    statsScreen->show();

    //save the user's data to a JSON file
    saveUserData(name, age, weight, height, bmi, bmr, strength, vitality, agility, rank);

    delete user;
    this->close();
}

//activate the function to save user data to a JSON file
void userinfo::saveUserData(const QString& name, int age, double weight, double height,
                            double bmi, double bmr, int strength, int vitality, int agility, char rank)
{
    QFile file("prevuser.json");

    if (!file.open(QIODevice::ReadWrite | QIODevice::Text)) {
        qWarning("Couldn't open file for writing.");
        return;
    }

    QByteArray data = file.readAll();
    QJsonDocument doc = QJsonDocument::fromJson(data);
    QJsonObject root = doc.object();
    QJsonArray users = root["users"].toArray();

    bool userExists = false;
//check if user exists
    for (int i = 0; i < users.size(); ++i) {
        QJsonObject user = users[i].toObject();
        if (user["name"].toString() == name) {
            user["age"] = age;
            user["weight"] = weight;
            user["height"] = height;
            user["bmi"] = bmi;
            user["bmr"] = bmr;
            user["strength"] = strength;
            user["vitality"] = vitality;
            user["agility"] = agility;
            user["grade"] = QString(rank);
            users[i] = user;
            userExists = true;
            break;
        }
    }
//if user doesnt exist then make user
    if (!userExists) {
        QJsonObject newUser;
        newUser["name"] = name;
        newUser["age"] = age;
        newUser["weight"] = weight;
        newUser["height"] = height;
        newUser["bmi"] = bmi;
        newUser["bmr"] = bmr;
        newUser["strength"] = strength;
        newUser["vitality"] = vitality;
        newUser["agility"] = agility;
        newUser["grade"] = QString(rank);
        users.append(newUser);
    }

    root["users"] = users;
    doc.setObject(root);

    file.resize(0);
    file.write(doc.toJson());
    file.close();
}
