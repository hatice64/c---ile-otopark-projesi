#include "oouyemusteriverierisimi.h"

OOUyeMusteriVeriErisimi::OOUyeMusteriVeriErisimi() {}

OOUyeMusteriVeriErisimi::pointer OOUyeMusteriVeriErisimi::yeniuyeMusteri() {
    return make_shared<Veri>();
}

void OOUyeMusteriVeriErisimi::listeyeEkle(OOUyeMusteriVeriErisimi::pointer uyemusteri) {
    for(auto uyemusteri_i : u_uyemusteriler) {
        if(uyemusteri->getMusteriNo() == uyemusteri_i->getMusteriNo()) {
            throw invalid_argument("Aynı Müşteri Numarasına Sahip Başka Bir Müşteri Var!");
        }
    }
    u_uyemusteriler.push_back(uyemusteri);
}

OOUyeMusteriVeriErisimi::pointer
OOUyeMusteriVeriErisimi::TCGoreMusteriBul(QString arananTC)
{
    pointer sonuc;
    for(auto uyemusteri_i : u_uyemusteriler) {
        if(arananTC == uyemusteri_i->getKisiselBilgiler().getTCKimlik()) {
            sonuc = uyemusteri_i;
            break;
        }
    }
    return sonuc;

}

OOUyeMusteriVeriErisimi::Liste
OOUyeMusteriVeriErisimi::adaGoreMusteriBul(QString arananAd, OOUyeMusteriVeriErisimi::AramaTuru tur)
{
    Liste sonuc;
    for(auto uyemusteri_i : u_uyemusteriler) {
        if(tur == AT_Iceren && uyemusteri_i->getKisiselBilgiler().getAdSoyad().contains(arananAd)) {
            sonuc.push_back(uyemusteri_i);
        }
        if(tur == AT_IleBaslayan && uyemusteri_i->getKisiselBilgiler().getAdSoyad().startsWith(arananAd)) {
            sonuc.push_back(uyemusteri_i);
        }
        if(tur == AT_IleBiten && uyemusteri_i->getKisiselBilgiler().getAdSoyad().endsWith(arananAd)) {
            sonuc.push_back(uyemusteri_i);
        }
    }
    return sonuc;
}

void OOUyeMusteriVeriErisimi::uyemusteriSil(QString MusteriNo)
{
    pointer silinecek;
    for(auto uyemusteri_i : u_uyemusteriler) {
        if(MusteriNo == uyemusteri_i->getMusteriNo()) {
            silinecek = uyemusteri_i;
            u_uyemusteriler.removeOne(silinecek);
            break;
        }
    }
}
