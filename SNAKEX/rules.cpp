#include "rules.h"
#include "constants.h"

#include "food.h"
#include "normalfood.h"
#include "slowfood.h"
#include "fastfood.h"

#include "obj.h"
#include "brick.h"
#include "wall.h"

#include "snake.h"
#include <QKeyEvent>

#include <QThread>

#include <QDebug>

Rules::Rules(QGraphicsScene &scene,QObject *parent) :
    QObject (parent),
    scene(scene),
    snake(new Snake(*this)),
    wall(new Wall())
{
    srand(unsigned(time(NULL)));
    std::random_shuffle(arrMap, arrMap + 3);
}


void Rules::setMap(int m)
{
    mapType = m;
    switch (mapType)
    {
        case 1://dungeon
        {
            QPixmap pixg(":/images/dungG.PNG");
            QBrush brushGround(pixg);
            scene.setBackgroundBrush(brushGround);
            break;
        }
        case 2://ice
        {
            QPixmap pixg(":/images/snowG.PNG");
            QBrush brushGround(pixg);
            scene.setBackgroundBrush(brushGround);
            break;
        }
        case 3://forest
        {
            QPixmap pixg(":/images/foreG.PNG");
            QBrush brushGround(pixg);
            scene.setBackgroundBrush(brushGround);
            break;
        }
        case 4://dessert
        {
            QPixmap pixg(":/images/dessG.PNG");
            QBrush brushGround(pixg);
            scene.setBackgroundBrush(brushGround);
            break;
        }
    }
}

int Rules::getType()
{
    return mapType;
}



void Rules::start()
{
    if(mode == 1)
    {
        ranking();
    }else if(mode == 2)
    {
        arcade();
    }
}

// ARCADE
void Rules::arcade()
{
    currLv++;
    reset(currLv, arrMap[currLv-1]);
}

//
void Rules::reset(int arcadeMode, int arcadeMap)
{
    scene.clear();
    timer.start(1000/40);

    brickList.clear();

    mapType = arcadeMap;
    setMap(mapType);
    wall->setType(mapType);
    snake->setType(mapType);

    if(arcadeMode == 1)
    {
        scene.addItem(wall);
        scene.addItem(snake);
        Food *food = new normalFood(0 , -50);
        scene.addItem(food);
    }


    //snake->reset();
    //snake->born->play();
/*
    // WHAT THE ARCADES LOOK LIKE >>> ADDING MONSTERS OR BRICKS OR TERRAIN
    // NORMAL 1(NOTHING);  INITIAL TERRAIN (BLOCKS) & RANDOMIZED BLOCKS 2;  INITIAL TERRAIN AND BOSS 3;
    // REALIZE THE MODES HERE ↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓

    qDebug("entering switch choose arcadeMode");
    switch(arcadeMode)
    {
        case 1:
        {
            Food *food = new normalFood(0 , -50);
            scene.addItem(food);
            break;
        }
        case 2:*/
        {
        if(arcadeMode == 2){
            qDebug("entered second mode :case 2");
            //Food *food = new normalFood(0 , -50);
            //scene.addItem(food);
            int xTL = -60;
            int yTL = -50;
            while(xTL <= -20)
            {
                Brick *brick1 = new Brick(xTL, -60, mapType);
                scene.addItem(brick1);
                Brick *brick2 = new Brick(xTL, 50, mapType);
                scene.addItem(brick2);
                QRectF temp1(xTL, -60, SIZE, SIZE);
                QRectF temp2(xTL, 50, SIZE, SIZE);
                brickList << temp1;
                brickList << temp2;
                xTL+=SIZE;
            }
            xTL = 10;
            while(xTL <= 50)
            {
                Brick *brick1 = new Brick(xTL, -60, mapType);
                scene.addItem(brick1);
                Brick *brick2 = new Brick(xTL, 50, mapType);
                scene.addItem(brick2);
                QRectF temp1(xTL, -60, SIZE, SIZE);
                QRectF temp2(xTL, 50, SIZE, SIZE);
                brickList << temp1;
                brickList << temp2;
                xTL+=SIZE;
            }

            while(yTL <= -20)
            {
                Brick *brick1 = new Brick(-60, yTL, mapType);
                scene.addItem(brick1);
                Brick *brick2 = new Brick(50, yTL, mapType);
                scene.addItem(brick2);
                QRectF temp1(-60, yTL, SIZE, SIZE);
                QRectF temp2(50, yTL, SIZE, SIZE);
                brickList << temp1;
                brickList << temp2;
                yTL+=SIZE;
            }
            yTL = 10;
            while(yTL <= 50)
            {
                Brick *brick1 = new Brick(-60, yTL, mapType);
                scene.addItem(brick1);
                Brick *brick2 = new Brick(50, yTL, mapType);
                scene.addItem(brick2);
                QRectF temp1(-60, yTL, SIZE, SIZE);
                QRectF temp2(50, yTL, SIZE, SIZE);
                brickList << temp1;
                brickList << temp2;
                yTL+=SIZE;
            }
        }
/*
            break;
        }

    }
  */
    scene.installEventFilter(this);
    resume();
}
}
/*
void Rules::Arena()
{

}

void Rules::Duel()
{
    //adding the boss
    //boss has funcs: adding blocks; roar; changeColor
}

void Rules::entNextLv()
{

}

*/

// RANKING
void Rules::ranking()
{
    scene.clear();

    timer.start(1000/40);

    wall->setType(mapType);
    snake->setType(mapType);
    scene.addItem(wall);

    snake->born->play();

    scene.addItem(snake);

    Food *food = new normalFood(0, -50);
    scene.addItem(food);

    scene.installEventFilter(this);

    resume();
}



// FOOD
void Rules::addFood()
{
    srand(time(0));
    int t = rand()%10+1;

    int x, y;
    bool in = false;
    do {
        in = false;
        x = (int) (qrand() % 100) / 10;
        y = (int) (qrand() % 100) / 10;

        x *= 10;
        y *= 10;

        int a = rand()%10+1;
        int b = rand()%10+1;
        if(a % 2 == 1){x = 0 - x;}else{};
        if(b % 2 == 1){y = 0 - y;}else{};

        foreach(QRectF tp, brickList)
        {
            if(x == int(tp.x()) && y == int(tp.y()))
            {
                qDebug("yup");

                in = true;
                break;
            }
        }
    } while (snake->shape().contains(snake->mapFromScene(QPointF(x + 5, y + 5))) || x > 70 || x < -70 || y > 70 || y < -70 || in);

    if(4 <= t && t <= 7){
        Food *food = new slowFood(x, y);
        scene.addItem(food);
    }
    else if(1 <= t && t <= 3){
        Food *food = new normalFood(x, y);
        scene.addItem(food);
    }
    else if(8 <= t && t <= 10){
        Food *food = new fastFood(x, y);
        scene.addItem(food);
    };
}

int Rules::eatFood(Snake *, Food *food)
{
    int type = food->getType();
    //addFood();
    scene.removeItem(food);
    delete food;

    addFood();

    return type;
}



// BRICK
void Rules::addBrick(int type)
{
    int x, y;
    do{
        x = (int) (qrand() % 100) / 10;
        y = (int) (qrand() % 100) / 10;
        x *= 10;
        y *= 10;


        int a = rand()%10+1;
        int b = rand()%10+1;
        if(a % 2 == 1){x = 0 - x;}else{};
        if(b % 2 == 1){y = 0 - y;}else{};


    }while (snake->shape().contains(snake->mapFromScene(QPointF(x + 5, y + 5))) || x > 70 || x < -70 || y > 70 || y < -70);

    Brick *brick = new Brick(x, y, type);
    QRectF temp(x,y, SIZE, SIZE);
    brickList << temp;
    scene.addItem(brick);
}



// GAMING RULE CONTROL
void Rules::resume()
{
    connect(&timer, SIGNAL(timeout()),
            &scene, SLOT(advance()));
}

void Rules::pause()
{
    disconnect(&timer, SIGNAL(timeout()),
               &scene, SLOT(advance()));
}

void Rules::gameOver()
{
    snake->death->play();
    pause();
}




void Rules::keyPressEvent(QKeyEvent *event)
{
    switch(event->key()){
        case Qt::Key_Up:
            snake->setDir(Snake::UP);
            break;
        case Qt::Key_Down:
            snake->setDir(Snake::DOWN);
            break;
        case Qt::Key_Left:
            snake->setDir(Snake::LEFT);
            break;
        case Qt::Key_Right:
            snake->setDir(Snake::RIGHT);
            break;
        case Qt::Key_Escape:
            snake->setDir(Snake::STOP);
            // esc menu
            break;
    }
}

bool Rules::eventFilter(QObject *object, QEvent *event)
{
    if (event->type() == QEvent::KeyPress) {
        keyPressEvent((QKeyEvent *)event);
        return true;
    } else {
        return QObject::eventFilter(object, event);
    }
}
