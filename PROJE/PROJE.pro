#-------------------------------------------------
#
# Project created by QtCreator 2018-03-25T15:15:10
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = PROJE
TEMPLATE = app

# The following define makes your compiler emit warnings if you use
# any feature of Qt which has been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0


SOURCES += \
        main.cpp \
        otaparkotamasyonu.cpp \
    Backend/Veriler/ooiletisim.cpp \
    Backend/Veriler/oootapark.cpp \
    Backend/Veriler/oosube.cpp \
    Backend/Veriler/oomusteri.cpp \
    Backend/Veriler/ooarac.cpp \
    Backend/Veriler/ookisiselbilgiler.cpp \
    Backend/Veriler/oostandartmusteri.cpp \
    Backend/Veriler/oouyemusteri.cpp \
    Backend/ooveritabani.cpp \
    Backend/VeriErisimi/oootaparkverierisimi.cpp \
    Backend/Veriler/ooaracgirisi.cpp \
    Backend/Veriler/ooaraccikisi.cpp \
    FrontEnd/oootoparkbilgilerformu.cpp \
    Backend/VeriErisimi/oosubeverierisimi.cpp \
    FrontEnd/oosubebilgileriformu.cpp \
    FrontEnd/aramaFormlari/oosubearamaformu.cpp \
    FrontEnd/duzeltmeFormlari/oosubeduzeltmeformu.cpp \
    Backend/VeriErisimi/oomusteriverierisimi.cpp \
    Backend/VeriErisimi/oouyemusteriverierisimi.cpp \
    Backend/VeriErisimi/oostandartmusteriverierisimi.cpp \
    FrontEnd/oomusteribilgileriformu.cpp \
    FrontEnd/oouyemusteribilgileriformu.cpp \
    FrontEnd/oostandartmusteribilgileriformu.cpp \
    Backend/VeriErisimi/ooaracverierisimi.cpp \
    FrontEnd/ooaracbilgileriformu.cpp \
    FrontEnd/aramaFormlari/oostandartmusteriaramaformu.cpp \
    FrontEnd/aramaFormlari/oouyemusteriaramaformu.cpp \
    FrontEnd/duzeltmeFormlari/oostandartmusteriduzeltmeformu.cpp \
    FrontEnd/duzeltmeFormlari/oouyemusteriduzeltmeformu.cpp \
    Backend/VeriErisimi/ooaracgirisiverierisimi.cpp \
    Backend/VeriErisimi/ooaraccikisiverierisimi.cpp \
    FrontEnd/ooaraccikisbilgileriformu.cpp \
    FrontEnd/ooaracgirisbilgileriformu.cpp \
    FrontEnd/aramaFormlari/ooaracaramaformu.cpp \
    FrontEnd/duzeltmeFormlari/ooaracgirisiduzeltmeformu.cpp


HEADERS += \
        otaparkotamasyonu.h \
    Backend/Veriler/ooiletisim.h \
    Backend/Veriler/oootapark.h \
    Backend/Veriler/oosube.h \
    Backend/Veriler/oomusteri.h \
    Backend/Veriler/ooarac.h \
    Backend/Veriler/ookisiselbilgiler.h \
    Backend/Veriler/oostandartmusteri.h \
    Backend/Veriler/oouyemusteri.h \
    Backend/ooveritabani.h \
    Backend/VeriErisimi/oootaparkverierisimi.h \
    Backend/Veriler/ooaracgirisi.h \
    Backend/Veriler/ooaraccikisi.h \
    FrontEnd/oootoparkbilgilerformu.h \
    Backend/VeriErisimi/oosubeverierisimi.h \
    FrontEnd/oosubebilgileriformu.h \
    FrontEnd/aramaFormlari/oosubearamaformu.h \
    FrontEnd/duzeltmeFormlari/oosubeduzeltmeformu.h \
    Backend/VeriErisimi/oomusteriverierisimi.h \
    Backend/VeriErisimi/oouyemusteriverierisimi.h \
    Backend/VeriErisimi/oostandartmusteriverierisimi.h \
    FrontEnd/oomusteribilgileriformu.h \
    FrontEnd/oouyemusteribilgileriformu.h \
    FrontEnd/oostandartmusteribilgileriformu.h \
    Backend/VeriErisimi/ooaracverierisimi.h \
    FrontEnd/ooaracbilgileriformu.h \
    FrontEnd/aramaFormlari/oostandartmusteriaramaformu.h \
    FrontEnd/aramaFormlari/oouyemusteriaramaformu.h \
    FrontEnd/duzeltmeFormlari/oostandartmusteriduzeltmeformu.h \
    FrontEnd/duzeltmeFormlari/oouyemusteriduzeltmeformu.h \
    Backend/VeriErisimi/ooaracgirisiverierisimi.h \
    Backend/VeriErisimi/ooaraccikisiverierisimi.h \
    FrontEnd/ooaraccikisbilgileriformu.h \
    FrontEnd/ooaracgirisbilgileriformu.h \
    FrontEnd/aramaFormlari/ooaracaramaformu.h \
    FrontEnd/duzeltmeFormlari/ooaracgirisiduzeltmeformu.h



FORMS += \
        otaparkotamasyonu.ui \
    FrontEnd/oootoparkbilgilerformu.ui \
    FrontEnd/oosubebilgileriformu.ui \
    FrontEnd/aramaFormlari/oosubearamaformu.ui \
    FrontEnd/oomusteribilgileriformu.ui \
    FrontEnd/oouyemusteribilgileriformu.ui \
    FrontEnd/oostandartmusteribilgileriformu.ui \
    FrontEnd/ooaracbilgileriformu.ui \
    FrontEnd/aramaFormlari/oostandartmusteriaramaformu.ui \
    FrontEnd/aramaFormlari/oouyemusteriaramaformu.ui \
    FrontEnd/ooaraccikisbilgileriformu.ui \
    FrontEnd/ooaracgirisbilgileriformu.ui \
    FrontEnd/aramaFormlari/ooaracaramaformu.ui


RESOURCES += \
    kaynaklar.qrc
