#include "flyingthings.h"


FlyingThings::FlyingThings()
{

}


void FlyingThings::setLocation(Location* in)
{
    this->location = in;
}

QPainter* FlyingThings::getimage()
{
    return this->image;
}



