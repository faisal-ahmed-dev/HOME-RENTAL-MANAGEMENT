#ifndef SIGNUP_FORM_H
#define SIGNUP_FORM_H

#include <QDialog>

namespace Ui {
class signup_form;
}

class signup_form : public QDialog
{
    Q_OBJECT
public:
     bool accept= false;
public:
    explicit signup_form(QWidget *parent = nullptr);
    ~signup_form();

private slots:
    void on_pushButton_SIGNUP_clicked();

    void show();

    void on_pushButton_back_clicked();



    void on_pushButton_eye_pressed();

    void on_pushButton_eye_released();

private:
    Ui::signup_form *ui;
};

#endif // SIGNUP_FORM_H
