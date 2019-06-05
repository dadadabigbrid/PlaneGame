#include "welcome.h"
#include "ui_welcome.h"
#include"mainwindow.h"
#include<QFrame>
#include<QSize>
#include<QPixmap>

WELCOME::WELCOME(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::WELCOME)
{
    ui->setupUi(this);

    setWindowTitle(tr("Welcome"));

    /*QFrame *frame = new QFrame;
     frame->setObjectName("myframe");
     frame->resize(400,700);
     frame->setStyleSheet("QFrame#myframe{border-image:url(:/map/re/Welcome.jpg)}" );
     frame->show();*/

    //设置背景
    QPixmap pixmap(":/map/re/Welcome.jpg");      //palette调色板
    QPalette palette;
    palette.setBrush(backgroundRole(),QBrush(pixmap));
    setPalette(palette);

    //为按钮添加图片
    QSize size;
    size.setWidth(300);
    size.setHeight(100);

    QPixmap start(tr(":/map/re/start_game.png"));
    ui->btn_start->setIcon(start);
    ui->btn_start->setIconSize(size);

    QPixmap help(tr(":/map/re/help.png"));
    ui->pushButton->setIcon(help);
    ui->pushButton->setIconSize(size);

    QPixmap exit(tr(":/map/re/exit.png"));
    ui->btn_exit->setIcon(exit);
    ui->btn_exit->setIconSize(size);
}

WELCOME::~WELCOME()
{
    delete ui;
}

void WELCOME::on_btn_start_clicked()
{
    MainWindow *w = new MainWindow;
    w->show();

    hide();
}

void WELCOME::on_btn_exit_clicked()
{
    close();
}
