#include "bullet.h"

#include<QDebug>

bullet::bullet(Location loca,Direction dir)
{
    this->loc.x = loca.x;
    this->loc.y = loca.y;

    //this->dir = dire;

    speed = 200;
    islive = true;
    if(dir == up)
        isup = true;
    else
        isup = false;

}

void bullet::run()
{
    qDebug() << "Ïß³ÌÆô¶¯";

    while (islive)
    {
        if(isup)
            loc.y -= speed;
        else
            loc.y += speed;
    }
    if(loc.x < 1100 || loc.x > 3000 || loc.y <0 || loc.y > 800)
    {
        islive = false;
        exit();
    }
}
