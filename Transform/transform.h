#ifndef TRANSFORM_H
#define TRANSFORM_H

#include <QMainWindow>

namespace Ui {
class Transform;
}

class Transform : public QMainWindow
{
    Q_OBJECT
    int V,Sx,Sy,Tx,Ty,i,flag,angle,height,width;
    float rot[3][3],scal_mat[3][3],coor[10][3],coor2[10][3];
public:
    explicit Transform(QWidget *parent = 0);
    ~Transform();
    void paintEvent(QPaintEvent *);

protected :
    void draw(float[][3]);
    void scale();
    void translate();
    void rotate();
    void draw_quadrant();
private slots:
    void on_Next_clicked();

    void on_Draw_clicked();

    void on_reset_clicked();

    void on_Scale_clicked();

    void on_translate_clicked();

    void on_Rotate_clicked();

private:
    Ui::Transform *ui;
};

#endif // TRANSFORM_H
