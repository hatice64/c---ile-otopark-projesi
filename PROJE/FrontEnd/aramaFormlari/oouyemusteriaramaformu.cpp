#include "oouyemusteriaramaformu.h"
#include "ui_oouyemusteriaramaformu.h"

#include "Backend/VeriErisimi/oouyemusteriverierisimi.h"
#include "Backend/ooveritabani.h"
#include "FrontEnd/duzeltmeFormlari/oouyemusteriduzeltmeformu.h"

#include <QMessageBox>
#include <QPushButton>
#include <QTableWidgetItem>

OOUyeMusteriAramaFormu::OOUyeMusteriAramaFormu(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::OOUyeMusteriAramaFormu)
{
    ui->setupUi(this);
}

OOUyeMusteriAramaFormu::~OOUyeMusteriAramaFormu()
{
    delete ui;
}


void OOUyeMusteriAramaFormu::on_btnAra_clicked()
{
    OOUyeMusteriVeriErisimi::AramaTuru tur;
    if(ui->rbIleBaslayan->isChecked()) {
        tur = OOUyeMusteriVeriErisimi::AT_IleBaslayan;
    }
    if(ui->rbIceren->isChecked()) {
        tur = OOUyeMusteriVeriErisimi::AT_Iceren;
    }
    if(ui->rbIleBiten->isChecked()) {
        tur = OOUyeMusteriVeriErisimi::AT_IleBiten;
    }
    auto UyeMusteriListesi = OOVeriTabani::getNesne()->getUyeMusteriErisim().adaGoreMusteriBul(
                ui->leArananAd->text(), tur);

    ui->tableWidget->setRowCount(UyeMusteriListesi.size());

    int satir = 0;

    for(auto uyemusteri : UyeMusteriListesi) {
        QString adisoyadi = uyemusteri->getKisiselBilgiler().getAdSoyad();
        QString TCKimlikNo = uyemusteri->getKisiselBilgiler().getTCKimlik();
        QString MusteriNo = uyemusteri->getMusteriNo();
        QString Tel = uyemusteri->getKisiselBilgiler().getTelefon();

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
               OOVeriTabani::getNesne()->getUyeMusteriErisim().uyemusteriSil(MusteriNo);
               this->ui->btnAra->click();
           }
        };

        connect(silmeButonu, &QPushButton::clicked, silmeButonuFonksiyonu);

        QPushButton *duzenleButonu = new QPushButton(ui->tableWidget);
        duzenleButonu->setText(tr("Müşteriyi Düzelt"));
        ui->tableWidget->setCellWidget(satir, 4, duzenleButonu);

        auto duzeltmeButonuFonksiyonu = [TCKimlikNo, this](){
           OOUyeMusteriDuzeltmeFormu form;

           form.uyemusteriGoster(TCKimlikNo);

            auto sonuc = form.exec();

            if(sonuc = QDialog::Accepted) {
                this->ui->btnAra->click();
            }
        };

        connect(duzenleButonu, &QPushButton::clicked, duzeltmeButonuFonksiyonu);

        satir++;
    }

        };

void OOUyeMusteriAramaFormu::on_leArananAd_textChanged(const QString &arg1)
{
    if(ui->cbYazarkenAra->isChecked()) {
        ui->btnAra->click();
    }
}
