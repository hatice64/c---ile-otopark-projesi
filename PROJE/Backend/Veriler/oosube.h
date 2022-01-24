#ifndef OOSUBE_H
#define OOSUBE_H

#include <QString>
#include "ooiletisim.h"

class OOSube
{
public:
    OOSube();

    QString getSubeKodu() const;
    void setSubeKodu(const QString &value);

    QString getSubeAdi() const;
    void setSubeAdi(const QString &value);

    OOIletisim& getIletisim();

private:
    QString u_strSubeKodu;
    QString u_strSubeAdi;
    OOIletisim u_Iletisim;
};

#endif // OOSUBE_H
