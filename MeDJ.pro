QT       += core gui multimedia

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += \
    c++11



# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0


INCLUDEPATH += \
    src/lib/ffmpeg/ \
    src/


SOURCES += \
    src/AudioTreatment/audiofile.cpp \
    src/AudioTreatment/audiodecoding.cpp \
    src/AudioTreatment/newaudiotrack.cpp \
    src/layout/SpininVinyl.cpp \
    src/layout/fader.cpp \
    src/layout/mainwindow.cpp \
    src/layout/mixer.cpp \
    src/layout/potentiometer.cpp \
    src/layout/track.cpp \
    src/layout/vinyl.cpp \
    main.cpp \


FORMS += \
    src/layout/mainwindow.ui \

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

DISTFILES += \
    src/layout/layout.pri \

HEADERS += \
    src/AudioTreatment/audiodecoding.h \
    src/AudioTreatment/audiofile.h \
    src/AudioTreatment/newaudiotrack.h \
    src/layout/SpininVinyl.h \
    src/layout/fader.h \
    src/layout/mainwindow.h \
    src/layout/mixer.h \
    src/layout/potentiometer.h \
    src/layout/track.h \
    src/layout/vinyl.h
