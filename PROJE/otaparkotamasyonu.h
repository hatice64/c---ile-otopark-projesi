#ifndef OTAPARKOTAMASYONU_H
#define OTAPARKOTAMASYONU_H

#include <QMainWindow>

namespace Ui {
class OtaparkOtamasyonu;
}

class OtaparkOtamasyonu : public QMainWindow
{
    Q_OBJECT

public:
    explicit OtaparkOtamasyonu(QWidget *parent = 0);
    ~OtaparkOtamasyonu();

private slots:
    void on_actionOtopark_Bilgilerini_G_ncelle_triggered();

    void on_action_ube_Ekle_triggered();

    void on_action_ube_Arama_triggered();

    void on_actionStandart_M_teri_triggered();

    void on_action_ye_M_teri_triggered();

    void on_actionStandart_Musteri_triggered();

    void on_action_ye_M_teri_2_triggered();

    void on_actionAra_Giri_i_triggered();

    void on_actionAra_k_triggered();

    void on_actionArac_Arama_triggered();

private:
    Ui::OtaparkOtamasyonu *ui;
};

#endif // OTAPARKOTAMASYONU_H
