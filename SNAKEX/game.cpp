#include "game.h"
#include "button.h"
#include "constants.h"
#include "food.h"
#include "normalfood.h"
#include "snake.h"

Game::Game(QWidget *parent) :
    QGraphicsView (parent),
    rules(rule)
    scene(new QGraphicsScene(this))
{

}

