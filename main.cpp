#include<admin_login.h>
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    admin_login w;
    a.setWindowIcon(QIcon(":/resources/resources/house_rental_icon.ico"));
    w.show();
    return a.exec();
}
