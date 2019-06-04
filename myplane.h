#ifndef MYPLANE_H
#define MYPLANE_H

#include"plane.h"
#include"bullet.h"
#include"define.h"
#include<QObject>
#include<QKeyEvent>
#include<QTimer>
#include<QVector>
#include<qobject.h>

class MyPlane  : public plane,public QObject
{
public:
    MyPlane();
    ~MyPlane();
    void start();
    void stop();

    bullet *bu;
    Direction dir;
    QVector<bullet*> bullet_vector;

    QTimer *timer;

public slots:
    void move();
    void shoot();
};

#endif // MYPLANE_H
