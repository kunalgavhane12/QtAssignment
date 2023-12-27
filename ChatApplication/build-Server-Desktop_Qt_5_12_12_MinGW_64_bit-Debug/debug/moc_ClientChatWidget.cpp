/****************************************************************************
** Meta object code from reading C++ file 'ClientChatWidget.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.12.12)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../Server/ClientChatWidget.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'ClientChatWidget.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.12.12. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_ClientChatWidget_t {
    QByteArrayData data[22];
    char stringdata0[289];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_ClientChatWidget_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_ClientChatWidget_t qt_meta_stringdata_ClientChatWidget = {
    {
QT_MOC_LITERAL(0, 0, 16), // "ClientChatWidget"
QT_MOC_LITERAL(1, 17, 17), // "clientNameChanged"
QT_MOC_LITERAL(2, 35, 0), // ""
QT_MOC_LITERAL(3, 36, 4), // "name"
QT_MOC_LITERAL(4, 41, 8), // "isTyping"
QT_MOC_LITERAL(5, 50, 7), // "message"
QT_MOC_LITERAL(6, 58, 13), // "statusChanged"
QT_MOC_LITERAL(7, 72, 20), // "ChatProtocol::Status"
QT_MOC_LITERAL(8, 93, 6), // "status"
QT_MOC_LITERAL(9, 100, 18), // "clientDisconnected"
QT_MOC_LITERAL(10, 119, 18), // "on_btnSend_clicked"
QT_MOC_LITERAL(11, 138, 19), // "textMessageReceived"
QT_MOC_LITERAL(12, 158, 8), // "onTyping"
QT_MOC_LITERAL(13, 167, 19), // "onInitReceivingFile"
QT_MOC_LITERAL(14, 187, 10), // "clientName"
QT_MOC_LITERAL(15, 198, 8), // "fileName"
QT_MOC_LITERAL(16, 207, 8), // "fileSize"
QT_MOC_LITERAL(17, 216, 11), // "onFileSaved"
QT_MOC_LITERAL(18, 228, 4), // "path"
QT_MOC_LITERAL(19, 233, 30), // "on_lblOpenFolder_linkActivated"
QT_MOC_LITERAL(20, 264, 4), // "link"
QT_MOC_LITERAL(21, 269, 19) // "onClientNameChanged"

    },
    "ClientChatWidget\0clientNameChanged\0\0"
    "name\0isTyping\0message\0statusChanged\0"
    "ChatProtocol::Status\0status\0"
    "clientDisconnected\0on_btnSend_clicked\0"
    "textMessageReceived\0onTyping\0"
    "onInitReceivingFile\0clientName\0fileName\0"
    "fileSize\0onFileSaved\0path\0"
    "on_lblOpenFolder_linkActivated\0link\0"
    "onClientNameChanged"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_ClientChatWidget[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
      11,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       3,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   69,    2, 0x06 /* Public */,
       4,    1,   72,    2, 0x06 /* Public */,
       6,    1,   75,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       9,    0,   78,    2, 0x08 /* Private */,
      10,    0,   79,    2, 0x08 /* Private */,
      11,    1,   80,    2, 0x08 /* Private */,
      12,    0,   83,    2, 0x08 /* Private */,
      13,    3,   84,    2, 0x08 /* Private */,
      17,    1,   91,    2, 0x08 /* Private */,
      19,    1,   94,    2, 0x08 /* Private */,
      21,    1,   97,    2, 0x08 /* Private */,

 // signals: parameters
    QMetaType::Void, QMetaType::QString,    3,
    QMetaType::Void, QMetaType::QString,    5,
    QMetaType::Void, 0x80000000 | 7,    8,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString,    5,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString, QMetaType::QString, QMetaType::LongLong,   14,   15,   16,
    QMetaType::Void, QMetaType::QString,   18,
    QMetaType::Void, QMetaType::QString,   20,
    QMetaType::Void, QMetaType::QString,    3,

       0        // eod
};

void ClientChatWidget::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<ClientChatWidget *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->clientNameChanged((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 1: _t->isTyping((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 2: _t->statusChanged((*reinterpret_cast< ChatProtocol::Status(*)>(_a[1]))); break;
        case 3: _t->clientDisconnected(); break;
        case 4: _t->on_btnSend_clicked(); break;
        case 5: _t->textMessageReceived((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 6: _t->onTyping(); break;
        case 7: _t->onInitReceivingFile((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2])),(*reinterpret_cast< qint64(*)>(_a[3]))); break;
        case 8: _t->onFileSaved((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 9: _t->on_lblOpenFolder_linkActivated((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 10: _t->onClientNameChanged((*reinterpret_cast< QString(*)>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (ClientChatWidget::*)(QString );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&ClientChatWidget::clientNameChanged)) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (ClientChatWidget::*)(QString );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&ClientChatWidget::isTyping)) {
                *result = 1;
                return;
            }
        }
        {
            using _t = void (ClientChatWidget::*)(ChatProtocol::Status );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&ClientChatWidget::statusChanged)) {
                *result = 2;
                return;
            }
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject ClientChatWidget::staticMetaObject = { {
    &QWidget::staticMetaObject,
    qt_meta_stringdata_ClientChatWidget.data,
    qt_meta_data_ClientChatWidget,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *ClientChatWidget::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *ClientChatWidget::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_ClientChatWidget.stringdata0))
        return static_cast<void*>(this);
    return QWidget::qt_metacast(_clname);
}

int ClientChatWidget::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 11)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 11;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 11)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 11;
    }
    return _id;
}

// SIGNAL 0
void ClientChatWidget::clientNameChanged(QString _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void ClientChatWidget::isTyping(QString _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void ClientChatWidget::statusChanged(ChatProtocol::Status _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
