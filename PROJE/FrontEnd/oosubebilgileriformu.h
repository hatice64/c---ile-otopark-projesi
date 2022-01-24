#ifndef OOSUBEBILGILERIFORMU_H
#define OOSUBEBILGILERIFORMU_H

#include <QDialog>

#include "Backend/VeriErisimi/oosubeverierisimi.h"

namespace Ui {
class OOSubeBilgileriFormu;
}

class OOSubeBilgileriFormu : public QDialog
{
    Q_OBJECT

public:
    explicit OOSubeBilgileriFormu(QWidget *parent = 0);
    ~OOSubeBilgileriFormu();

    void gorselGuncelle();

    void VeriGuncelle();
    
public slots:
    void DegisiklikVar();

    virtual void accept();
    virtual void reject();

private slots:
    void on_btnTemizle_clicked();

protected:
    Ui::OOSubeBilgileriFormu *ui;

    OOSubeVeriErisimi::pointer u_ptrSube;

    bool u_bDegisiklikVarMi;
};

#endif // OOSUBEBILGILERIFORMU_H
