#ifndef OOILETISIM_H
#define OOILETISIM_H

#include <QDate>
#include <QString>

class OOIletisim
{
public:
    OOIletisim();

    QDate getKurulusTarihi() const;
    void setKurulusTarihi(const QDate &value);

    QString getTelefon() const;
    void setTelefon(const QString &value);

    QString getAdres() const;
    void setAdres(const QString &value);

    QString getEPosta() const;
    void setEPosta(const QString &value);

    QString getSosyalMedya() const;
    void setSosyalMedya(const QString &value);

private:
    QDate u_tarKurulusTarihi;
    QString u_strTelefon;
    QString u_strAdres;
    QString u_strEPosta;
    QString u_strSosyalMedya;
};

#endif // OOILETISIM_H
