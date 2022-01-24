#include "oouyemusteriduzeltmeformu.h"
#include "ui_oouyemusteribilgileriformu.h"

#include "Backend/ooveritabani.h"

OOUyeMusteriDuzeltmeFormu::OOUyeMusteriDuzeltmeFormu(QWidget *parent)
    : OOUyeMusteriBilgileriFormu(parent)
{

}

void OOUyeMusteriDuzeltmeFormu::uyemusteriGoster(QString TCKimlikNo) {
    u_ptruyemusteri =
            OOVeriTabani::getNesne()->getUyeMusteriErisim().TCGoreMusteriBul(TCKimlikNo);

    ekraniGuncelle();

    ui->leTCNo->setReadOnly(true);
}

void OOUyeMusteriDuzeltmeFormu::accept() {
    veriGuncelle();
    QDialog::accept();
}
