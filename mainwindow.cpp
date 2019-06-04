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

    /*���ؼ�һ��ʼ���أ�֮������ʾ*/
    ui->L_Life->setVisible(false);
    ui->L_Score->setVisible(false);
    ui->L_Request->setVisible(false);

    //ʹ�ö�ʱ�������»���
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
        /*�����ｫ�ؼ���ʾ*/
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
        //����ͼƬ
        QString qs = ":/map/re/plane2.png";
        paint(myPlane1.loc.x,myPlane1.loc.y,qs,50,50,50,50);

        //�ӵ�
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
    //���Ʊ�ը�龰

    }

    //���Ƶ���ͼƬ
    for (int j = 0;j < vector_enemy.size();j++)
    {
        Enemy *enemy = vector_enemy.at(j);
        getx = enemy->loc.x;
        gety = enemy->loc.y;
        if(enemy->islive)
        {
            //���Ƶ��˵�ͼƬ
            QString ps = ":/map/re/enemy.png";
            paint(bu->loc.x,bu->loc.y,ps,50,50,50,50);
            //ÿһ�����˵��ӵ�
            for (int t = 0;t < enemy->bullet_vector.size();t++)
            {
                bull = enemy->bullet_vector.at(t);
                if(bull->islive)
                {
                    //�����ӵ���ͼƬ
                    QString bs = ":/map/re/bullet.png";
                    paint(bu->loc.x,bu->loc.y,bs,10,10,10,10);
                }else
                {
                    enemy->bullet_vector.remove(t);
                }
            }
        }else
        {
            //���Ƶ��˱�����

            vector_enemy.remove(j);
        }

    }
}

//������Ӧ�¼�
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
    //�������㴴�����̵߳��Ǹ��ӵ� ��������  �ӵ��������
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
                        //���������ֵ��1
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
        //myPlane��ը�Ļ���

        //������棬Ȼ�����"��"
        //���ؼ�����
        ui->L_Life->setVisible(false);
        ui->L_Score->setVisible(false);
        ui->L_Request->setVisible(false);

    }
}
