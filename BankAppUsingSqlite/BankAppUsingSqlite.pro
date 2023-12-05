QT       += core gui sql

LIBS     += 'D:\qt practice program\QtPractice\Sql application\BankAppUsingSqlite\libLoginLib.a'

LIBS    += 'D:\qt practice program\QtPractice\Sql application\BankAppUsingSqlite\libsqllite3.a'

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    main.cpp \
    login.cpp \
    profile.cpp \
    transfer.cpp

HEADERS += \
    login.h \
    profile.h \
    sqlite3.h \
    sqlite3ext.h \
    transfer.h

FORMS += \
    login.ui \
    profile.ui \
    transfer.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
