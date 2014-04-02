/****************************************************************************
** Meta object code from reading C++ file 'uuiddialog.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.1.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../XemlLab/XemlDesigner/DialogWindows/uuiddialog.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'uuiddialog.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.1.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_UuidDialog_t {
    QByteArrayData data[7];
    char stringdata[59];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    offsetof(qt_meta_stringdata_UuidDialog_t, stringdata) + ofs \
        - idx * sizeof(QByteArrayData) \
    )
static const qt_meta_stringdata_UuidDialog_t qt_meta_stringdata_UuidDialog = {
    {
QT_MOC_LITERAL(0, 0, 10),
QT_MOC_LITERAL(1, 11, 8),
QT_MOC_LITERAL(2, 20, 0),
QT_MOC_LITERAL(3, 21, 5),
QT_MOC_LITERAL(4, 27, 9),
QT_MOC_LITERAL(5, 37, 15),
QT_MOC_LITERAL(6, 53, 4)
    },
    "UuidDialog\0new_uuid\0\0_text\0OkClicked\0"
    "enabledOkButton\0text\0"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_UuidDialog[] = {

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
       4,    0,   32,    2, 0x08,
       5,    1,   33,    2, 0x08,

 // signals: parameters
    QMetaType::Void, QMetaType::QString,    3,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString,    6,

       0        // eod
};

void UuidDialog::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        UuidDialog *_t = static_cast<UuidDialog *>(_o);
        switch (_id) {
        case 0: _t->new_uuid((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 1: _t->OkClicked(); break;
        case 2: _t->enabledOkButton((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (UuidDialog::*_t)(QString );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&UuidDialog::new_uuid)) {
                *result = 0;
            }
        }
    }
}

const QMetaObject UuidDialog::staticMetaObject = {
    { &QDialog::staticMetaObject, qt_meta_stringdata_UuidDialog.data,
      qt_meta_data_UuidDialog,  qt_static_metacall, 0, 0}
};


const QMetaObject *UuidDialog::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *UuidDialog::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_UuidDialog.stringdata))
        return static_cast<void*>(const_cast< UuidDialog*>(this));
    return QDialog::qt_metacast(_clname);
}

int UuidDialog::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
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
void UuidDialog::new_uuid(QString _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}
QT_END_MOC_NAMESPACE
