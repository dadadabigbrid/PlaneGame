#ifndef FLYINGTHINGS_H
#define FLYINGTHINGS_H
#include <QString>
#include <QPainter>
#include "define.h"

class FlyingThings
{
public:
    FlyingThings();
    //实现导入图片
    virtual void flaingImage(const QString& fileName) = 0;
    //设置图片坐标
    virtual void setLocation(Location*);

    QPainter* getimage();
private:
    QPainter *image;
    Location *location;
};

#endif // FLYINGTHINGS_H
