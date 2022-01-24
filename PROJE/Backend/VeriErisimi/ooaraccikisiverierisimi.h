#ifndef OOARACCIKISIVERIERISIMI_H
#define OOARACCIKISIVERIERISIMI_H

#include "Backend/Veriler/ooaraccikisi.h"

#include <QVector>
#include <memory>

using namespace std;

class OOAracCikisiVeriErisimi
{
public:
    typedef OOAracCikisi Veri;
    typedef shared_ptr<Veri> pointer;
    typedef  QVector<pointer> Liste;

    OOAracCikisiVeriErisimi();

    pointer yeniAracCikisi();

    void listeyeEkle(pointer Araccikisi);

private:
    Liste u_Araccikislari;
};

#endif // OOARACCIKISIVERIERISIMI_H
