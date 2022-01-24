#ifndef OOSTANDARTMUSTERIARAMAFORMU_H
#define OOSTANDARTMUSTERIARAMAFORMU_H

#include <QDialog>

namespace Ui {
class OOStandartMusteriAramaFormu;
}

class OOStandartMusteriAramaFormu : public QDialog
{
    Q_OBJECT

public:
    explicit OOStandartMusteriAramaFormu(QWidget *parent = 0);
    ~OOStandartMusteriAramaFormu();

private slots:
    void on_btnAra_clicked();

    void on_leArananMusteriAdi_textChanged(const QString &arg1);

private:
    Ui::OOStandartMusteriAramaFormu *ui;
};

#endif // OOSTANDARTMUSTERIARAMAFORMU_H
