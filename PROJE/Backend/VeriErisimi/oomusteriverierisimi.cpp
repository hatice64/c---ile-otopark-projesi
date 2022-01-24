#include "oomusteriverierisimi.h"

OOMusteriVeriErisimi::OOMusteriVeriErisimi() {}

OOMusteriVeriErisimi::pointer OOMusteriVeriErisimi::yeniMusteri() {
    return make_shared<Veri>();
}

void OOMusteriVeriErisimi::listeyeEkle(OOMusteriVeriErisimi::pointer musteri) {
    for(auto musteri_i : u_musteriler) {
        if(musteri->getMusteriNo() == musteri_i->getMusteriNo()) {
            throw invalid_argument("Aynı Müşteri Numarasına Sahip Başka Bir Müşteri Var!");
        }
    }
    u_musteriler.push_back(musteri);
}
