 #ifndef FASTFOOD_H
#define FASTFOOD_H

#include "food.h"

class fastFood : public Food
{
public:
    fastFood(qreal x, qreal y, int type = 3);

    void paint(QPainter *painter, const QStyleOptionGraphicsItem *, QWidget *);
};

#endif // FASTFOOD_H
