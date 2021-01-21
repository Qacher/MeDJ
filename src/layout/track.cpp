//=========================================================================================================================================
// Track is the whole line of a channel
//=========================================================================================================================================



#include "layout/track.h"
#include <QGridLayout>

Track::Track(QWidget *parent) : QWidget(parent)
{
    //TODO be able to change it's configuration
    //(various number of potentiometer, with different roles (multi fx for exemple or 4 band EQ ect ect)

    gainPotar = new Potentiometer();
        gainPotar->setLabel("Gain");

    lowPotar = new Potentiometer();
        lowPotar->setLabel("Low");

    midPotar = new Potentiometer();
        midPotar->setLabel("Mid");

    highPotar = new Potentiometer();
        highPotar->setLabel("High");

    fxPotar = new Potentiometer();
        fxPotar->setSize(fxPotar->getSize() + 10);
        fxPotar->setPotentiometerColor(QColor(220,220,220));
        fxPotar->setPinColor(QColor(0,0,0));
        fxPotar->setLabel("FX");

    channelFader = new Fader();


    QGridLayout *grid = new QGridLayout();
        grid->addWidget(gainPotar, 1, 1, 1, 1);
        grid->addWidget(highPotar, 2, 1, 1, 1);
        grid->addWidget(midPotar, 3, 1, 1, 1);
        grid->addWidget(lowPotar, 4, 1, 1, 1);
        grid->addWidget(fxPotar, 5, 1, 1, 1);
        grid->addWidget(channelFader, 6, 1, 6, 1);
    setLayout(grid);

}
