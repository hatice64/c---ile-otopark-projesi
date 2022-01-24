#ifndef OOUYEMUSTERIDUZELTMEFORMU_H
#define OOUYEMUSTERIDUZELTMEFORMU_H

#include <QObject>
#include <QWidget>
#include "FrontEnd/oouyemusteribilgileriformu.h"

class OOUyeMusteriDuzeltmeFormu : public OOUyeMusteriBilgileriFormu
{
    Q_OBJECT
public:
    explicit OOUyeMusteriDuzeltmeFormu(QWidget *parent = nullptr);

    void uyemusteriGoster(QString TCKimlikNo);

signals:

public slots:
    virtual void accept();
};

#endif // OOUYEMUSTERIDUZELTMEFORMU_H
