#include "ooarac.h"

OOArac::OOArac()
{

}

QString OOArac::getMarka() const
{
    return u_strMarka;
}

void OOArac::setMarka(const QString &value)
{
    u_strMarka = value;
}

QString OOArac::getRenk() const
{
    return u_strRenk;
}

void OOArac::setRenk(const QString &value)
{
    u_strRenk = value;
}

QString OOArac::getPlaka() const
{
    return u_strPlaka;
}

void OOArac::setPlaka(const QString &value)
{
    u_strPlaka = value;
}

double OOArac::getAracNo() const
{
    return u_dAracNo;
}

void OOArac::setAracNo(double value)
{
    u_dAracNo = value;
}

QString OOArac::getKonum() const
{
    return u_strKonum;
}

void OOArac::setKonum(const QString &value)
{
    u_strKonum = value;
}


