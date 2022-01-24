#include "oomusteribilgileriformu.h"
#include "ui_oomusteribilgileriformu.h"

OOMusteriBilgileriFormu::OOMusteriBilgileriFormu(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::OOMusteriBilgileriFormu)
{
    ui->setupUi(this);
}

OOMusteriBilgileriFormu::~OOMusteriBilgileriFormu()
{
    delete ui;
}
