#ifndef OOMUSTERIBILGILERIFORMU_H
#define OOMUSTERIBILGILERIFORMU_H

#include <QDialog>

namespace Ui {
class OOMusteriBilgileriFormu;
}

class OOMusteriBilgileriFormu : public QDialog
{
    Q_OBJECT

public:
    explicit OOMusteriBilgileriFormu(QWidget *parent = 0);
    ~OOMusteriBilgileriFormu();

private:
    Ui::OOMusteriBilgileriFormu *ui;
};

#endif // OOMUSTERIBILGILERIFORMU_H
