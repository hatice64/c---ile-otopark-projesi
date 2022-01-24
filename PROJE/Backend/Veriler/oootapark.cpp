#include "oootapark.h"

OOOtapark::OOOtapark() {}

QString OOOtapark::getAdi() const { return u_strAdi; }

void OOOtapark::setAdi(const QString &value) { u_strAdi = value; }

OOIletisim &OOOtapark::getIletisim() { return u_Iletisim; }

QVector<shared_ptr<OOSube> > &OOOtapark::getSubeleri() {}
