QT       += core gui sql

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

VERSION = 1.0
QMAKE_TARGET_COMPANY = sql company
QMAKE_TARGET_PRODUCT = printerproject
QMAKE_TARGET_DESCRIPTION = faults printer
QMAKE_TARGET_COPYRIGHT = Anton Ilinsky

CONFIG += c++11



# The following define makes your compiler emit warnings if you use
# any Qt feature that has been marked deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    compnetwork.cpp \
    densityimage.cpp \
    driverconection.cpp \
    driverinstall.cpp \
    edgeimage.cpp \
    empty.cpp \
    emptyimage.cpp \
    faksdevise.cpp \
    fon.cpp \
    fuser.cpp \
    gorizontline.cpp \
    instfuser.cpp \
    instruction.cpp \
    kaset.cpp \
    katrig.cpp \
    main.cpp \
    mainmenu.cpp \
    mainwindow.cpp \
    mfypozitronik.cpp \
    mkoper.cpp \
    mqualitu.cpp \
    mstart.cpp \
    mytop.cpp \
    notpinnedcopi.cpp \
    paper.cpp \
    prints.cpp \
    pytna.cpp \
    ribe.cpp \
    rolikpodachi.cpp \
    skew.cpp \
    stripsdirection.cpp \
    tefval.cpp \
    term.cpp \
    termoplenk.cpp \
    tormozpol.cpp \
    trasirovka.cpp \
    wfaksregim.cpp

HEADERS += \
    compnetwork.h \
    densityimage.h \
    driverconection.h \
    driverinstall.h \
    edgeimage.h \
    empty.h \
    emptyimage.h \
    faksdevise.h \
    fon.h \
    fuser.h \
    gorizontline.h \
    instfuser.h \
    instruction.h \
    kaset.h \
    katrig.h \
    mainmenu.h \
    mainwindow.h \
    mfypozitronik.h \
    mkoper.h \
    mqualitu.h \
    mstart.h \
    mytop.h \
    notpinnedcopi.h \
    paper.h \
    prints.h \
    pytna.h \
    ribe.h \
    rolikpodachi.h \
    skew.h \
    stripsdirection.h \
    tefval.h \
    term.h \
    termoplenk.h \
    tormozpol.h \
    trasirovka.h \
    wfaksregim.h

FORMS += \
    compnetwork.ui \
    densityimage.ui \
    driverconection.ui \
    driverinstall.ui \
    edgeimage.ui \
    empty.ui \
    emptyimage.ui \
    faksdevise.ui \
    fon.ui \
    fuser.ui \
    gorizontline.ui \
    instfuser.ui \
    instruction.ui \
    kaset.ui \
    katrig.ui \
    mainmenu.ui \
    mainwindow.ui \
    mfypozitronik.ui \
    mkoper.ui \
    mqualitu.ui \
    mstart.ui \
    mytop.ui \
    notpinnedcopi.ui \
    paper.ui \
    prints.ui \
    pytna.ui \
    ribe.ui \
    rolikpodachi.ui \
    skew.ui \
    stripsdirection.ui \
    tefval.ui \
    term.ui \
    termoplenk.ui \
    tormozpol.ui \
    trasirovka.ui \
    wfaksregim.ui


RC_ICONS = icon/printer.ico

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES +=
