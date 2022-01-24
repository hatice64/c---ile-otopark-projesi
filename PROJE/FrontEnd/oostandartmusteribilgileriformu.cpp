#include "oostandartmusteribilgileriformu.h"
#include "ui_oostandartmusteribilgileriformu.h"

#include "Backend/ooveritabani.h"

#include <QMessageBox>

void OOStandartMusteriBilgileriFormu::resimGuncelle()
{
    ui->leMusteriNo->setText(u_ptrstandartmusteri->getMusteriNo());
    ui->leTCNo->setText(u_ptrstandartmusteri->getKisiselBilgiler().getTCKimlik());
    ui->leAdSoyad->setText(u_ptrstandartmusteri->getKisiselBilgiler().getAdSoyad());
    ui->deDogumTarihi->setDate(u_ptrstandartmusteri->getKisiselBilgiler().getDogumTarihi());
    ui->pteAdres->setPlainText(u_ptrstandartmusteri->getKisiselBilgiler().getAdres());
    ui->leTelefon->setText(u_ptrstandartmusteri->getKisiselBilgiler().getTelefon());
    ui->leEposta->setText(u_ptrstandartmusteri->getKisiselBilgiler().getEPosta());
    ui->leInstagram->setText(u_ptrstandartmusteri->getKisiselBilgiler().getInstagram());
}

OOStandartMusteriBilgileriFormu::OOStandartMusteriBilgileriFormu(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::OOStandartMusteriBilgileriFormu)
{
    ui->setupUi(this);

    u_ptrstandartmusteri = OOVeriTabani::getNesne()->getStandartMusteriErisim().yeniStandartMusteri();

    resimGuncelle();

    u_bDegisiklikVarMi = false;
}

OOStandartMusteriBilgileriFormu::~OOStandartMusteriBilgileriFormu() { delete ui; }

void OOStandartMusteriBilgileriFormu::degisiklikVar() { u_bDegisiklikVarMi = true; }

void OOStandartMusteriBilgileriFormu::veriGuncelle()
{
    u_ptrstandartmusteri->setMusteriNo(ui->leMusteriNo->text());
    u_ptrstandartmusteri->getKisiselBilgiler().setTCKimlik(ui->leTCNo->text());
    u_ptrstandartmusteri->getKisiselBilgiler().setAdSoyad(ui->leAdSoyad->text());
    u_ptrstandartmusteri->getKisiselBilgiler().setDogumTarihi(ui->deDogumTarihi->date());
    u_ptrstandartmusteri->getKisiselBilgiler().setAdres(ui->pteAdres->toPlainText());
    u_ptrstandartmusteri->getKisiselBilgiler().setTelefon(ui->leTelefon->text());
    u_ptrstandartmusteri->getKisiselBilgiler().setEPosta(ui->leEposta->text());
    u_ptrstandartmusteri->getKisiselBilgiler().setInstagram(ui->leInstagram->text());
}

void OOStandartMusteriBilgileriFormu::accept() {

     veriGuncelle();

     try {
         OOVeriTabani::getNesne()->getStandartMusteriErisim().listeyeEkle(u_ptrstandartmusteri);

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

void OOStandartMusteriBilgileriFormu::reject() {
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

void OOStandartMusteriBilgileriFormu::on_btnTemizle_clicked() {

        ui->leMusteriNo->clear();
        ui->leEposta->clear();
        ui->leInstagram->clear();
        ui->leAdSoyad->clear();
        ui->leTCNo->clear();
        ui->leTelefon->clear();
        ui->deDogumTarihi->clear();
        ui->pteAdres->clear();

        u_bDegisiklikVarMi = false;
        ui->leTCNo->setFocus();
}
