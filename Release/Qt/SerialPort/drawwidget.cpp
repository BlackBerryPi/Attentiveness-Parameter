#include "drawwidget.h"
#include <QPainter>
#include <QPen>
#include <QDebug>

#define MAX_ITEM 500

DrawWidget::DrawWidget(QWidget *parent) : QWidget(parent)
{
    top = 0;
    t_points.push_back(0);
    setWindowTitle("Monitor");
    setFixedSize(MAX_ITEM+1, 500);
}

void DrawWidget::setData(QString op, int d)
{
    if(!op.compare("T"))
    {
        if(top<MAX_ITEM)
        {
            t_points.push_back(d);
            top++;
        }
        else
        {
            qDebug() << "item removed";
            t_points.remove(0);
            t_points.push_back(d);
        }

        this->update();
        qDebug() << "Updated";
    }
    qDebug() << "d = "  << d;
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
    for(QVector<int>::iterator it = t_points.begin(); it != t_points.end(); it++)
    {
        if(top==1)
        {
            continue;
        }
//        p.drawPoint(i, height()+120-(*it)*2.0);
        p.drawLine(i, height()+100-(*(it-1))*2.0, i+1, height()+100-(*(it))*2.0);
        qDebug() << height()+180-(*it)*2.0;
        i++;
    }
}
