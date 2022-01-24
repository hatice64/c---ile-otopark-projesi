#ifndef OOARACCIKISBILGILERIFORMU_H
#define OOARACCIKISBILGILERIFORMU_H

#include "Backend/VeriErisimi/ooaraccikisiverierisimi.h"
#include <QDialog>

namespace Ui {
class OOAracCikisBilgileriFormu;
}

class OOAracCikisBilgileriFormu : public QDialog
{
    Q_OBJECT

public:
    explicit OOAracCikisBilgileriFormu(QWidget *parent = 0);
    ~OOAracCikisBilgileriFormu();

public slots:
    void degisiklikVar();

    virtual void accept();
    virtual void reject();

private slots:
    void on_btnTemizle_clicked();

private:
    Ui::OOAracCikisBilgileriFormu *ui;

    OOAracCikisiVeriErisimi::pointer u_ptrAracCikisi;

    bool u_bDegisiklikVarMi;
};

#endif // OOARACCIKISBILGILERIFORMU_H
