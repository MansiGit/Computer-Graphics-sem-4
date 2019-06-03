#include "lineclipping.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    lineclipping w;
    w.show();

    return a.exec();
}
