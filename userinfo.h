#ifndef GYMNERDS_USERINFO_H
#define GYMNERDS_USERINFO_H

#include <QWidget>
#include <QLabel>
#include "BackgroundWidget.h"

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

private://making the instances for the window
    Ui::userinfo *ui;
    BackgroundWidget *backgroundWidget;
};

#endif //GYMNERDS_USERINFO_H
