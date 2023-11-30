/****************************************************************************
** Meta object code from reading C++ file 'profilepage.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.12.12)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../BankApp/profilepage.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'profilepage.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.12.12. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_profilePage_t {
    QByteArrayData data[11];
    char stringdata0[217];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_profilePage_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_profilePage_t qt_meta_stringdata_profilePage = {
    {
QT_MOC_LITERAL(0, 0, 11), // "profilePage"
QT_MOC_LITERAL(1, 12, 29), // "on_pushButton_account_clicked"
QT_MOC_LITERAL(2, 42, 0), // ""
QT_MOC_LITERAL(3, 43, 30), // "on_pushButton_Transfer_clicked"
QT_MOC_LITERAL(4, 74, 29), // "on_pushButton_Balance_clicked"
QT_MOC_LITERAL(5, 104, 28), // "on_pushButton_Logout_clicked"
QT_MOC_LITERAL(6, 133, 14), // "accountDetails"
QT_MOC_LITERAL(7, 148, 7), // "deposit"
QT_MOC_LITERAL(8, 156, 15), // "balanceTransfer"
QT_MOC_LITERAL(9, 172, 14), // "balanceEnquiry"
QT_MOC_LITERAL(10, 187, 29) // "on_pushButton_Deposit_clicked"

    },
    "profilePage\0on_pushButton_account_clicked\0"
    "\0on_pushButton_Transfer_clicked\0"
    "on_pushButton_Balance_clicked\0"
    "on_pushButton_Logout_clicked\0"
    "accountDetails\0deposit\0balanceTransfer\0"
    "balanceEnquiry\0on_pushButton_Deposit_clicked"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_profilePage[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
       9,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,   59,    2, 0x08 /* Private */,
       3,    0,   60,    2, 0x08 /* Private */,
       4,    0,   61,    2, 0x08 /* Private */,
       5,    0,   62,    2, 0x08 /* Private */,
       6,    0,   63,    2, 0x08 /* Private */,
       7,    1,   64,    2, 0x08 /* Private */,
       8,    1,   67,    2, 0x08 /* Private */,
       9,    0,   70,    2, 0x08 /* Private */,
      10,    0,   71,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Float,    2,
    QMetaType::Bool, QMetaType::Float,    2,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void profilePage::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<profilePage *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->on_pushButton_account_clicked(); break;
        case 1: _t->on_pushButton_Transfer_clicked(); break;
        case 2: _t->on_pushButton_Balance_clicked(); break;
        case 3: _t->on_pushButton_Logout_clicked(); break;
        case 4: _t->accountDetails(); break;
        case 5: _t->deposit((*reinterpret_cast< float(*)>(_a[1]))); break;
        case 6: { bool _r = _t->balanceTransfer((*reinterpret_cast< float(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = std::move(_r); }  break;
        case 7: _t->balanceEnquiry(); break;
        case 8: _t->on_pushButton_Deposit_clicked(); break;
        default: ;
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject profilePage::staticMetaObject = { {
    &QDialog::staticMetaObject,
    qt_meta_stringdata_profilePage.data,
    qt_meta_data_profilePage,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *profilePage::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *profilePage::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_profilePage.stringdata0))
        return static_cast<void*>(this);
    return QDialog::qt_metacast(_clname);
}

int profilePage::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDialog::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 9)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 9;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 9)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 9;
    }
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
