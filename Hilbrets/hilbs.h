#ifndef HILBS_H
#define HILBS_H

#include <QMainWindow>
#include<QScreen>
namespace Ui {
class hilbs;
}

class hilbs : public QMainWindow
{
    Q_OBJECT
    int flag,p1,p2;
public:
    explicit hilbs(QWidget *parent = 0);
    ~hilbs();
    void paintEvent(QPaintEvent *event);
    void changeEvent(QEvent *e);
    void  move(int j, int h, int &x, int &y);
    void hilbert(int r, int d, int l, int u, int i, int h, int &x, int &y);
private slots:
    void on_Draw_clicked();

private:
    Ui::hilbs *ui;
};

#endif // HILBS_H
