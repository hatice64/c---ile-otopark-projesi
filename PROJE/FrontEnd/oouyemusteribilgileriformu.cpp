#include "oouyemusteribilgileriformu.h"
#include "ui_oouyemusteribilgileriformu.h"

#include "Backend/ooveritabani.h"

#include <QMessageBox>

void OOUyeMusteriBilgileriFormu::ekraniGuncelle()
{
    ui->leUyeNo->setText(u_ptruyemusteri->getUyeNo());
    ui->leMusteriNo->setText(u_ptruyemusteri->getMusteriNo());
    ui->leAdSoyad->setText(u_ptruyemusteri->getKisiselBilgiler().getAdSoyad());
    ui->leTCNo->setText(u_ptruyemusteri->getKisiselBilgiler().getTCKimlik());
    ui->deDogumTarihi->setDate(u_ptruyemusteri->getKisiselBilgiler().getDogumTarihi());
    ui->leTelefon->setText(u_ptruyemusteri->getKisiselBilgiler().getTelefon());
    ui->leEposta->setText(u_ptruyemusteri->getKisiselBilgiler().getEPosta());
    ui->pteAdres->setPlainText(u_ptruyemusteri->getKisiselBilgiler().getAdres());
    ui->leInstagram->setText(u_ptruyemusteri->getKisiselBilgiler().getInstagram());

    u_bDegisiklikVarMi = false;
}

OOUyeMusteriBilgileriFormu::OOUyeMusteriBilgileriFormu(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::OOUyeMusteriBilgileriFormu)
{
    ui->setupUi(this);

    u_ptruyemusteri = OOVeriTabani::getNesne()->getUyeMusteriErisim().yeniuyeMusteri();

    ekraniGuncelle();
}

OOUyeMusteriBilgileriFormu::~OOUyeMusteriBilgileriFormu() { delete ui; }

void OOUyeMusteriBilgileriFormu::degisiklikVar() { u_bDegisiklikVarMi = true; }

void OOUyeMusteriBilgileriFormu::veriGuncelle()
{
    u_ptruyemusteri->setUyeNo(ui->leUyeNo->text());
    u_ptruyemusteri->setMusteriNo(ui->leMusteriNo->text());
    u_ptruyemusteri->getKisiselBilgiler().setAdSoyad(ui->leAdSoyad->text());
    u_ptruyemusteri->getKisiselBilgiler().setTCKimlik(ui->leTCNo->text());
    u_ptruyemusteri->getKisiselBilgiler().setDogumTarihi(ui->deDogumTarihi->date());
    u_ptruyemusteri->getKisiselBilgiler().setTelefon(ui->leTelefon->text());
    u_ptruyemusteri->getKisiselBilgiler().setEPosta(ui->leEposta->text());
    u_ptruyemusteri->getKisiselBilgiler().setAdres(ui->pteAdres->toPlainText());
    u_ptruyemusteri->getKisiselBilgiler().setInstagram(ui->leInstagram->text());
}

void OOUyeMusteriBilgileriFormu::accept() {

    veriGuncelle();

    try {
        OOVeriTabani::getNesne()->getUyeMusteriErisim().listeyeEkle(u_ptruyemusteri);

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

void OOUyeMusteriBilgileriFormu::reject() {
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

void OOUyeMusteriBilgileriFormu::on_btnTemizle_clicked() {

    ui->leUyeNo->clear();
    ui->leEposta->clear();
    ui->leMusteriNo->clear();
    ui->leInstagram->clear();
    ui->leAdSoyad->clear();
    ui->leTCNo->clear();
    ui->leTelefon->clear();
    ui->deDogumTarihi->clear();
    ui->pteAdres->clear();

    u_bDegisiklikVarMi = false;
    ui->leTCNo->setFocus();
}
