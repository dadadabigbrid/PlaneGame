#include "enemy.h"

#include<ctime>
#include<QTextCodec>

Enemy::Enemy()
{

}

Enemy::Enemy(Location loc,Direction dir)
{
    islive = true;
    speed = 100;

    srand(clock());
    loc.x = 1200 + qrand()%800;
    loc.y = 0;

    timer = new QTimer;

    connect(timer,SIGNAL(timeout()),this,SLOT(run()));
    connect(timer,SIGNAL(timeout()),this,SLOT(shoot()));

    if(dir == up)
        isup = true;
    else
        isup = false;
}

void Enemy::run()
{
    while(islive)
    {
        Enemy::msleep(50);
        if(isup)
            loc.y -= speed;
        else
            loc.y += speed;
    }
}

void Enemy::shoot()
{
    if(isup)
    {
        bu = new bullet(loc,up);
        bullet_vector.append(bu);
        bu->start();
    }
    else {
        bu = new bullet(loc,down);
        bullet_vector.append(bu);
        bu->start();
    }
}
