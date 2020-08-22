#ifndef BRICK_H
#define BRICK_H

#include "obj.h"

class Brick : public Obj
{
public:
    Brick(qreal x, qreal y, int type);

    void paint(QPainter *painter, const QStyleOptionGraphicsItem *, QWidget *);
};

#endif // BRICK_H
