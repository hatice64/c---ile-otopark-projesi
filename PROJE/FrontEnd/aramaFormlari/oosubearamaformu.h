#ifndef OOSUBEARAMAFORMU_H
#define OOSUBEARAMAFORMU_H

#include <QDialog>

namespace Ui {
class OOSubeAramaFormu;
}

class OOSubeAramaFormu : public QDialog
{
    Q_OBJECT

public:
    explicit OOSubeAramaFormu(QWidget *parent = 0);
    ~OOSubeAramaFormu();

private slots:
    void on_btnAra_clicked();

    void on_leArananSubeAdi_textChanged(const QString &arg1);

    void on_btnAramayap_clicked();

private:
    Ui::OOSubeAramaFormu *ui;
};

#endif // OOSUBEARAMAFORMU_H
