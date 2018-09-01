#include "wgt.h"
#include <QDebug>
Wgt::Wgt()
{
    elka.show();
    connect(&timer,SIGNAL(timeout()),this,SLOT(calc_snow()));
    timer.start(80);


       speed_wind_max = 2,speed_wind_min = -8;
       int znak  = (rand()%2);
       if(znak == 0) znak = -1;
       int celoe = rand()%(int)(speed_wind_max + speed_wind_min) - speed_wind_min;
       float drobnoe  = (float)(rand()%100)/100;
       speed_wind = znak*celoe + znak*drobnoe;
//       lights = new QPixmap[5];
//       for(int i = 1;i<=4;i++)
//       {
//           QString str = QString(":/") + QString::number(i) + QString::number(i) + QString(".png");
//           lights[i-1].load(str);
//       }


//       number = 5;
}
void Wgt::calc_snow()
{
    QDesktopWidget d;
    if(!(rand()%6))
    {
      sneg * Sneg = new sneg(QPointF(((float)rand()/RAND_MAX *d.width() ) ,0));
      snow_list.append(Sneg);
      Sneg->show();
    }
    if(!(rand()%20)) //изменение ветра
    {
        int znak  = (rand()%2);
        if(znak == 0) znak = -1;
        if(speed_wind>speed_wind_max) znak = -1;
        if(speed_wind<speed_wind_min) znak = 1;
        float drobnoe  = (float)(rand()%500)/100;
        speed_wind +=  znak * drobnoe ;
        if(speed_wind>speed_wind_max*2) speed_wind = speed_wind_max;
        if(speed_wind<speed_wind_min*2) speed_wind = speed_wind_min;
        //qDebug()<<"speed_wind = "<<speed_wind;
    }
    for(int i = 0; i<snow_list.size();i++)//движение снежинок
    {
        snow_list[i]->set_wind(speed_wind);
        snow_list[i]->move();

        if(snow_list[i]->y>d.height())
        {

            snow_list[i]->close();
            snow_list.removeAt(i);
        }

    }
}


//    //===========================================
//        /* Лапмпочки*/
//    paint.drawPixmap(elka.width()/4,elka.height()/2,lights[rand()%number].width(),lights[rand()%number].height(),lights[rand()%number]);
//    paint.drawPixmap(elka.width()/2,elka.height()/2,lights[rand()%number].width(),lights[rand()%number].height(),lights[rand()%number]);
//    paint.drawPixmap(elka.width()/2-30,190,lights[rand()%number].width(),lights[rand()%number].height(),lights[rand()%number]);
//    paint.drawPixmap(elka.width()/2-60,290,lights[rand()%number].width(),lights[rand()%number].height(),lights[rand()%number]);
//    paint.drawPixmap(elka.width()/2-80,490,lights[rand()%number].width(),lights[rand()%number].height(),lights[rand()%number]);
//    paint.drawPixmap(elka.width()/2+20,550,lights[rand()%number].width(),lights[rand()%number].height(),lights[rand()%number]);
//    paint.drawPixmap(elka.width()/2-130,550,lights[rand()%number].width(),lights[rand()%number].height(),lights[rand()%number]);
//    paint.end();





