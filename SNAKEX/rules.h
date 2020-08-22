#ifndef RULES_H
#define RULES_H

#include <QObject>
#include <QTimer>
#include <QGraphicsScene>
#include <QMediaPlayer>


class QGraphicsScene;
class QKeyEvent;

class Snake;
class Food;
class Wall;
class Brick;

class Rules : public QObject
{
    Q_OBJECT
public:
    Rules(QGraphicsScene &scene, QObject *parent);

    int eatFood(Snake * snake, Food *food);
    void hitSelf(Snake * snake);
    void hitWall();

    int mode;
    int rounds;

    void gameOver();
    void start();

    int currLv = 0;
    int arrMap[4] = {1, 2, 3, 4};

    void reset(int arcadeMode, int arcadeMap);
    void arcade();
    QMediaPlayer * born;

    void ranking();

    void setMap(int m);
    int getType();

    int brickSpd;
    void addBrick(int type);
    void addFood();
    void addWall();

    int mapType;
    bool added = false;
public slots:
    void resume();
    void pause();


protected:
    bool eventFilter(QObject *object, QEvent *event);


private:
    QGraphicsScene &scene;

    QTimer timer;

    Snake * snake;

    Wall * wall;

    QList<QRectF> brickList;



    void keyPressEvent(QKeyEvent *event);

};

#endif // RULES_H



#ifndef RULES_H
#define RULES_H

#include <QObject>
#include <QTimer>
#include <QGraphicsScene>
#include <QMediaPlayer>

class QGraphicsScene;
class QKeyEvent;

class Snake;
class Food;
class Wall;
class Brick;

class Rules : public QObject
{
    Q_OBJECT
public:
    Rules(QGraphicsScene &scene, QObject *parent);

    int mode;
    void start();
    void gameOver();

    void arcade();
    void reset(int arcadeMode, int arcadeMap);
    int rounds;
    int currLv = 0;
    int arrMap[4] = {1, 2, 3, 4};

    void ranking();

    int mapType;
    void setMap(int m);
    int getType();

    int brickSpd;
    void addBrick(int type);
    void addWall();
    void addFood();

    int eatFood(Snake * snake, Food *food);
    void hitSelf(Snake * snake);
    void hitWall();


public slots:
    void resume();
    void pause();


protected:
    bool eventFilter(QObject *object, QEvent *event);


private:
    QGraphicsScene &scene;

    QTimer timer;

    Snake * snake;

    Wall * wall;

    QList<QRectF> brickList;

    void keyPressEvent(QKeyEvent *event);

};

#endif // RULES_H
