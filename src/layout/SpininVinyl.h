#ifndef SPININVINYL_H
#define SPININVINYL_H

#include <QWidget>
#include <QPainter>
class SpininVinyl : public QWidget
{
    Q_OBJECT

public:
    explicit SpininVinyl(QWidget *parent = nullptr);
    float getAnglePosition();
    void setAnglePosition(qreal a);

signals:

protected:
    void paintEvent(QPaintEvent *event);

private:
    qreal anglePosition;
    QRect *positionRectangle;

    int size;
    QColor vinylColor;
    QColor stripeColor;




};

#endif // SPININVINYL_H
