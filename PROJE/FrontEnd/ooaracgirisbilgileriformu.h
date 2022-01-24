#ifndef OOARACGIRISBILGILERIFORMU_H
#define OOARACGIRISBILGILERIFORMU_H

#include <QDialog>
#include "Backend/VeriErisimi/ooaracgirisiverierisimi.h"

namespace Ui {
class OOAracGirisBilgileriFormu;
}

class OOAracGirisBilgileriFormu : public QDialog
{
    Q_OBJECT

public:
    explicit OOAracGirisBilgileriFormu(QWidget *parent = 0);
    ~OOAracGirisBilgileriFormu();

    void gorselGuncelle();

    void veriGuncelle();

public slots:
    void degisiklikVar();

    virtual void accept();
    virtual void reject();

private slots:
    void on_btnTemizle_clicked();

protected:
    Ui::OOAracGirisBilgileriFormu *ui;

    OOAracGirisiVeriErisimi::pointer u_ptrAracGirisi;

    bool u_bDegisiklikVarMi = true;
};

#endif // OOARACGIRISBILGILERIFORMU_H
