#include "welcome.h"
#include "ui_welcome.h"
#include"mainwindow.h"
#include<QFrame>

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

    //ÉèÖÃ±³¾°
    QPixmap pixmap(":/map/re/Welcome.jpg");      //paletteµ÷É«°å
    QPalette palette;
    palette.setBrush(backgroundRole(),QBrush(pixmap));
    setPalette(palette);
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
