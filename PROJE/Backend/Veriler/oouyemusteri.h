#ifndef OOUYEMUSTERI_H
#define OOUYEMUSTERI_H

#include "oomusteri.h"
#include "ookisiselbilgiler.h"

#include <QString>

class OOUyeMusteri : public OOMusteri
{
public:
    OOUyeMusteri();

    OOKisiselBilgiler &getKisiselBilgiler();

    QString getUyeNo() const;
    void setUyeNo(const QString &value);

private:
    OOKisiselBilgiler u_KisiselBilgiler;
    QString u_strUyeNo;

};

#endif // OOUYEMUSTERI_H
