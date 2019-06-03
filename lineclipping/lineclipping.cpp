#include "lineclipping.h"
#include "ui_lineclipping.h"
#include<QPainter>
#include "QMouseEvent"
lineclipping::lineclipping(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::lineclipping)
{
    ui->setupUi(this);
}

lineclipping::~lineclipping()
{
    delete ui;
}
void lineclipping::paintEvent(QPaintEvent *)
{
    if(flag==2)
    {
        x_max=ui->xmax->toPlainText().toInt();
        y_max=ui->ymax->toPlainText().toInt();
        x_min=ui->xmin->toPlainText().toInt();
        y_min=ui->ymin->toPlainText().toInt();
        draw(x_max,y_max,x_max,y_min);
        draw(x_min,y_min,x_max,y_min);
        draw(x_min,y_min,x_min,y_max);
        draw(x_min,y_max,x_max,y_max);
        draw(x[0],y[0],x[1],y[1]);
    }
    if(flag==3)
    {
        x_max=ui->xmax->toPlainText().toInt();
        y_max=ui->ymax->toPlainText().toInt();
        x_min=ui->xmin->toPlainText().toInt();
        y_min=ui->ymin->toPlainText().toInt();
        draw(x_max,y_max,x_max,y_min);
        draw(x_min,y_min,x_max,y_min);
        draw(x_min,y_min,x_min,y_max);
        draw(x_min,y_max,x_max,y_max);
        clip();
    }
    if(flag==4 || flag==0)
    {
        x_max=ui->xmax->toPlainText().toInt();
        y_max=ui->ymax->toPlainText().toInt();
        x_min=ui->xmin->toPlainText().toInt();
        y_min=ui->ymin->toPlainText().toInt();
        draw(x_max,y_max,x_max,y_min);
        draw(x_min,y_min,x_max,y_min);
        draw(x_min,y_min,x_min,y_max);
        draw(x_min,y_max,x_max,y_max);
    }
}

void lineclipping::mousePressEvent(QMouseEvent *)
{
        if(i<n)
        {
            x[i]=QCursor::pos().x();
            y[i]=QCursor::pos().y();
            i++;
        }
}
void lineclipping :: draw(int a, int b ,int c,int d)
{
    QPainter painter(this);
    i=flag=0;
    painter.drawLine(a,b,c,d);
    //painter.setPen(QPen((Qt::blue),1));
    //painter.drawLine(0,480,1280,480);
    //painter.drawLine(640,0,640,960);
}
void lineclipping::clip ()
{
    /*x_max=ui->xmax->toPlainText().toInt();
    y_max=ui->ymax->toPlainText().toInt();
    x_min=ui->xmin->toPlainText().toInt();
    y_min=ui->ymin->toPlainText().toInt();*/


    cohenSutherlandClip(x[0],y[0],x[1],y[1]);
}
// Function to compute region code for a point(x, y)
int lineclipping ::computeCode(double x, double y)
{
    // initialized as being inside
    int code = INSIDE;

    if (x < x_min)       // to the left of rectangle
        code |= LEFT;
    else if (x > x_max)  // to the right of rectangle
        code |= RIGHT;
    if (y < y_min)       // below the rectangle
        code |= BOTTOM;
    else if (y > y_max)  // above the rectangle
        code |= TOP;

    return code;
}

// Implementing Cohen-Sutherland algorithm
// Clipping a line from P1 = (x2, y2) to P2 = (x2, y2)
void lineclipping ::cohenSutherlandClip(double x1, double y1,
                         double x2, double y2)
{
    // Compute region codes for P1, P2
    int code1 = computeCode(x1, y1);
    int code2 = computeCode(x2, y2);

    // Initialize line as outside the rectangular window
    bool accept = false;

    while (true)
    {
        if ((code1 == 0) && (code2 == 0))
        {
            // If both endpoints lie within rectangle
            accept = true;
            break;
        }
        else if (code1 & code2)
        {
            // If both endpoints are outside rectangle,
            // in same region
            break;
        }
        else
        {
            // Some segment of line lies within the
            // rectangle
            int code_out;
            double x, y;

            // At least one endpoint is outside the
            // rectangle, pick it.
            if (code1 != 0)
                code_out = code1;
            else
                code_out = code2;

            // Find intersection point;
            // using formulas y = y1 + slope * (x - x1),
            // x = x1 + (1 / slope) * (y - y1)
            if (code_out & TOP)
            {
                // point is above the clip rectangle
                x = x1 + (x2 - x1) * (y_max - y1) / (y2 - y1);
                y = y_max;
            }
            else if (code_out & BOTTOM)
            {
                // point is below the rectangle
                x = x1 + (x2 - x1) * (y_min - y1) / (y2 - y1);
                y = y_min;
            }
            else if (code_out & RIGHT)
            {
                // point is to the right of rectangle
                y = y1 + (y2 - y1) * (x_max - x1) / (x2 - x1);
                x = x_max;
            }
            else if (code_out & LEFT)
            {
                // point is to the left of rectangle
                y = y1 + (y2 - y1) * (x_min - x1) / (x2 - x1);
                x = x_min;
            }
            if (code_out == code1)
            {
                x1 = x;
                y1 = y;
                code1 = computeCode(x1, y1);
            }
            else
            {
                x2 = x;
                y2 = y;
                code2 = computeCode(x2, y2);
            }
            accept=true;
        }
    }
    if (accept)
    {
        draw(x1,y1,x2,y2);
    }
}
void lineclipping::on_select_clicked()
{
    n=2;
    flag=0;
    update();
}

void lineclipping::on_draw_clicked()
{
    flag=2;
    update();
}

void lineclipping::on_clip_clicked()
{
    flag=3;
    update();
}

void lineclipping::on_ShowWindow_clicked()
{
    flag=4;
    update();
}
