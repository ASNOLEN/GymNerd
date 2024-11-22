#include "statscreen.h"
#include "ui_statscreen.h"
#include "BackgroundWidget.h"
#include <QFile>
#include <QJsonDocument>
#include <QJsonObject>
#include <QJsonArray>
#include <QMessageBox>

statscreen::statscreen(QWidget *parent)
        : QWidget(parent), ui(new Ui::statscreen) {

    ui->setupUi(this);

    //set border same as other windows
    backgroundWidget = new BackgroundWidget(this);
    backgroundWidget->setGeometry(this->rect());
    backgroundWidget->raise();

    //connect back button to close the statscreen
    connect(ui->backbutton, &QPushButton::clicked, this, &statscreen::onReturnToMainClicked);

    //connect daily challenge button to the stat adjustment function
    connect(ui->dailyChallengeButton, &QPushButton::clicked, this, &statscreen::onChallengeClicked);
}

statscreen::~statscreen() {
    delete ui;
}

//set the stats for this user and update the display
void statscreen::setStats(const QString& name, float bmi, float bmr, int strength, int vitality, int agility) {
    this->username = name;
    this->strength = strength;
    this->vitality = vitality;
    this->agility = agility;

    ui->usern->setText(name);
    ui->bodymassind->setText(QString::number(bmi));
    ui->basemrate->setText(QString::number(bmr));
    ui->strength->setText(QString::number(strength));
    ui->vitality->setText(QString::number(vitality));
    ui->agility->setText(QString::number(agility));
}

//set the user rank
void statscreen::setRank(const QString& rank) {
    this->grade = rank;
    ui->usergrade->setText(rank);
}
//border function just like other windows
void statscreen::resizeEvent(QResizeEvent *event) {
    QWidget::resizeEvent(event);
    backgroundWidget->setGeometry(this->rect());
}

//daily challenge button slot
void statscreen::onChallengeClicked() {
    //increment stats slightly and update
    strength += 1;
    vitality += 1;
    agility += 1;

    updateStats();
    saveData();
}

//slot for close button
void statscreen::onReturnToMainClicked() {
    saveData();  //save data of user before closing
    close();
}

//update the status display
void statscreen::updateStats() {
    ui->strength->setText(QString::number(strength));
    ui->vitality->setText(QString::number(vitality));
    ui->agility->setText(QString::number(agility));
}

//save the user's name, grade, and stats to a JSON file
void statscreen::saveData() {
    QFile file("prevuser.json");

    QJsonDocument doc;
    QJsonObject root;

    if (file.open(QIODevice::ReadWrite | QIODevice::Text)) {
        QByteArray data = file.readAll();
        if (!data.isEmpty()) {
            doc = QJsonDocument::fromJson(data);
            root = doc.object();
        }

        QJsonArray users = root["users"].toArray();
        bool userExists = false;

        // Check if user exists and update data
        for (int i = 0; i < users.size(); ++i) {
            QJsonObject user = users[i].toObject();
            if (user["name"].toString() == username) {
                user["grade"] = grade;
                user["strength"] = strength;
                user["vitality"] = vitality;
                user["agility"] = agility;
                users[i] = user;
                userExists = true;
                break;
            }
        }

        //add new user if not found
        if (!userExists) {
            QJsonObject newUser;
            newUser["name"] = username;
            newUser["grade"] = grade;
            newUser["strength"] = strength;
            newUser["vitality"] = vitality;
            newUser["agility"] = agility;
            users.append(newUser);
        }

        root["users"] = users;
        doc.setObject(root);

        //save the json to file
        file.resize(0);
        file.write(doc.toJson());
        file.close();
    } else { // display error if there was a problem
        QMessageBox::warning(this, "Save Error", "Could not save user data.");
    }
}

//load selected users data and displays
void statscreen::loadData(const QString &usernameToLoad) {
    QFile file("prevuser.json");

    //display error if problem
    if (!file.open(QIODevice::ReadOnly | QIODevice::Text)) {
        QMessageBox::warning(this, "Load Error", "Could not open the user data file.");
        return;
    }

    QByteArray data = file.readAll();
    QJsonDocument doc = QJsonDocument::fromJson(data);
    file.close();

    //display error if problem
    if (!doc.isObject()) {
        QMessageBox::warning(this, "Load Error", "Invalid user data file.");
        return;
    }

    QJsonObject root = doc.object();
    QJsonArray users = root["users"].toArray();

    //display user
    for (const QJsonValue &val : users) {
        QJsonObject user = val.toObject();
        if (user["name"].toString() == usernameToLoad) {
            username = user["name"].toString();
            grade = user["grade"].toString();
            strength = user["strength"].toInt(0);
            vitality = user["vitality"].toInt(0);
            agility = user["agility"].toInt(0);

            double bmi = user.contains("bmi") ? user["bmi"].toDouble() : 0.0;
            double bmr = user.contains("bmr") ? user["bmr"].toDouble() : 0.0;

            setStats(username, bmi, bmr, strength, vitality, agility);
            setRank(grade);
            return;
        }
    }

    QMessageBox::warning(this, "Load Error", "User not found.");
}

