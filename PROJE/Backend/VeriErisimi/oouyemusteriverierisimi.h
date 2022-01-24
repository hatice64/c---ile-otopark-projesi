#ifndef OOUYEMUSTERIVERIERISIMI_H
#define OOUYEMUSTERIVERIERISIMI_H

#include "Backend/Veriler/oouyemusteri.h"
#include <QVector>
#include <memory>

using namespace std;

class OOUyeMusteriVeriErisimi
{
public:
    typedef OOUyeMusteri Veri;
    typedef shared_ptr<Veri> pointer;
    typedef  QVector<pointer> Liste;

    typedef enum { AT_IleBaslayan = 1, AT_IleBiten = 2, AT_Iceren = 3} AramaTuru;

    OOUyeMusteriVeriErisimi();

    pointer yeniuyeMusteri();

    void listeyeEkle(pointer uyemusteri);

    pointer TCGoreMusteriBul(QString arananTC);
    Liste adaGoreMusteriBul(QString arananAd, AramaTuru tur);

    void uyemusteriSil(QString MusteriNo);


private:
    Liste u_uyemusteriler;
};

#endif // OOUYEMUSTERIVERIERISIMI_H
