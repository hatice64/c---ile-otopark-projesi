#ifndef OOSUBEDUZELTMEFORMU_H
#define OOSUBEDUZELTMEFORMU_H

#include <QObject>
#include <QWidget>
#include "FrontEnd/oosubebilgileriformu.h"

class OOSubeDuzeltmeFormu : public OOSubeBilgileriFormu
{
    Q_OBJECT
public:
    explicit OOSubeDuzeltmeFormu(QWidget *parent = nullptr);

    void subeGoster(QString subeKodu);

signals:

public slots:
    virtual void accept();
};

#endif // OOSUBEDUZELTMEFORMU_H
