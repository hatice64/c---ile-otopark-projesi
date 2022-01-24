#ifndef OOARACARAMAFORMU_H
#define OOARACARAMAFORMU_H

#include <QDialog>

namespace Ui {
class OOAracAramaFormu;
}

class OOAracAramaFormu : public QDialog
{
    Q_OBJECT

public:
    explicit OOAracAramaFormu(QWidget *parent = 0);
    ~OOAracAramaFormu();

private slots:
    void on_btnAra_clicked();

    void on_leArananRenk_textEdited(const QString &arg1);

private:
    Ui::OOAracAramaFormu *ui;
};

#endif // OOARACARAMAFORMU_H
