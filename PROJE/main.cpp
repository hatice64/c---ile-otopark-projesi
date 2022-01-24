#include "otaparkotamasyonu.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    OtaparkOtamasyonu w;
    w.show();

    return a.exec();
}
