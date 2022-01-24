#include "oostandartmusteriaramaformu.h"
#include "ui_oostandartmusteriaramaformu.h"

#include "Backend/VeriErisimi/oostandartmusteriverierisimi.h"
#include "Backend/ooveritabani.h"
#include "FrontEnd/duzeltmeFormlari/oostandartmusteriduzeltmeformu.h"

#include <QMessageBox>
#include <QPushButton>
#include <QTableWidgetItem>

OOStandartMusteriAramaFormu::OOStandartMusteriAramaFormu(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::OOStandartMusteriAramaFormu)
{
    ui->setupUi(this);

    ui->btnAra->click();
}

OOStandartMusteriAramaFormu::~OOStandartMusteriAramaFormu()
{
    delete ui;
}

void OOStandartMusteriAramaFormu::on_btnAra_clicked()
{
    OOStandartMusteriVeriErisimi::AramaTuru tur;
    if(ui->rbIleBaslayan->isChecked()) {
        tur = OOStandartMusteriVeriErisimi::AT_IleBaslayan;
    }
    if(ui->rbIceren->isChecked()) {
        tur = OOStandartMusteriVeriErisimi::AT_Iceren;
    }
    if(ui->rbIleBiten->isChecked()) {
        tur = OOStandartMusteriVeriErisimi::AT_IleBiten;
    }
    auto StandartMusteriListesi = OOVeriTabani::getNesne()->getStandartMusteriErisim().adaGoreMusteriBul(
                ui->leArananMusteriAdi->text(), tur);

    ui->tableWidget->setRowCount(StandartMusteriListesi.size());

    int satir = 0;

    for(auto standartmusteri : StandartMusteriListesi) {
        QString adisoyadi = standartmusteri->getKisiselBilgiler().getAdSoyad();
        QString TCKimlikNo = standartmusteri->getKisiselBilgiler().getTCKimlik();
        QString MusteriNo = standartmusteri->getMusteriNo();
        QString Tel = standartmusteri->getKisiselBilgiler().getTelefon();

        QTableWidgetItem *kodHucresi = new QTableWidgetItem;
        kodHucresi->setText(adisoyadi);
        ui->tableWidget->setItem(satir, 0, kodHucresi);

        QTableWidgetItem *adHucresi = new QTableWidgetItem;
        adHucresi->setText(TCKimlikNo);
        ui->tableWidget->setItem(satir, 1, adHucresi);

        QTableWidgetItem *tarihHucresi = new QTableWidgetItem;
        tarihHucresi->setText(MusteriNo);
        ui->tableWidget->setItem(satir, 2, tarihHucresi);

        QTableWidgetItem *telHucresi = new QTableWidgetItem;
        telHucresi->setText(Tel);
        ui->tableWidget->setItem(satir, 3, telHucresi);

        QPushButton *silmeButonu = new QPushButton(ui->tableWidget);
        silmeButonu->setText(tr("Müşteri Sil"));
        ui->tableWidget->setCellWidget(satir, 5, silmeButonu);

        auto silmeButonuFonksiyonu = [this, adisoyadi, MusteriNo](){
           auto cevap = QMessageBox::question(
                       this, tr("Uyari"),
                       tr("%1 Müşteriyi Silmek İstediginize Emin misiniz?").arg(adisoyadi));
           if(cevap == QMessageBox::Yes) {
               OOVeriTabani::getNesne()->getStandartMusteriErisim().standartmusteriSil(MusteriNo);
               this->ui->btnAra->click();
           }
        };

        connect(silmeButonu, &QPushButton::clicked, silmeButonuFonksiyonu);

        QPushButton *duzenleButonu = new QPushButton(ui->tableWidget);
        duzenleButonu->setText(tr("Müşteriyi Düzelt"));
        ui->tableWidget->setCellWidget(satir, 4, duzenleButonu);

        auto duzeltmeButonuFonksiyonu = [TCKimlikNo, this](){
           OOStandartMusteriDuzeltmeFormu form;

           form.standartmusteriGoster(TCKimlikNo);

            auto sonuc = form.exec();

            if(sonuc = QDialog::Accepted) {
                this->ui->btnAra->click();
            }
        };

        connect(duzenleButonu, &QPushButton::clicked, duzeltmeButonuFonksiyonu);

        satir++;
    }

        };

void OOStandartMusteriAramaFormu::on_leArananMusteriAdi_textChanged(const QString &arg1)
{
    if(ui->cbYazarkenAra->isChecked()) {
        ui->btnAra->click();
    }
}
