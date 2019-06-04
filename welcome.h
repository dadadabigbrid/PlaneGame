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

private slots:
    void on_btn_start_clicked();

    void on_btn_exit_clicked();

private:
    Ui::WELCOME *ui;
};

#endif // WELCOME_H
