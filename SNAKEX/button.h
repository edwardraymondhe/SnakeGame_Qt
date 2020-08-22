#ifndef BUTTON_H
#define BUTTON_H

#include <QGraphicsRectItem>
#include <QGraphicsSceneMouseEvent>
#include <QGraphicsTextItem>
#include <QString>
#include <QBrush>
#include <QMediaPlayer>


class Button: public QObject, public QGraphicsRectItem{
    Q_OBJECT
public:
    // constructor
    Button(QString name, QGraphicsItem * parent = NULL);

    // public methods (events)
    void mousePressEvent(QGraphicsSceneMouseEvent *event);
    void hoverEnterEvent(QGraphicsSceneHoverEvent *event);
    void hoverLeaveEvent(QGraphicsSceneHoverEvent *event);

    QMediaPlayer *button;


signals:
    void clicked();

private:
    QGraphicsTextItem * text;
};


#endif // BUTTON_H
