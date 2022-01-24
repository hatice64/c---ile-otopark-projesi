#include "ooiletisim.h"

OOIletisim::OOIletisim()
{

}

QDate OOIletisim::getKurulusTarihi() const
{
    return u_tarKurulusTarihi;
}

void OOIletisim::setKurulusTarihi(const QDate &value)
{
    u_tarKurulusTarihi = value;
}

QString OOIletisim::getTelefon() const
{
    return u_strTelefon;
}

void OOIletisim::setTelefon(const QString &value)
{
    u_strTelefon = value;
}

QString OOIletisim::getAdres() const
{
    return u_strAdres;
}

void OOIletisim::setAdres(const QString &value)
{
    u_strAdres = value;
}

QString OOIletisim::getEPosta() const
{
    return u_strEPosta;
}

void OOIletisim::setEPosta(const QString &value)
{
    u_strEPosta = value;
}

QString OOIletisim::getSosyalMedya() const
{
    return u_strSosyalMedya;
}

void OOIletisim::setSosyalMedya(const QString &value)
{
    u_strSosyalMedya = value;
}
