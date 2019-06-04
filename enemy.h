#ifndef ENEMY_H
#define ENEMY_H

#include<QThread>
#include<QVector>
#include<QTimer>
#include<QObject>
#include"plane.h"
#include"define.h"
#include"bullet.h"

class Enemy : public plane,public QThread
{
public:
    Enemy();
    Enemy(Location loc,Direction dir);
    //~Enemy();
    void run();

    bullet *bu;
    bool isup;
    QTimer *timer;
    QVector<bullet*>bullet_vector;



private slots:
    void move();
    void shoot();
};

#endif // ENEMY_H
