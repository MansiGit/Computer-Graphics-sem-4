#ifndef CIRCTRI_H
#define CIRCTRI_H

#include <QMainWindow>

namespace Ui {
class circtri;
}

class circtri : public QMainWindow
{
    Q_OBJECT

public:
    explicit circtri(QWidget *parent = 0);
    ~circtri();
    int flag;
    void plot(int,int,int,int);
    void plot(int,int);
    void accept();
    void drawCircle(int,int,int);
    void draw(float,float,float,float);
protected:
    void changeEvent(QEvent *e);
    void paintEvent(QPaintEvent *);

private slots:
    void on_pushButton_clicked();

private:
    Ui::circtri *ui;
};

#endif // CIRCTRI_H
