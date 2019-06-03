#include "transform.h"
#include "ui_transform.h"
#include <QPainter>
#include<math.h>
#include<QScreen>
Transform::Transform(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Transform)
{
    ui->setupUi(this);
    i=0;
}

Transform::~Transform()
{
    delete ui;
}
void Transform::draw_quadrant()
{
  QPainter painter(this);
  int cnt,x,y;
  char buffer[2];

  QScreen *screen = QGuiApplication::primaryScreen();
  QRect  screenGeometry = screen->geometry();
  height = screenGeometry.height();//1360;//
  width = screenGeometry.width();
  painter.setPen(QPen(Qt::blue,2));

  painter.drawLine(0,height/2,width,height/2);
  painter.drawLine(width/2,0,width/2,height);
  painter.setPen(QPen(Qt::blue,2));

  x=40;y=height/2;

  for(cnt=-16;cnt<=16;cnt++)
      {
           painter.setPen(QPen(Qt::blue,2));

           sprintf(buffer,"%d",cnt);
           painter.drawText(x,y,buffer);
           painter.setPen(QPen(Qt::red,3));
           painter.drawPoint(x,y);
           x=x+40;
      }

  x=width/2;y=30;
  for(cnt=9;cnt>=-9;cnt--)
      {
          painter.setPen(QPen(Qt::blue,2));
           if(cnt!=0)
           {
            sprintf(buffer,"%d",cnt);
            painter.drawText(x,y,buffer);
            painter.setPen(QPen(Qt::red,3));
            painter.drawPoint(x,y);
           }
            y=y+40;
  }
}
void Transform :: paintEvent(QPaintEvent *event)
{
    V=ui->vert->toPlainText().toInt();
    draw_quadrant();
    if (flag==1)
          draw(coor);
    if (flag==2)
    {
        int l,m;
        for(l=0;l<3;l++)
                for(m=0;m<3;m++)
                    scal_mat[l][m]=0;
        Sx=ui->sx->toPlainText().toInt();
        Sy=ui->sy->toPlainText().toInt();
        scal_mat[0][0]=Sx;
        scal_mat[1][1]=Sy;
        scal_mat[2][2]=1;
        scale();
    }
    if (flag==3)
    {
        int l,m;
        for(l=0;l<3;l++)
                for(m=0;m<3;m++)
                    scal_mat[l][m]=0;
        Tx=ui->tx->toPlainText().toInt();
        Ty=ui->ty->toPlainText().toInt();
        scal_mat[0][0]=1;
        scal_mat[1][1]=1;
        scal_mat[2][0]=Tx;
        scal_mat[2][1]=Ty;
        scal_mat[2][2]=1;
        translate();
    }
    if(flag==4)
    {
        int l,m;
        for(l=0;l<3;l++)
                for(m=0;m<3;m++)
                    rot[l][m]=0;
        angle=ui->theta->toPlainText().toInt();
        rot[0][0]=cos(3.14*angle/180);
        rot[1][1]=cos(3.14*angle/180);
        rot[0][1]=-sin(3.14*angle/180);
        rot[2][1]=sin(3.14*angle/180);
        rot[2][2]=1;
        rotate();
    }
    if (flag==5)
    {   i=0;
       ui->Next->setVisible(true);
    }

}

void Transform:: draw(float abc[][3])
{
    QPainter p(this);
    abc[V][0]=abc[0][0];
    abc[V][1]=abc[0][1];
    int j;
    for(j=0;j<V;j++)
        p.drawLine(abc[j][0],abc[j][1],abc[j+1][0],abc[j+1][1]);
}
void Transform::scale()
{
    int l,m,k;
    for(l=0;l<V;l++)
            for(m=0;m<3;m++)
            {
                coor2[l][m]=0;
                for(k=0;k<3;k++)
                {
                    coor2[l][m]=coor2[l][m]+coor[l][k]*scal_mat[k][m];
                }
            }
    draw(coor2);
}
void Transform::translate()
{
    int l,m,k;
    for(l=0;l<V;l++)
            for(m=0;m<3;m++)
            {
                coor2[l][m]=0;
                for(k=0;k<3;k++)
                {
                    coor2[l][m]=coor2[l][m]+coor[l][k]*scal_mat[k][m];
                }
            }
    draw(coor);
    draw(coor2);
}
void Transform::rotate()
{
    int l,m,k;
    for(l=0;l<V;l++)
            for(m=0;m<3;m++)
            {
                coor2[l][m]=0;
                for(k=0;k<3;k++)
                {
                    coor2[l][m]=coor2[l][m]+(float)coor[l][k]*rot[k][m];

                }
            }
    for(int j=0;j<V;j++)
        coor2[j][0]-=coor2[j][1];
    draw(coor2);
}
void Transform::on_Next_clicked()
{
    if(i==(V-1))
       ui->Next->setVisible(false);
    if(i<V)
    {
        coor[i][0]=(ui->x->toPlainText().toInt())*40+(width/2);
        coor[i][1]=(ui->y->toPlainText().toInt())*40+(height/2);
        coor[i][2]=1;
        i++;
    }

    ui->x->QTextEdit::clear();
    ui->y->QTextEdit::clear();
}

void Transform::on_Draw_clicked()
{
    flag=1;
    update();
}

void Transform::on_reset_clicked()
{
    i=0;
    ui->Next->setVisible(true);
    //update();

}

void Transform::on_Scale_clicked()
{
    flag=2;
    update();
}

void Transform::on_translate_clicked()
{
    flag=3;
    update();
}

void Transform::on_Rotate_clicked()
{
    flag=4;
    update();
}
