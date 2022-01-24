#include "ooaracgirisbilgileriformu.h"
#include "ui_ooaracgirisbilgileriformu.h"
#include "ooaracbilgileriformu.h"

#include "Backend/ooveritabani.h"
#include <QMessageBox>

void OOAracGirisBilgileriFormu::gorselGuncelle()
{
    ui->sbAracNo->setAccelerated(u_ptrAracGirisi->getAracNo());
    ui->lePlaka->setText(u_ptrAracGirisi->getPlaka());
    ui->leMarka->setText(u_ptrAracGirisi->getMarka());
    ui->leRenk->setText(u_ptrAracGirisi->getRenk());
    ui->pteGirisNedeni->setPlainText(u_ptrAracGirisi->getGirisNedeni());
    ui->deGirisTarihSaat->setDate(u_ptrAracGirisi->getGirisTarihSaat());

    u_bDegisiklikVarMi = false;
}

OOAracGirisBilgileriFormu::OOAracGirisBilgileriFormu(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::OOAracGirisBilgileriFormu)
{
    ui->setupUi(this);

    u_ptrAracGirisi = OOVeriTabani::getNesne()->getAracGirisiErisim().yeniAracGirisi();

    gorselGuncelle();
}

OOAracGirisBilgileriFormu::~OOAracGirisBilgileriFormu() { delete ui; }

void OOAracGirisBilgileriFormu::degisiklikVar() { u_bDegisiklikVarMi = true; }

void OOAracGirisBilgileriFormu::veriGuncelle()
{
    u_ptrAracGirisi->setAracNo(ui->sbAracNo->acceptDrops());
    u_ptrAracGirisi->setPlaka(ui->lePlaka->text());
    u_ptrAracGirisi->setMarka(ui->leMarka->text());
    u_ptrAracGirisi->setRenk(ui->leRenk->text());
    u_ptrAracGirisi->setGirisNedeni(ui->pteGirisNedeni->toPlainText());
    u_ptrAracGirisi->setGirisTarihSaat(ui->deGirisTarihSaat->date());
}

void OOAracGirisBilgileriFormu::accept() {
     veriGuncelle();

     try {
     OOVeriTabani::getNesne()->getAracGirisiErisim().listeyeEkle(u_ptrAracGirisi);

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

void OOAracGirisBilgileriFormu::reject() {
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

void OOAracGirisBilgileriFormu::on_btnTemizle_clicked()
{
    ui->lePlaka->clear();
    ui->sbAracNo->clear();
    ui->leMarka->clear();
    ui->leRenk->clear();
    ui->pteGirisNedeni->clear();
    ui->deGirisTarihSaat->clear();

    u_bDegisiklikVarMi = false;

    ui->lePlaka->setFocus();
}
