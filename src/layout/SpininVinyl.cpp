//=========================================================================================================================================
// Spinninvinyl imitate real vinyl with 33 rpm initially and
//=========================================================================================================================================



#include "layout/SpininVinyl.h"


SpininVinyl::SpininVinyl( QWidget *parent) : QWidget(parent)
{
    // Defining position (rotationary)
    anglePosition = 0;

    // Display's setting

    size = 200;
    vinylColor = QColor (124, 124, 124);
    stripeColor = QColor (244, 196, 19);
}


// When SpinninVinyl Comes to be painted, see QPainter to learn more
void SpininVinyl::paintEvent(QPaintEvent *)
{
    //stripe turning to imitate  rotation
    static const QPoint stripe[4] = {
        QPoint(7, -size/5),
        QPoint(-7, -size/5),
        QPoint(-7, -size/2),
        QPoint(7, -size/2)
    };


    QPainter painter(this);
    painter.setRenderHint(QPainter::Antialiasing);
    painter.translate(width() / 2 , height() / 2);
    painter.setPen(Qt::NoPen);

    painter.setBrush(vinylColor);
    painter.drawEllipse(-size/2, -size/2, size, size);

    painter.setBrush(stripeColor);
    painter.save();
        painter.rotate(anglePosition);
        painter.drawConvexPolygon(stripe, 4);
    painter.restore();
}

//turning vinyl getter and setter
void SpininVinyl::setAnglePosition(qreal a)
{
    // We need to get a number between 0 to 360 not to go over MAXQreal after some time using it
    while (a  >= 360)
    {
        a -= 360;
    }
    while (a  <0)
    {
        a += 360;
    }

    anglePosition = a ;
    update();
}

float SpininVinyl::getAnglePosition()
{
    return anglePosition;
};



