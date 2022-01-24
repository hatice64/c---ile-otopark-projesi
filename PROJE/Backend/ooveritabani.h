#ifndef OOVERITABANI_H
#define OOVERITABANI_H

#include "VeriErisimi/oootaparkverierisimi.h"
#include "VeriErisimi/oosubeverierisimi.h"
#include "VeriErisimi/oomusteriverierisimi.h"
#include "VeriErisimi/oouyemusteriverierisimi.h"
#include "VeriErisimi/oostandartmusteriverierisimi.h"
#include "VeriErisimi/ooaracverierisimi.h"
#include "VeriErisimi/ooaracgirisiverierisimi.h"
#include "VeriErisimi/ooaraccikisiverierisimi.h"

class OOVeriTabani
{
public:
    static OOVeriTabani *getNesne();

    OOOtaparkVeriErisimi &getOtaparkErisim();
    OOSubeVeriErisimi &getSubeErisim();
    OOUyeMusteriVeriErisimi &getUyeMusteriErisim();
    OOStandartMusteriVeriErisimi &getStandartMusteriErisim();
    OOMusteriVeriErisimi &getMusteriErisim();
    OOAracVeriErisimi &getAracErisim();
    OOAracGirisiVeriErisimi &getAracGirisiErisim();
    OOAracCikisiVeriErisimi &getAracCikisiErisim();

    void yukle();

    void sakla();

private:
    OOVeriTabani();

    static OOVeriTabani *u_ptrNesne;

    OOOtaparkVeriErisimi u_OtaparkErisim;
    OOSubeVeriErisimi u_SubeErisim;
    OOMusteriVeriErisimi u_MusteriErisim;
    OOUyeMusteriVeriErisimi u_UyeMusteriErisim;
    OOStandartMusteriVeriErisimi u_StandartMusteriErisim;
    OOAracVeriErisimi u_AracErisim;
    OOAracGirisiVeriErisimi u_AracGirisiErisim;
    OOAracCikisiVeriErisimi u_AracCikisiErisim;

};

#endif // OOVERITABANI_H
