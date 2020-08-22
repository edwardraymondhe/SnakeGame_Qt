#include "wall.h"
#include "constants.h"

Wall::Wall()
{
    setData(DATA, WALL);
}

QRectF Wall::boundingRect() const
{
    return QRectF(-100, -100, 200, 200);
}

QPainterPath Wall::shape() const
{
    QPainterPath wallPath;
    int width = 100;
    int height = 100;
    int w = width - SIZE;
    int h = height - 2 * SIZE;
    while(w >= -100)
    {
        wallPath.addRect(w + 0.1, -100 + 0.1, SIZE - 0.2, SIZE - 0.2);
        wallPath.addRect(w + 0.1, 100 - SIZE + 0.1, SIZE - 0.2, SIZE - 0.2);
        w -= SIZE;
    }
    while(h > -100)
    {
        wallPath.addRect(-100 + 0.1, h + 0.1, SIZE - 0.2, SIZE - 0.2);
        wallPath.addRect(100 - SIZE + 0.1, h + 0.1, SIZE - 0.2, SIZE - 0.2);
        h -= SIZE;
    }

    return wallPath;
}

void Wall::paint(QPainter *painter, const QStyleOptionGraphicsItem *, QWidget *)
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
