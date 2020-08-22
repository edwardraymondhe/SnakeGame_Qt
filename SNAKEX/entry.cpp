#include "entry.h"
#include "constants.h"

Entry::Entry(qreal x, qreal y, int type)
{
    this->setType(type);
    setData(DATA, ENTRY);
    setPos(x, y);
}



void Entry::paint(QPainter *painter, const QStyleOptionGraphicsItem *, QWidget *)
{
    painter->save();

    switch(getType())
    {
        case 1://dungeon
        {
            QPixmap pixb(":/images/dungB.png");
            QBrush brushEntry(pixb);
            painter->setBrush(brushEntry);
            painter->fillPath(shape(), brushEntry);
            break;
        }
        case 2://ice
        {
            QPixmap pixb(":/images/snowB.png");
            QBrush brushEntry(pixb);
            painter->setBrush(brushEntry);
            painter->fillPath(shape(), brushEntry);
            break;
        }
        case 3://forest
        {
            QPixmap pixb(":/images/foreB.png");
            QBrush brushEntry(pixb);
            painter->setBrush(brushEntry);
            painter->fillPath(shape(), brushEntry);
            break;
        }
        case 4://dessert
        {
            QPixmap pixb(":/images/dessB.png);
            QBrush brushEntry(pixb);
            painter->setBrush(brushEntry);
            painter->fillPath(shape(), brushEntry);
            break;
        }
    }

    painter->restore();
}
