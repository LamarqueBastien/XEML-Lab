/****************************************************************************
** Meta object code from reading C++ file 'responserangeparameter.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.1.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../XemlLab/XemlDesigner/DialogWindows/responserangeparameter.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'responserangeparameter.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.1.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_ResponseRangeParameter_t {
    QByteArrayData data[14];
    char stringdata[156];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    offsetof(qt_meta_stringdata_ResponseRangeParameter_t, stringdata) + ofs \
        - idx * sizeof(QByteArrayData) \
    )
static const qt_meta_stringdata_ResponseRangeParameter_t qt_meta_stringdata_ResponseRangeParameter = {
    {
QT_MOC_LITERAL(0, 0, 22),
QT_MOC_LITERAL(1, 23, 10),
QT_MOC_LITERAL(2, 34, 0),
QT_MOC_LITERAL(3, 35, 13),
QT_MOC_LITERAL(4, 49, 2),
QT_MOC_LITERAL(5, 52, 9),
QT_MOC_LITERAL(6, 62, 12),
QT_MOC_LITERAL(7, 75, 9),
QT_MOC_LITERAL(8, 85, 15),
QT_MOC_LITERAL(9, 101, 4),
QT_MOC_LITERAL(10, 106, 14),
QT_MOC_LITERAL(11, 121, 10),
QT_MOC_LITERAL(12, 132, 9),
QT_MOC_LITERAL(13, 142, 12)
    },
    "ResponseRangeParameter\0send_value\0\0"
    "DynamicValue*\0_v\0OkClicked\0set_dateTime\0"
    "_datetime\0enabledOkButton\0text\0"
    "inactive_value\0_CycleMode\0add_cycle\0"
    "remove_cycle\0"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_ResponseRangeParameter[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       7,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   49,    2, 0x05,

 // slots: name, argc, parameters, tag, flags
       5,    0,   52,    2, 0x08,
       6,    1,   53,    2, 0x08,
       8,    1,   56,    2, 0x08,
      10,    1,   59,    2, 0x08,
      12,    0,   62,    2, 0x08,
      13,    0,   63,    2, 0x08,

 // signals: parameters
    QMetaType::Void, 0x80000000 | 3,    4,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void, QMetaType::QDateTime,    7,
    QMetaType::Void, QMetaType::QString,    9,
    QMetaType::Void, QMetaType::Bool,   11,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void ResponseRangeParameter::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        ResponseRangeParameter *_t = static_cast<ResponseRangeParameter *>(_o);
        switch (_id) {
        case 0: _t->send_value((*reinterpret_cast< DynamicValue*(*)>(_a[1]))); break;
        case 1: _t->OkClicked(); break;
        case 2: _t->set_dateTime((*reinterpret_cast< QDateTime(*)>(_a[1]))); break;
        case 3: _t->enabledOkButton((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 4: _t->inactive_value((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 5: _t->add_cycle(); break;
        case 6: _t->remove_cycle(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (ResponseRangeParameter::*_t)(DynamicValue * );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&ResponseRangeParameter::send_value)) {
                *result = 0;
            }
        }
    }
}

const QMetaObject ResponseRangeParameter::staticMetaObject = {
    { &QDialog::staticMetaObject, qt_meta_stringdata_ResponseRangeParameter.data,
      qt_meta_data_ResponseRangeParameter,  qt_static_metacall, 0, 0}
};


const QMetaObject *ResponseRangeParameter::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *ResponseRangeParameter::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_ResponseRangeParameter.stringdata))
        return static_cast<void*>(const_cast< ResponseRangeParameter*>(this));
    return QDialog::qt_metacast(_clname);
}

int ResponseRangeParameter::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
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

// SIGNAL 0
void ResponseRangeParameter::send_value(DynamicValue * _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}
QT_END_MOC_NAMESPACE
