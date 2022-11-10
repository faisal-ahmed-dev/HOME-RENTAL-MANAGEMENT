#include "signup_form.h"
#include "qsqlquery.h"
#include "ui_signup_form.h"
#include<QSql>
#include<QSqlDatabase>
#include<QMessageBox>
#include<admin_mainmenu.h>
#include<admin_login.h>
#include<QTimer>
signup_form::signup_form(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::signup_form)
{
    ui->setupUi(this);

    QTimer *timer=new QTimer(this);
    connect(timer,SIGNAL(timeout()),this,SLOT(show()));
    timer->start();

}

signup_form::~signup_form()
{
    delete ui;
}

void signup_form::show()
{
    QString password= ui->lineEdit_2->text();

       int n = password.length();
if(n!=0)
{
       // Checking lower alphabet in string
       bool hasLower = false, hasUpper = false;
       bool hasDigit = false, specialChar = false;


       for (int i = 0; i < n; i++) {
           if ((password[i]).isLower())
               hasLower = true;
           if ((password[i]).isUpper())
               hasUpper = true;
           if ((password[i]).isNumber())
               hasDigit = true;
            if (!(password[i]).isLetter()&& !(password[i]).isNumber() )
                specialChar=true;
    }



       if((hasLower || hasUpper) && hasDigit &&specialChar && (n >= 12))
       {
              ui->label_strength->setText("VERY STRONG");
              QPalette palette = ui->label_strength->palette();
          accept=true;
              palette.setColor(ui->label_strength->foregroundRole(), Qt::darkGreen);
              ui->label_strength->setPalette(palette);

       }
       else if(hasDigit && (hasLower||hasUpper|| specialChar) && (n>=10))
       {
               ui->label_strength->setText("STRONG");
               QPalette palette = ui->label_strength->palette();
               accept=true;
               palette.setColor(ui->label_strength->foregroundRole(), Qt::darkGreen);
               ui->label_strength->setPalette(palette);

       }
        else if(((hasLower || hasUpper)&& hasDigit && (n >= 8))||n>=20)
           {
                    ui->label_strength->setText("MODERATE");
                       accept=true;
                     QPalette palette = ui->label_strength->palette();

                     palette.setColor(ui->label_strength->foregroundRole(), Qt::darkCyan);
                     ui->label_strength->setPalette(palette);

           }

           else
       {

           ui->label_strength->setText("WEAK");
           QPalette palette = ui->label_strength->palette();
           palette.setColor(ui->label_strength->foregroundRole(), Qt::red);
           ui->label_strength->setPalette(palette);

       }
}
else
{
    ui->label_strength->setText("");
}
}


void signup_form::on_pushButton_SIGNUP_clicked()
{
    QSqlDatabase db= QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName("C:/sqlitestudio/database/faisal_sql.sqlite");



    if(db.open())
    {

      QString username= ui->lineEdit_si_username->text().toLower();
      QString password= ui->lineEdit_2->text();
      QString confirm=ui->lineEdit_CONFIRM->text();

      if(password!=confirm)
      {
          accept=false;
           QMessageBox::warning(this,"SIGNUP","PASSWORD MISMATCHED");

      }
       else
      {

       if(accept==true)
        {
              QSqlQuery qy(QSqlDatabase::database("myconnect"));
              qy.prepare("insert into login(user,pass)""values(:username,:password)");
              qy.bindValue(":username",username);
              qy.bindValue(":password",password);

                 if(qy.exec())
                 {
                     QMessageBox::information(this,"SIGNUP","SIGNUP SUCCESSFULL");
                     hide();
                     admin_login ad;
                     ad.setModal(true);
                     ad.exec();

                  }
                  else
                  {
                   QMessageBox::warning(this,"SIGNUP","NOT INSERTED INTO DATABASE");
                   }
        }
     else
     {
        QMessageBox::warning(this,"SIGNUP","PASSWORD WEAK");
     }
      }
    }

}




void signup_form::on_pushButton_back_clicked()
{
    hide();
    admin_login ad;
    ad.setModal(true);
    ad.exec();
}





void signup_form::on_pushButton_eye_pressed()
{

    ui->pushButton_eye->setStyleSheet("image: url(:/resources/resources/vecteezy_preview-show-interface-icon_6086018.jpg);");
   ui->lineEdit_2->setEchoMode(QLineEdit::Normal);
    ui->lineEdit_CONFIRM->setEchoMode(QLineEdit::Normal);
}


void signup_form::on_pushButton_eye_released()
{
    ui->pushButton_eye->setStyleSheet("image: url(:/resources/resources/eye_off.jpg);");
    ui->lineEdit_2->setEchoMode(QLineEdit::Password);
     ui->lineEdit_CONFIRM->setEchoMode(QLineEdit::Password);
}

