#ifndef SLOWFOOD_H
#define SLOWFOOD_H

#include "food.h"

class slowFood : public Food
{
public:
    slowFood(qreal x, qreal y, int type = 2);

    void paint(QPainter *painter, const QStyleOptionGraphicsItem *, QWidget *);
};

#endif // SLOWFOOD_H
