#include "oouyemusteri.h"

OOUyeMusteri::OOUyeMusteri()
{

}

OOKisiselBilgiler &OOUyeMusteri::getKisiselBilgiler()
{
    return u_KisiselBilgiler;
}

QString OOUyeMusteri::getUyeNo() const
{
    return u_strUyeNo;
}

void OOUyeMusteri::setUyeNo(const QString &value)
{
    u_strUyeNo = value;
}


