//the cpp of the main window of the program, lets user exit or make new user
//libraries and headers
//------------------------------------------------------------
#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "userinfo.h"
#include "BackgroundWidget.h"

MainWindow::MainWindow(QWidget *parent)
        : QMainWindow(parent), ui(new Ui::MainWindow), statsScreen(new statscreen), backgroundWidget(new BackgroundWidget(this)) {

    ui->setupUi(this);

    //make the border image fit on the screen and not obscure the buttons
    backgroundWidget->setGeometry(this->rect());
    backgroundWidget->raise();

    //connect the buttons to a function/slot
    connect(ui->nwuserbutton, &QPushButton::clicked, this, &MainWindow::openUserInfo);
    connect(ui->exitprogbutton, &QPushButton::clicked, this, &MainWindow::close);
}

//make border size change dynamically
void MainWindow::resizeEvent(QResizeEvent *event) {
    QMainWindow::resizeEvent(event);
    backgroundWidget->setGeometry(this->rect());
}

MainWindow::~MainWindow() {
    delete ui;//delete the window
}

void MainWindow::openUserInfo() {//open the next window
    this->hide();
    userinfo *userInfo = new userinfo;
    userInfo->show();
}
