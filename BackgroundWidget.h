//
// Created by Alex Nolen on 11/1/24.
//
//a header file for the border image
#ifndef GYMNERD_BACKGROUNDWIDGET_H
#define GYMNERD_BACKGROUNDWIDGET_H

#include <QWidget>
#include <QPainter>

class BackgroundWidget : public QWidget {
    Q_OBJECT

public:
    explicit BackgroundWidget(QWidget *parent = nullptr) : QWidget(parent) {
        setAttribute(Qt::WA_TransparentForMouseEvents); // Ignore mouse events
    }

protected:
    void paintEvent(QPaintEvent *event) override {//selecting the border image for the border
        QPainter painter(this);
        painter.drawPixmap(this->rect(), QPixmap(":/images/border.png"));
    }
};

#endif //GYMNERD_BACKGROUNDWIDGET_H