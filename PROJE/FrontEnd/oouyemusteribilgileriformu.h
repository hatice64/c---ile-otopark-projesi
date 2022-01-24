#ifndef OOUYEMUSTERIBILGILERIFORMU_H
#define OOUYEMUSTERIBILGILERIFORMU_H

#include <QDialog>

#include "Backend/VeriErisimi/oouyemusteriverierisimi.h"

namespace Ui {
class OOUyeMusteriBilgileriFormu;
}

class OOUyeMusteriBilgileriFormu : public QDialog
{
    Q_OBJECT

public:
    explicit OOUyeMusteriBilgileriFormu(QWidget *parent = 0);
    ~OOUyeMusteriBilgileriFormu();

    void ekraniGuncelle();
    
    void veriGuncelle();
    
public slots:
          void degisiklikVar();

          virtual void accept();
          virtual void reject();

private slots:
          void on_btnTemizle_clicked();

protected:
    Ui::OOUyeMusteriBilgileriFormu *ui;

    OOUyeMusteriVeriErisimi::pointer u_ptruyemusteri;

    bool u_bDegisiklikVarMi;
};

#endif // OOUYEMUSTERIBILGILERIFORMU_H
