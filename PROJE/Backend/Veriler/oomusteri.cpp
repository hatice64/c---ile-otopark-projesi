#include "oomusteri.h"

OOMusteri::OOMusteri()
{

}

QVector<shared_ptr<OOArac> > &OOMusteri::getU_Araclar()
{
    return u_Araclar;
}

QString OOMusteri::getMusteriNo() const
{
    return u_strMusteriNo;
}

void OOMusteri::setMusteriNo(const QString &value)
{
    u_strMusteriNo = value;
}
