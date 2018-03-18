#include "drawwidget.h"
#include <QPainter>
#include <QPen>
#include <QDebug>

DrawWidget::DrawWidget(QWidget *parent) : QWidget(parent)
{
    top = 0;
    setWindowTitle("Monitor");
    setFixedSize(500, 500);
}

void DrawWidget::setData(int d)
{
    qDebug() << "top = "  << top;
    if(top<500)
    {
        points.push_back(d);
        top++;
    }
    else
    {
        qDebug() << "item removed";
        points.remove(0);
        points.push_back(d);
    }

    this->update();
    qDebug() << "Updated";
}

void DrawWidget::paintEvent(QPaintEvent *e)
{
    qDebug() << "paintEvent";

    QPainter p(this);
    QPen pen;
    qDebug() << "Pen set";

    pen.setColor(QColor(66, 207, 227));
//    pen.setColor(QColor(0, 0, 0));
    pen.setWidth(3);
    p.setPen(pen);

    int  i = 0;
    qDebug() << "ready for the draw";
    for(QVector<int>::iterator it = points.begin(); it++ != points.end();)
    {
//        p.drawPoint(i, height()+120-(*it)*2.0);
        p.drawLine(i, height()+180-(*(it-1))*2.0, i+1, height()+100-(*(it))*2.0);
        qDebug() << height()+180-(*it)*2.0;
        i++;
    }
}
