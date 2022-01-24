#include "ooaraccikisiverierisimi.h"

OOAracCikisiVeriErisimi::OOAracCikisiVeriErisimi() {}

OOAracCikisiVeriErisimi::pointer OOAracCikisiVeriErisimi::yeniAracCikisi() {
    return make_shared<Veri>();
}

void OOAracCikisiVeriErisimi::listeyeEkle(OOAracCikisiVeriErisimi::pointer Araccikisi) {
    for(auto Araccikisi_i : u_Araccikislari) {
            if(Araccikisi->getPlaka() == Araccikisi_i->getPlaka()) {
                throw invalid_argument("Aynı Plakaya Sahip Başka Bir Araba Var!");
            }
        }
    u_Araccikislari.push_back(Araccikisi);
}
