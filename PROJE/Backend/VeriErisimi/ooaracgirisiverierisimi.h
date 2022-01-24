#ifndef OOARACGIRISIVERIERISIMI_H
#define OOARACGIRISIVERIERISIMI_H

#include "Backend/Veriler/ooaracgirisi.h"

#include <QVector>
#include <memory>

#include <QDate>

using namespace std;

class OOAracGirisiVeriErisimi
{
public:
    typedef OOAracGirisi Veri;
    typedef shared_ptr<Veri> pointer;
    typedef  QVector<pointer> Liste;

    typedef enum { AT_IleBaslayan = 1, AT_IleBiten = 2, AT_Iceren = 3} AramaTuru;

    OOAracGirisiVeriErisimi();

    pointer yeniAracGirisi();

    void listeyeEkle(pointer Aracgirisi);

    pointer PlakayaGoreAracBul(QString arananplaka);
    Liste RengeGoreAracBul(QString arananRenk, AramaTuru tur);
    Liste GirisTarihineGoreAracBul(QDate baslangic, QDate bitis);
    Liste GirisTarihineGoreAracBul(QDate tarih);

    void AracSil(QString plaka);

private:
    Liste u_Aracgirisleri;

};

#endif // OOARACGIRISIVERIERISIMI_H
