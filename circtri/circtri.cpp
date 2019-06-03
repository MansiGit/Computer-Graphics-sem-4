#include "circtri.h"
#include "ui_circtri.h"
#include<QtGui>
#include<math.h>
#include <QPainter>
circtri::circtri(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::circtri)
{
    ui->setupUi(this);
}

circtri::~circtri()
{
    delete ui;
}
void circtri :: plot(int x,int y,int x1,int y1)
{       QPainter painter(this);
        painter.setPen(QPen((Qt::blue),1));
        painter.drawPoint(x+x1,y+y1);
        painter.drawPoint(x-x1,y+y1);
        painter.drawPoint(x+x1,y-y1);
        painter.drawPoint(x-x1,y-y1);
        painter.drawPoint(x+y1,y+x1);
        painter.drawPoint(x-y1,y+x1);
        painter.drawPoint(x+y1,y-x1);
        painter.drawPoint(x-y1,y-x1);
}

void circtri::changeEvent(QEvent *e)
{
    QMainWindow::changeEvent(e);
    switch (e->type()) {
    case QEvent::LanguageChange:
        ui->retranslateUi(this);
        break;
    default:
        break;
    }
}

void circtri :: paintEvent(QPaintEvent *event)
{
    QPainter painter(this);
    painter.setPen(QPen((Qt::red),5));
    int x,y,r;
    x=ui->textEdit->toPlainText().toInt();
    y=ui->textEdit_2->toPlainText().toInt();
    r=ui->textEdit_3->toPlainText().toInt();
    drawCircle(x,y,r);
    drawCircle(x,y,2*r);
    draw((float) x , y-2*r , (float)(x-1.732*r) , y+r );
    draw((float)(x-1.732*r) , y+r , (float)x+1.732*r , y+r );
    draw((float)x+1.732*r , y+r, (float)x , y-2*r );
}

void circtri::on_pushButton_clicked()
{
    flag=0;
    ui->label->setVisible(false);
    ui->label_2->setVisible(false);
    ui->label_3->setVisible(false);
    ui->label_4->setVisible(false);
    ui->textEdit->setVisible(false);
    ui->textEdit_2->setVisible(false);
    ui->textEdit_3->setVisible(false);
    ui->pushButton->setVisible(false);
    update();
}

void circtri :: draw(float x1, float y1,float x2,float y2) //DDA
{
        float x,y,xi,yi,dx,dy,len;
        int i=0;
        QPainter painter(this);
        painter.setPen(QPen((Qt::red),1));

        dx=x2-x1;
        dy=y2-y1;
        len = (abs(dx)>abs(dy)) ? abs(dx) : abs(dy);
        xi=dx/len;
        yi=dy/len;
        x=x1+0.5;
        y=y1+0.5;
        while(i<len)
        {
                painter.drawPoint(x,y);
                x=x+xi;
                y=y+yi;
                i++;
        }
}
void circtri :: drawCircle(int x,int y,int r)
{
        int i=0,d,x1=0,y1=r;
        d=3-2*r;
        while(x1<=y1)
        {
                if(d>0)
                {
                        d=d+4*x1-4*y1+10;
                        plot(x,y,x1++,y1--);
                        continue;
                }
                if(d<=0)
                {
                        d=d+4*x1+6;
                        plot(x,y,x1++,y1);
                }
        }
}

