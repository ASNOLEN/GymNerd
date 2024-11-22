#ifndef GYMNERDS_MAINWINDOW_H
#define GYMNERDS_MAINWINDOW_H

#include <QMainWindow>
#include "userinfo.h"
#include "statscreen.h"
#include "profilechooser.h"
#include "BackgroundWidget.h"

namespace Ui {
    class MainWindow;
}

class MainWindow : public QMainWindow
{
Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

protected:
    void resizeEvent(QResizeEvent *event) override;

private slots:
    void onNewUserButtonClicked();
    void onExistingUserButtonClicked();

private:
    //pointers
    Ui::MainWindow *ui;
    BackgroundWidget *backgroundWidget;

};

extern ProfileChooser* _profileChooser;
extern statscreen* _stats;

#endif // GYMNERDS_MAINWINDOW_H

#endif //GYMNERDS_MAINWINDOW_H
