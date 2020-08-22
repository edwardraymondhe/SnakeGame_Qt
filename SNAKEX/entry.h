#ifndef ENTRY_H
#define ENTRY_H

#include "obj.h"

class Entry : public Obj
{
public:
    Entry(qreal x, qreal y, int type);

    void paint(QPainter *painter, const QStyleOptionGraphicsItem *, QWidget *);
};

#endif // ENTRY_H
