#ifndef LINECLIPPING_H
#define LINECLIPPING_H

#include <QMainWindow>
#include<QPainter>
#include "QMouseEvent"

namespace Ui {
class lineclipping;
}

class lineclipping : public QMainWindow
{
    Q_OBJECT

public:
    int flag,x[2],y[2],i,n,x_max,y_max,x_min,y_min;
    // Defining region codes
    const int INSIDE = 0; // 0000
    const int LEFT = 1;   // 0001
    const int RIGHT = 2;  // 0010
    const int BOTTOM = 4; // 0100
    const int TOP = 8;    // 1000

    explicit lineclipping(QWidget *parent = 0);
    void mousePressEvent(QMouseEvent *);
    void paintEvent(QPaintEvent *);
    void clip ();
    int computeCode(double x, double y);
    void cohenSutherlandClip(double x1, double y1,
                             double x2, double y2);
    void draw(int,int,int,int);


    ~lineclipping();

private slots:
    void on_select_clicked();

    void on_draw_clicked();

    void on_clip_clicked();

    void on_ShowWindow_clicked();

private:
    Ui::lineclipping *ui;
};

#endif // LINECLIPPING_H
