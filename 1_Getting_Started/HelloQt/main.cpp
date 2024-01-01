//#include "mainwindow.h"

#include <QApplication>
#include <QLabel>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    //MainWindow w;
    //w.show();
    QLabel *label = new QLabel("<h1><i>Hello</i> <font color=blue>Qt!</font></h1>");
    label->show();
    return a.exec();
}
