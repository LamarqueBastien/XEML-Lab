/****************************************************************************
** Meta object code from reading C++ file 'qualitativeparameter.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.1.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../XemlLab/XemlDesigner/DialogWindows/qualitativeparameter.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'qualitativeparameter.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.1.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_QualitativeParameter_t {
    QByteArrayData data[14];
    char stringdata[154];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    offsetof(qt_meta_stringdata_QualitativeParameter_t, stringdata) + ofs \
        - idx * sizeof(QByteArrayData) \
    )
static const qt_meta_stringdata_QualitativeParameter_t qt_meta_stringdata_QualitativeParameter = {
    {
QT_MOC_LITERAL(0, 0, 20),
QT_MOC_LITERAL(1, 21, 10),
QT_MOC_LITERAL(2, 32, 0),
QT_MOC_LITERAL(3, 33, 13),
QT_MOC_LITERAL(4, 47, 2),
QT_MOC_LITERAL(5, 50, 14),
QT_MOC_LITERAL(6, 65, 10),
QT_MOC_LITERAL(7, 76, 12),
QT_MOC_LITERAL(8, 89, 9),
QT_MOC_LITERAL(9, 99, 9),
QT_MOC_LITERAL(10, 109, 9),
QT_MOC_LITERAL(11, 119, 12),
QT_MOC_LITERAL(12, 132, 15),
QT_MOC_LITERAL(13, 148, 4)
    },
    "QualitativeParameter\0send_value\0\0"
    "DynamicValue*\0_v\0inactive_value\0"
    "_CycleMode\0set_dateTime\0_datetime\0"
    "OkClicked\0add_cycle\0remove_cycle\0"
    "enabledOkButton\0text\0"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_QualitativeParameter[] = {

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
       5,    1,   52,    2, 0x08,
       7,    1,   55,    2, 0x08,
       9,    0,   58,    2, 0x08,
      10,    0,   59,    2, 0x08,
      11,    0,   60,    2, 0x08,
      12,    1,   61,    2, 0x08,

 // signals: parameters
    QMetaType::Void, 0x80000000 | 3,    4,

 // slots: parameters
    QMetaType::Void, QMetaType::Bool,    6,
    QMetaType::Void, QMetaType::QDateTime,    8,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString,   13,

       0        // eod
};

void QualitativeParameter::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        QualitativeParameter *_t = static_cast<QualitativeParameter *>(_o);
        switch (_id) {
        case 0: _t->send_value((*reinterpret_cast< DynamicValue*(*)>(_a[1]))); break;
        case 1: _t->inactive_value((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 2: _t->set_dateTime((*reinterpret_cast< QDateTime(*)>(_a[1]))); break;
        case 3: _t->OkClicked(); break;
        case 4: _t->add_cycle(); break;
        case 5: _t->remove_cycle(); break;
        case 6: _t->enabledOkButton((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (QualitativeParameter::*_t)(DynamicValue * );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&QualitativeParameter::send_value)) {
                *result = 0;
            }
        }
    }
}

const QMetaObject QualitativeParameter::staticMetaObject = {
    { &QDialog::staticMetaObject, qt_meta_stringdata_QualitativeParameter.data,
      qt_meta_data_QualitativeParameter,  qt_static_metacall, 0, 0}
};


const QMetaObject *QualitativeParameter::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *QualitativeParameter::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_QualitativeParameter.stringdata))
        return static_cast<void*>(const_cast< QualitativeParameter*>(this));
    return QDialog::qt_metacast(_clname);
}

int QualitativeParameter::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
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
void QualitativeParameter::send_value(DynamicValue * _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}
QT_END_MOC_NAMESPACE
