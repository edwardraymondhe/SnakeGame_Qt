#include "normalfood.h"
#include "constants.h"

normalFood::normalFood(qreal x, qreal y, int type){
    this->setType(type);
    setPos(x, y);
    setData(DATA, FOOD);
};


void normalFood::paint(QPainter *painter,
           const QStyleOptionGraphicsItem *,
           QWidget *)
{
    painter->save();

    painter->setRenderHint(QPainter::Antialiasing);
    painter->fillPath(shape(), Qt::red);

    painter->restore();
}
