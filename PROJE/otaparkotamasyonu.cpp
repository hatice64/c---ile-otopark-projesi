#include "otaparkotamasyonu.h"
#include "ui_otaparkotamasyonu.h"

#include "Backend/ooveritabani.h"

#include "FrontEnd/oootoparkbilgilerformu.h"
#include "FrontEnd/aramaFormlari/oosubearamaformu.h"
#include "FrontEnd/oosubebilgileriformu.h"
#include "FrontEnd/oostandartmusteribilgileriformu.h"
#include "FrontEnd/oouyemusteribilgileriformu.h"
#include "FrontEnd/aramaFormlari/oostandartmusteriaramaformu.h"
#include "FrontEnd/aramaFormlari/oouyemusteriaramaformu.h"
#include "FrontEnd/ooaracbilgileriformu.h"
#include "FrontEnd/ooaracgirisbilgileriformu.h"
#include "FrontEnd/ooaraccikisbilgileriformu.h"
#include "FrontEnd/aramaFormlari/ooaracaramaformu.h"

OtaparkOtamasyonu::OtaparkOtamasyonu(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::OtaparkOtamasyonu)
{
    ui->setupUi(this);
    OOVeriTabani::getNesne()->yukle();
}

OtaparkOtamasyonu::~OtaparkOtamasyonu() {
    delete ui;
    OOVeriTabani::getNesne()->sakla();
}

void OtaparkOtamasyonu::on_actionOtopark_Bilgilerini_G_ncelle_triggered()
{
   OOOtoparkBilgilerFormu form;

   form.exec();
}

void OtaparkOtamasyonu::on_action_ube_Ekle_triggered()
{
    OOSubeBilgileriFormu form;

    form.exec();
}

void OtaparkOtamasyonu::on_action_ube_Arama_triggered()
{
    OOSubeAramaFormu form;

    form.exec();
}

void OtaparkOtamasyonu::on_actionStandart_M_teri_triggered()
{
    OOStandartMusteriBilgileriFormu form;

    form.exec();
}

void OtaparkOtamasyonu::on_action_ye_M_teri_triggered()
{
    OOUyeMusteriBilgileriFormu form;

    form.exec();
}


void OtaparkOtamasyonu::on_actionStandart_Musteri_triggered()
{
    OOStandartMusteriAramaFormu form;

    form.exec();
}

void OtaparkOtamasyonu::on_action_ye_M_teri_2_triggered()
{
    OOUyeMusteriAramaFormu form;

    form.exec();
}

void OtaparkOtamasyonu::on_actionAra_Giri_i_triggered()
{
    OOAracGirisBilgileriFormu form;

    form.exec();
}

void OtaparkOtamasyonu::on_actionAra_k_triggered()
{
    OOAracCikisBilgileriFormu form;

    form.exec();
}

void OtaparkOtamasyonu::on_actionArac_Arama_triggered()
{
    OOAracAramaFormu form;

    form.exec();
}
