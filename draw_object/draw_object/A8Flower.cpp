#include "mainwindow.h"
#include "ui_mainwindow.h"

#include<QPainter>
#include<math.h>
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::changeEvent(QEvent *e)
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

void MainWindow::paintEvent(QPaintEvent *)
{
  QPainter P(this);

  int i;
          float u;
          float px[10][5],py[10][5],cx,cy;

          /* Upper petal*/
       px[0][0]=200;
       px[0][1]=120;
       px[0][2]=280;
       px[0][3]=200;

       py[0][0]=150;
       py[0][1]=50;
       py[0][2]=50;
       py[0][3]=150;

       /* Down petal*/
       px[1][0]=200;
       px[1][1]=280;
       px[1][2]=120;
       px[1][3]=200;

       py[1][0]=210;
       py[1][1]=310;
       py[1][2]=310;
       py[1][3]=210;

       /* Left petal*/
       px[2][0]=170;
       px[2][1]=70;
       px[2][2]=70;
       px[2][3]=170;

       py[2][0]=180;
       py[2][1]=100;
       py[2][2]=260;
       py[2][3]=180;

       /*  Right petal*/
       px[3][0]=230;
       px[3][1]=330;
       px[3][2]=330;
       px[3][3]=230;

       py[3][0]=180;
       py[3][1]=100;
       py[3][2]=260;
       py[3][3]=180;

       /* right upper petal*/
       px[4][0]=220;
       px[4][1]=250;
       px[4][2]=350;
       px[4][3]=220;

       py[4][0]=160;
       py[4][1]=30;
       py[4][2]=150;
       py[4][3]=160;

       /* right lower petal*/
       px[5][0]=220;
       px[5][1]=350;
       px[5][2]=250;
       px[5][3]=220;

       py[5][0]=200;
       py[5][1]=210;
       py[5][2]=330;
       py[5][3]=200;

       /* Left lower petal*/
       px[6][0]=180;
       px[6][1]=50;
       px[6][2]=150;
       px[6][3]=180;

       py[6][0]=200;
       py[6][1]=210;
       py[6][2]=330;
       py[6][3]=200;

       /* Left upper petal*/
       px[7][0]=180;
       px[7][1]=50;
       px[7][2]=150;
       px[7][3]=180;

       py[7][0]=160;
       py[7][1]=150;
       py[7][2]=30;
       py[7][3]=160;
       /* For Drawing Tail of Flower*/
       px[8][0]=215;
       px[8][1]=200;
       px[8][2]=340;
       px[8][3]=320;

       py[8][0]=200;
       py[8][1]=280;
       py[8][2]=260;
       py[8][3]=460;

    /*   /* For Drawing cross curve
       px[9][0]=440;
       px[9][1]=300;
       px[9][2]=520;
       px[9][3]=380;

       py[9][0]=320;
       py[9][1]=200;
       py[9][2]=200;
       py[9][3]=320;
*/

//        P.setPen(QPen(Qt::red,3));
//       for(u=0.0;u<=1.0;u=(u+0.005))
//               {
//                       cx=(px[9][0]*pow(1-u,3))+(3*px[9][1]*u*pow(1-u,2))+(3*px[9][2]*pow(u,2)*(1-u))+(px[9][3]*pow(u,3));
//                       cy=(py[9][0]*pow(1-u,3))+(3*py[9][1]*u*pow(1-u,2))+(3*py[9][2]*pow(u,2)*(1-u))+(py[9][3]*pow(u,3));
//                       P.drawPoint(cx,cy);
//                       //delay(100);
//               }
       //QBrush Brush;
       //P.fillPath(140,Brush);
//       P.setPen(QPen(Qt::red,2));
//       P.drawEllipse(140,120,120,120);

//       P.setPen(QPen(Qt::gray,2));
//       P.drawEllipse(150,130,100,100);
//       P.setPen(QPen(Qt::blue,2));
//       P.drawEllipse(160,140,80,80);
       P.setPen(QPen(Qt::yellow,7));
       P.drawEllipse(174,154,50,50);
       P.setPen(QPen(Qt::blue,10));
       P.drawEllipse(190,170,20,20);

       P.setPen(QPen(Qt::red,7));
       for(i=0;i<4;i++)
          {
          for(u=0.0;u<=1.0;u=(u+0.005))
                  {
                          cx=(px[i][0]*pow(1-u,3))+(3*px[i][1]*u*pow(1-u,2))+(3*px[i][2]*pow(u,2)*(1-u))+(px[i][3]*pow(u,3));
                          cy=(py[i][0]*pow(1-u,3))+(3*py[i][1]*u*pow(1-u,2))+(3*py[i][2]*pow(u,2)*(1-u))+(py[i][3]*pow(u,3));
                          P.drawPoint(cx,cy);
                          //delay(100);
                  }
          }
       P.setPen(QPen(Qt::blue,7));
       for(i=4;i<8;i++)
          {
          for(u=0.0;u<=1.0;u=(u+0.005))
                  {
                          cx=(px[i][0]*pow(1-u,3))+(3*px[i][1]*u*pow(1-u,2))+(3*px[i][2]*pow(u,2)*(1-u))+(px[i][3]*pow(u,3));
                          cy=(py[i][0]*pow(1-u,3))+(3*py[i][1]*u*pow(1-u,2))+(3*py[i][2]*pow(u,2)*(1-u))+(py[i][3]*pow(u,3));
                          P.drawPoint(cx,cy);
                          //delay(100);
                  }
          }
         P.setPen(QPen(Qt::green,4));
         for(u=0.0;u<=1.0;u=(u+0.005))
                  {
                          cx=(px[8][0]*pow(1-u,3))+(3*px[8][1]*u*pow(1-u,2))+(3*px[8][2]*pow(u,2)*(1-u))+(px[8][3]*pow(u,3));
                         cy=(py[8][0]*pow(1-u,3))+(3*py[8][1]*u*pow(1-u,2))+(3*py[8][2]*pow(u,2)*(1-u))+(py[8][3]*pow(u,3));
                         P.drawPoint(cx,cy);
                          //delay(100);
                 }

}
