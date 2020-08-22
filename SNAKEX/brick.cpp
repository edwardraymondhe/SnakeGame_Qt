#include "brick.h"
#include "constants.h"

Brick::Brick(qreal x, qreal y, int type)
{
    this->setType(type);
    setData(DATA, BRICK);
    setPos(x, y);
}



void Brick::paint(QPainter *painter, const QStyleOptionGraphicsItem *, QWidget *)
{
    painter->save();

    switch(getType())
    {
        case 1://dungeon
        {
            QPixmap pixb(":/images/dungB.png");
            QBrush brushBrick(pixb);
            painter->setBrush(brushBrick);
            painter->fillPath(shape(), brushBrick);
            break;
        }
        case 2://ice
        {
            QPixmap pixb(":/images/snowB.png");
            QBrush brushBrick(pixb);
            painter->setBrush(brushBrick);
            painter->fillPath(shape(), brushBrick);
            break;
        }
        case 3://forest
        {
            QPixmap pixb(":/images/foreB.png");
            QBrush brushBrick(pixb);
            painter->setBrush(brushBrick);
            painter->fillPath(shape(), brushBrick);
            break;
        }
        case 4://dessert
        {
            QPixmap pixb(":/images/dessB.png");
            QBrush brushBrick(pixb);
            painter->setBrush(brushBrick);
            painter->fillPath(shape(), brushBrick);
            break;
        }
    }

    painter->restore();
}
