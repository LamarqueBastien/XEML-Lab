/****************************************************************************
** Meta object code from reading C++ file 'quantitativeparameter.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.1.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../XemlLab/XemlDesigner/DialogWindows/quantitativeparameter.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'quantitativeparameter.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.1.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_QuantitativeParameter_t {
    QByteArrayData data[12];
    char stringdata[133];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    offsetof(qt_meta_stringdata_QuantitativeParameter_t, stringdata) + ofs \
        - idx * sizeof(QByteArrayData) \
    )
static const qt_meta_stringdata_QuantitativeParameter_t qt_meta_stringdata_QuantitativeParameter = {
    {
QT_MOC_LITERAL(0, 0, 21),
QT_MOC_LITERAL(1, 22, 9),
QT_MOC_LITERAL(2, 32, 0),
QT_MOC_LITERAL(3, 33, 5),
QT_MOC_LITERAL(4, 39, 15),
QT_MOC_LITERAL(5, 55, 4),
QT_MOC_LITERAL(6, 60, 12),
QT_MOC_LITERAL(7, 73, 9),
QT_MOC_LITERAL(8, 83, 14),
QT_MOC_LITERAL(9, 98, 10),
QT_MOC_LITERAL(10, 109, 9),
QT_MOC_LITERAL(11, 119, 12)
    },
    "QuantitativeParameter\0OkClicked\0\0reset\0"
    "enabledOkButton\0_tmp\0set_dateTime\0"
    "_datetime\0inactive_value\0_CycleMode\0"
    "add_cycle\0remove_cycle\0"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_QuantitativeParameter[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       7,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,   49,    2, 0x08,
       3,    0,   50,    2, 0x08,
       4,    1,   51,    2, 0x08,
       6,    1,   54,    2, 0x08,
       8,    1,   57,    2, 0x08,
      10,    0,   60,    2, 0x08,
      11,    0,   61,    2, 0x08,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,    5,
    QMetaType::Void, QMetaType::QDateTime,    7,
    QMetaType::Void, QMetaType::Bool,    9,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void QuantitativeParameter::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        QuantitativeParameter *_t = static_cast<QuantitativeParameter *>(_o);
        switch (_id) {
        case 0: _t->OkClicked(); break;
        case 1: _t->reset(); break;
        case 2: _t->enabledOkButton((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 3: _t->set_dateTime((*reinterpret_cast< QDateTime(*)>(_a[1]))); break;
        case 4: _t->inactive_value((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 5: _t->add_cycle(); break;
        case 6: _t->remove_cycle(); break;
        default: ;
        }
    }
}

const QMetaObject QuantitativeParameter::staticMetaObject = {
    { &QDialog::staticMetaObject, qt_meta_stringdata_QuantitativeParameter.data,
      qt_meta_data_QuantitativeParameter,  qt_static_metacall, 0, 0}
};


const QMetaObject *QuantitativeParameter::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *QuantitativeParameter::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_QuantitativeParameter.stringdata))
        return static_cast<void*>(const_cast< QuantitativeParameter*>(this));
    return QDialog::qt_metacast(_clname);
}

int QuantitativeParameter::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDialog::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 7)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 7;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 7)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 7;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
