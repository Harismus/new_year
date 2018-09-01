#ifndef WGT_H
#define WGT_H

#include <QTimer>
#include "sneg.h"
#include "derevo.h"
#include <QObject>
#include <QDesktopWidget>
class Wgt:public QObject
{
    Q_OBJECT
public:
      Wgt();
      float speed_wind_max,speed_wind_min,speed_wind;

      QList<sneg*>snow_list;
      Elka elka;

      QTimer timer;
public slots:
       // void redraw();
        void calc_snow();
};

#endif // WGT_H
