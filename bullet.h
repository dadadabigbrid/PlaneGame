#ifndef BULLET_H
#define BULLET_H

#include<QThread>
#include"define.h"

class bullet : public QThread
{
public:
    bullet();
    bullet(Location loc,Direction dir);   //����Ϊ�ɻ���λ�úͷ���
    void run();

    Location loc;      //�ӵ���λ��
    bool isup;         //����
    int speed;
    bool islive;
};

#endif // BULLET_H
