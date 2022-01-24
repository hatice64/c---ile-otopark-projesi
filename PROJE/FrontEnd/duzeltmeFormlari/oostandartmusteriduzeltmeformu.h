#ifndef OOSTANDARTMUSTERIDUZELTMEFORMU_H
#define OOSTANDARTMUSTERIDUZELTMEFORMU_H

#include <QObject>
#include <QWidget>
#include "FrontEnd/oostandartmusteribilgileriformu.h"

class OOStandartMusteriDuzeltmeFormu : public OOStandartMusteriBilgileriFormu
{
    Q_OBJECT
public:
    explicit OOStandartMusteriDuzeltmeFormu(QWidget *parent = nullptr);

    void standartmusteriGoster(QString TCKimlikNo);

signals:

public slots:
    virtual void accept();
};

#endif // OOSTANDARTMUSTERIDUZELTMEFORMU_H
