/****************************************************************************
** Meta object code from reading C++ file 'aboutparameter.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.1.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../XemlLab/XemlDesigner/AboutWindows/aboutparameter.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'aboutparameter.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.1.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_AboutParameter_t {
    QByteArrayData data[15];
    char stringdata[216];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    offsetof(qt_meta_stringdata_AboutParameter_t, stringdata) + ofs \
        - idx * sizeof(QByteArrayData) \
    )
static const qt_meta_stringdata_AboutParameter_t qt_meta_stringdata_AboutParameter = {
    {
QT_MOC_LITERAL(0, 0, 14),
QT_MOC_LITERAL(1, 15, 15),
QT_MOC_LITERAL(2, 31, 0),
QT_MOC_LITERAL(3, 32, 16),
QT_MOC_LITERAL(4, 49, 5),
QT_MOC_LITERAL(5, 55, 10),
QT_MOC_LITERAL(6, 66, 6),
QT_MOC_LITERAL(7, 73, 10),
QT_MOC_LITERAL(8, 84, 17),
QT_MOC_LITERAL(9, 102, 23),
QT_MOC_LITERAL(10, 126, 13),
QT_MOC_LITERAL(11, 140, 2),
QT_MOC_LITERAL(12, 143, 25),
QT_MOC_LITERAL(13, 169, 24),
QT_MOC_LITERAL(14, 194, 20)
    },
    "AboutParameter\0set_up_finished\0\0"
    "ItfOntologyTerm*\0_term\0StoryNode*\0"
    "_story\0BasicTerm*\0on_setup_finished\0"
    "set_up_qualitativeValue\0DynamicValue*\0"
    "_v\0set_up_responseRangeValue\0"
    "set_up_quantitativeValue\0set_up_freeTextValue\0"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_AboutParameter[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       7,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       2,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   49,    2, 0x05,
       1,    2,   52,    2, 0x05,

 // slots: name, argc, parameters, tag, flags
       8,    0,   57,    2, 0x08,
       9,    1,   58,    2, 0x08,
      12,    1,   61,    2, 0x08,
      13,    1,   64,    2, 0x08,
      14,    1,   67,    2, 0x08,

 // signals: parameters
    QMetaType::Void, 0x80000000 | 3,    4,
    QMetaType::Void, 0x80000000 | 5, 0x80000000 | 7,    6,    4,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 10,   11,
    QMetaType::Void, 0x80000000 | 10,   11,
    QMetaType::Void, 0x80000000 | 10,   11,
    QMetaType::Void, 0x80000000 | 10,   11,

       0        // eod
};

void AboutParameter::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        AboutParameter *_t = static_cast<AboutParameter *>(_o);
        switch (_id) {
        case 0: _t->set_up_finished((*reinterpret_cast< ItfOntologyTerm*(*)>(_a[1]))); break;
        case 1: _t->set_up_finished((*reinterpret_cast< StoryNode*(*)>(_a[1])),(*reinterpret_cast< BasicTerm*(*)>(_a[2]))); break;
        case 2: _t->on_setup_finished(); break;
        case 3: _t->set_up_qualitativeValue((*reinterpret_cast< DynamicValue*(*)>(_a[1]))); break;
        case 4: _t->set_up_responseRangeValue((*reinterpret_cast< DynamicValue*(*)>(_a[1]))); break;
        case 5: _t->set_up_quantitativeValue((*reinterpret_cast< DynamicValue*(*)>(_a[1]))); break;
        case 6: _t->set_up_freeTextValue((*reinterpret_cast< DynamicValue*(*)>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (AboutParameter::*_t)(ItfOntologyTerm * );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&AboutParameter::set_up_finished)) {
                *result = 0;
            }
        }
        {
            typedef void (AboutParameter::*_t)(StoryNode * , BasicTerm * );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&AboutParameter::set_up_finished)) {
                *result = 1;
            }
        }
    }
}

const QMetaObject AboutParameter::staticMetaObject = {
    { &QDialog::staticMetaObject, qt_meta_stringdata_AboutParameter.data,
      qt_meta_data_AboutParameter,  qt_static_metacall, 0, 0}
};


const QMetaObject *AboutParameter::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *AboutParameter::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_AboutParameter.stringdata))
        return static_cast<void*>(const_cast< AboutParameter*>(this));
    return QDialog::qt_metacast(_clname);
}

int AboutParameter::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
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
void AboutParameter::set_up_finished(ItfOntologyTerm * _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void AboutParameter::set_up_finished(StoryNode * _t1, BasicTerm * _t2)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}
QT_END_MOC_NAMESPACE
