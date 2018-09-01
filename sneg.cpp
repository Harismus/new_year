#include "sneg.h"
#include <QDebug>
sneg::sneg(QPointF pos)
{  
    pixmap.load(":/snow8.png");
    x = pos.x();
    y = -pixmap.height();
    deltax = 0;
    deltay = 5;
    right_flag = false;
    left_flag = false;
    setGeometry(x,y,pixmap.width(),pixmap.height());
    setMask(pixmap.mask());
    setWindowFlags(Qt::Tool);
    update();
}
sneg::sneg(const sneg&sn)
{
    x = sn.x;
    y = sn.y;
    deltax = sn.deltax;
    deltay = sn.deltay;
    pixmap = sn.pixmap;
    right_flag = sn.right_flag;
    left_flag = sn.left_flag;
}

void sneg::move()
{
    QDesktopWidget d;
    x = x + deltax;
    y = y + deltay;
    setGeometry(x,y,pixmap.width(),pixmap.height());
    //====================================================
            /*если вышел за пределы справа от экрана*/
    if(x+pixmap.width()>d.width()&& !right_flag)
    {
        float x =   this->x -  d.width() ;
        Sneg = new sneg(QPointF(x,y));
        Sneg->show();
        right_flag = true;
        return;
    }
    if(right_flag&&x+pixmap.width()<d.width())//если вернулся в экран
    {
        if(Sneg)
        {
            Sneg->close();
            delete Sneg;
            Sneg = 0;
        }
        right_flag = false;
        return;
    }
    if(right_flag&&x>d.width())//снежинка вышла за пределы
    {
        x = Sneg->x;
        y = Sneg->y;
        setGeometry(x,y,pixmap.width(),pixmap.height());
        if(Sneg)
        {
            Sneg->close();
            delete Sneg;
            Sneg = 0;
        }
        right_flag = false;
        return;
    }
    if(right_flag)//если вышел за пределы справа, то двигаем зеркальную снежинку аналогично основной
    {
       Sneg->x = this->x - d.width() ;//вычисляем значение координат зеркальной снежинки по иксу
       Sneg->y = y;
       Sneg->setGeometry(Sneg->x,Sneg->y,pixmap.width(),pixmap.height());
       return;
    }
    //====================================================
            /*если вышел за пределы слева от экрана*/
    if(x<0&&!left_flag)
    {
        float x =  d.width() + this->x;
        Sneg = new sneg(QPointF(x,this->y));
        Sneg->show();
        left_flag = true;
        return;
    }
    if(left_flag&&x>0)//если вернулся в экран
    {
        if(Sneg)
        {
            Sneg->close();
            delete Sneg;
            Sneg = 0;
        }
        left_flag = false;
        return;
    }
    if(left_flag&&x+pixmap.width()<0)//снежинка вышла за пределы
    {
        x = Sneg->x;
        y = Sneg->y;
        setGeometry(x,y,pixmap.width(),pixmap.height());
        if(Sneg)
        {
            Sneg->close();
            delete Sneg;
            Sneg = 0;
        }
        left_flag = false;
        return;
    }
    if(left_flag)//  двигаем зеркальную снежинку аналогично основной
    {
       Sneg->x = d.width() + this->x;//вычисляем значение координат зеркальной снежинки по иксу
       Sneg->y = y;
       Sneg->setGeometry(Sneg->x,Sneg->y,pixmap.width(),pixmap.height());
    }
}

void sneg::set_wind(float wind_speed)
{
    deltax = wind_speed;
    int celoe = 0;
    float drobnoe = 0;
    celoe = rand()%2;
    drobnoe  = (float)(rand()%500)/100;
    if(!celoe)
    {
        celoe = -1;
        drobnoe = -1 *drobnoe;
    }
    deltax = celoe + drobnoe;
    deltax+=wind_speed;
}

void sneg::mousePressEvent(QMouseEvent*me)
{
   x1 = me->x(); y1 = me->y();
}

void sneg::mouseMoveEvent(QMouseEvent*me)
{
    x = x + (me->x() - x1);
    y = y + (me->y() - y1);
    x1 = me->x(); y1 = me->y();
    setGeometry(x,y,pixmap.width(),pixmap.height());
}

void sneg::paintEvent(QPaintEvent *)
{
    paint.begin(this);
    paint.drawPixmap(0,0,pixmap);
    paint.end();
}
