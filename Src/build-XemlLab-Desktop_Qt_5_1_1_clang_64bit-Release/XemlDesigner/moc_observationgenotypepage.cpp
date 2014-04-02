/****************************************************************************
** Meta object code from reading C++ file 'observationgenotypepage.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.1.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../XemlLab/XemlDesigner/SampleLoader/observationgenotypepage.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'observationgenotypepage.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.1.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_ObservationGenotypePage_t {
    QByteArrayData data[9];
    char stringdata[112];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    offsetof(qt_meta_stringdata_ObservationGenotypePage_t, stringdata) + ofs \
        - idx * sizeof(QByteArrayData) \
    )
static const qt_meta_stringdata_ObservationGenotypePage_t qt_meta_stringdata_ObservationGenotypePage = {
    {
QT_MOC_LITERAL(0, 0, 23),
QT_MOC_LITERAL(1, 24, 8),
QT_MOC_LITERAL(2, 33, 0),
QT_MOC_LITERAL(3, 34, 4),
QT_MOC_LITERAL(4, 39, 13),
QT_MOC_LITERAL(5, 53, 15),
QT_MOC_LITERAL(6, 69, 5),
QT_MOC_LITERAL(7, 75, 14),
QT_MOC_LITERAL(8, 90, 20)
    },
    "ObservationGenotypePage\0validate\0\0"
    "_QMI\0validate_list\0QModelIndexList\0"
    "_QMIL\0selectionModel\0QItemSelectionModel*\0"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_ObservationGenotypePage[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       2,   14, // methods
       1,   30, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    1,   24,    2, 0x08,
       4,    1,   27,    2, 0x08,

 // slots: parameters
    QMetaType::Void, QMetaType::QModelIndex,    3,
    QMetaType::Void, 0x80000000 | 5,    6,

 // properties: name, type, flags
       7, 0x80000000 | 8, 0x00095009,

       0        // eod
};

void ObservationGenotypePage::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        ObservationGenotypePage *_t = static_cast<ObservationGenotypePage *>(_o);
        switch (_id) {
        case 0: _t->validate((*reinterpret_cast< QModelIndex(*)>(_a[1]))); break;
        case 1: _t->validate_list((*reinterpret_cast< QModelIndexList(*)>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::RegisterPropertyMetaType) {
        switch (_id) {
        default: *reinterpret_cast<int*>(_a[0]) = -1; break;
        case 0:
            *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< QItemSelectionModel* >(); break;
        }
    }

}

const QMetaObject ObservationGenotypePage::staticMetaObject = {
    { &QWizardPage::staticMetaObject, qt_meta_stringdata_ObservationGenotypePage.data,
      qt_meta_data_ObservationGenotypePage,  qt_static_metacall, 0, 0}
};


const QMetaObject *ObservationGenotypePage::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *ObservationGenotypePage::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_ObservationGenotypePage.stringdata))
        return static_cast<void*>(const_cast< ObservationGenotypePage*>(this));
    return QWizardPage::qt_metacast(_clname);
}

int ObservationGenotypePage::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWizardPage::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 2)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 2;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 2)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 2;
    }
#ifndef QT_NO_PROPERTIES
      else if (_c == QMetaObject::ReadProperty) {
        void *_v = _a[0];
        switch (_id) {
        case 0: *reinterpret_cast< QItemSelectionModel**>(_v) = selectionModel(); break;
        }
        _id -= 1;
    } else if (_c == QMetaObject::WriteProperty) {
        _id -= 1;
    } else if (_c == QMetaObject::ResetProperty) {
        _id -= 1;
    } else if (_c == QMetaObject::QueryPropertyDesignable) {
        _id -= 1;
    } else if (_c == QMetaObject::QueryPropertyScriptable) {
        _id -= 1;
    } else if (_c == QMetaObject::QueryPropertyStored) {
        _id -= 1;
    } else if (_c == QMetaObject::QueryPropertyEditable) {
        _id -= 1;
    } else if (_c == QMetaObject::QueryPropertyUser) {
        _id -= 1;
    } else if (_c == QMetaObject::RegisterPropertyMetaType) {
        if (_id < 1)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 1;
    }
#endif // QT_NO_PROPERTIES
    return _id;
}
QT_END_MOC_NAMESPACE
