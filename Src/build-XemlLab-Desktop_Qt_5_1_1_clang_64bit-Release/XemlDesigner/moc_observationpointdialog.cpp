/****************************************************************************
** Meta object code from reading C++ file 'observationpointdialog.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.1.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../XemlLab/XemlDesigner/DialogWindows/observationpointdialog.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'observationpointdialog.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.1.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_ObservationPointDialog_t {
    QByteArrayData data[8];
    char stringdata[91];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    offsetof(qt_meta_stringdata_ObservationPointDialog_t, stringdata) + ofs \
        - idx * sizeof(QByteArrayData) \
    )
static const qt_meta_stringdata_ObservationPointDialog_t qt_meta_stringdata_ObservationPointDialog = {
    {
QT_MOC_LITERAL(0, 0, 22),
QT_MOC_LITERAL(1, 23, 10),
QT_MOC_LITERAL(2, 34, 0),
QT_MOC_LITERAL(3, 35, 17),
QT_MOC_LITERAL(4, 53, 4),
QT_MOC_LITERAL(5, 58, 9),
QT_MOC_LITERAL(6, 68, 15),
QT_MOC_LITERAL(7, 84, 5)
    },
    "ObservationPointDialog\0mon_signal\0\0"
    "ObservationPoint*\0_obs\0OkClicked\0"
    "enabledOkButton\0_date\0"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_ObservationPointDialog[] = {

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
    QMetaType::Void, QMetaType::QDateTime,    7,

       0        // eod
};

void ObservationPointDialog::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        ObservationPointDialog *_t = static_cast<ObservationPointDialog *>(_o);
        switch (_id) {
        case 0: _t->mon_signal((*reinterpret_cast< ObservationPoint*(*)>(_a[1]))); break;
        case 1: _t->OkClicked(); break;
        case 2: _t->enabledOkButton((*reinterpret_cast< QDateTime(*)>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (ObservationPointDialog::*_t)(ObservationPoint * );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&ObservationPointDialog::mon_signal)) {
                *result = 0;
            }
        }
    }
}

const QMetaObject ObservationPointDialog::staticMetaObject = {
    { &QDialog::staticMetaObject, qt_meta_stringdata_ObservationPointDialog.data,
      qt_meta_data_ObservationPointDialog,  qt_static_metacall, 0, 0}
};


const QMetaObject *ObservationPointDialog::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *ObservationPointDialog::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_ObservationPointDialog.stringdata))
        return static_cast<void*>(const_cast< ObservationPointDialog*>(this));
    return QDialog::qt_metacast(_clname);
}

int ObservationPointDialog::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
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
void ObservationPointDialog::mon_signal(ObservationPoint * _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}
QT_END_MOC_NAMESPACE
