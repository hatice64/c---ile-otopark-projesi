#include "oootoparkbilgilerformu.h"
#include "ui_oootoparkbilgilerformu.h"

#include "Backend/ooveritabani.h"

#include <QMessageBox>

OOOtoparkBilgilerFormu::OOOtoparkBilgilerFormu(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::OOOtoparkBilgilerFormu)
{
    ui->setupUi(this);

    auto otapark = OOVeriTabani::getNesne()->getOtaparkErisim().otapark();

    ui->leOtaparkAdi->setText(otapark->getAdi());
    ui->deKurulusTarihi->setDate(otapark->getIletisim().getKurulusTarihi());
    ui->pteAdres->setPlainText(otapark->getIletisim().getAdres());
    ui->leEposta->setText(otapark->getIletisim().getEPosta());
    ui->leInstagram->setText(otapark->getIletisim().getSosyalMedya());
    ui->leTelefon->setText(otapark->getIletisim().getTelefon());

    u_bDegisiklikVarMi = false;
}

OOOtoparkBilgilerFormu::~OOOtoparkBilgilerFormu() { delete ui; }

void OOOtoparkBilgilerFormu::accept()
{
    auto otapark = OOVeriTabani::getNesne()->getOtaparkErisim().otapark();

    otapark->setAdi(ui->leOtaparkAdi->text());
    otapark->getIletisim().setAdres(ui->pteAdres->toPlainText());
    otapark->getIletisim().setEPosta(ui->leEposta->text());
    otapark->getIletisim().setKurulusTarihi(ui->deKurulusTarihi->date());
    otapark->getIletisim().setSosyalMedya(ui->leInstagram->text());
    otapark->getIletisim().setTelefon(ui->leTelefon->text());

    QDialog::accept();
}

void OOOtoparkBilgilerFormu::reject() {
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

void OOOtoparkBilgilerFormu::DegisiklikYapildi() { u_bDegisiklikVarMi = true; }

void OOOtoparkBilgilerFormu::on_btnTemizle_clicked()
{
    ui->leEposta->clear();
    ui->leInstagram->clear();
    ui->leTelefon->clear();
    ui->deKurulusTarihi->clear();
    ui->pteAdres->clear();
    ui->leOtaparkAdi->clear();

    u_bDegisiklikVarMi = false;

}
