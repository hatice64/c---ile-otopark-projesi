#ifndef OOMUSTERIVERIERISIMI_H
#define OOMUSTERIVERIERISIMI_H

#include "Backend/Veriler/oomusteri.h"
#include <QVector>
#include <memory>

using namespace std;

class OOMusteriVeriErisimi
{
public:
    typedef OOMusteri Veri;
    typedef shared_ptr<Veri> pointer;
    typedef  QVector<pointer> Liste;

    OOMusteriVeriErisimi();

    pointer yeniMusteri();

    void listeyeEkle(pointer musteri);

private:
    Liste u_musteriler;
};

#endif // OOMUSTERIVERIERISIMI_H
