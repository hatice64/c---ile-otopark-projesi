#ifndef OOUYEMUSTERIARAMAFORMU_H
#define OOUYEMUSTERIARAMAFORMU_H

#include <QDialog>

namespace Ui {
class OOUyeMusteriAramaFormu;
}

class OOUyeMusteriAramaFormu : public QDialog
{
    Q_OBJECT

public:
    explicit OOUyeMusteriAramaFormu(QWidget *parent = 0);
    ~OOUyeMusteriAramaFormu();

private slots:

    void on_btnAra_clicked();

    void on_leArananAd_textChanged(const QString &arg1);

private:
    Ui::OOUyeMusteriAramaFormu *ui;
};

#endif // OOUYEMUSTERIARAMAFORMU_H
