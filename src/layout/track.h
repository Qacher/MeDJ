#ifndef TRACK_H
#define TRACK_H

#include <QWidget>

#include "layout/fader.h"
#include "layout/potentiometer.h"

class Track : public QWidget
{
    Q_OBJECT
public:
    explicit Track(QWidget *parent = nullptr);

signals:

private:
    Potentiometer *gainPotar;
    Potentiometer *lowPotar;
    Potentiometer *midPotar;
    Potentiometer *highPotar;
    Potentiometer *fxPotar;
    Fader *channelFader;



};

#endif // TRACK_H
