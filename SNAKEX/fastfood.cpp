#include "fastfood.h"
#include "constants.h"

fastFood::fastFood(qreal x, qreal y, int type){
    this->setType(type);
    setPos(x, y);
    setData(DATA, FOOD);
};


void fastFood::paint(QPainter *painter,
           const QStyleOptionGraphicsItem *,
           QWidget *)
{
    painter->save();

    painter->setRenderHint(QPainter::Antialiasing);
    painter->fillPath(shape(), Qt::yellow);

    painter->restore();
}
