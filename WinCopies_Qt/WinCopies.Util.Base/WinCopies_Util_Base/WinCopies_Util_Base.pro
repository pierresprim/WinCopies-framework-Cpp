#-------------------------------------------------
#
# Project created by QtCreator 2020-10-03T17:37:57
#
#-------------------------------------------------

QT       -= gui

TARGET = WinCopies_Util_Base
TEMPLATE = lib

DEFINES += WINCOPIES_UTIL_BASE_LIBRARY

# The following define makes your compiler emit warnings if you use
# any feature of Qt which has been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

DEFINES += QT

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
        ../../../WinCopies.Util.Base.Shared/Exception.cpp \
        ../../../WinCopies.Util.Base.Shared/IDisposable.cpp \
        ../../../WinCopies.Util.Base.Shared/Nullable.cpp \
        ../../../WinCopies.Util.Base.Shared/SafePointer.cpp \
        ../../../WinCopies.Util.Base.Shared/wincopies_defines.cpp \
        main.cpp

HEADERS += \
        ../../../WinCopies.Collections.Shared/IDisposable.h \
        ../../../WinCopies.Util.Base.Shared/Exception.h \
        ../../../WinCopies.Util.Base.Shared/IDisposable.h \
        ../../../WinCopies.Util.Base.Shared/Nullable.h \
        ../../../WinCopies.Util.Base.Shared/SafePointer.h \
        ../../../WinCopies.Util.Base.Shared/pch.h \
        ../../../WinCopies.Util.Base.Shared/wincopies_defines.h \
        main.h \
        wincopies_util_base_global.h 

unix {
    target.path = /usr/lib
    INSTALLS += target
}
