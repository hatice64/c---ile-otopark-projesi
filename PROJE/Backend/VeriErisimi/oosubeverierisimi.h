#ifndef OOSUBEVERIERISIMI_H
#define OOSUBEVERIERISIMI_H

#include "Backend/Veriler/oosube.h"
#include <QVector>
#include <memory>

#include <QDate>

using namespace std;

class OOSubeVeriErisimi
{
public:
    typedef OOSube Veri;
    typedef shared_ptr<Veri> pointer;
    typedef QVector<pointer> Liste;

    typedef enum { AT_IleBaslayan = 1, AT_IleBiten = 2, AT_Iceren = 3} AramaTuru;

    OOSubeVeriErisimi();

    pointer yeniSube();

    void listeyeEkle(pointer sube);

    pointer kodaGoreSubeBul(QString arananKod);
    Liste adaGoreSubeBul(QString arananAd, AramaTuru tur);
    Liste kurulusTarihineGoreSubeBul(QDate baslangic, QDate bitis);
    Liste kurulusTarihineGoreSubeBul(QDate tarih);

    void subeSil(QString subeKodu);

    void kaydet(QDataStream &kaydedici);

    void yukle(QDataStream &kaydedici);

private:
    Liste u_Subeler;
};

#endif // OOSUBEVERIERISIMI_H
