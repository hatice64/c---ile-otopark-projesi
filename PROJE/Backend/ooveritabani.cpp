#include "ooveritabani.h"

#include <QDataStream>
#include <QFile>
#include <QStandardPaths>

OOVeriTabani *OOVeriTabani::u_ptrNesne=nullptr;

OOVeriTabani::OOVeriTabani() {}

OOAracCikisiVeriErisimi &OOVeriTabani::getAracCikisiErisim() { return u_AracCikisiErisim; }

void OOVeriTabani::yukle()
{
    QString dosyaYolu =
            QStandardPaths::writableLocation(QStandardPaths::DocumentsLocation);
    QString dosyaTamAdi = dosyaYolu+"/oootapark.data";

    QFile veriDosyasi(dosyaTamAdi);
    if(veriDosyasi.open(QIODevice::ReadOnly)) {
        QDataStream kaydedici(&veriDosyasi);

        u_OtaparkErisim.yukle(kaydedici);
        u_SubeErisim.yukle(kaydedici);

        veriDosyasi.close();
    }
}

void OOVeriTabani::sakla()
{
  QString dosyaYolu =
          QStandardPaths::writableLocation(QStandardPaths::DocumentsLocation);
  QString dosyaTamAdi = dosyaYolu+"/oootapark.data";

  QFile veriDosyasi(dosyaTamAdi);
  if(veriDosyasi.open(QIODevice::WriteOnly)) {
      QDataStream kaydedici(&veriDosyasi);

      u_OtaparkErisim.kaydet(kaydedici);
      u_SubeErisim.kaydet(kaydedici);

      veriDosyasi.close();
  }
}

OOAracGirisiVeriErisimi &OOVeriTabani::getAracGirisiErisim() { return u_AracGirisiErisim; }

OOAracVeriErisimi &OOVeriTabani::getAracErisim() { return u_AracErisim; }

OOStandartMusteriVeriErisimi &OOVeriTabani::getStandartMusteriErisim() { return u_StandartMusteriErisim; }

OOUyeMusteriVeriErisimi &OOVeriTabani::getUyeMusteriErisim() { return u_UyeMusteriErisim; }

OOMusteriVeriErisimi &OOVeriTabani::getMusteriErisim() { return u_MusteriErisim; }

OOSubeVeriErisimi &OOVeriTabani::getSubeErisim() { return u_SubeErisim; }

OOOtaparkVeriErisimi &OOVeriTabani::getOtaparkErisim() { return u_OtaparkErisim; }

OOVeriTabani *OOVeriTabani::getNesne()
{
    if(u_ptrNesne==nullptr) {
        u_ptrNesne = new OOVeriTabani;
    }
    return u_ptrNesne;
}
