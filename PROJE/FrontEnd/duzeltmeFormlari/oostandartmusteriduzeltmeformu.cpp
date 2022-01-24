#include "oostandartmusteriduzeltmeformu.h"
#include "ui_oostandartmusteribilgileriformu.h"

#include "Backend/ooveritabani.h"

OOStandartMusteriDuzeltmeFormu::OOStandartMusteriDuzeltmeFormu(QWidget *parent)
    : OOStandartMusteriBilgileriFormu(parent)
{

}

void OOStandartMusteriDuzeltmeFormu::standartmusteriGoster(QString TCKimlikNo)
{
    u_ptrstandartmusteri =
            OOVeriTabani::getNesne()->getStandartMusteriErisim().TCGoreMusteriBul(TCKimlikNo);
   resimGuncelle();

   ui->leTCNo->setReadOnly(true);

}

void OOStandartMusteriDuzeltmeFormu::accept()
{
    veriGuncelle();
    QDialog::accept();
}
