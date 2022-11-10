#include "admin_login.h"
#include "qsqlquery.h"
#include "ui_admin_login.h"
#include<QMessageBox>
#include<QSql>
#include<QSqlDatabase>
#include<admin_after_login.h>
#include<signup_form.h>
#include<QDateTime>
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
    db.setDatabaseName("C:/sqlitestudio/database/faisal_sql.sqlite");
    QString username= ui->lineEdit_username->text();
    QString password= ui->lineEdit_2->text();

    QSqlQuery query(QSqlDatabase::database("myconnect"));
    QSqlQuery query1(QSqlDatabase::database("myconnect"));
    query.prepare(QString("select * from login where user= :username and pass =:password "));
    query.bindValue(":username",username);
    query.bindValue(":password",password);
    if(!query.exec())
    {
         QMessageBox::warning(this,"Login Form","UNSUCCESSFULL IN QUERY");
    }
    else
    {
       if(query.next())
        {
           QDateTime dateTime = dateTime.currentDateTime();
           QString as=dateTime.toString("HH:mm:ss  dd/MM/yyyy");
           query1.prepare("insert into LOGIN_TIME(USER,TIME)""values(:user,:time)");
           query1.bindValue(":user",username);
           query1.bindValue(":time",as);
           query1.exec();
            hide();
                admin_after_login af;
                af.setModal(true);
                af.exec();
        }
       else{

            QMessageBox::warning(this,"Login Form","USERNAME OR PASSWORD DOESN'T MATCHED");

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

