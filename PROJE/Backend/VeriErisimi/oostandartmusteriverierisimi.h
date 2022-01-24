#ifndef OOSTANDARTMUSTERIVERIERISIMI_H
#define OOSTANDARTMUSTERIVERIERISIMI_H

#include "Backend/Veriler/oostandartmusteri.h"
#include <QVector>
#include <memory>

using namespace std;

class OOStandartMusteriVeriErisimi
{
public:
    typedef OOStandartMusteri Veri;
    typedef shared_ptr<Veri> pointer;
    typedef  QVector<pointer> Liste;

    typedef enum { AT_IleBaslayan = 1, AT_IleBiten = 2, AT_Iceren = 3} AramaTuru;


    OOStandartMusteriVeriErisimi();

    pointer yeniStandartMusteri();

    void listeyeEkle(pointer standartmusteri);

    pointer TCGoreMusteriBul(QString arananTC);
    Liste adaGoreMusteriBul(QString arananAd, AramaTuru tur);

    void standartmusteriSil(QString MusteriNo);


private:
    Liste u_standartmusteriler;
};

#endif // OOSTANDARTMUSTERIVERIERISIMI_H
