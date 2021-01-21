#ifndef VINYL_H
#define VINYL_H


#include "SpininVinyl.h"

#include <QWidget>
#include <layout/fader.h>
#include <QPushButton>

class Vinyl : public QWidget
{
    Q_OBJECT
public:
    explicit Vinyl(QWidget *parent = nullptr);

public slots:
    void changePlayMode();
    void changeSpinSpeed(int a);
    void show();

private:
    bool spinning;
    int percent;
    qreal spinSpeed;
    Fader *speed ;
    QPushButton *play;
    QPushButton *cue;
    SpininVinyl *disk;
signals:

};

#endif // VINYL_H
