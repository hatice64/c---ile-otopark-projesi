#include "ooaraccikisi.h"

OOAracCikisi::OOAracCikisi()
{

}

QDate OOAracCikisi::getCikisTarihSaat() const
{
    return u_tarCikisTarihSaat;
}

void OOAracCikisi::setCikisTarihSaat(const QDate &value)
{
    u_tarCikisTarihSaat = value;
}

double OOAracCikisi::getUcret() const
{
    return u_dUcret;
}

void OOAracCikisi::setUcret(double value)
{
    u_dUcret = value;
}
