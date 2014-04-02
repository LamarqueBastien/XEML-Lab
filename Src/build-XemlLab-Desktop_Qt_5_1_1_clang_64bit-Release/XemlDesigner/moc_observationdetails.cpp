/****************************************************************************
** Meta object code from reading C++ file 'observationdetails.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.1.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../XemlLab/XemlDesigner/SampleLoader/observationdetails.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'observationdetails.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.1.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_ObservationDetails_t {
    QByteArrayData data[18];
    char stringdata[223];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    offsetof(qt_meta_stringdata_ObservationDetails_t, stringdata) + ofs \
        - idx * sizeof(QByteArrayData) \
    )
static const qt_meta_stringdata_ObservationDetails_t qt_meta_stringdata_ObservationDetails = {
    {
QT_MOC_LITERAL(0, 0, 18),
QT_MOC_LITERAL(1, 19, 18),
QT_MOC_LITERAL(2, 38, 0),
QT_MOC_LITERAL(3, 39, 26),
QT_MOC_LITERAL(4, 66, 16),
QT_MOC_LITERAL(5, 83, 5),
QT_MOC_LITERAL(6, 89, 22),
QT_MOC_LITERAL(7, 112, 5),
QT_MOC_LITERAL(8, 118, 15),
QT_MOC_LITERAL(9, 134, 14),
QT_MOC_LITERAL(10, 149, 5),
QT_MOC_LITERAL(11, 155, 18),
QT_MOC_LITERAL(12, 174, 7),
QT_MOC_LITERAL(13, 182, 3),
QT_MOC_LITERAL(14, 186, 12),
QT_MOC_LITERAL(15, 199, 6),
QT_MOC_LITERAL(16, 206, 4),
QT_MOC_LITERAL(17, 211, 10)
    },
    "ObservationDetails\0on_modelCB_clicked\0"
    "\0add_details_about_pos_term\0"
    "ItfOntologyTerm*\0_term\0on_item_double_clicked\0"
    "index\0on_item_checked\0QStandardItem*\0"
    "_item\0add_parameter_item\0add_ind\0_id\0"
    "_isDestroyed\0_count\0_row\0_germplasm\0"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_ObservationDetails[] = {

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
       3,    1,   50,    2, 0x08,
       6,    1,   53,    2, 0x08,
       8,    1,   56,    2, 0x08,
      11,    1,   59,    2, 0x08,
      12,    0,   62,    2, 0x08,
      12,    5,   63,    2, 0x08,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 4,    5,
    QMetaType::Void, QMetaType::QModelIndex,    7,
    QMetaType::Void, 0x80000000 | 9,   10,
    QMetaType::Void, 0x80000000 | 4,    5,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int, QMetaType::Bool, QMetaType::Int, QMetaType::Int, QMetaType::QString,   13,   14,   15,   16,   17,

       0        // eod
};

void ObservationDetails::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        ObservationDetails *_t = static_cast<ObservationDetails *>(_o);
        switch (_id) {
        case 0: _t->on_modelCB_clicked(); break;
        case 1: _t->add_details_about_pos_term((*reinterpret_cast< ItfOntologyTerm*(*)>(_a[1]))); break;
        case 2: _t->on_item_double_clicked((*reinterpret_cast< QModelIndex(*)>(_a[1]))); break;
        case 3: _t->on_item_checked((*reinterpret_cast< QStandardItem*(*)>(_a[1]))); break;
        case 4: _t->add_parameter_item((*reinterpret_cast< ItfOntologyTerm*(*)>(_a[1]))); break;
        case 5: _t->add_ind(); break;
        case 6: _t->add_ind((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< bool(*)>(_a[2])),(*reinterpret_cast< int(*)>(_a[3])),(*reinterpret_cast< int(*)>(_a[4])),(*reinterpret_cast< QString(*)>(_a[5]))); break;
        default: ;
        }
    }
}

const QMetaObject ObservationDetails::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_ObservationDetails.data,
      qt_meta_data_ObservationDetails,  qt_static_metacall, 0, 0}
};


const QMetaObject *ObservationDetails::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *ObservationDetails::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_ObservationDetails.stringdata))
        return static_cast<void*>(const_cast< ObservationDetails*>(this));
    return QWidget::qt_metacast(_clname);
}

int ObservationDetails::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
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
