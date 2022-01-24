#ifndef OOARACBILGILERIFORMU_H
#define OOARACBILGILERIFORMU_H

#include <QDialog>

#include "Backend/VeriErisimi/ooaracverierisimi.h"

namespace Ui {
class OOAracBilgileriFormu;
}

class OOAracBilgileriFormu : public QDialog
{
    Q_OBJECT

public:
    explicit OOAracBilgileriFormu(QWidget *parent = 0);
    ~OOAracBilgileriFormu();

private:
    Ui::OOAracBilgileriFormu *ui;

};

#endif // OOARACBILGILERIFORMU_H
