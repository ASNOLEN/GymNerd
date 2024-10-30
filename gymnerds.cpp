//gymnerds.cpp
//
//COP 3003
//Final project
//A framework for a gym user interface that takes a users values
//and displays their stats in a game-like fashion.
//------------------------------------------------------------

//libraries
//------------------------------------------------------------
#include "mainwindow.h"
#include <QApplication>

//main
//------------------------------------------------------------

int main(int argc, char *argv[]) { //check for inputs
    QApplication a(argc, argv);//open Qapplications
    MainWindow w; //open the mainmenu ui
    w.show();
    return a.exec();
}

