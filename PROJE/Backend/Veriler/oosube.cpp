#include "oosube.h"

OOSube::OOSube()
{

}

QString OOSube::getSubeKodu() const
{
    return u_strSubeKodu;
}

void OOSube::setSubeKodu(const QString &value)
{
    u_strSubeKodu = value;
}

QString OOSube::getSubeAdi() const
{
    return u_strSubeAdi;
}

void OOSube::setSubeAdi(const QString &value)
{
    u_strSubeAdi = value;
}

OOIletisim &OOSube::getIletisim()
{
    return u_Iletisim;
}


