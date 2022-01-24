#include "ooaracbilgileriformu.h"
#include "ui_ooaracbilgileriformu.h"

#include "Backend/ooveritabani.h"
#include "Backend/VeriErisimi/ooaracverierisimi.h"

#include <QMessageBox>
#include <QTableWidgetItem>

OOAracBilgileriFormu::OOAracBilgileriFormu(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::OOAracBilgileriFormu)
{
    ui->setupUi(this);

}

OOAracBilgileriFormu::~OOAracBilgileriFormu() { delete ui; }
