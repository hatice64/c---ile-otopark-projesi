#ifndef OOARACVERIERISIMI_H
#define OOARACVERIERISIMI_H

#include "Backend/Veriler/ooarac.h"

#include <QVector>
#include <memory>

using namespace std;

class OOAracVeriErisimi
{
public:
    typedef OOArac Veri;
    typedef shared_ptr<Veri> pointer;
    typedef  QVector<pointer> Liste;

    OOAracVeriErisimi();

    pointer yeniArac();

    void listeyeEkle(pointer Arac);

private:
    Liste u_Araclar;
};

#endif // OOARACVERIERISIMI_H
