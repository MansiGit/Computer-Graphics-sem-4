#ifndef DRAWPOLY_H
#define DRAWPOLY_H

#include <QMainWindow>
#include "QtGui"
#include "QtCore"
#include "QMouseEvent"

namespace Ui {
class drawpoly;
}

class drawpoly : public QMainWindow
{
    Q_OBJECT

public:
    explicit drawpoly(QWidget *parent = 0);
    ~drawpoly();
    int flag,x[15],y[15],i,n;

private:
    Ui::drawpoly *ui;
protected:
    void paintEvent(QPaintEvent *);
    void mousePressEvent(QMouseEvent *);
    void draw();
    void fill();
    void sort(int arr[], int l);
private slots:
    void on_pushButton_clicked();
    void on_pushButton_2_clicked();
    void on_pushButton_3_clicked();
};

#endif // DRAWPOLY_H
