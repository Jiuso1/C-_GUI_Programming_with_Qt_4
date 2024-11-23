#include "mainwindow.h"

#include <QApplication>
#include <QSplashScreen>

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);

    QSplashScreen *splash = new QSplashScreen;
    splash->setPixmap(QPixmap("C:/Users/jesus/Documents/C++/ProyectosQt/C++_GUI_Programming_with_Qt_4/3_Creating_Main_Windows/Spreadsheet/images/splash.jpg"));//:/images/splash.jpg
    splash->show();

    Qt::Alignment topRight = Qt::AlignRight | Qt::AlignTop;

    splash->showMessage(QObject::tr("Setting up the main window..."));

    _sleep(2000);

    MainWindow mainWin;

    /*
    He omitido el resto de funciones porque creo que nunca se implementarán,
    eran simplemente a modo de ejemplo.
    */

    splash->showMessage(QObject::tr("Doing a few more things..."));

    _sleep(2000);

    mainWin.show();

    splash->finish(&mainWin);
    delete splash;

    return app.exec();
}
