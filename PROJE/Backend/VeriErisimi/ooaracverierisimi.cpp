#include "ooaracverierisimi.h"

OOAracVeriErisimi::OOAracVeriErisimi() {}

OOAracVeriErisimi::pointer OOAracVeriErisimi::yeniArac() {
    return make_shared<Veri>();
}

void OOAracVeriErisimi::listeyeEkle(OOAracVeriErisimi::pointer Arac) {
    for(auto Arac_i : u_Araclar) {
            if(Arac->getPlaka() == Arac_i->getPlaka()) {
                throw invalid_argument("Aynı Plakaya Sahip Başka Bir Araba Var!");
            }
        }
    u_Araclar.push_back(Arac);
}


