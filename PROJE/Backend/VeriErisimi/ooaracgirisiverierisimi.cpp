#include "ooaracgirisiverierisimi.h"

OOAracGirisiVeriErisimi::OOAracGirisiVeriErisimi() {}

OOAracGirisiVeriErisimi::pointer OOAracGirisiVeriErisimi::yeniAracGirisi() {
    return make_shared<Veri>();
}

void OOAracGirisiVeriErisimi::listeyeEkle(OOAracGirisiVeriErisimi::pointer Aracgirisi)
{
    for(auto Aracgirisi_i : u_Aracgirisleri) {
            if(Aracgirisi->getPlaka() == Aracgirisi_i->getPlaka()) {
                throw invalid_argument("Aynı Plakaya Sahip Başka Bir Araç Var!");
            }
        }
    u_Aracgirisleri.push_back(Aracgirisi);
}

OOAracGirisiVeriErisimi::pointer
OOAracGirisiVeriErisimi::PlakayaGoreAracBul(QString arananplaka) {
    pointer sonuc;
    for(auto aracgirisi_i : u_Aracgirisleri) {
        if(arananplaka == aracgirisi_i->getPlaka()) {
            sonuc = aracgirisi_i;
            break;
        }
    }
    return sonuc;
}

OOAracGirisiVeriErisimi::Liste
OOAracGirisiVeriErisimi::RengeGoreAracBul(QString arananRenk, OOAracGirisiVeriErisimi::AramaTuru tur) {
    Liste sonuc;
    for(auto aracgirisi_i : u_Aracgirisleri) {
        if(tur == AT_Iceren && aracgirisi_i->getRenk().contains(arananRenk)) {
            sonuc.push_back(aracgirisi_i);
        }
        if(tur == AT_IleBaslayan && aracgirisi_i->getRenk().startsWith(arananRenk)) {
            sonuc.push_back(aracgirisi_i);
        }
        if(tur == AT_IleBiten && aracgirisi_i->getRenk().endsWith(arananRenk)) {
            sonuc.push_back(aracgirisi_i);
        }
    }
    return sonuc;
}

OOAracGirisiVeriErisimi::Liste
OOAracGirisiVeriErisimi::GirisTarihineGoreAracBul(QDate baslangic, QDate bitis) {
    Liste sonuc;
    for(auto aracgirisi_i : u_Aracgirisleri) {
        if(aracgirisi_i->getGirisTarihSaat() >= baslangic &&
                aracgirisi_i->getGirisTarihSaat() <= bitis) {
            sonuc.push_back(aracgirisi_i);
        }
    }
    return sonuc;
}

OOAracGirisiVeriErisimi::Liste OOAracGirisiVeriErisimi::GirisTarihineGoreAracBul(QDate tarih) {
    return GirisTarihineGoreAracBul(tarih, tarih);
}

void OOAracGirisiVeriErisimi::AracSil(QString plaka)
{
    pointer silinecek;
    for(auto aracgirisi_i : u_Aracgirisleri) {
        if(plaka == aracgirisi_i->getPlaka()) {
            silinecek = aracgirisi_i;
            u_Aracgirisleri.removeOne(silinecek);
            break;
        }
    }
}


