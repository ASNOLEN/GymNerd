#ifndef GYMNERDS_USERINFO_H
#define GYMNERDS_USERINFO_H

#include <QWidget>
#include <QLabel>
#include "BackgroundWidget.h"
#include <QJsonObject>

namespace Ui {
    class userinfo;
}

class userinfo : public QWidget
{
Q_OBJECT

public:
    explicit userinfo(QWidget *parent = nullptr);
    ~userinfo();

protected:
    void resizeEvent(QResizeEvent *event) override;

private slots:
    void processUserData();
    void onMetricSelected();
    void onImperialSelected();

private:
    Ui::userinfo *ui;
    BackgroundWidget *backgroundWidget;
    bool isMetric;


    void saveUserData(const QString& name, int age, double weight, double height,
                      double bmi, double bmr, int strength, int vitality,
                      int agility, char rank);
};

#endif // GYMNERDS_USERINFO_H
