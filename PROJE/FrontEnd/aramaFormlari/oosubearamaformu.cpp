#include "oosubearamaformu.h"
#include "ui_oosubearamaformu.h"

#include "FrontEnd/duzeltmeFormlari/oosubeduzeltmeformu.h"
#include "Backend/ooveritabani.h"

#include <QMessageBox>
#include <QPushButton>
#include <QTableWidgetItem>

OOSubeAramaFormu::OOSubeAramaFormu(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::OOSubeAramaFormu)
{
    ui->setupUi(this);

    ui->btnAra->click();
}

OOSubeAramaFormu::~OOSubeAramaFormu() { delete ui; }

void OOSubeAramaFormu::on_btnAra_clicked() {
    OOSubeVeriErisimi::AramaTuru tur;
    if(ui->rbIleBaslayan->isChecked()) {
        tur = OOSubeVeriErisimi::AT_IleBaslayan;
    }
    if(ui->rbIceren->isChecked()) {
        tur = OOSubeVeriErisimi::AT_Iceren;
    }
    if(ui->rbIleBiten->isChecked()) {
        tur = OOSubeVeriErisimi::AT_IleBiten;
    }
    auto SubeListesi = OOVeriTabani::getNesne()->getSubeErisim().adaGoreSubeBul(
                ui->leArananSubeAdi->text(), tur);

    ui->tableWidget->setRowCount(SubeListesi.size());

    int satir = 0;

    for(auto sube : SubeListesi) {
        QString subeKodu = sube->getSubeKodu();
        QString subeAdi = sube->getSubeAdi();
        QDate subeTarih = sube->getIletisim().getKurulusTarihi();
        QString subeTel = sube->getIletisim().getTelefon();

        QTableWidgetItem *kodHucresi = new QTableWidgetItem;
        kodHucresi->setText(subeKodu);
        ui->tableWidget->setItem(satir, 0, kodHucresi);

        QTableWidgetItem *adHucresi = new QTableWidgetItem;
        adHucresi->setText(subeAdi);
        ui->tableWidget->setItem(satir, 1, adHucresi);

        QTableWidgetItem *tarihHucresi = new QTableWidgetItem;
        tarihHucresi->setText(subeTarih.toString());
        ui->tableWidget->setItem(satir, 2, tarihHucresi);

        QTableWidgetItem *telHucresi = new QTableWidgetItem;
        telHucresi->setText(subeTel);
        ui->tableWidget->setItem(satir, 3, telHucresi);

        QPushButton *silmeButonu = new QPushButton(ui->tableWidget);
        silmeButonu->setText(tr("Şube Sil"));
        ui->tableWidget->setCellWidget(satir, 5, silmeButonu);

        auto silmeButonuFonksiyonu = [this, subeAdi, subeKodu](){
           auto cevap = QMessageBox::question(
                       this, tr("Uyari"),
                       tr("%1 Şubeyi Silmek İstediginize Emin misiniz?").arg(subeAdi));
           if(cevap == QMessageBox::Yes) {
               OOVeriTabani::getNesne()->getSubeErisim().subeSil(subeKodu);
               this->ui->btnAra->click();
           }
        };

        connect(silmeButonu, &QPushButton::clicked, silmeButonuFonksiyonu);

        QPushButton *duzenleButonu = new QPushButton(ui->tableWidget);
        duzenleButonu->setText(tr("Şube Düzelt"));
        ui->tableWidget->setCellWidget(satir, 4, duzenleButonu);

        auto duzeltmeButonuFonksiyonu = [subeKodu, this](){
           OOSubeDuzeltmeFormu form;

           form.subeGoster(subeKodu);

           auto sonuc = form.exec();

           if(sonuc = QDialog::Accepted) {
               this->ui->btnAra->click();
           }
        };

        connect(duzenleButonu, &QPushButton::clicked, duzeltmeButonuFonksiyonu);

        satir++;
    }
}

void OOSubeAramaFormu::on_leArananSubeAdi_textChanged(const QString &arg1)
{
    if(ui->cbYazarkenAra->isChecked()) {
        ui->btnAra->click();
    }
}
