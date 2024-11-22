//
// Created by Alex Nolen on 11/15/24.
//

#include "profilechooser.h"
#include <QFile>
#include <QJsonDocument>
#include <QVBoxLayout>

//checks the file and allows user to select between multiple previous users
//Note- not working properly
ProfileChooser::ProfileChooser(QWidget *parent)
        : QDialog(parent), userList(new QListWidget(this)) {
    QVBoxLayout *layout = new QVBoxLayout(this);
    layout->addWidget(userList);
    setLayout(layout);

    connect(userList, &QListWidget::itemClicked, this, &ProfileChooser::onUserClicked);
}

ProfileChooser::~ProfileChooser() {}
//search for the name of a user and display
void ProfileChooser::loadData(const QString &filePath) {
    QFile file(filePath);
    if (!file.open(QIODevice::ReadOnly | QIODevice::Text)) {
        qWarning("Failed to open file: %s", qPrintable(filePath));
        return;
    }

    QByteArray data = file.readAll();
    file.close();

    QJsonDocument doc = QJsonDocument::fromJson(data);
    if (!doc.isObject()) {
        qWarning("Invalid JSON format in file: %s", qPrintable(filePath));
        return;
    }

    QJsonObject rootObject = doc.object();
    QJsonArray usersArray = rootObject["users"].toArray(); //access the "users" array
    userData = usersArray; //store the array for later use

    userList->clear();
    for (const QJsonValue &value : usersArray) {
        QJsonObject user = value.toObject();
        QString name = user["name"].toString();
        if (!name.isEmpty()) {
            userList->addItem(name);
        }
    }

    if (userList->count() == 0) {
        qWarning("No users found in file: %s", qPrintable(filePath));
    }
}
//check for user being selected
void ProfileChooser::onUserClicked(QListWidgetItem *item) {
    for (const QJsonValue &val : userData) {
        QJsonObject user = val.toObject();
        if (user["name"].toString() == item->text()) {
            chosenUser = user;
            accept();
            break;
        }
    }
}

QJsonObject ProfileChooser::getSelectedUser() const {
    return chosenUser;
}