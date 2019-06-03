#include "transform.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Transform w;
    w.show();

    return a.exec();
}
