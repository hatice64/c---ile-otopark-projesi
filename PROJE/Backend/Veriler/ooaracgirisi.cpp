#include "ooaracgirisi.h"

OOAracGirisi::OOAracGirisi()
{

}

QDate OOAracGirisi::getGirisTarihSaat() const
{
    return u_tarGirisTarihSaat;
}

void OOAracGirisi::setGirisTarihSaat(const QDate &value)
{
    u_tarGirisTarihSaat = value;
}

QString OOAracGirisi::getGirisNedeni() const
{
    return u_strGirisNedeni;
}

void OOAracGirisi::setGirisNedeni(const QString &value)
{
    u_strGirisNedeni = value;
}


