#include "statscreen.h"
#include "ui_statscreen.h"

statscreen::statscreen(QWidget *parent)
        : QWidget(parent), ui(new Ui::statscreen) {

    ui->setupUi(this);

    // setting border same as other windows
    backgroundWidget = new BackgroundWidget(this);
    backgroundWidget->setGeometry(this->rect());
    backgroundWidget->raise();

    //connect the button
    connect(ui->backbutton, &QPushButton::clicked, this, &statscreen::close);
}

statscreen::~statscreen() {//delete the window
    delete ui;
}
//set the stats through pointers
void statscreen::setStats(const QString& name, float bmi, float bmr, int strength, int vitality, int agility) {
    ui->usern->setText(name);
    ui->bodymassind->setText(QString::number(bmi));
    ui->basemrate->setText(QString::number(bmr));
    ui->strength->setText(QString::number(strength));
    ui->vitality->setText(QString::number(vitality));
    ui->agility->setText(QString::number(agility));
}

void statscreen::setRank(const QString& rank) {
    ui->usergrade->setText(rank);
}

void statscreen::resizeEvent(QResizeEvent *event) {//dynamically adjust the border same as the windows before
    QWidget::resizeEvent(event);
    backgroundWidget->setGeometry(this->rect());
}