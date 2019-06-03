#ifndef LINE_TYPES_H
#define LINE_TYPES_H

#include <QMainWindow>
#include <QPainter>
namespace Ui {
class Line_types;
}

class Line_types : public QMainWindow
{
    Q_OBJECT
    int x1,y1,x2,y2,th;
public:
    int flag;
    explicit Line_types(QWidget *parent = 0);
    ~Line_types();
    void dashed (int ,int ,int ,int );
     void dashdot (int ,int ,int ,int );
    void dotted (int x1,int y1,int x2,int y2);
    void draw_bresen(int,int,int,int);
protected:
    void changeEvent(QEvent *e);
    void paintEvent(QPaintEvent *);
private slots:
    void on_dashed_clicked();

    void on_dotted_clicked();

    void on_dashdot_clicked();

    void on_solid_clicked();

    void on_thick_clicked();

    void make_invisible();

    void on_back_clicked();

private:
    Ui::Line_types *ui;
};

#endif // LINE_TYPES_H
