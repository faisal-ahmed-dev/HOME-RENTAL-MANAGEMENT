#include<admin_login.h>
#include <QApplication>
#include<QSql>
#include<QSqlQuery>
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    admin_login w;
    QSqlDatabase db= QSqlDatabase::addDatabase("QSQLITE");
   db.setDatabaseName("HOME.sqlite");
 db.open();
    a.setWindowIcon(QIcon(":/resources/resources/house_rental_icon.ico"));
    w.show();
    return a.exec();
}
