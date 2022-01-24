#include "ooaraccikisbilgileriformu.h"
#include "ui_ooaraccikisbilgileriformu.h"
#include "ooaracbilgileriformu.h"

#include "Backend/ooveritabani.h"
#include <QMessageBox>

OOAracCikisBilgileriFormu::OOAracCikisBilgileriFormu(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::OOAracCikisBilgileriFormu)
{
    ui->setupUi(this);

    u_ptrAracCikisi = OOVeriTabani::getNesne()->getAracCikisiErisim().yeniAracCikisi();

    ui->lePlaka->setText(u_ptrAracCikisi->getPlaka());
    ui->deCikisTarihSaat->setDate(u_ptrAracCikisi->getCikisTarihSaat());
    ui->dsbUcret->setAccelerated(u_ptrAracCikisi->getUcret());
    ui->cbKonum->setCurrentText(u_ptrAracCikisi->getKonum());

    u_bDegisiklikVarMi = false;
}

OOAracCikisBilgileriFormu::~OOAracCikisBilgileriFormu() { delete ui; }

void OOAracCikisBilgileriFormu::degisiklikVar() { u_bDegisiklikVarMi = true; }

void OOAracCikisBilgileriFormu::accept() {
    u_ptrAracCikisi->setPlaka(ui->lePlaka->text());
    u_ptrAracCikisi->setCikisTarihSaat(ui->deCikisTarihSaat->date());
    u_ptrAracCikisi->setUcret(ui->dsbUcret->acceptDrops());
    u_ptrAracCikisi->setKonum(ui->cbKonum->currentText());

    try {
    OOVeriTabani::getNesne()->getAracCikisiErisim().listeyeEkle(u_ptrAracCikisi);

    QDialog::accept();
    } catch (invalid_argument hata) {
        QMessageBox hataMesaji;

        hataMesaji.setText(hata.what());
        hataMesaji.setStandardButtons(QMessageBox::Ok);

        hataMesaji.setButtonText(QMessageBox::Ok, tr("Tamam"));

        hataMesaji.setIcon(QMessageBox::Critical);

        hataMesaji.exec();

}
}
void OOAracCikisBilgileriFormu::reject() {
    QMessageBox soru;

    soru.setText(tr("Degişiklikleri Kaydetmeden Çıkmak İstediginize Emin Misiniz?"));
    soru.setStandardButtons(QMessageBox::Yes | QMessageBox::No);

    soru.setButtonText(QMessageBox::Yes, tr("Evet"));
    soru.setButtonText(QMessageBox::No, tr("Hayır"));

    soru.setIcon(QMessageBox::Warning);

    soru.setInformativeText(tr("Bu soruya Evet cevabı verirseniz yaptıgınız "
                               "degişiklikler kalıcı olarak silinecektir."));

    if(u_bDegisiklikVarMi == true) {
        if(soru.exec()== QMessageBox::Yes) {
            QDialog::reject();
        }
      } else {
        QDialog::reject();
    }
}

void OOAracCikisBilgileriFormu::on_btnTemizle_clicked()
{
    ui->lePlaka->clear();
    ui->deCikisTarihSaat->clear();
    ui->dsbUcret->clear();
    ui->cbKonum->clear();

    u_bDegisiklikVarMi = false;

    ui->lePlaka->setFocus();
}
