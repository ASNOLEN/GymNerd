//
// Created by Alex Nolen on 11/15/24.
//

#ifndef GYMNERD_PROFILECHOOSER_H
#define GYMNERD_PROFILECHOOSER_H

#include <QDialog>
#include <QListWidget>
#include <QJsonArray>
#include <QJsonObject>

class ProfileChooser : public QDialog {
Q_OBJECT

public:
    explicit ProfileChooser(QWidget *parent = nullptr);
    ~ProfileChooser();

    //load user data from a JSON file
    void loadData(const QString &filePath);
    QJsonObject getSelectedUser() const;

private:
    QListWidget *userList;
    QJsonArray userData;
    QJsonObject chosenUser;

private slots:
    void onUserClicked(QListWidgetItem *item); //allows for user selection
};

#endif //GYMNERD_PROFILECHOOSER_H
