#ifndef PLANE_H
#define PLANE_H

#include"define.h"

class plane
{
public:
    plane();
    void shoot();

    Location loc;     //位置
    int life;         //生命值
    int speed;
    bool islive;
    Kind kind;        //友方单位||敌方单位
};

#endif // PLANE_H
