#ifndef DRAWWIDGET_H
#define DRAWWIDGET_H

#include <QWidget>
#include <QPoint>

class DrawWidget : public QWidget
{
    Q_OBJECT
public:
    explicit DrawWidget(QWidget *parent = nullptr);
    void setData(int d);

signals:

public slots:

protected:
    void paintEvent(QPaintEvent *e);

private:
    QVector<int> points;
    int top;
};

#endif // DRAWWIDGET_H
