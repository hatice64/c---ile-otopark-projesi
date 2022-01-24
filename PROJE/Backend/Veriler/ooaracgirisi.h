#ifndef OOARACGIRISI_H
#define OOARACGIRISI_H

#include <QString>
#include <QDate>

#include "ooarac.h"

class OOAracGirisi :public OOArac
{
public:
    OOAracGirisi();

    QDate getGirisTarihSaat() const;
    void setGirisTarihSaat(const QDate &value);

    QString getGirisNedeni() const;
    void setGirisNedeni(const QString &value);

private:
    QDate u_tarGirisTarihSaat;
    QString u_strGirisNedeni;
};

#endif // OOARACGIRISI_H
