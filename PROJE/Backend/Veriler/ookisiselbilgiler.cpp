#include "ookisiselbilgiler.h"

OOKisiselBilgiler::OOKisiselBilgiler()
{

}

QString OOKisiselBilgiler::getTCKimlik() const
{
    return u_strTCKimlik;
}

void OOKisiselBilgiler::setTCKimlik(const QString &value)
{
    u_strTCKimlik = value;
}

QString OOKisiselBilgiler::getAdSoyad() const
{
    return u_strAdSoyad;
}

void OOKisiselBilgiler::setAdSoyad(const QString &value)
{
    u_strAdSoyad = value;
}

QDate OOKisiselBilgiler::getDogumTarihi() const
{
    return u_tarDogumTarihi;
}

void OOKisiselBilgiler::setDogumTarihi(const QDate &value)
{
    u_tarDogumTarihi = value;
}

QString OOKisiselBilgiler::getTelefon() const
{
    return u_strTelefon;
}

void OOKisiselBilgiler::setTelefon(const QString &value)
{
    u_strTelefon = value;
}

QString OOKisiselBilgiler::getInstagram() const
{
    return u_strInstagram;
}

void OOKisiselBilgiler::setInstagram(const QString &value)
{
    u_strInstagram = value;
}

QString OOKisiselBilgiler::getEPosta() const
{
    return u_strEPosta;
}

void OOKisiselBilgiler::setEPosta(const QString &value)
{
    u_strEPosta = value;
}

QString OOKisiselBilgiler::getAdres() const
{
    return u_strAdres;
}

void OOKisiselBilgiler::setAdres(const QString &value)
{
    u_strAdres = value;
}
