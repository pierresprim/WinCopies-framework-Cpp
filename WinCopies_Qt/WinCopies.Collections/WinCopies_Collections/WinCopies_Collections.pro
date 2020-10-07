#-------------------------------------------------
#
# Project created by QtCreator 2020-10-03T17:50:23
#
#-------------------------------------------------

QT       -= gui

TARGET = WinCopies_Collections
TEMPLATE = lib

DEFINES += WINCOPIES_COLLECTIONS_LIBRARY

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
        ../../../WinCopies.Collections.Shared/EnumerableQueue.cpp \
        ../../../WinCopies.Collections.Shared/EnumerableStack.cpp \
        ../../../WinCopies.Collections.Shared/EnumeratorBase.cpp \
        ../../../WinCopies.Collections.Shared/IEnumerable.cpp \
        ../../../WinCopies.Collections.Shared/IEnumerator.cpp \
        ../../../WinCopies.Collections.Shared/ILinkedList.cpp \
        ../../../WinCopies.Collections.Shared/IQueue.cpp \
        ../../../WinCopies.Collections.Shared/ISimpleLinkedList.cpp \
        ../../../WinCopies.Collections.Shared/ISimpleLinkedListNode.cpp \
        ../../../WinCopies.Collections.Shared/IStack.cpp \
        ../../../WinCopies.Collections.Shared/IUIntCountable.cpp \
        ../../../WinCopies.Collections.Shared/Queue.cpp \
        ../../../WinCopies.Collections.Shared/QueueEnumerator.cpp \
        ../../../WinCopies.Collections.Shared/ReadOnlyQueue.cpp \
        ../../../WinCopies.Collections.Shared/ReadOnlyStack.cpp \
        ../../../WinCopies.Collections.Shared/SafeArray.cpp \
        ../../../WinCopies.Collections.Shared/SimpleLinkedList.cpp \
        ../../../WinCopies.Collections.Shared/SimpleLinkedListNode.cpp \
        ../../../WinCopies.Collections.Shared/Stack.cpp \
        ../../../WinCopies.Collections.Shared/StackEnumerator.cpp \
        main.cpp

HEADERS += \
        ../../../WinCopies.Collections.Shared/EnumerableQueue.h \
        ../../../WinCopies.Collections.Shared/EnumerableStack.h \
        ../../../WinCopies.Collections.Shared/EnumeratorBase.h \
        ../../../WinCopies.Collections.Shared/IEnumerable.h \
        ../../../WinCopies.Collections.Shared/IEnumerator.h \
        ../../../WinCopies.Collections.Shared/ILinkedList.h \
        ../../../WinCopies.Collections.Shared/IQueue.h \
        ../../../WinCopies.Collections.Shared/ISimpleLinkedList.h \
        ../../../WinCopies.Collections.Shared/ISimpleLinkedListNode.h \
        ../../../WinCopies.Collections.Shared/IStack.h \
        ../../../WinCopies.Collections.Shared/IUIntCountable.h \
        ../../../WinCopies.Collections.Shared/Queue.h \
        ../../../WinCopies.Collections.Shared/QueueEnumerator.h \
        ../../../WinCopies.Collections.Shared/ReadOnlyQueue.h \
        ../../../WinCopies.Collections.Shared/ReadOnlyStack.h \
        ../../../WinCopies.Collections.Shared/SafeArray.h \
        ../../../WinCopies.Collections.Shared/SimpleLinkedList.h \
        ../../../WinCopies.Collections.Shared/SimpleLinkedListNode.h \
        ../../../WinCopies.Collections.Shared/Stack.h \
        ../../../WinCopies.Collections.Shared/StackEnumerator.h \
        ../../../WinCopies.Collections.Shared/defines.h \
        ../../../WinCopies.Collections.Shared/pch.h \
        main.h \
        wincopies_collections_global.h

unix {
    target.path = /usr/lib
    INSTALLS += target
}
