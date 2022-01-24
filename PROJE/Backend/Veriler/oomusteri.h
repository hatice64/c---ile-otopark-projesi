#ifndef OOMUSTERI_H
#define OOMUSTERI_H

#include <QString>
#include <QVector>
#include <memory>

#include "ooarac.h"

using namespace std;

class OOMusteri
{
public:
    OOMusteri();

    QVector<shared_ptr<OOArac> >& getU_Araclar();

    QString getMusteriNo() const;
    void setMusteriNo(const QString &value);

private:
    QVector<shared_ptr<OOArac>> u_Araclar;
    QString  u_strMusteriNo;

};

#endif // OOMUSTERI_H
