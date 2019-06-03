#ifndef REFL_H
#define REFL_H

#include <QMainWindow>

#include<QPainter>
#include "QMouseEvent"
#include<QScreen>
namespace Ui {
class refl;
}

class refl : public QMainWindow
{
    Q_OBJECT

public:
    int height,width,flag,i,n,x[10],y[10],xr[10],yr[10];
    explicit refl(QWidget *parent = 0);
    ~refl();
    void paintEvent(QPaintEvent *event);
    void mousePressEvent(QMouseEvent *);
    void draw();
    void draw2();
    void draw3();
private slots:
    void on_Draw_clicked();

    void on_xrefl_clicked();

    void on_yrefl_clicked();

    void on_xyrefl_clicked();

    void on_Origin_clicked();

private:
    Ui::refl *ui;
};

#endif // REFL_H
