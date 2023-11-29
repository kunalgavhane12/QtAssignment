QT += widgets

LIBS += 'D:\qt practice program\QtPractice\Sql application\Login_Library\libsqllite3.a'

TEMPLATE = lib
CONFIG += staticlib

CONFIG += c++11

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    loginpage.cpp \
    main.cpp \
    profilepage.cpp

HEADERS += \
    loginpage.h \
    profilepage.h \
    sqlite3.h

# Default rules for deployment.
unix {
    target.path = $$[QT_INSTALL_PLUGINS]/generic
}
!isEmpty(target.path): INSTALLS += target

FORMS += \
    loginpage.ui \
    profilepage.ui
