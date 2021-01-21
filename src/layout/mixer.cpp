//=========================================================================================================================================
// Mixer create the different Track(channel speaking with DJ's terms)
//=========================================================================================================================================


#include "layout/mixer.h"
#include "layout/fader.h"
#include "layout/potentiometer.h"

#include <QHBoxLayout>


Mixer::Mixer(QWidget *parent) : QWidget(parent)
{
    QHBoxLayout *layout = new QHBoxLayout();
    channel1 = new Track();
    layout->addWidget(channel1);
    channel2 = new Track();
    layout->addWidget(channel2);
    channel3 = new Track();
    layout->addWidget(channel3);
    channel4 = new Track();
    layout->addWidget(channel4);

    setLayout(layout);
}
