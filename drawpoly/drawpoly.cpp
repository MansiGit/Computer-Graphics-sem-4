#include "drawpoly.h"
#include "ui_drawpoly.h"
#include "QMouseEvent"

drawpoly::drawpoly(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::drawpoly)
{
    ui->setupUi(this);
}

drawpoly::~drawpoly()
{
    delete ui;
}

void drawpoly ::draw()
{
    QPainter p(this);
    i=flag=0;
    x[n]=x[0];
    y[n]=y[0];
    int j;
    for(j=0;j<n;j++)
        p.drawLine(x[j],y[j],x[j+1],y[j+1]);
}

void drawpoly::fill()
{
    QPainter paint(this);
    int maxy=0,miny=y[0],p,point[10],dx,dy;
    float m[15];
    for(int j=0;j<n;j++)
    {
        if(y[j]>maxy)
            maxy=y[j];
        if(y[j]<miny)
            miny=y[j];
        dx=x[j]-x[j+1];
        dy=y[j]-y[j+1];
        if(dx==0)
            m[j]=0;
        if(dy==0)
            m[j]=1;
        if(dx!=0 && dy!=0)
        m[j]=(float)(dx)/(dy);
    }

    for(int j=miny;j<=maxy;j++)
    {
        p=0;
        int k,max,min;
        for(k=0;k<n;k++)
        {
            if(y[k]>y[k+1])
            {
                max=y[k];
                min=y[k+1];
            }
            else
            {
                max=y[k+1];
                min=y[k];
            }
            if(max>j&&min<=j)
            {
                point[p]=((j-y[k])*m[k])+x[k];
                p++;
            }
        }
        sort(point,p);
        for(k=0;k<p-1;k+=2)
            paint.drawLine(point[k],j,point[k+1],j);
    }
}
void drawpoly::sort(int arr[], int l)
{
    int temp;
    for(int j=0;j<l;j++)
        for(int k=0;k<l-1-j;k++)
        {
            if(arr[k]>arr[k+1])
            {
                temp=arr[k];
                arr[k]=arr[k+1];
                arr[k+1]=temp;
            }
        }
}

void drawpoly::paintEvent(QPaintEvent *)
{
    if(flag==2)
        draw();
    if(flag==3)
    {
        draw();
        fill();
    }

}

void drawpoly::mousePressEvent(QMouseEvent *)
{
    if(i<n)
    {
        x[i]=QCursor::pos().x();
        y[i]=QCursor::pos().y();
        i++;
    }
}
void drawpoly::on_pushButton_clicked()//select
{
    flag=0;
    n=ui->textEdit->toPlainText().toInt();
    update();
}

void drawpoly::on_pushButton_2_clicked()//draw
{
    flag=2;
    update();
}

void drawpoly::on_pushButton_3_clicked()//fill
{
    flag=3;
    update();
}
