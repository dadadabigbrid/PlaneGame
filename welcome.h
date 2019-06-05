#ifndef WELCOME_H
#define WELCOME_H

#include <QMainWindow>

namespace Ui {
class WELCOME;
}

class WELCOME : public QMainWindow
{
    Q_OBJECT

public:
    explicit WELCOME(QWidget *parent = nullptr);
    ~WELCOME();

    //TODO
    //第二次打开时将“开始游戏”变为“再来一次”

private slots:
    void on_btn_start_clicked();

    void on_btn_exit_clicked();

private:
    Ui::WELCOME *ui;
};

#endif // WELCOME_H
