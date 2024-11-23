#include "hexspinbox.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    HexSpinBox *hexSpinBox = new HexSpinBox;
    hexSpinBox->show();
    return a.exec();
}
