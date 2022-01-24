#ifndef OOSTANDARTMUSTERIBILGILERIFORMU_H
#define OOSTANDARTMUSTERIBILGILERIFORMU_H

#include <QDialog>

#include "Backend/VeriErisimi/oostandartmusteriverierisimi.h"

namespace Ui {
class OOStandartMusteriBilgileriFormu;
}

class OOStandartMusteriBilgileriFormu : public QDialog
{
    Q_OBJECT

public:
    explicit OOStandartMusteriBilgileriFormu(QWidget *parent = 0);
    ~OOStandartMusteriBilgileriFormu();

    void resimGuncelle();
    
    void veriGuncelle();
    
public slots:
      void degisiklikVar();

      virtual void accept();
      virtual void reject();


private slots:
      void on_btnTemizle_clicked();

protected:
    Ui::OOStandartMusteriBilgileriFormu *ui;

     OOStandartMusteriVeriErisimi::pointer u_ptrstandartmusteri;

     bool u_bDegisiklikVarMi;
};

#endif // OOSTANDARTMUSTERIBILGILERIFORMU_H
