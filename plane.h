#ifndef PLANE_H
#define PLANE_H

#include"define.h"

class plane
{
public:
    plane();
    void shoot();

    Location loc;     //λ��
    int life;         //����ֵ
    int speed;
    bool islive;
    Kind kind;        //�ѷ���λ||�з���λ
};

#endif // PLANE_H
