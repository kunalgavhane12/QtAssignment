/****************************************************************************
** Meta object code from reading C++ file 'ClientManager.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.12.12)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../Server/ClientManager.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'ClientManager.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.12.12. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_ClientManager_t {
    QByteArrayData data[20];
    char stringdata0[226];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_ClientManager_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_ClientManager_t qt_meta_stringdata_ClientManager = {
    {
QT_MOC_LITERAL(0, 0, 13), // "ClientManager"
QT_MOC_LITERAL(1, 14, 9), // "connected"
QT_MOC_LITERAL(2, 24, 0), // ""
QT_MOC_LITERAL(3, 25, 12), // "disconnected"
QT_MOC_LITERAL(4, 38, 19), // "textMessageReceived"
QT_MOC_LITERAL(5, 58, 7), // "message"
QT_MOC_LITERAL(6, 66, 8), // "isTyping"
QT_MOC_LITERAL(7, 75, 11), // "nameChanged"
QT_MOC_LITERAL(8, 87, 4), // "name"
QT_MOC_LITERAL(9, 92, 13), // "statusChanged"
QT_MOC_LITERAL(10, 106, 20), // "ChatProtocol::Status"
QT_MOC_LITERAL(11, 127, 6), // "status"
QT_MOC_LITERAL(12, 134, 19), // "rejectReceivingFile"
QT_MOC_LITERAL(13, 154, 17), // "initReceivingFile"
QT_MOC_LITERAL(14, 172, 10), // "clientName"
QT_MOC_LITERAL(15, 183, 8), // "fileName"
QT_MOC_LITERAL(16, 192, 8), // "fileSize"
QT_MOC_LITERAL(17, 201, 9), // "fileSaved"
QT_MOC_LITERAL(18, 211, 4), // "path"
QT_MOC_LITERAL(19, 216, 9) // "readyRead"

    },
    "ClientManager\0connected\0\0disconnected\0"
    "textMessageReceived\0message\0isTyping\0"
    "nameChanged\0name\0statusChanged\0"
    "ChatProtocol::Status\0status\0"
    "rejectReceivingFile\0initReceivingFile\0"
    "clientName\0fileName\0fileSize\0fileSaved\0"
    "path\0readyRead"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_ClientManager[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
      10,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       9,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    0,   64,    2, 0x06 /* Public */,
       3,    0,   65,    2, 0x06 /* Public */,
       4,    1,   66,    2, 0x06 /* Public */,
       6,    0,   69,    2, 0x06 /* Public */,
       7,    1,   70,    2, 0x06 /* Public */,
       9,    1,   73,    2, 0x06 /* Public */,
      12,    0,   76,    2, 0x06 /* Public */,
      13,    3,   77,    2, 0x06 /* Public */,
      17,    1,   84,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
      19,    0,   87,    2, 0x08 /* Private */,

 // signals: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString,    5,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString,    8,
    QMetaType::Void, 0x80000000 | 10,   11,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString, QMetaType::QString, QMetaType::LongLong,   14,   15,   16,
    QMetaType::Void, QMetaType::QString,   18,

 // slots: parameters
    QMetaType::Void,

       0        // eod
};

void ClientManager::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<ClientManager *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->connected(); break;
        case 1: _t->disconnected(); break;
        case 2: _t->textMessageReceived((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 3: _t->isTyping(); break;
        case 4: _t->nameChanged((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 5: _t->statusChanged((*reinterpret_cast< ChatProtocol::Status(*)>(_a[1]))); break;
        case 6: _t->rejectReceivingFile(); break;
        case 7: _t->initReceivingFile((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2])),(*reinterpret_cast< qint64(*)>(_a[3]))); break;
        case 8: _t->fileSaved((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 9: _t->readyRead(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (ClientManager::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&ClientManager::connected)) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (ClientManager::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&ClientManager::disconnected)) {
                *result = 1;
                return;
            }
        }
        {
            using _t = void (ClientManager::*)(const QString );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&ClientManager::textMessageReceived)) {
                *result = 2;
                return;
            }
        }
        {
            using _t = void (ClientManager::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&ClientManager::isTyping)) {
                *result = 3;
                return;
            }
        }
        {
            using _t = void (ClientManager::*)(QString );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&ClientManager::nameChanged)) {
                *result = 4;
                return;
            }
        }
        {
            using _t = void (ClientManager::*)(ChatProtocol::Status );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&ClientManager::statusChanged)) {
                *result = 5;
                return;
            }
        }
        {
            using _t = void (ClientManager::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&ClientManager::rejectReceivingFile)) {
                *result = 6;
                return;
            }
        }
        {
            using _t = void (ClientManager::*)(QString , QString , qint64 );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&ClientManager::initReceivingFile)) {
                *result = 7;
                return;
            }
        }
        {
            using _t = void (ClientManager::*)(QString );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&ClientManager::fileSaved)) {
                *result = 8;
                return;
            }
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject ClientManager::staticMetaObject = { {
    &QObject::staticMetaObject,
    qt_meta_stringdata_ClientManager.data,
    qt_meta_data_ClientManager,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *ClientManager::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *ClientManager::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_ClientManager.stringdata0))
        return static_cast<void*>(this);
    return QObject::qt_metacast(_clname);
}

int ClientManager::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 10)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 10;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 10)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 10;
    }
    return _id;
}

// SIGNAL 0
void ClientManager::connected()
{
    QMetaObject::activate(this, &staticMetaObject, 0, nullptr);
}

// SIGNAL 1
void ClientManager::disconnected()
{
    QMetaObject::activate(this, &staticMetaObject, 1, nullptr);
}

// SIGNAL 2
void ClientManager::textMessageReceived(const QString _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}

// SIGNAL 3
void ClientManager::isTyping()
{
    QMetaObject::activate(this, &staticMetaObject, 3, nullptr);
}

// SIGNAL 4
void ClientManager::nameChanged(QString _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 4, _a);
}

// SIGNAL 5
void ClientManager::statusChanged(ChatProtocol::Status _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 5, _a);
}

// SIGNAL 6
void ClientManager::rejectReceivingFile()
{
    QMetaObject::activate(this, &staticMetaObject, 6, nullptr);
}

// SIGNAL 7
void ClientManager::initReceivingFile(QString _t1, QString _t2, qint64 _t3)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)), const_cast<void*>(reinterpret_cast<const void*>(&_t3)) };
    QMetaObject::activate(this, &staticMetaObject, 7, _a);
}

// SIGNAL 8
void ClientManager::fileSaved(QString _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 8, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
