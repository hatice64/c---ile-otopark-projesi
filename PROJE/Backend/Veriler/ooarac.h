#ifndef OOARAC_H
#define OOARAC_H

#include <QString>
#include <QDate>

class OOArac
{
public:
    OOArac();

    QString getMarka() const;
    void setMarka(const QString &value);

    QString getRenk() const;
    void setRenk(const QString &value);

    QString getPlaka() const;
    void setPlaka(const QString &value);

    double getAracNo() const;
    void setAracNo(double value);

    QString getKonum() const;
    void setKonum(const QString &value);

private:
    QString u_strMarka;
    QString u_strRenk;
    QString u_strPlaka;
    double u_dAracNo;
    QString u_strKonum;
};

#endif // OOARAC_H
