#ifndef GYMNERDS_STATSCREEN_H
#define GYMNERDS_STATSCREEN_H

#include <QWidget>
#include <QLabel>
#include "BackgroundWidget.h"

namespace Ui {
    class statscreen;
}

class statscreen : public QWidget
{
Q_OBJECT

public:
    explicit statscreen(QWidget *parent = nullptr);
    ~statscreen();

    void setStats(const QString& name, float bmi, float bmr, int strength, int vitality, int agility);
    void setRank(const QString& rank);



protected:
    void resizeEvent(QResizeEvent *event) override;

private://making the instances for the window
    Ui::statscreen *ui;
    BackgroundWidget *backgroundWidget;
};

#endif //GYMNERDS_STATSCREEN_H
