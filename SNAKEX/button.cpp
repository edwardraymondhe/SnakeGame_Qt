#include "button.h"
#include "game.h"

Button::Button(QString name, QGraphicsItem *parent): QGraphicsRectItem (parent)
{
    //draw the rect
    setRect(0, 0, 60, 15);
    QBrush brush;
    brush.setStyle(Qt::SolidPattern);
    brush.setColor(Qt::darkRed);
    setBrush(brush);

    // draw the text
    text = new QGraphicsTextItem(name, this);
    int xPos = rect().width()/2 - text->boundingRect().width()/2;
    int yPos = rect().height()/2 - text->boundingRect().height()/2;
    text->setPos(xPos, yPos);

    // allow responding to hover events
    setAcceptHoverEvents(true);

    button = new QMediaPlayer();
    button->setMedia(QUrl("qrc:/music/button.mp3"));
}

void Button::mousePressEvent(QGraphicsSceneMouseEvent *event){
    if(button->state() == QMediaPlayer::PlayingState)
    {
        button->setPosition(0);
    } else if(button->state() == QMediaPlayer::StoppedState)
    {
        button->play();
    }
    emit clicked();
}

void Button::hoverEnterEvent(QGraphicsSceneHoverEvent *event){
    if(button->state() == QMediaPlayer::PlayingState)
    {
        button->setPosition(0);
    } else if(button->state() == QMediaPlayer::StoppedState)
    {
        button->play();
    }
    QBrush brush;
    brush.setStyle(Qt::SolidPattern);
    brush.setColor(Qt::red);
    setBrush(brush);

}

void Button::hoverLeaveEvent(QGraphicsSceneHoverEvent *event){
    QBrush brush;
    brush.setStyle(Qt::SolidPattern);
    brush.setColor(Qt::darkRed);
    setBrush(brush);

}

