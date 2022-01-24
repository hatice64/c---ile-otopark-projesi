#include "oosubebilgileriformu.h"
#include "ui_oosubebilgileriformu.h"

#include "Backend/ooveritabani.h"

#include <QMessageBox>

void OOSubeBilgileriFormu::gorselGuncelle()
{
    ui->leSubeKodu->setText(u_ptrSube->getSubeKodu());
    ui->leSubeAdi->setText(u_ptrSube->getSubeAdi());
    ui->leEposta->setText(u_ptrSube->getIletisim().getEPosta());
    ui->leInstagram->setText(u_ptrSube->getIletisim().getSosyalMedya());
    ui->leTelefon->setText(u_ptrSube->getIletisim().getTelefon());
    ui->deKurulusTarihi->setDate(u_ptrSube->getIletisim().getKurulusTarihi());
    ui->pteAdres->setPlainText(u_ptrSube->getIletisim().getAdres());

    u_bDegisiklikVarMi = false;
}

OOSubeBilgileriFormu::OOSubeBilgileriFormu(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::OOSubeBilgileriFormu)
{
    ui->setupUi(this);

    u_ptrSube = OOVeriTabani::getNesne()->getSubeErisim().yeniSube();

    gorselGuncelle();
}

OOSubeBilgileriFormu::~OOSubeBilgileriFormu() { delete ui; }

void OOSubeBilgileriFormu::DegisiklikVar() { u_bDegisiklikVarMi = true; }

void OOSubeBilgileriFormu::VeriGuncelle()
{
    u_ptrSube->setSubeKodu(ui->leSubeKodu->text());
    u_ptrSube->setSubeAdi(ui->leSubeAdi->text());
    u_ptrSube->getIletisim().setAdres(ui->pteAdres->toPlainText());
    u_ptrSube->getIletisim().setEPosta(ui->leEposta->text());
    u_ptrSube->getIletisim().setKurulusTarihi(ui->deKurulusTarihi->date());
    u_ptrSube->getIletisim().setSosyalMedya(ui->leInstagram->text());
    u_ptrSube->getIletisim().setTelefon(ui->leTelefon->text());
}

void OOSubeBilgileriFormu::accept() {
    VeriGuncelle();

    try {
        OOVeriTabani::getNesne()->getSubeErisim().listeyeEkle(u_ptrSube);

        QDialog::accept();
    } catch (invalid_argument hata) {
        QMessageBox hataMesaji;

        hataMesaji.setText(hata.what());
        hataMesaji.setStandardButtons(QMessageBox::Ok);

        hataMesaji.setButtonText(QMessageBox::Ok, tr("Tamam"));

        hataMesaji.setIcon(QMessageBox::Critical);

        hataMesaji.exec();

        ui->leSubeKodu->setFocus();
        ui->leSubeKodu->selectAll();
    }
}

void OOSubeBilgileriFormu::reject() {
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

void OOSubeBilgileriFormu::on_btnTemizle_clicked()
{
    ui->leEposta->clear();
    ui->leInstagram->clear();
    ui->leSubeAdi->clear();
    ui->leSubeKodu->clear();
    ui->leTelefon->clear();
    ui->deKurulusTarihi->clear();
    ui->pteAdres->clear();

    u_bDegisiklikVarMi = false;

    ui->leSubeKodu->setFocus();
}
