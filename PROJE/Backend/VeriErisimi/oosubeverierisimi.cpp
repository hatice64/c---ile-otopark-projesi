#include "oosubeverierisimi.h"

#include <exception>
#include <QDataStream>

OOSubeVeriErisimi::OOSubeVeriErisimi() {}

OOSubeVeriErisimi::pointer OOSubeVeriErisimi::yeniSube() {
    return make_shared<Veri>();
}

void OOSubeVeriErisimi::listeyeEkle(OOSubeVeriErisimi::pointer sube) {
    for(auto sube_i : u_Subeler) {
        if(sube->getSubeKodu() == sube_i->getSubeKodu()) {
            throw invalid_argument("Aynı Şube Koduna Sahip Başka Bir Otopark Şubesi Var!");
        }
    }
    u_Subeler.push_back(sube);
}

OOSubeVeriErisimi::pointer
OOSubeVeriErisimi::kodaGoreSubeBul(QString arananKod) {
    pointer sonuc;
    for(auto sube_i : u_Subeler) {
        if(arananKod == sube_i->getSubeKodu()) {
            sonuc = sube_i;
            break;
        }
    }
    return sonuc;
}

OOSubeVeriErisimi::Liste
OOSubeVeriErisimi::adaGoreSubeBul(QString arananAd, OOSubeVeriErisimi::AramaTuru tur) {
    Liste sonuc;
    for(auto sube_i : u_Subeler) {
        if(tur == AT_Iceren && sube_i->getSubeAdi().contains(arananAd)) {
            sonuc.push_back(sube_i);
        }
        if(tur == AT_IleBaslayan && sube_i->getSubeAdi().startsWith(arananAd)) {
            sonuc.push_back(sube_i);
        }
        if(tur == AT_IleBiten && sube_i->getSubeAdi().endsWith(arananAd)) {
            sonuc.push_back(sube_i);
        }
    }
    return sonuc;
}

OOSubeVeriErisimi::Liste
OOSubeVeriErisimi::kurulusTarihineGoreSubeBul(QDate baslangic, QDate bitis) {
    Liste sonuc;
    for(auto sube_i : u_Subeler) {
        if(sube_i->getIletisim().getKurulusTarihi()>=baslangic &&
                sube_i->getIletisim().getKurulusTarihi()<=bitis) {
            sonuc.push_back(sube_i);
        }
    }
    return sonuc;
}

OOSubeVeriErisimi::Liste
OOSubeVeriErisimi::kurulusTarihineGoreSubeBul(QDate tarih) {
    return kurulusTarihineGoreSubeBul(tarih, tarih);
}

void OOSubeVeriErisimi::subeSil(QString subeKodu) {
    pointer silinecek;
    for(auto sube_i : u_Subeler) {
        if(subeKodu == sube_i->getSubeKodu()) {
            silinecek = sube_i;
            u_Subeler.removeOne(silinecek);
            break;
        }
    }
}

void OOSubeVeriErisimi::kaydet(QDataStream &kaydedici)
{
    kaydedici << u_Subeler.size();

    for(auto sube_i : u_Subeler) {
        kaydedici << sube_i->getSubeAdi() << sube_i->getSubeKodu()
                  << sube_i->getIletisim().getAdres()
                  << sube_i->getIletisim().getEPosta()
                  << sube_i->getIletisim().getKurulusTarihi()
                  << sube_i->getIletisim().getSosyalMedya()
                  << sube_i->getIletisim().getTelefon();

    }
}

void OOSubeVeriErisimi::yukle(QDataStream &kaydedici)
{  int elemanSayisi = u_Subeler.size();
    kaydedici << elemanSayisi;

    QString SubeKodu, SubeAdi, adres, Eposta, sosyalmedya, telefon;
    QDate KurulusTarihi;

    int subeSayisi;
    kaydedici >> subeSayisi;

    for(int i = 0; i<subeSayisi; i++) {
        kaydedici >> SubeKodu >> SubeAdi >> adres >> Eposta >> KurulusTarihi >>
                sosyalmedya >> telefon;

        auto yeniSube = this->yeniSube();
        yeniSube->setSubeKodu(SubeKodu);
        yeniSube->setSubeAdi(SubeAdi);
        yeniSube->getIletisim().setAdres(adres);
        yeniSube->getIletisim().setEPosta(Eposta);
        yeniSube->getIletisim().setKurulusTarihi(KurulusTarihi);
        yeniSube->getIletisim().setSosyalMedya(sosyalmedya);
        yeniSube->getIletisim().setTelefon(telefon);
        listeyeEkle(yeniSube);
    }
}
