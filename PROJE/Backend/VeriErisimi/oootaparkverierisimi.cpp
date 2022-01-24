#include "oootaparkverierisimi.h"

OOOtaparkVeriErisimi::OOOtaparkVeriErisimi() {}

shared_ptr<OOOtapark> OOOtaparkVeriErisimi::otapark()
{
    if(u_ptrOtapark.get()==nullptr) {
        u_ptrOtapark = make_shared<OOOtapark>();
    }
    return u_ptrOtapark;
}

void OOOtaparkVeriErisimi::yukle(QDataStream &kaydedici)
{
    QString otaparkAdi, Adres, Eposta, SosyalMedya, telefon;
    QDate kurulusTarihi;

    kaydedici >> otaparkAdi
              >> Adres
              >> Eposta
              >> kurulusTarihi
              >> SosyalMedya
              >> telefon;

    auto otprk = otapark();

    otprk->setAdi(otaparkAdi);
    otprk->getIletisim().setAdres(Adres);
    otprk->getIletisim().setEPosta(Eposta);
    otprk->getIletisim().setSosyalMedya(SosyalMedya);
    otprk->getIletisim().setTelefon(telefon);

}

void OOOtaparkVeriErisimi::kaydet(QDataStream &kaydedici)
{
    kaydedici << u_ptrOtapark->getAdi()
              << u_ptrOtapark->getIletisim().getAdres()
              << u_ptrOtapark->getIletisim().getEPosta()
              << u_ptrOtapark->getIletisim().getKurulusTarihi()
              << u_ptrOtapark->getIletisim().getSosyalMedya()
              << u_ptrOtapark->getIletisim().getTelefon();

}

