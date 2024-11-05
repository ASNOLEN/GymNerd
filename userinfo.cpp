//the cpp of the userinfo window. it takes in
//the users information in order to create stats for the user
//------------------------------------------------------------

#include "userinfo.h"
#include "ui_userinfo.h"
#include "statscreen.h"
#include "calculations.h"
#include <QPixmap>

userinfo::userinfo(QWidget *parent)
        : QWidget(parent), ui(new Ui::userinfo) {
    ui->setupUi(this);

    //add a border just like in mainwindow
    backgroundWidget = new BackgroundWidget(this);
    backgroundWidget->setGeometry(this->rect());
    backgroundWidget->raise();

    //connect the button to the next screen
    connect(ui->continuebutton, &QPushButton::clicked, this, &userinfo::processUserData);
}

void userinfo::resizeEvent(QResizeEvent *event) {//dynamically resize just like in main window
    QWidget::resizeEvent(event);
    backgroundWidget->setGeometry(this->rect());
}

userinfo::~userinfo() {//delete the window
    delete ui;
}

void userinfo::processUserData() {// process the data inputed by the user and call their calculations
    QString name = ui->username->toPlainText();
    int age = ui->age->text().toInt();
    double weight = ui->weightuser->text().toDouble();
    double height = ui->heightuser->text().toDouble();
    double sprint = ui->sprintuser->text().toDouble();
    double maxBench = ui->benchm->text().toDouble();
    double maxSquat = ui->squatm->text().toDouble();

    User *user = nullptr; // select gender for calculations
    if (ui->female->isChecked()) {
        user = new Female(age, weight, height);
    } else if (ui->male->isChecked()) {
        user = new Male(age, weight, height);
    } else {
        return;
    }

    //claculate the values through pointers
    double bmi = user->calcBMI();
    double bmr = user->calcBMR();
    int strength = user->calcStrength(maxBench, maxSquat);
    int vitality = user->calcVitality(sprint);
    int agility = user->calcAgility(sprint);
    char rank = user->calcRank(maxBench, maxSquat, sprint);

    statscreen *statsScreen = new statscreen();//send values to statscreen
    statsScreen->setStats(name, bmi, bmr, strength, vitality, agility);
    statsScreen->setRank(QString(rank));
    statsScreen->show();

    //delete the user boject and close the window
    delete user;
    this->close();
}