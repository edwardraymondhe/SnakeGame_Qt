#include "food.h"
#include "constants.h"
#include "normalfood.h"
#include "fastfood.h"
#include "slowfood.h"

Food::Food(){}

Food::Food(qreal x, qreal y, int type)
{
    qDebug("Creating food");
    setType(type);
    setPos(0, 0);
    setData(DATA, FOOD);
}

QRectF Food::boundingRect() const
{
    return QRectF(-SIZE, -SIZE, SIZE * 2, SIZE * 2);
}

QPainterPath Food::shape() const
{
    QPainterPath f;
    f.addEllipse(QPointF(SIZE / 2, SIZE / 2), RADIUS, RADIUS);
    return f;
}

void Food::paint(QPainter *, const QStyleOptionGraphicsItem *, QWidget *)
{

}

int Food::getType()
{
    return ft;
}

void Food::setType(int type)
{
    this->ft = type;
}
