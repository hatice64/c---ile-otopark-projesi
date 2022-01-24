#ifndef OOOTOPARKBILGILERFORMU_H
#define OOOTOPARKBILGILERFORMU_H

#include <QDialog>

namespace Ui {
class OOOtoparkBilgilerFormu;
}

class OOOtoparkBilgilerFormu : public QDialog
{
    Q_OBJECT

public:
    explicit OOOtoparkBilgilerFormu(QWidget *parent = 0);
    ~OOOtoparkBilgilerFormu();

    virtual void accept();

    virtual void reject();

public slots:
    void DegisiklikYapildi();

private slots:
    void on_btnTemizle_clicked();

private:
    Ui::OOOtoparkBilgilerFormu *ui;
    bool u_bDegisiklikVarMi;
};

#endif // OOOTOPARKBILGILERFORMU_H
