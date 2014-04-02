/****************************************************************************
** Meta object code from reading C++ file 'sqlconnectiondialog.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.1.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../XemlLab/XemlDesigner/DialogWindows/sqlconnectiondialog.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'sqlconnectiondialog.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.1.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_SQLConnectionDialog_t {
    QByteArrayData data[8];
    char stringdata[98];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    offsetof(qt_meta_stringdata_SQLConnectionDialog_t, stringdata) + ofs \
        - idx * sizeof(QByteArrayData) \
    )
static const qt_meta_stringdata_SQLConnectionDialog_t qt_meta_stringdata_SQLConnectionDialog = {
    {
QT_MOC_LITERAL(0, 0, 19),
QT_MOC_LITERAL(1, 20, 19),
QT_MOC_LITERAL(2, 40, 0),
QT_MOC_LITERAL(3, 41, 12),
QT_MOC_LITERAL(4, 54, 11),
QT_MOC_LITERAL(5, 66, 9),
QT_MOC_LITERAL(6, 76, 15),
QT_MOC_LITERAL(7, 92, 4)
    },
    "SQLConnectionDialog\0on_connection_added\0"
    "\0QStringList*\0_parameters\0OkClicked\0"
    "enabledOkButton\0text\0"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_SQLConnectionDialog[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       3,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   29,    2, 0x05,

 // slots: name, argc, parameters, tag, flags
       5,    0,   32,    2, 0x08,
       6,    1,   33,    2, 0x08,

 // signals: parameters
    QMetaType::Void, 0x80000000 | 3,    4,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString,    7,

       0        // eod
};

void SQLConnectionDialog::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        SQLConnectionDialog *_t = static_cast<SQLConnectionDialog *>(_o);
        switch (_id) {
        case 0: _t->on_connection_added((*reinterpret_cast< QStringList*(*)>(_a[1]))); break;
        case 1: _t->OkClicked(); break;
        case 2: _t->enabledOkButton((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (SQLConnectionDialog::*_t)(QStringList * );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&SQLConnectionDialog::on_connection_added)) {
                *result = 0;
            }
        }
    }
}

const QMetaObject SQLConnectionDialog::staticMetaObject = {
    { &QDialog::staticMetaObject, qt_meta_stringdata_SQLConnectionDialog.data,
      qt_meta_data_SQLConnectionDialog,  qt_static_metacall, 0, 0}
};


const QMetaObject *SQLConnectionDialog::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *SQLConnectionDialog::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_SQLConnectionDialog.stringdata))
        return static_cast<void*>(const_cast< SQLConnectionDialog*>(this));
    return QDialog::qt_metacast(_clname);
}

int SQLConnectionDialog::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDialog::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 3)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 3;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 3)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 3;
    }
    return _id;
}

// SIGNAL 0
void SQLConnectionDialog::on_connection_added(QStringList * _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}
QT_END_MOC_NAMESPACE
