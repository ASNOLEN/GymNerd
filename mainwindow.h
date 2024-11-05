#ifndef GYMNERDS_MAINWINDOW_H
#define GYMNERDS_MAINWINDOW_H

#include <QMainWindow>
#include "statscreen.h"
#include "BackgroundWidget.h"

QT_BEGIN_NAMESPACE
namespace Ui {
    class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

protected:
    void resizeEvent(QResizeEvent *event) override;

private slots:
            void openUserInfo();

private://making the instances for the ui and border
    Ui::MainWindow *ui;
    BackgroundWidget *backgroundWidget;
    statscreen *statsScreen;
};

#endif //GYMNERDS_MAINWINDOW_H
