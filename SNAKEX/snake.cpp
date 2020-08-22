#include "snake.h"
#include "constants.h"

Snake::Snake(Rules & rule) :
    head(0,0),
    growth(5),
    speed(6),
    moveDir(STOP),
    rule(rule)
{
    born = new QMediaPlayer();
    born->setMedia(QUrl("qrc:/music/born.mp3"));
    death = new QMediaPlayer();
    death->setMedia(QUrl("qrc:/music/death.mp3"));
    roar = new QMediaPlayer();
    roar->setMedia(QUrl("qrc:/music/roar.mp3"));
    eat = new QMediaPlayer();
    eat->setMedia(QUrl("qrc:/music/eat.mp3"));

}

QRectF Snake::boundingRect() const
{
    qreal minX = head.x();
    qreal minY = head.y();
    qreal maxX = head.x();
    qreal maxY = head.y();

    foreach (QPointF p, tail)
    {
        maxX = p.x() > maxX ? p.x() : maxX;
        maxY = p.y() > maxY ? p.y() : maxY;
        minX = p.x() < minX ? p.x() : minX;
        minY = p.y() < minY ? p.y() : minY;
    }

    QPointF topLeft = mapFromScene(QPointF(minX, minY));
    QPointF bottomRight = mapFromScene(QPointF(maxX, maxY));

    QRectF bound = QRectF(topLeft.x(), topLeft.y(), bottomRight.x() - topLeft.x() + SIZE, bottomRight.y() - topLeft.y() + SIZE);

    return bound;
}
QPainterPath Snake::shape() const
{
    QPainterPath snakePath;

    snakePath.setFillRule(Qt::WindingFill);

    snakePath.addRect(QRectF(0, 0, SIZE, SIZE));

    foreach(QPointF tempTail, tail)
    {
        QPointF p = mapFromScene(tempTail);
        snakePath.addRect(QRectF(p.x(), p.y(), SIZE, SIZE));
    }
    return snakePath;
}

void Snake::paint(QPainter * painter, const QStyleOptionGraphicsItem *, QWidget *)
{
    painter->save();
    switch(snakeType)
    {
        case 1:
        {
            painter->fillPath(shape(), QColor(185, 108, 100));
            break;
        }
        case 2:
        {
            painter->fillPath(shape(), QColor(98, 111, 240));
            break;
        }
        case 3:
        {
            painter->fillPath(shape(), QColor(237, 102, 37));
            break;
        }
        case 4:
        {
            painter->fillPath(shape(), Qt::black);
            break;
        }
    }
    painter->restore();
}

void Snake::setDir(Direction dir)
{
    moveDir = dir;
}

void Snake::setSpd(int spd)
{
    speed = spd;
}

void Snake::setType(int type)
{
    snakeType = type;
}

int Snake::getType()
{
    return snakeType;
}

void Snake::advance(int phase)
{
    if(!phase)
    {
        return;
    }
    if(fps++ % speed != 0)
    {
        return;
    }
    if(moveDir == STOP)
    {
        return;
    }

    if(growth > 0)
    {
        QPointF temp = head;
        tail << temp;
        growth--;
    }else if(growth == 0)
    {
        tail.takeFirst();
        tail << head;
    }

    switch(moveDir)
    {
        case LEFT:
            moveLeft();
            break;
        case RIGHT:
            moveRight();
            break;
        case UP:
            moveUp();
            break;
        case DOWN:
            moveDown();
            break;
        case ESC:
            rule.pause();
            break;
    }

    setPos(head);
    collidingEvent();
    /*
    QPixmap pixHead(SIZE, SIZE);
    pixHead.fill(QColor(157, 49, 38));
    QPainter p(&pixHead);
    p.setBrush(QBrush());
    hr->setRect(QRectF(head.x(), head.y(), SIZE, SIZE));
    hr->setZValue(1);
    */

}



void Snake::moveUp()
{
    head.ry() -= SIZE;
    if (head.ry() < -100) {
        head.ry() = 100;
    }
}

void Snake::moveDown()
{
    head.ry() += SIZE;
    if (head.ry() >= 100) {
        head.ry() = -100;
    }
}

void Snake::moveLeft()
{
    head.rx() -= SIZE;
    if (head.rx() < -100) {
        head.rx() = 100;
    }
}

void Snake::moveRight()
{
    head.rx() += SIZE;
    if (head.rx() >= 100) {
        head.rx() = -100;
    }
}



void Snake::collidingEvent()
{
    QList<QGraphicsItem *> collisions = collidingItems();
    foreach(QGraphicsItem *collidingItem, collisions){
        if (collidingItem->data(DATA) == FOOD){
            int type = rule.eatFood(this, (Food *)collidingItem);
            if(eat->state() == QMediaPlayer::PlayingState)
            {
                eat->setPosition(0);
            } else if(eat->state() == QMediaPlayer::StoppedState)
            {
                eat->play();
            }
            switch(type)
            {
                case 1:
                    break;
                case 2:
                    setSpd(3);
                    break;
                case 3:
                    setSpd(8);
                    break;
            }
            growth += 1;
            eaten += 1;


            if(eaten <= 10)
            {
                rule.brickSpd = 4;
            }else if(eaten > 10){
                rule.brickSpd = 3;
            }



            if(rule.mode == 2)
            {
                if(rule.currLv == 1 && eaten == 1)
                {
                    reset();
                    rule.arcade();
                }
                if(rule.currLv == 2 && eaten == 2)
                {
                    rule.arcade();
                }
            }

            }

            if(eaten % rule.brickSpd == 0)
            {
                rule.addBrick(rule.getType());
            }

            if(eaten % 3 == 0)
            {
                roar->play();
            }

        if (collidingItem->data(DATA) == WALL || collidingItem->data(DATA) == BRICK )
        {
            rule.gameOver();
        }
    }

    if(tail.contains(head))
    {
        rule.gameOver();
    }
}

void Snake::reset()
{
    eaten = 0;

    if(moveDir != STOP)
    {
        int tempGrowth = 0;
        foreach(QPointF dumpTail, tail)
        {
            tempGrowth++;
        }
        growth = tempGrowth;
        tail.clear();
        head.setX(0);
        head.setY(0);
        setPos(head);
        moveDir = STOP;
    }
}



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

    void reset();

    void setDir(Direction dir);
    void setSpd(int spd);

    void setType(int type);
    int getType();

    int eaten;
    QMediaPlayer * born;
    QMediaPlayer * death;

protected:
    void advance(int phase);

private:
    void moveUp();
    void moveDown();
    void moveLeft();
    void moveRight();
    void collidingEvent();

    QMediaPlayer * roar;
    QMediaPlayer * eat;

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

