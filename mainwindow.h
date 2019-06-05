#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include<QTimer>
#include<QVector>
#include<time.h>
#include"define.h"
#include"bullet.h"
#include"myplane.h"
#include"enemy.h"
#include"welcome.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

    QTimer *timer;
    QTimer *timer1;
    MyPlane myPlane1;
    bullet *bu;
    bullet *bull;

    Enemy enemy1;
    QVector<Enemy*> vector_enemy;

    int getx,gety;   //炸弹的绘制
    int x1,y1;
    int akg,kg;
    QString LS;     //得分控制
    int LS_int;
    QString LF;     //坦克生命控制
    int LF_int;

private:
    Ui::MainWindow *ui;
    int x = 0;

    void keyPressEvent(QKeyEvent *event);          //键盘响应函数
    void paintEvent(QPaintEvent *event);           //绘图函数
    void paint(int x, int y, QString a, int target_x, int target_y, int sourse_x, int sourse_y);
    void gameover();
    void hited();       //飞机被击中
    void getscore();    //得分

    int life;
    int score;

    int temp = 0;

protected:
    void drawemap();        //绘制背景

private slots:
    void scroll();

public slots:
    void hit_ene();     //判断敌人是否被击中
    void hit_me();      //判断自己是否被击中
    void hit();         //飞机之间的碰撞

    void I_am_running();

};

#endif // MAINWINDOW_H
