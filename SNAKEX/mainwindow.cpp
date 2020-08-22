



#include <QGraphicsView>
#include <QMediaPlayer>
#include <QGraphicsPixmapItem>
#include <QThread>
#include "mainwindow.h"
#include "constants.h"
#include "button.h"
#include "rules.h"
#include "mainwindow.h"


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent),
      scene(new QGraphicsScene(this)),
      view(new QGraphicsView(scene, this)),
      rule(new Rules(*scene, this))
{
    // ***********STARTUP MUSIC
    QMediaPlayer * bgMusic = new QMediaPlayer();
    bgMusic->setMedia(QUrl("qrc:/music/bgm.mp3"));
    bgMusic->setVolume(10);
    bgMusic->play();

    // set up the sceen
    setCentralWidget(view);
    resize(600, 600);

    //set up the scene
    scene->setSceneRect(-100, -100, 200, 200);

    mainMBGDisplay();
    displayMainMenu();

    QTimer::singleShot(0, this, SLOT(adjustViewSize()));

}

MainWindow::~MainWindow()
{
}


void MainWindow::mainMBGDisplay()
{
    QPixmap pixel(SIZE, SIZE);
    pixel.fill(Qt::black);
    scene->setBackgroundBrush(QBrush(pixel));
}

void MainWindow::adjustViewSize()
{
    view->fitInView(scene->sceneRect(), Qt::KeepAspectRatioByExpanding);
}



void MainWindow::displayMainMenu()
{
    // ***********TITLE TEXT
    QGraphicsTextItem * titleText = new QGraphicsTextItem(QString("SNAKE-X"));
    titleText->setDefaultTextColor(Qt::darkRed);
    QFont titleFont("Times", 15);
    titleText->setFont(titleFont);
    int x1Pos = -titleText->boundingRect().width()/2;
    int y1Pos = -titleText->boundingRect().height() * 2;
    titleText->setPos(x1Pos, y1Pos);
    scene->addItem(titleText);

    Button * fMButton = new Button(QString("PLAY"));
    int x2Pos = -fMButton->boundingRect().width()/2;
    int y2Pos = titleText->boundingRect().height();
    fMButton->setPos(x2Pos, y2Pos);
    connect(fMButton, SIGNAL(clicked()), this, SLOT(pickMode()));
    scene->addItem(fMButton);

    Button * quitButton = new Button(QString("QUIT"));
    int qxPos = -quitButton->boundingRect().width()/2;
    int qyPos = fMButton->y() + quitButton->boundingRect().height() * 2;
    quitButton->setPos(qxPos, qyPos);
    connect(quitButton, SIGNAL(clicked()), this, SLOT(quit()));
    scene->addItem(quitButton);

}

// ***********SECOND LEVEL MENU:::PICK MODE
void MainWindow::pickMode()
{
    scene->clear();

    QGraphicsTextItem * titleText = new QGraphicsTextItem(QString("PICK YOUR MODE"));
    titleText->setDefaultTextColor(Qt::darkRed);
    QFont titleFont("Times", 15);
    titleText->setFont(titleFont);
    int x1Pos = -titleText->boundingRect().width()/2;
    int y1Pos = -titleText->boundingRect().height()*2;
    titleText->setPos(x1Pos, y1Pos);
    scene->addItem(titleText);

    Button * rankButton = new Button(QString("RANKING"));
    int x2Pos = -rankButton->boundingRect().width()/2;
    int y2Pos = titleText->boundingRect().height();
    rankButton->setPos(x2Pos, y2Pos);
    connect(rankButton, SIGNAL(clicked()), this, SLOT(pickTheme()));
    scene->addItem(rankButton);

    Button * arcButton = new Button(QString("ARCADE"));
    int qxPos = -arcButton->boundingRect().width()/2;
    int qyPos = rankButton->y() + arcButton->boundingRect().height() * 2;
    arcButton->setPos(qxPos, qyPos);
    connect(arcButton, SIGNAL(clicked()), this, SLOT(pickRound()));
    scene->addItem(arcButton);

}



// ***********THIRD LEVEL MENU-1:::PICKTHEME
void MainWindow::pickTheme()
{
    scene->clear();

    QGraphicsTextItem * titleText = new QGraphicsTextItem(QString("PICK YOUR THEME"));
    titleText->setDefaultTextColor(Qt::darkRed);
    QFont titleFont("Times", 15);
    titleText->setFont(titleFont);
    int xtPos = -titleText->boundingRect().width()/2;
    int ytPos = -titleText->boundingRect().height()*2;
    titleText->setPos(xtPos, ytPos);
    scene->addItem(titleText);

    Button * theme1 = new Button(QString("THEME 1"));
    int x1Pos = -theme1->boundingRect().width() - 10 ;
    int y1Pos = -theme1->boundingRect().height();
    theme1->setPos(x1Pos, y1Pos);
    connect(theme1, SIGNAL(clicked()), this, SLOT(rank1()));//*******************
    scene->addItem(theme1);

    Button * theme3 = new Button(QString("THEME 3"));
    int x3Pos = x1Pos;
    int y3Pos = y1Pos + theme3->boundingRect().height() * 2;
    theme3->setPos(x3Pos, y3Pos);
    connect(theme3, SIGNAL(clicked()), this, SLOT(rank3()));//*******************
    scene->addItem(theme3);

    Button * theme2 = new Button(QString("THEME 2"));
    int x2Pos = 10;
    int y2Pos = y1Pos;
    theme2->setPos(x2Pos, y2Pos);
    connect(theme2, SIGNAL(clicked()), this, SLOT(rank2()));//*******************
    scene->addItem(theme2);

    Button * theme4 = new Button(QString("THEME 4"));
    int x4Pos = 10;
    int y4Pos = y3Pos;
    theme4->setPos(x4Pos, y4Pos);
    connect(theme4, SIGNAL(clicked()), this, SLOT(rank4()));//*******************
    scene->addItem(theme4);

}

void MainWindow::rank1()
{
    rule->mode = 1;
    rule->setMap(1);
    playMenu();
}

void MainWindow::rank2()
{
    rule->mode = 1;
    rule->setMap(2);
    playMenu();
}

void MainWindow::rank3()
{
    rule->mode = 1;
    rule->setMap(3);
    playMenu();
}

void MainWindow::rank4()
{
    rule->mode = 1;
    rule->setMap(4);
    playMenu();
}



// ***********THIRD LEVEL MENU-1:::PICKROUNDS → DECIDES MAPS RANDOMLY
void MainWindow::pickRound()
{
    scene->clear();

    QGraphicsTextItem * titleText = new QGraphicsTextItem(QString("PICK YOUR ROUNDS"));
    titleText->setDefaultTextColor(Qt::darkRed);
    QFont titleFont("Times", 15);
    titleText->setFont(titleFont);
    int xtPos = -titleText->boundingRect().width()/2;
    int ytPos = -titleText->boundingRect().height()*2;
    titleText->setPos(xtPos, ytPos);
    scene->addItem(titleText);

    Button * round1 = new Button(QString("Ⅰ"));
    int x1Pos = -round1->boundingRect().width() - 10 ;
    int y1Pos = -round1->boundingRect().height();
    round1->setPos(x1Pos, y1Pos);
    connect(round1, SIGNAL(clicked()), this, SLOT(round1()));//*******************
    scene->addItem(round1);



    Button * round3 = new Button(QString("Ⅲ"));
    int x3Pos = x1Pos;
    int y3Pos = y1Pos + round3->boundingRect().height() * 2;
    round3->setPos(x3Pos, y3Pos);
    connect(round3, SIGNAL(clicked()), this, SLOT(round3()));//*******************
    scene->addItem(round3);


    Button * round2 = new Button(QString("Ⅱ"));
    int x2Pos = 10;
    int y2Pos = y1Pos;
    round2->setPos(x2Pos, y2Pos);
    connect(round2, SIGNAL(clicked()), this, SLOT(round2()));//*******************
    scene->addItem(round2);



    Button * round4 = new Button(QString("Ⅳ"));
    int x4Pos = 10;
    int y4Pos = y3Pos;
    round4->setPos(x4Pos, y4Pos);
    connect(round4, SIGNAL(clicked()), this, SLOT(round4()));//*******************
    scene->addItem(round4);

}

void MainWindow::round1()
{
    rounds = 1;
    arcade();
}

void MainWindow::round2()
{
    rounds = 2;
    arcade();
}

void MainWindow::round3()
{
    rounds = 3;
    arcade();
}

void MainWindow::round4()
{
    rounds = 4;
    arcade();
}

void MainWindow::arcade()
{
    rule->mode = 2;
    rule->rounds = rounds;
    playMenu();
}



void MainWindow::playMenu()
{
    scene->clear();

    QGraphicsTextItem * titleText = new QGraphicsTextItem(QString("PICK YOUR MODE"));
    titleText->setDefaultTextColor(Qt::darkRed);
    QFont titleFont("Times", 15);
    titleText->setFont(titleFont);
    int x1Pos = -titleText->boundingRect().width()/2;
    int y1Pos = -titleText->boundingRect().height()*2;
    titleText->setPos(x1Pos, y1Pos);
    scene->addItem(titleText);

    Button * fMButton = new Button(QString("PLAY"));
    int x2Pos = -fMButton->boundingRect().width()/2;
    int y2Pos = titleText->boundingRect().height();
    fMButton->setPos(x2Pos, y2Pos);
    connect(fMButton, SIGNAL(clicked()), this, SLOT(start()));
    scene->addItem(fMButton);
}



void MainWindow::start()
{
    rule->start();
}

void MainWindow::quit()
{
    rule->pause();
}
