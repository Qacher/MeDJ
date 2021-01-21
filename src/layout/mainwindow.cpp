
//=========================================================================================================================================
// MainWindow contain the main applicaiton display
//=========================================================================================================================================

#include "layout/mainwindow.h"
#include "layout/vinyl.h"
#include "layout/mixer.h"

#include <QFileSystemModel>
#include <QTreeView>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QBoxLayout>

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent)
{

    center = new QWidget();
        QVBoxLayout *globalLayout = new  QVBoxLayout();
        center->setLayout(globalLayout);
    setCentralWidget(center);

    mixPart = new QWidget();
        QHBoxLayout *mixLayout = new QHBoxLayout();

        Vinyl *side1 = new Vinyl();
        mixLayout->addWidget(side1);

        Mixer *mixer = new Mixer();
        mixLayout->addWidget(mixer);

        Vinyl *side2 = new Vinyl();
        mixLayout->addWidget(side2);

    mixPart->setLayout(mixLayout);
    globalLayout->addWidget(mixPart);


    setMinimumSize(1500, 1000);


}
