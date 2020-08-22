#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QMediaPlayer>
#include <QTimer>

class QGraphicsScene;
class QGraphicsView;

class Rules;

class MainWindow : public QMainWindow
{
    Q_OBJECT
public:
    MainWindow(QWidget *parent = 0);

    ~MainWindow();

public slots:
    void rank1();
    void rank2();
    void rank3();
    void rank4();

    void round1();
    void round2();
    void round3();
    void round4();

    void start();
    void quit();
    void pickMode();
    void pickTheme();
    void pickRound();

    void arcade();

private slots:
    void adjustViewSize();

private:
    void displayMainMenu();
    void mainMBGDisplay();
    void playMenu();

    int rounds;

    QGraphicsScene * scene;
    QGraphicsView * view;

    Rules * rule;

    QTimer *timer;

};

#endif // MAINWINDOW_H



#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QMediaPlayer>
#include <QTimer>

class QGraphicsScene;
class QGraphicsView;

class Rules;

class MainWindow : public QMainWindow
{
    Q_OBJECT
public:
    MainWindow(QWidget *parent = 0);

    ~MainWindow();

public slots:
    // 调用Rules类的rule实例中的 rule->start()，来进行游戏模式的选择
    void start();
    // 退出游戏
    void quit();

    void mainMenu();

    // 选择模式：ARCADE或者RANKING，ARCADE对应pickRound()；RANKING对应pickTheme()
    void pickMode();
    void pickTheme();
    void pickRound();

    void arcade();


    // 玩家在RANKING模式中选择对应地图，1~4个槽对应设置4种不一样的地图
    void rankMap1();
    void rankMap2();
    void rankMap3();
    void rankMap4();

    // 玩家在ARCADE模式中选择回合数，1~4个槽对应1~4个回合
    void round1();
    void round2();
    void round3();
    void round4();

private slots:

    void adjustViewSize();


private:
    void displayMainMenu(); // 主菜单显示
    void mainMBGDisplay();  // 背景图案显示
    void playMenu();        // 模式选择菜单显示

    int rounds;             // 回合数

    Rules * rule;           // 游戏操作类

    QGraphicsScene * scene;
    QGraphicsView * view;
    QTimer *timer;
};

#endif // MAINWINDOW_H
