#include "obj.h"
#include "constants.h"

Obj::Obj(){}

Obj::Obj(qreal x, qreal y, int type)
{
    setType(type);
    setPos(x, y);
    setData(DATA, OBJ);
}

QRectF Obj::boundingRect() const
{
    return QRectF(-SIZE, -SIZE, SIZE * 2, SIZE * 2);
}

QPainterPath Obj::shape() const
{
    QPainterPath f;
    f.addRect(QRectF(0.1, 0.1, SIZE - 0.2, SIZE - 0.2));
    return f;
}

void Obj::paint(QPainter *, const QStyleOptionGraphicsItem *, QWidget *)
{
}

int Obj::getType()
{
    return ot;
}

void Obj::setType(int type)
{
    this->ot = type;
}
