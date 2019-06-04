#ifndef BULLET_H
#define BULLET_H

#include<QThread>
#include"define.h"

class bullet : public QThread
{
public:
    bullet();
    bullet(Location loc,Direction dir);   //传参为飞机的位置和方向
    void run();

    Location loc;      //子弹的位置
    bool isup;         //方向
    int speed;
    bool islive;
};

#endif // BULLET_H
