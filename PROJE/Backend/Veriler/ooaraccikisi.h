#ifndef OOARACCIKISI_H
#define OOARACCIKISI_H

#include "ooarac.h"

#include <QDate>

class OOAracCikisi : public OOArac
{
public:
    OOAracCikisi();

    QDate getCikisTarihSaat() const;
    void setCikisTarihSaat(const QDate &value);

    double getUcret() const;
    void setUcret(double value);

private:
    QDate u_tarCikisTarihSaat;
    double u_dUcret;
};

#endif // OOARACCIKISI_H
