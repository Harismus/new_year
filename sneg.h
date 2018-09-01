#ifndef SNEG_H
#define SNEG_H

#include <QWidget>
#include <QPixmap>
#include <QMouseEvent>
#include <QBitmap>
#include <QPainter>
#include <QDesktopWidget>
class sneg:public QWidget
{
public:
    sneg(QPointF pos);

    sneg(const sneg&);
    float x,y;
    float deltax,deltay;
    float x1,y1;
    QPainter paint;
    void move();
    void set_wind(float);
    bool right_flag,left_flag;
    sneg * Sneg;//для создание отражения снега
   QPixmap pixmap;
   void mousePressEvent(QMouseEvent*);
   void mouseMoveEvent(QMouseEvent*);
   void paintEvent(QPaintEvent *);
};

#endif //
