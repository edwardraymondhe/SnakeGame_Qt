#ifndef FOOD_H
#define FOOD_H

#include <QGraphicsItem>
#include <QRectF>
#include <QPainter>
#include <QDebug>

const int RADIUS = 4;

class Food : public QGraphicsItem{
public:
    Food();
    Food (qreal x, qreal y, int type);
    QRectF boundingRect() const;
    QPainterPath shape() const;
    void paint(QPainter *painter,
               const QStyleOptionGraphicsItem *option,
               QWidget *widget);
    int ft;

    int getType();

protected:
    void setType(int type);



    /*void paintNormal(QPainter *painter,
               QStyleOptionGraphicsItem *option,
               QWidget *widget);
    void paintPoison(QPainter *painter,
               QStyleOptionGraphicsItem *option,
               QWidget *widget);
    void paintSpeed(QPainter *painter,
               QStyleOptionGraphicsItem *option,
               QWidget *widget);
    */
};

#endif // FOOD_H
