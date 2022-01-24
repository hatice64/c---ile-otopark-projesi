#include "ooaracaramaformu.h"
#include "ui_ooaracaramaformu.h"

#include "Backend/ooveritabani.h"
#include "FrontEnd/duzeltmeFormlari/ooaracgirisiduzeltmeformu.h"

#include <QMessageBox>
#include <QPushButton>
#include <QTableWidgetItem>


OOAracAramaFormu::OOAracAramaFormu(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::OOAracAramaFormu)
{
    ui->setupUi(this);

    ui->btnAra->click();
}

OOAracAramaFormu::~OOAracAramaFormu()
{
    delete ui;
}

void OOAracAramaFormu::on_btnAra_clicked()
{
    OOAracGirisiVeriErisimi::AramaTuru tur;
    if(ui->rbIleBaslayan->isChecked()) {
        tur = OOAracGirisiVeriErisimi::AT_IleBaslayan;
    }
    if(ui->rbIceren->isChecked()) {
        tur = OOAracGirisiVeriErisimi::AT_Iceren;
    }
    if(ui->rbIleBiten->isChecked()) {
        tur = OOAracGirisiVeriErisimi::AT_IleBiten;
    }
    auto AracGirisiListesi = OOVeriTabani::getNesne()->getAracGirisiErisim().RengeGoreAracBul(
                ui->leArananRenk->text(), tur);

    ui->tableWidget->setRowCount(AracGirisiListesi.size());

    int satir = 0;

    for(auto aracgirisi : AracGirisiListesi) {
        double AracNo = aracgirisi->getAracNo();
        QString Plaka = aracgirisi->getPlaka();
        QDate GirisTarihiSaati= aracgirisi->getGirisTarihSaat();
        QString  Renk = aracgirisi->getRenk();

        QTableWidgetItem *numaraHucresi = new QTableWidgetItem;
        numaraHucresi->setTextAlignment(AracNo);
        ui->tableWidget->setItem(satir, 0, numaraHucresi);

        QTableWidgetItem *plakaHucresi = new QTableWidgetItem;
        plakaHucresi->setText(Plaka);
        ui->tableWidget->setItem(satir, 1, plakaHucresi);

        QTableWidgetItem *tarihSaatHucresi = new QTableWidgetItem;
        tarihSaatHucresi->setText(GirisTarihiSaati.toString());
        ui->tableWidget->setItem(satir, 3, tarihSaatHucresi);

        QTableWidgetItem *RenkHucresi = new QTableWidgetItem;
        RenkHucresi->setText(Renk);
        ui->tableWidget->setItem(satir, 2, RenkHucresi);

        QPushButton *silmeButonu = new QPushButton(ui->tableWidget);
        silmeButonu->setText(tr("Şube Sil"));
        ui->tableWidget->setCellWidget(satir, 5, silmeButonu);

        auto silmeButonuFonksiyonu = [this, Renk, Plaka](){
           auto cevap = QMessageBox::question(
                       this, tr("Uyari"),
                       tr("%1 Renkli Araç Girişini Silmek İstediginize Emin misiniz?").arg(Renk));
           if(cevap == QMessageBox::Yes) {
               OOVeriTabani::getNesne()->getAracGirisiErisim().AracSil(Plaka);
               this->ui->btnAra->click();
           }
        };    
        connect(silmeButonu, &QPushButton::clicked, silmeButonuFonksiyonu);

        QPushButton *duzenleButonu = new QPushButton(ui->tableWidget);
        duzenleButonu->setText(tr("Araç Düzelt"));
        ui->tableWidget->setCellWidget(satir, 4, duzenleButonu);

        auto duzeltmeButonuFonksiyonu = [Plaka, this](){
           OOAracGirisiDuzeltmeFormu form;

           form.aracgirisiGoster(Plaka);

           auto sonuc = form.exec();

           if(sonuc = QDialog::Accepted) {
               this->ui->btnAra->click();
           }
        };

        connect(duzenleButonu, &QPushButton::clicked, duzeltmeButonuFonksiyonu);

        satir++;
    }
}

void OOAracAramaFormu::on_leArananRenk_textEdited(const QString &arg1)
{
    if(ui->cbYazarkenAra->isChecked()) {
        ui->btnAra->click();
    }
}
