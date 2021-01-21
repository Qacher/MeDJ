
//=========================================================================================================================================
// Entry point of MeDJ
//=========================================================================================================================================

#include <Headers/layout/mainwindow.h>

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;

    w.show();

    return a.exec();
}
