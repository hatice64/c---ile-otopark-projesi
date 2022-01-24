#ifndef OOOTAPARK_H
#define OOOTAPARK_H

#include <QString>
#include "ooiletisim.h"
#include "oosube.h"
#include <memory>

using namespace std;

class OOOtapark
{
public:
    OOOtapark();

    QString getAdi() const;
    void setAdi(const QString &value);

    OOIletisim& getIletisim();

    QVector<shared_ptr<OOSube> >& getSubeleri();

private:
    QString u_strAdi;
    OOIletisim u_Iletisim;

    friend class OOOtaparkVeriErisimi;
};

#endif // OOOTAPARK_H
