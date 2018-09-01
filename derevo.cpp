#include "derevo.h"

Elka::Elka()
{
    x = width()/2,y=height()/2;
    pixmap.load(":/1.png");
    setGeometry(x,y,pixmap.width(),pixmap.height());
    setMask(pixmap.mask());
    setWindowFlags(Qt::Tool);
    update();
}

void Elka::mousePressEvent(QMouseEvent*me)
{
   x1 = me->x(); y1 = me->y();
}

void Elka::mouseMoveEvent(QMouseEvent*me)
{
    x = x + (me->x() - x1);
    y  = y + (me->y() - y1);
    x1 = me->x(); y1 = me->y();
    setGeometry(x,y,pixmap.width(),pixmap.height());
}

void Elka::paintEvent(QPaintEvent *)
{
    paint.begin(this);
    paint.drawPixmap(0,0,pixmap);
    paint.end();
}
