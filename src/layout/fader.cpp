
//=========================================================================================================================================
//  Fader class is nearly a QSlider but with a different display, in order to be able to change it
//=========================================================================================================================================

#include "layout/fader.h"
#include <QPainter>
#include <QtMath>
#include <QMouseEvent>

Fader::Fader(QWidget *parent) : QWidget(parent)
{
    //Fader's actual value and it's save and limits
    value = 0;
    lastValue= value;
    minValue = 0.;
    maxValue = 1.;

    // initialising display's setting
    layout = new QVBoxLayout();
    size = 200;
    faderSize = 15;
    faderColor = QColor(124,124,124) ;
    holeColor = QColor(0,0,0);
}


//display size and color of the fader/hole , getter and/or setter
int Fader::getFaderSize()
{
    return faderSize;
}

void Fader::setFaderSize(int newFaderSize)
{
    faderSize = newFaderSize;
    update();
}

void Fader::setFaderColor(QColor color)
{
    faderColor = color;
    update();
}

void Fader::setHoleColor(QColor color)
{
    holeColor = color;
    update();
}


// All setter needed with value and it's limits
void Fader::setValue(qreal val)
{
    printf("%f\n", val);
    value = val;
    if (value > maxValue){
        value = maxValue;
        emit overMax();
    } if (value < minValue){
        value = minValue;
        emit underMin();
    }
    update();
}

void Fader::setMinValue(qreal min)
{
    minValue = min;
    update();
}

void Fader::setMaxValue(qreal max)
{
    maxValue = max;
    update();
}


//SLOT of the fader valueChanged

void Fader::valueChanged()
{
    update();
}



//mouse reaction
void Fader::mousePressEvent(QMouseEvent *event)
{
    qreal posFader = height() *(1 - (value - minValue)/(maxValue - minValue)) ;
    if ( event->button() == Qt::LeftButton && (event->pos() - QPoint(width()/2,(int) posFader)).manhattanLength() < faderSize * 3)
    {
        lastPoint = event->pos();
        lastValue = value;
        follow = true;

    }
}

void Fader::mouseMoveEvent(QMouseEvent *event)
{
    if (follow)
    {
        setValue(lastValue - (maxValue - minValue) * ( ((float)(event->pos() - lastPoint).y())/((float)height())));
    }
}

void Fader::mouseReleaseEvent(QMouseEvent *event)
{
    if ( event->button() == Qt::LeftButton)
    {
        lastPoint = event->pos();
        follow = false;
    }
}



// when Fader is needed to be showed (see QPainter for more informations)
void Fader::paintEvent(QPaintEvent *)
{
    static const QPoint stripe[4] = {
        QPoint(-1, 0),
        QPoint(1, 0),
        QPoint(1, height()),
        QPoint(-1, height())
    };
    static const QPoint fader[4] = {
        QPoint(-faderSize, faderSize/3),
        QPoint(faderSize, faderSize/3),
        QPoint(faderSize, -faderSize/3),
        QPoint(-faderSize, -faderSize/3)
    };


    QPainter painter(this);
    painter.setRenderHint(QPainter::Antialiasing);
    painter.translate(width() / 2 , 0);

    painter.setPen(Qt::NoPen);
    painter.setBrush(holeColor);


    painter.drawConvexPolygon(stripe, 4);


    painter.setBrush(faderColor);

    painter.save();
        painter.translate(0, height() *(1 - (value - minValue)/(maxValue - minValue) ));
        painter.drawConvexPolygon(fader, 4);
    painter.restore();
}

