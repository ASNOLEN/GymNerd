#ifndef GYMNERDS_STATSCREEN_H
#define GYMNERDS_STATSCREEN_H

#include <QWidget>
#include <QJsonObject>
#include "BackgroundWidget.h"

namespace Ui {
    class statscreen;
}

class statscreen : public QWidget {
Q_OBJECT

public:
    explicit statscreen(QWidget *parent = nullptr);
    ~statscreen();

    void setStats(const QString& name, float bmi, float bmr, int strength, int vitality, int agility);
    void setRank(const QString& rank);
    void loadData(const QString &usernameToLoad);

protected:
    void resizeEvent(QResizeEvent *event) override;

private slots:
    void onChallengeClicked();
    void onReturnToMainClicked();

private:
    Ui::statscreen *ui;
    BackgroundWidget *backgroundWidget;

    QString username;
    QString grade;
    int strength;
    int vitality;
    int agility;

    void updateStats();
    void saveData();
};

#endif // GYMNERDS_STATSCREEN_H
