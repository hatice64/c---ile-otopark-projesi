#include "ooaracgirisiduzeltmeformu.h"
#include "ui_ooaracgirisbilgileriformu.h"

#include "Backend/ooveritabani.h"

OOAracGirisiDuzeltmeFormu::OOAracGirisiDuzeltmeFormu(QWidget *parent)
    : OOAracGirisBilgileriFormu(parent)
{

}

void OOAracGirisiDuzeltmeFormu::aracgirisiGoster(QString plaka)
{
    auto AracGirisi =
            OOVeriTabani::getNesne()->getAracGirisiErisim().PlakayaGoreAracBul(plaka);

    gorselGuncelle();

    ui->lePlaka->setReadOnly(true);

}

void OOAracGirisiDuzeltmeFormu::accept()
{
  veriGuncelle();
  QDialog::accept();
}
