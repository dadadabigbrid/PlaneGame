#include "myplane.h"

MyPlane::MyPlane()
{
    kind = Friend;

    timer = new QTimer;

    //connect(timer,SIGNAL(timeout()),this,SLOT(move()));
    connect(timer,SIGNAL(timeout()),this,SLOT(shoot()));

}

MyPlane::~MyPlane()
{
    delete timer;
}

void MyPlane::move()
{
    switch (dir)
    {
    case up:
        if(loc.y > speed)
            loc.y -= speed;
        break;
    case down:
        if(loc.y < 800 - speed)
            loc.y += speed;
        break;
    case l:
        if(loc.x > speed / 2)
            loc.x -= speed / 2;
        break;
    case r:
        if(loc.x < 800 - speed / 2)
            loc.x += speed / 2;
        break;
    }
}

void MyPlane::shoot()
{
    if(islive)
    {
        bu = new bullet(loc,up);
        bullet_vector.append(bu);
        bu->start();
    }

}
