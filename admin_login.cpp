#include "admin_login.h"
#include "qsqlquery.h"
#include "ui_admin_login.h"
#include<QMessageBox>
#include<QSql>
#include<QSqlDatabase>
#include<admin_after_login.h>
#include<signup_form.h>
#include<QDateTime>
#include<QPalette>
admin_login::admin_login(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::admin_login)
{
    hide();
    ui->setupUi(this);


}
admin_login::~admin_login()
{
    delete ui;
}

void admin_login::on_pushButton_LOGIN_clicked()
{
    QSqlDatabase db= QSqlDatabase::addDatabase("QSQLITE","myconnect");
  db.setDatabaseName("HOME.sqlite");
    QString username= ui->lineEdit_username->text();
    QString password= ui->lineEdit_2->text();

    QSqlQuery query(QSqlDatabase::database("myconnect"));
    QSqlQuery query1(QSqlDatabase::database("myconnect"));
    query.prepare(QString("select * from login where user= :username and pass =:password "));
    query.bindValue(":username",username);
    query.bindValue(":password",password);
    if(!query.exec())
    {
         QMessageBox::warning(0,"Login Form","UNSUCCESSFULL IN QUERY");
    }
    else
    {
       if(query.next())
        {
           QDateTime dateTime = dateTime.currentDateTime();
           QString astime=dateTime.toString("HH:mm:ss");
           QString asdate=dateTime.toString("dd/MM/yyyy");
           query1.prepare("insert into LOGIN_TIME(USER,TIME,DATE)""values(:user,:time,:date)");
           query1.bindValue(":user",username);
           query1.bindValue(":time",astime);
           query1.bindValue(":date",asdate);
           query1.exec();
            hide();
                admin_after_login af;
                af.setModal(true);
                af.exec();
        }
       else{
            QMessageBox msg;

         msg.warning(0,"Login Form","USERNAME OR PASSWORD DOESN'T MATCHED");
       }
    }

}


void admin_login::on_pushButton_SIGNUP_clicked()
{
    hide();
    signup_form af;
    af.setModal(true);
    af.exec();
}


void admin_login::on_pushButton_eye_pressed()
{
    ui->pushButton_eye->setStyleSheet("#pushButton_eye {image: url(:/resources/resources/8666618_eye_icon.png);border:none; background:#E5CB94;  color:#0F1628;border-radius:16px; border: 2px solid blue ; border-color: #0F1628; border-radius: 8px;   padding: 2px;  } #pushButton_eye:hover  {border:none;background:floral white;color:#0F1628;border-radius:16px;border: 2px solid blue ;border-color: #0F1628;border-radius: 8px;padding: 2px;     }");
   ui->lineEdit_2->setEchoMode(QLineEdit::Normal);

}


void admin_login::on_pushButton_eye_released()
{
    ui->pushButton_eye->setStyleSheet("#pushButton_eye {image: url(:/resources/resources/8666649_eye_off_icon.png);border:none; background:#E5CB94;  color:#0F1628;border-radius:16px; border: 2px solid blue ; border-color: #0F1628; border-radius: 8px;   padding: 2px;  } #pushButton_eye:hover  {border:none;background:floral white;color:#0F1628;border-radius:16px;border: 2px solid blue ;border-color: #0F1628;border-radius: 8px;padding: 2px;     }");
    ui->lineEdit_2->setEchoMode(QLineEdit::Password);
}

