#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

class MainWindow : public QMainWindow
{
    Q_OBJECT
public:
    explicit MainWindow(QWidget *parent = nullptr);
    QWidget *center ;

    QWidget *mixPart;
    QWidget *songPart;

signals:

};

#endif // MAINWINDOW_H
