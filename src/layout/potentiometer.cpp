//=========================================================================================================================================
// Potentiometer imitate real rotary potentiometer with kind of evolving display
//=========================================================================================================================================


#include "layout/potentiometer.h"

#include <QtMath>
#include <QPainter>
#include <QMouseEvent>


Potentiometer::Potentiometer(QWidget *parent) : QWidget(parent)
{
    //Value of the potentiometer and it's limits
    value = 0.5;
    minValue = 0.;
    maxValue = 1.;

    //to follow the mouse
    follow = false;
    lastPoint = pos();

    //Display setting
    potentiometerColor = QColor(90,90,90) ;
    pinColor = QColor(0,0,0);
    layout = new QVBoxLayout();
    size = 30;
    labelColor = QColor(25,94,68);
    label = tr("");
}


//display getter/setter
void Potentiometer::setSize(int newSize)
{
    size = newSize;
    displayChanged();
}

int Potentiometer::getSize()
{
    return size;
}

void Potentiometer::setPotentiometerColor(QColor color)
{
    potentiometerColor = color;
    displayChanged();
}

void Potentiometer::setPinColor(QColor color)
{
    pinColor = color;
    displayChanged();
}

void Potentiometer::setLabel(QString newLabel)
{
    label = newLabel;
    displayChanged();
}

// parametter's getter/setter
void Potentiometer::setValue(qreal val)
{
    value = val;
    if (value > maxValue){
        emit overMax();
        value = maxValue;
    } else if (val < minValue){
        emit underMin();
        value = minValue;
    }
    emit valueChanged(val);
    displayChanged();
}

qreal Potentiometer::getValue()
{
    return value;
}

void Potentiometer::setMinValue(qreal min)
{
    minValue = min;
    displayChanged();
}

void Potentiometer::setMaxValue(qreal max)
{
    maxValue = max;
    displayChanged();
}


//SLOT valueChanged
void Potentiometer::displayChanged()
{
    update();
}



// When Potentiometer comes to be painted, this function is called, see QPainter for more informations
void Potentiometer::paintEvent(QPaintEvent *)
{
    static const QPoint pin[4] = {
        QPoint(-1, -size/2 + 2),
        QPoint(1, -size/2 + 2),
        QPoint(1, -size/2 + 7),
        QPoint(-1, -size/2 + 7)
    };


    QPainter painter(this);
    painter.setRenderHint(QPainter::Antialiasing);
    painter.translate(width() / 2 , height()/2);


    painter.setPen(Qt::NoPen);
    painter.setBrush(potentiometerColor);


    painter.drawEllipse(-size/2,-size/2, size, size);

    painter.setBrush(pinColor);

    painter.save();
        painter.rotate(-160 + (value/(maxValue - minValue)) * 320 );
        painter.drawConvexPolygon(pin, 4);
    painter.restore();

    painter.setBrush(labelColor);

    painter.translate(-size/2 + 5, size/2 +12);
    painter.setPen(QPen(labelColor));
    painter.drawText(0,0,label);
}


//Mouse actions handling
void Potentiometer::mousePressEvent(QMouseEvent *event)
{
    if ( event->button() == Qt::LeftButton && (event->pos() - QPoint(width()/2, height()/2)).manhattanLength() < size)
    {
        lastPoint = event->pos();
        lastValue = value;
        follow = true;

    }
}

void Potentiometer::mouseMoveEvent(QMouseEvent *event)
{
    if (follow)
    {
        setValue(lastValue - (2. * ( (float)(event->pos() - lastPoint).y())/((float)500)));
    }
}


void Potentiometer::mouseReleaseEvent(QMouseEvent *event)
{
    if ( event->button() == Qt::LeftButton)
    {
        lastPoint = event->pos();
        follow = false;
    }
}
