#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QPainter>
#include<QTime>
#include<QObject>
#include<QMessageBox>
#include<iterator>
#include<math.h>
#include<QLabel>
#include<QDebug>
#include<qbitmap.h>
#include<QKeyEvent>


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    drawemap();

    setWindowTitle(tr("Plane Game"));

    ui->L_Score->setText("     0");
    ui->L_Request->setText("     1");
    ui->L_Life->setText("   5");

    /*将控件一开始隐藏，之后再显示*/
    ui->L_Life->setVisible(false);
    ui->L_Score->setVisible(false);
    ui->L_Request->setVisible(false);

    //使用定时器来更新画面
    timer = new QTimer;
    connect(timer,SIGNAL(timeout()),this,SLOT(scroll()));
    connect(timer,SIGNAL(timeout()),this,SLOT(hit_ene()));
    connect(timer,SIGNAL(timeout()),this,SLOT(hit_me()));

    timer->start(65);

}

MainWindow::~MainWindow()
{
    delete ui;
}



void MainWindow::drawemap()
{
    QPixmap pix(":/map/re/wallpaper1.jpeg");
    ui->label->resize(pix.size().width(),741);

    QPixmap dest=pix.scaled(ui->label->size(),Qt::KeepAspectRatioByExpanding);
    ui->label->setPixmap(dest);

}

void MainWindow::scroll()
{
    static int m = 0;
    if(m > 2000)
    {
        /*在这里将控件显示*/
        ui->L_Life->setVisible(true);
        ui->L_Score->setVisible(true);
        ui->L_Request->setVisible(true);
        return;
    }
    m+=5;
    ui->label->move(-m,0);
}

void MainWindow::paintEvent(QPaintEvent *event)
{
    if(myPlane1.islive)
    {
        //加入图片
        QString qs = ":/map/re/plane2.png";
        paint(myPlane1.loc.x,myPlane1.loc.y,qs,50,50,50,50);

        //子弹
        for (int i = 0;i <myPlane1.bullet_vector.size();i++)
        {
            bullet *bu = myPlane1.bullet_vector.at(i);
            if(bu->islive)
            {
                QString bs = ":/map/re/bullet.png";
                paint(bu->loc.x,bu->loc.y,bs,10,10,10,10);
            }else {
                myPlane1.bullet_vector.remove(i);
            }

        }
    }else {
    //绘制爆炸情景

    }

    //绘制敌人图片
    for (int j = 0;j < vector_enemy.size();j++)
    {
        Enemy *enemy = vector_enemy.at(j);
        getx = enemy->loc.x;
        gety = enemy->loc.y;
        if(enemy->islive)
        {
            //绘制敌人的图片
            QString ps = ":/map/re/enemy.png";
            paint(bu->loc.x,bu->loc.y,ps,50,50,50,50);
            //每一个敌人的子弹
            for (int t = 0;t < enemy->bullet_vector.size();t++)
            {
                bull = enemy->bullet_vector.at(t);
                if(bull->islive)
                {
                    //绘制子弹的图片
                    QString bs = ":/map/re/bullet.png";
                    paint(bu->loc.x,bu->loc.y,bs,10,10,10,10);
                }else
                {
                    enemy->bullet_vector.remove(t);
                }
            }
        }else
        {
            //绘制敌人被击毁

            vector_enemy.remove(j);
        }

    }
}

//键盘响应事件
void MainWindow::keyPressEvent(QKeyEvent *event)
{
    if(event->key() == Qt::Key_W)
    {
        myPlane1.dir = up;
        myPlane1.move();
    }
    if(event->key() == Qt::Key_S)
    {
        myPlane1.dir = down;
        myPlane1.move();
    }
    if(event->key() == Qt::Key_A)
    {
        myPlane1.dir = l;
        myPlane1.move();
    }
    if(event->key() == Qt::Key_D)
    {
        myPlane1.dir = r;
        myPlane1.move();
    }
    this->repaint();
}

void MainWindow::paint(int x, int y, QString a, int target_x, int target_y, int sourse_x, int sourse_y)
{
    //这里是你创建的线程的那个子弹 而不能用  子弹类的坐标
    QRectF target(x,y,target_x,target_y);
    QRectF source(0,0,sourse_x,sourse_y);
    QImage image(a);

    QPainter painter(this);
    painter.drawImage(target,image,source);

}

void MainWindow::hit_ene()
{
    for (int i = 0;i < myPlane1.bullet_vector.size();i++)
    {
        bu = myPlane1.bullet_vector.at(i);
        if(bu->islive)
        {
            for (int j = 0;j < vector_enemy.size();j ++)
            {
                Enemy *ene = vector_enemy.at(j);
                if(ene->islive)
                {
                    if(abs(bu->loc.x - ene->loc.x) <= 50 || abs(bu->loc.y - ene->loc.y) <= 50)
                    {
                        bu->islive = ene->islive = false;
                        //积分面板数值加1
                        vector_enemy.remove(j);
                        myPlane1.bullet_vector.remove(i);
                    }
                }
            }
        }
    }
}

void MainWindow::hit_me()
{
    for (int i = 0;i < vector_enemy.size();i++)
    {
        Enemy *ene = vector_enemy.at(i);
        if(ene->islive)
        {
            for(int j = 0;j < ene->bullet_vector.size();j++)
            {
                bull = ene->bullet_vector.at(j);
                if(bu->islive)
                {
                    if(abs(bu->loc.x - ene->loc.x) <= 50 || abs(bu->loc.y - ene->loc.y))
                    {
                        bu->islive = ene->islive = false;

                        gameover();
                    }
                }
            }
        }
    }
}

void MainWindow::hit()
{
    if(!myPlane1.islive)
        return;
    for (int i = 0;i < vector_enemy.size();i++)
    {
        Enemy *ene = vector_enemy.at(i);
        if(ene->islive)
        {
            if(abs(ene->loc.x - myPlane1.loc.x) <= 100 || abs(ene->loc.y - myPlane1.loc.y) <= 100)
                gameover();
        }
    }
}

void MainWindow::gameover()
{
    if(!myPlane1.islive)
    {
        //myPlane爆炸的画面

        //清除画面，然后出现"菜"
        //将控件隐藏
        ui->L_Life->setVisible(false);
        ui->L_Score->setVisible(false);
        ui->L_Request->setVisible(false);

    }
}
