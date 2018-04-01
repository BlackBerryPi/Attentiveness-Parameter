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
    setFixedSize(MAX_ITEM, 500);
}

void DrawWidget::setData(int d)
{

    if(top<MAX_ITEM+5)
    {
        t_points.push_back(d);
        top++;
    }
    else
    {
        t_points.remove(0);
        t_points.push_back(d);
    }

    this->update();

    qDebug() << "d = "  << d;
}

void DrawWidget::paintEvent(QPaintEvent *e)
{
    QPainter p(this);
    QPen pen;

    pen.setColor(QColor(66, 207, 227));
    pen.setWidth(3);
    p.setPen(pen);

    int  i = 0;
    for(QVector<int>::iterator it = t_points.begin(); it != t_points.end(); it++)
    {
        if(top==1)
        {
            continue;
        }
        p.drawLine(i-5, height()+(*(it-1)), i-4, height()+(*it));
        i++;
    }
}
