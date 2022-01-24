#ifndef OOARACGIRISIDUZELTMEFORMU_H
#define OOARACGIRISIDUZELTMEFORMU_H

#include <QWidget>
#include <QObject>
#include "FrontEnd/ooaracgirisbilgileriformu.h"

class OOAracGirisiDuzeltmeFormu : public OOAracGirisBilgileriFormu
{
    Q_OBJECT
public:
    explicit OOAracGirisiDuzeltmeFormu(QWidget *parent = nullptr);

    void aracgirisiGoster(QString plaka);

signals:

public slots:
    virtual void accept();
};

#endif // OOARACGIRISIDUZELTMEFORMU_H
