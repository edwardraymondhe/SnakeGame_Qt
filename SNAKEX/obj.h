#ifndef OBJ_H
#define OBJ_H

#include <QGraphicsItem>
#include <QRectF>
#include <QPainter>
#include <QBrush>
#include <QDebug>

class Obj : public QGraphicsItem{
public:
    Obj();
    Obj (qreal x, qreal y, int type);
    QRectF boundingRect() const;
    QPainterPath shape() const;
    void paint(QPainter *painter,
               const QStyleOptionGraphicsItem *option,
               QWidget *widget);
    int ot;

    int getType();
    void setType(int type);
};

#endif // OBJ_H
