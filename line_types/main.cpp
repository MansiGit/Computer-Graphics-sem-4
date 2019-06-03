#include "line_types.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Line_types w;
    w.show();

    return a.exec();
}
