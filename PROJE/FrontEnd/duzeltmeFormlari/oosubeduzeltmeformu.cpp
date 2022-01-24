#include "oosubeduzeltmeformu.h"
#include "ui_oosubebilgileriformu.h"

#include "Backend/ooveritabani.h"

OOSubeDuzeltmeFormu::OOSubeDuzeltmeFormu(QWidget *parent)
    : OOSubeBilgileriFormu(parent) {}

void OOSubeDuzeltmeFormu::subeGoster(QString subeKodu) {
    u_ptrSube =
            OOVeriTabani::getNesne()->getSubeErisim().kodaGoreSubeBul(subeKodu);

    gorselGuncelle();

    ui->leSubeKodu->setReadOnly(true);
}

void OOSubeDuzeltmeFormu::accept() {
    VeriGuncelle();
    QDialog::accept();
}
