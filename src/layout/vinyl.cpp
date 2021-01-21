//=========================================================================================================================================
// Vinyl  is the whole TurnTable with speed control (turning on 33 rpm initally) play pause
//TODO: Add controlBlock
//TODO: Add scratch possibility
//=========================================================================================================================================



#include "layout/vinyl.h"

#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QTimer>

Vinyl::Vinyl(QWidget *parent) : QWidget(parent)
{
    // boolean : Is the vinyl turning ?
    spinning = false;
    spinSpeed = 360 * 33 / 60;

    QVBoxLayout *globalLayout = new  QVBoxLayout();
    QHBoxLayout *upperLayout = new QHBoxLayout();
    globalLayout->addLayout(upperLayout);

    disk = new SpininVinyl();
    upperLayout->addWidget(disk);

    percent = 200; // 200 correspond to a max difference of 20 percent on the pitch ( it have to be modifiable )

    //Pitch fader
    speed = new Fader();
        speed->setFaderColor(QColor(255,120,120));
        speed->setMinValue(-percent);
        speed->setMaxValue(percent);
        speed->setValue(0);
    upperLayout->addWidget(speed);



    QHBoxLayout *belowLayout = new QHBoxLayout();
    globalLayout->addLayout(belowLayout);


        play = new QPushButton(tr("Play"));
            belowLayout->addWidget(play);

        cue = new QPushButton(tr("Cue"));
            belowLayout->addWidget(cue);

        QSpacerItem *space = new QSpacerItem(200, 200);
            belowLayout->addItem(space);


    setLayout(globalLayout);

    // For now a timer actionate every 10ms to change value of the vinyl's angle
    QTimer *timer = new QTimer(this);
    timer->start(10); //100 fps
    show();

    connect(timer, &QTimer::timeout, this, &Vinyl::show);
    connect(play, SIGNAL(clicked()), this, SLOT(changePlayMode()));
    connect(speed, SIGNAL(valueChanged(int)), this, SLOT(changeSpinSpeed(int)));

}

void Vinyl::changePlayMode()
{
    spinning= !spinning;
}

void Vinyl::changeSpinSpeed(int a)
{

    spinSpeed = 360. * (33./60.) * (1. + ((float) a)/ 1000);

}

void Vinyl::show()
{
    if (spinning) {
        disk->setAnglePosition(disk->getAnglePosition() + spinSpeed/1000 * 10 );
    }
}
