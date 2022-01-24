#ifndef OOOTAPARKVERIERISIMI_H
#define OOOTAPARKVERIERISIMI_H

#include <QVector>
#include <memory>
#include "Backend/Veriler/oootapark.h"

using namespace std;

class OOOtaparkVeriErisimi
{
public:
    OOOtaparkVeriErisimi();

    shared_ptr<OOOtapark> otapark();

     void yukle(QDataStream &kaydedici);

    void kaydet(QDataStream &kaydedici);

private:
    shared_ptr<OOOtapark> u_ptrOtapark;
};

#endif // OOOTAPARKVERIERISIMI_H
