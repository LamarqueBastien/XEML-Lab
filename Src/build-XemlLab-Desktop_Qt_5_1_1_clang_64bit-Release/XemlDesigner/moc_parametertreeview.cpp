/****************************************************************************
** Meta object code from reading C++ file 'parametertreeview.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.1.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../XemlLab/XemlDesigner/Views/parametertreeview.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'parametertreeview.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.1.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_ParameterTreeView_t {
    QByteArrayData data[15];
    char stringdata[201];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    offsetof(qt_meta_stringdata_ParameterTreeView_t, stringdata) + ofs \
        - idx * sizeof(QByteArrayData) \
    )
static const qt_meta_stringdata_ParameterTreeView_t qt_meta_stringdata_ParameterTreeView = {
    {
QT_MOC_LITERAL(0, 0, 17),
QT_MOC_LITERAL(1, 18, 19),
QT_MOC_LITERAL(2, 38, 0),
QT_MOC_LITERAL(3, 39, 16),
QT_MOC_LITERAL(4, 56, 5),
QT_MOC_LITERAL(5, 62, 16),
QT_MOC_LITERAL(6, 79, 9),
QT_MOC_LITERAL(7, 89, 11),
QT_MOC_LITERAL(8, 101, 13),
QT_MOC_LITERAL(9, 115, 13),
QT_MOC_LITERAL(10, 129, 12),
QT_MOC_LITERAL(11, 142, 15),
QT_MOC_LITERAL(12, 158, 13),
QT_MOC_LITERAL(13, 172, 12),
QT_MOC_LITERAL(14, 185, 14)
    },
    "ParameterTreeView\0onParameterselected\0"
    "\0ItfOntologyTerm*\0_term\0ontology_to_load\0"
    "show_help\0search_term\0add_parameter\0"
    "showSelection\0add_ontology\0send_ontologies\0"
    "_xeoIsChecked\0_eoIsChecked\0_envoIsChecked\0"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_ParameterTreeView[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       8,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       2,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   54,    2, 0x05,
       5,    3,   57,    2, 0x05,

 // slots: name, argc, parameters, tag, flags
       6,    0,   64,    2, 0x08,
       7,    1,   65,    2, 0x08,
       8,    0,   68,    2, 0x08,
       9,    0,   69,    2, 0x08,
      10,    0,   70,    2, 0x08,
      11,    3,   71,    2, 0x08,

 // signals: parameters
    QMetaType::Void, 0x80000000 | 3,    4,
    QMetaType::Void, QMetaType::Bool, QMetaType::Bool, QMetaType::Bool,    2,    2,    2,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString,    4,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Bool, QMetaType::Bool, QMetaType::Bool,   12,   13,   14,

       0        // eod
};

void ParameterTreeView::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        ParameterTreeView *_t = static_cast<ParameterTreeView *>(_o);
        switch (_id) {
        case 0: _t->onParameterselected((*reinterpret_cast< ItfOntologyTerm*(*)>(_a[1]))); break;
        case 1: _t->ontology_to_load((*reinterpret_cast< bool(*)>(_a[1])),(*reinterpret_cast< bool(*)>(_a[2])),(*reinterpret_cast< bool(*)>(_a[3]))); break;
        case 2: _t->show_help(); break;
        case 3: _t->search_term((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 4: _t->add_parameter(); break;
        case 5: _t->showSelection(); break;
        case 6: _t->add_ontology(); break;
        case 7: _t->send_ontologies((*reinterpret_cast< bool(*)>(_a[1])),(*reinterpret_cast< bool(*)>(_a[2])),(*reinterpret_cast< bool(*)>(_a[3]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (ParameterTreeView::*_t)(ItfOntologyTerm * );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&ParameterTreeView::onParameterselected)) {
                *result = 0;
            }
        }
        {
            typedef void (ParameterTreeView::*_t)(bool , bool , bool );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&ParameterTreeView::ontology_to_load)) {
                *result = 1;
            }
        }
    }
}

const QMetaObject ParameterTreeView::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_ParameterTreeView.data,
      qt_meta_data_ParameterTreeView,  qt_static_metacall, 0, 0}
};


const QMetaObject *ParameterTreeView::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *ParameterTreeView::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_ParameterTreeView.stringdata))
        return static_cast<void*>(const_cast< ParameterTreeView*>(this));
    return QWidget::qt_metacast(_clname);
}

int ParameterTreeView::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 8)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 8;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 8)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 8;
    }
    return _id;
}

// SIGNAL 0
void ParameterTreeView::onParameterselected(ItfOntologyTerm * _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void ParameterTreeView::ontology_to_load(bool _t1, bool _t2, bool _t3)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)), const_cast<void*>(reinterpret_cast<const void*>(&_t3)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}
QT_END_MOC_NAMESPACE
