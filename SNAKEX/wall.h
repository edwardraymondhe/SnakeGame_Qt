#ifndef WALL_H
#define WALL_H

#include "obj.h"

class Wall : public Obj
{
public:
    Wall();
    QPainterPath shape() const;
    QRectF boundingRect() const;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *, QWidget *);

    QList<QPointF> wallList;
};



#endif // WALL_H
