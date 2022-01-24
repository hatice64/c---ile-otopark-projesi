#include "oostandartmusteriverierisimi.h"

OOStandartMusteriVeriErisimi::OOStandartMusteriVeriErisimi() {}

OOStandartMusteriVeriErisimi::pointer OOStandartMusteriVeriErisimi::yeniStandartMusteri() {
    return make_shared<Veri>();
}

void OOStandartMusteriVeriErisimi::listeyeEkle(OOStandartMusteriVeriErisimi::pointer standartmusteri) {
    for(auto standartmusteri_i : u_standartmusteriler) {
        if(standartmusteri->getMusteriNo() == standartmusteri_i->getMusteriNo()) {
            throw invalid_argument("Aynı Müşteri Numarasına Sahip Başka Bir Müşteri Var!");
        }
    }
    u_standartmusteriler.push_back(standartmusteri);
}

OOStandartMusteriVeriErisimi::pointer OOStandartMusteriVeriErisimi::TCGoreMusteriBul(QString arananTC)
{
    pointer sonuc;
    for(auto standartmusteri_i : u_standartmusteriler) {
        if(arananTC == standartmusteri_i->getKisiselBilgiler().getTCKimlik()) {
            sonuc = standartmusteri_i;
            break;
        }
    }
    return sonuc;
}

OOStandartMusteriVeriErisimi::Liste OOStandartMusteriVeriErisimi::adaGoreMusteriBul(QString arananAd, OOStandartMusteriVeriErisimi::AramaTuru tur)
{
    Liste sonuc;
    for(auto standartmusteri_i : u_standartmusteriler) {
        if(tur == AT_Iceren && standartmusteri_i->getKisiselBilgiler().getAdSoyad().contains(arananAd)) {
            sonuc.push_back(standartmusteri_i);
        }
        if(tur == AT_IleBaslayan && standartmusteri_i->getKisiselBilgiler().getAdSoyad().startsWith(arananAd)) {
            sonuc.push_back(standartmusteri_i);
        }
        if(tur == AT_IleBiten && standartmusteri_i->getKisiselBilgiler().getAdSoyad().endsWith(arananAd)) {
            sonuc.push_back(standartmusteri_i);
        }
    }
    return sonuc;
}

void OOStandartMusteriVeriErisimi::standartmusteriSil(QString musteriNo)
{
    pointer silinecek;
    for(auto standartmusteri_i : u_standartmusteriler) {
        if(musteriNo == standartmusteri_i->getMusteriNo()) {
            silinecek = standartmusteri_i;
            u_standartmusteriler.removeOne(silinecek);
            break;
        }
    }
}
