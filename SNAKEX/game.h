#ifndef GAME_H
#define GAME_H


#include <QTimer>
#include <QGraphicsView>

#include "food.h"
#include "snakE.h"
#include "button.h"
#include "rules.h"

class Game: public QGraphicsView{
    Q_OBJECT
public:
    // constructor
    Game(QWidget * parent=NULL);

    void displayMainMenu();
    void playInterface();
    void quit();
    void gameOver();

    QTimer timer;
    Snake *snake;

public slots:
    void start();
    void resume();

};

#endif // GAME_H
