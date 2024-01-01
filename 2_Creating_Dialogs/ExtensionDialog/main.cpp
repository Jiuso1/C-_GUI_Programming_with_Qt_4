#include "sortdialog.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    SortDialog *dialog = new SortDialog;
    dialog->setColumnRange('C','F');
    dialog->show();
    return a.exec();
}
