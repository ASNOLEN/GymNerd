//The main window of the program, lets user exit or make new user
//Libraries and headers
//------------------------------------------------------------
#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "userinfo.h"
#include "statscreen.h"
#include "BackgroundWidget.h"
#include "profilechooser.h"

MainWindow::MainWindow(QWidget *parent) :
        QMainWindow(parent),
        ui(new Ui::MainWindow),
        backgroundWidget(new BackgroundWidget(this)) //create the border image
{
    ui->setupUi(this);

    //set border to fit window
    backgroundWidget->setGeometry(this->rect());
    backgroundWidget->raise(); //make it go behind the buttons

    //connect the buttons
    connect(ui->nwuserbutton, &QPushButton::clicked, this, &MainWindow::onNewUserButtonClicked);
    connect(ui->userButton, &QPushButton::clicked, this, &MainWindow::onExistingUserButtonClicked);
    connect(ui->exitprogbutton, &QPushButton::clicked, this, &MainWindow::close);
}

MainWindow::~MainWindow() {
    delete ui;
}

void MainWindow::resizeEvent(QResizeEvent *event) {
    QMainWindow::resizeEvent(event);
    backgroundWidget->setGeometry(this->rect());  //set border to change with window
}

void MainWindow::onNewUserButtonClicked() {
    this->hide();
    userinfo *userInfo = new userinfo;
    userInfo->show();
}
//access the user file to get previous users
void MainWindow::onExistingUserButtonClicked() {
    ProfileChooser profileDialog(this);
    profileDialog.loadData("prevuser.json");
    //display previous user list
    if (profileDialog.exec() == QDialog::Accepted) {
        QJsonObject selectedUser = profileDialog.getSelectedUser();
        statscreen* statsScreen = new statscreen();
        statsScreen->loadData(selectedUser["name"].toString());
        statsScreen->show();
    }
}
