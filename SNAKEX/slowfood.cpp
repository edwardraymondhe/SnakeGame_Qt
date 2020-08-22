#include "slowfood.h"
#include "constants.h"

slowFood::slowFood(qreal x, qreal y, int type){
    this->setType(type);
    setPos(x, y);
    setData(DATA, FOOD);
};


void slowFood::paint(QPainter *painter,
           const QStyleOptionGraphicsItem *,
           QWidget *)
{
    painter->save();

    painter->setRenderHint(QPainter::Antialiasing);
    painter->fillPath(shape(), Qt::green);

    painter->restore();
}
