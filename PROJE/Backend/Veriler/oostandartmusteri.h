#ifndef OOSTANDARTMUSTERI_H
#define OOSTANDARTMUSTERI_H

#include "oomusteri.h"
#include "ookisiselbilgiler.h"

class OOStandartMusteri : public OOMusteri
{
public:
    OOStandartMusteri();

    OOKisiselBilgiler& getKisiselBilgiler();

private:
    OOKisiselBilgiler u_KisiselBilgiler;

};

#endif // OOSTANDARTMUSTERI_H
