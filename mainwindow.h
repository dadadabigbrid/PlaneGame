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

    int getx,gety;   //ը���Ļ���
    int x1,y1;
    int akg,kg;
    QString LS;     //�÷ֿ���
    int LS_int;
    QString LF;     //̹����������
    int LF_int;

private:
    Ui::MainWindow *ui;
    int x = 0;

    void keyPressEvent(QKeyEvent *event);          //������Ӧ����
    void paintEvent(QPaintEvent *event);           //��ͼ����
    void paint(int x, int y, QString a, int target_x, int target_y, int sourse_x, int sourse_y);
    void gameover();
    void hited();       //�ɻ�������
    void getscore();    //�÷�

    int life;
    int score;

    int temp = 0;

protected:
    void drawemap();        //���Ʊ���

private slots:
    void scroll();

public slots:
    void hit_ene();     //�жϵ����Ƿ񱻻���
    void hit_me();      //�ж��Լ��Ƿ񱻻���
    void hit();         //�ɻ�֮�����ײ

    void I_am_running();

};

#endif // MAINWINDOW_H
