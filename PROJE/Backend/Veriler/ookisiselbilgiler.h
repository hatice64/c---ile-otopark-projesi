#ifndef OOKISISELBILGILER_H
#define OOKISISELBILGILER_H

#include <QDate>
#include <QString>

class OOKisiselBilgiler
{
public:
    OOKisiselBilgiler();

    QString getTCKimlik() const;
    void setTCKimlik(const QString &value);

    QString getAdSoyad() const;
    void setAdSoyad(const QString &value);

    QDate getDogumTarihi() const;
    void setDogumTarihi(const QDate &value);

    QString getTelefon() const;
    void setTelefon(const QString &value);

    QString getInstagram() const;
    void setInstagram(const QString &value);

    QString getEPosta() const;
    void setEPosta(const QString &value);

    QString getAdres() const;
    void setAdres(const QString &value);

private:
    QString u_strTCKimlik;
    QString u_strAdSoyad;
    QDate u_tarDogumTarihi;
    QString u_strTelefon;
    QString u_strInstagram;
    QString u_strEPosta;
    QString u_strAdres;

};

#endif // OOKISISELBILGILER_H
