#ifndef MIXER_H
#define MIXER_H

#include <QWidget>
#include "layout/fader.h"
#include <layout/track.h>
class Mixer : public QWidget
{
    Q_OBJECT
public:
    explicit Mixer(QWidget *parent = nullptr);

private:
    Track *channel1;
    Track *channel2;
    Track *channel3;
    Track *channel4;

signals:

};

#endif // MIXER_H
