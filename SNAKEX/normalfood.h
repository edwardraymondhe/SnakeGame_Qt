#ifndef NORMALFOOD_H
#define NORMALFOOD_H

#include "food.h"

class normalFood : public Food
{
public:

    normalFood(qreal x, qreal y, int type = 1);

    void paint(QPainter *painter, const QStyleOptionGraphicsItem *, QWidget *);
};

#endif // NORMALFOOD_H
