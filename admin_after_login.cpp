#include "admin_after_login.h"
#include "ui_admin_after_login.h"
#include<building_customize_menu.h>
#include<QMessageBox>
#include<admin_after_login.h>
#include<renter_menu.h>
#include<mainwindow.h>
#include<QApplication>
#include<renter_search.h>
#include<transactions.h>
#include<tc.h>
#include<tolet.h>
#include<maintenance.h>
#include<admin_login.h>
#include<profile.h>
#include<about.h>
#include<notepad.h>
admin_after_login::admin_after_login(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::admin_after_login)
{
     hide();
    ui->setupUi(this);


    QSqlQuery qy(QSqlDatabase::database("myconnect"));
    QSqlQuery qy1(QSqlDatabase::database("myconnect"));
            qy.prepare("select * from building");
            qy.exec();
            if(qy.next())
            {
            ui->label_name->setText(qy.value(0).toString());
            QString welcome=qy.value(0).toString();
            if(welcome=="")
            {
                ui->label_name->setText("WELCOME");
            }
           }
            else
            {
                ui->label_name->setText("WELCOME");
            }
            qy1.prepare("SELECT * FROM LOGIN_TIME ORDER BY SERIAL DESC LIMIT 1");
            qy1.exec();
            if(qy1.next())
            {
            ui->label_username_2->setText(qy1.value(0).toString());

           }






}

admin_after_login::~admin_after_login()
{
    delete ui;
}


void admin_after_login::on_pushButton_buildin_clicked()
{
    hide();
     building_customize_menu bu;
     bu.setModal(true);
     bu.exec();
}
void admin_after_login::on_pushButton_CUSTOMIZE_clicked()
{
    hide();
    renter_menu ru;
    ru.setModal(true);
    ru.exec();
}



void admin_after_login::on_pushButton_RENTE_SEARCH_clicked()
{
     hide();
    renter_search re;
    re.setModal(true);
    re.exec();
}

void admin_after_login::on_pushButton_trans_clicked()
{
     hide();
    TRANSACTIONS t;
    t.setModal(true);
    t.exec();
}


void admin_after_login::on_pushButton_TC_clicked()
{
    hide();
    tc t;
    t.setModal(true);
    t.exec();
}


void admin_after_login::on_pushButton_TO_LET_clicked()
{
    hide();
    TOLET t;
    t.setModal(true);
    t.exec();
}


void admin_after_login::on_pushButton_MAINTENANCE_clicked()
{
    hide();
    MAINTENANCE m;
    m.setModal(true);
    m.exec();
}


void admin_after_login::on_pushButton_back_clicked()
{
    hide();
    admin_login a;
    a.setModal(true);
    a.exec();

}




void admin_after_login::on_pushButton_profile_clicked()
{
    hide();
    profile a;
    a.setModal(true);
    a.exec();
}


void admin_after_login::on_pushButton_profile_info_clicked()
{
    hide();
    profile a;
    a.setModal(true);
    a.exec();
}




void admin_after_login::on_pushButton_ABOUT_clicked()
{
    hide();
    ABOUT a;
    a.setModal(true);
    a.exec();
}


void admin_after_login::on_pushButton_NOTEPAD_clicked()
{
    hide();
    notepad a;
    a.setModal(true);
    a.exec();


}


void admin_after_login::on_pushButton_notepad_pic_clicked()
{
    hide();
    notepad a;
    a.setModal(true);
    a.exec();
}


void admin_after_login::on_pushButton_building_pic_clicked()
{
    hide();
     building_customize_menu bu;
     bu.setModal(true);
     bu.exec();
}


void admin_after_login::on_pushButton_customize_pic_clicked()
{
    hide();
    renter_menu ru;
    ru.setModal(true);
    ru.exec();
}


void admin_after_login::on_pushButton_search_pic_clicked()
{
    hide();
   renter_search re;
   re.setModal(true);
   re.exec();
}


void admin_after_login::on_pushButton_trans_pic_clicked()
{
    hide();
   TRANSACTIONS t;
   t.setModal(true);
   t.exec();
}


void admin_after_login::on_pushButton_maintenance_pic_clicked()
{
    hide();
    MAINTENANCE m;
    m.setModal(true);
    m.exec();
}

