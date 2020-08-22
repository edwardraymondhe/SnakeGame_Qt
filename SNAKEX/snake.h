#ifndef SNAKE_H
#define SNAKE_H

#include <QGraphicsRectItem>
#include <QRectF>
#include <QRect>
#include <QPainter>
#include <QPainterPath>
#include <QMediaPlayer>
#include "rules.h"

class Snake : public QGraphicsItem
{
public:
    enum Direction{
        STOP,
        UP,
        DOWN,
        LEFT,
        RIGHT,
        ESC
    };

    Snake(Rules & rule);

    QRectF boundingRect() const;
    QPainterPath shape() const;
    void paint(QPainter * painter, const QStyleOptionGraphicsItem *, QWidget *);

    void setDir(Direction dir);
    void setSpd(int spd);
    void setType(int type);
    int getType();
    int eaten;

    //bool eatenAll = false;

    QMediaPlayer * born;
    QMediaPlayer * death;
    QMediaPlayer * roar;
    QMediaPlayer * eat;

    void reset();

protected:
    void advance(int phase);

private:
    void moveUp();
    void moveDown();
    void moveLeft();
    void moveRight();
    void collidingEvent();

    int snakeType;
    QPointF head;
    QGraphicsRectItem *hr;
    QList<QPointF> tail;
    int growth;
    int speed;
    int fps;
    Direction moveDir;
    Rules & rule;
};


#endif // SNAKE_H
