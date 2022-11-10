#include "tc.h"
#include "ui_tc.h"
#include "renter_search.h"
#include "ui_renter_search.h"
#include "renter_menu.h"
#include "qsqlquery.h"
#include "qsqlquerymodel.h"
#include "ui_renter_menu.h"
#include<QSql>
#include<QSqlDatabase>
#include<renter_add.h>
#include<QMessageBox>
#include<admin_after_login.h>
#include<renter_edit.h>
#include<renter_delete.h>
tc::tc(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::tc)
{
    ui->setupUi(this);



}

tc::~tc()
{
    delete ui;
}

void tc::on_pushButton_back_clicked()
{
    hide();
    admin_after_login ad;
    ad.setModal(true);
    ad.exec();

}

