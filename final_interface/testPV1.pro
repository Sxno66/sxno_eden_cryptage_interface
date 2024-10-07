QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    main.cpp \
    mainwindow.cpp

HEADERS += \
    mainwindow.h

FORMS += \
    mainwindow.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target



win32:CONFIG(release, debug|release): LIBS += -L$$PWD/../cryptopp/x64/Output/release/ -lcryptlib
else:win32:CONFIG(debug, debug|release): LIBS += -L$$PWD/../cryptopp/x64/Output/debug/ -lcryptlib

INCLUDEPATH += $$PWD/../cryptopp
DEPENDPATH += $$PWD/../cryptopp

win32-g++:CONFIG(release, debug|release): PRE_TARGETDEPS += $$PWD/../cryptopp/x64/Output/release/libcryptlib.a
else:win32-g++:CONFIG(debug, debug|release): PRE_TARGETDEPS += $$PWD/../cryptopp/x64/Output/debug/libcryptlib.a
else:win32:!win32-g++:CONFIG(release, debug|release): PRE_TARGETDEPS += $$PWD/../cryptopp/x64/Output/release/cryptlib.lib
else:win32:!win32-g++:CONFIG(debug, debug|release): PRE_TARGETDEPS += $$PWD/../cryptopp/x64/Output/debug/cryptlib.lib



win32: LIBS += -L$$PWD/../CryptoCiel/x64/Release/ -lcryptoCielTest

INCLUDEPATH += $$PWD/../CryptoCiel
DEPENDPATH += $$PWD/../CryptoCiel

win32:!win32-g++: PRE_TARGETDEPS += $$PWD/../CryptoCiel/x64/Release/cryptoCielTest.lib
else:win32-g++: PRE_TARGETDEPS += $$PWD/../CryptoCiel/x64/Release/libcryptoCielTest.a

unix|win32: LIBS += -L$$PWD/../CryptoCiel/x64/Release/ -lcryptoCielTest

INCLUDEPATH += $$PWD/../CryptoCiel
DEPENDPATH += $$PWD/../CryptoCiel

win32:!win32-g++: PRE_TARGETDEPS += $$PWD/../CryptoCiel/x64/Release/cryptoCielTest.lib
else:unix|win32-g++: PRE_TARGETDEPS += $$PWD/../CryptoCiel/x64/Release/libcryptoCielTest.a


