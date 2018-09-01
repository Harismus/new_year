#ifndef DEREVO_H
#define DEREVO_H


#include <QWidget>
#include <QPixmap>
#include <QMouseEvent>
#include <QBitmap>
#include <QPainter>
class Elka:public QWidget
{
public:
    Elka();
    float x1,y1;
    float x, y;
    QPainter paint;
    void paintEvent(QPaintEvent *);
    QPixmap pixmap;
    void mousePressEvent(QMouseEvent*);
    void mouseMoveEvent(QMouseEvent*);
};
#endif // DEREVO_H
