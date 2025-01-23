QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    aggiungimediadialog.cpp \
    creatoolbar.cpp \
    creaview.cpp \
    film.cpp \
    jsonconvert.cpp \
    jsonfile.cpp \
    libro.cpp \
    main.cpp \
    mainwindow.cpp \
    media.cpp \
    mediamodel.cpp \
    modificamediadialog.cpp \
    rivistearticoli.cpp

HEADERS += \
    aggiungimediadialog.h \
    creatoolbar.h \
    creaview.h \
    film.h \
    jsonconvert.h \
    jsonfile.h \
    libro.h \
    mainwindow.h \
    media.h \
    mediamodel.h \
    modificamediadialog.h \
    rivistearticoli.h

FORMS += \
    mainwindow.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    resources.qrc

DISTFILES += \
    database.json \
    database/database.json \
    database/database2.json \
    immagini/1984.jpg \
    immagini/IlPadrino.jpg \
    immagini/IlSignoreDegliAnelli.jpg \
    immagini/Inception.jpg \
    immagini/InnovazioneDigitale.jpg \
    immagini/OrgoglioEPregiudizio.jpg \
    immagini/PulpFiction.jpg

