/****************************************************************************
** Meta object code from reading C++ file 'manageusers.h'
**
** Created by: The Qt Meta Object Compiler version 68 (Qt 6.0.3)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../../NoodleClient/manageusers.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'manageusers.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 68
#error "This file was generated using the moc from 6.0.3. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_manageUsers_t {
    const uint offsetsAndSize[24];
    char stringdata0[185];
};
#define QT_MOC_LITERAL(ofs, len) \
    uint(offsetof(qt_meta_stringdata_manageUsers_t, stringdata0) + ofs), len 
static const qt_meta_stringdata_manageUsers_t qt_meta_stringdata_manageUsers = {
    {
QT_MOC_LITERAL(0, 11), // "manageUsers"
QT_MOC_LITERAL(12, 24), // "on_addUserButton_clicked"
QT_MOC_LITERAL(37, 0), // ""
QT_MOC_LITERAL(38, 27), // "on_deleteUserButton_clicked"
QT_MOC_LITERAL(66, 18), // "populateUsersTable"
QT_MOC_LITERAL(85, 15), // "vector<string>&"
QT_MOC_LITERAL(101, 1), // "v"
QT_MOC_LITERAL(103, 27), // "on_listAccounts_itemClicked"
QT_MOC_LITERAL(131, 17), // "QTableWidgetItem*"
QT_MOC_LITERAL(149, 4), // "item"
QT_MOC_LITERAL(154, 25), // "on_searchUser_textChanged"
QT_MOC_LITERAL(180, 4) // "arg1"

    },
    "manageUsers\0on_addUserButton_clicked\0"
    "\0on_deleteUserButton_clicked\0"
    "populateUsersTable\0vector<string>&\0v\0"
    "on_listAccounts_itemClicked\0"
    "QTableWidgetItem*\0item\0on_searchUser_textChanged\0"
    "arg1"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_manageUsers[] = {

 // content:
       9,       // revision
       0,       // classname
       0,    0, // classinfo
       5,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags, initial metatype offsets
       1,    0,   44,    2, 0x08,    0 /* Private */,
       3,    0,   45,    2, 0x08,    1 /* Private */,
       4,    1,   46,    2, 0x08,    2 /* Private */,
       7,    1,   49,    2, 0x08,    4 /* Private */,
      10,    1,   52,    2, 0x08,    6 /* Private */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 5,    6,
    QMetaType::Void, 0x80000000 | 8,    9,
    QMetaType::Void, QMetaType::QString,   11,

       0        // eod
};

void manageUsers::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<manageUsers *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->on_addUserButton_clicked(); break;
        case 1: _t->on_deleteUserButton_clicked(); break;
        case 2: _t->populateUsersTable((*reinterpret_cast< vector<string>(*)>(_a[1]))); break;
        case 3: _t->on_listAccounts_itemClicked((*reinterpret_cast< QTableWidgetItem*(*)>(_a[1]))); break;
        case 4: _t->on_searchUser_textChanged((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        default: ;
        }
    }
}

const QMetaObject manageUsers::staticMetaObject = { {
    QMetaObject::SuperData::link<QDialog::staticMetaObject>(),
    qt_meta_stringdata_manageUsers.offsetsAndSize,
    qt_meta_data_manageUsers,
    qt_static_metacall,
    nullptr,
qt_incomplete_metaTypeArray<qt_meta_stringdata_manageUsers_t

, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<vector<string> &, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<QTableWidgetItem *, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<const QString &, std::false_type>


>,
    nullptr
} };


const QMetaObject *manageUsers::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *manageUsers::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_manageUsers.stringdata0))
        return static_cast<void*>(this);
    return QDialog::qt_metacast(_clname);
}

int manageUsers::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDialog::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 5)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 5;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 5)
            *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType();
        _id -= 5;
    }
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
