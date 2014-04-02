/****************************************************************************
** Meta object code from reading C++ file 'tableview.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.1.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../XemlLab/XemlDesigner/Views/tableview.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'tableview.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.1.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_TableView_t {
    QByteArrayData data[7];
    char stringdata[103];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    offsetof(qt_meta_stringdata_TableView_t, stringdata) + ofs \
        - idx * sizeof(QByteArrayData) \
    )
static const qt_meta_stringdata_TableView_t qt_meta_stringdata_TableView = {
    {
QT_MOC_LITERAL(0, 0, 9),
QT_MOC_LITERAL(1, 10, 19),
QT_MOC_LITERAL(2, 30, 0),
QT_MOC_LITERAL(3, 31, 14),
QT_MOC_LITERAL(4, 46, 14),
QT_MOC_LITERAL(5, 61, 21),
QT_MOC_LITERAL(6, 83, 18)
    },
    "TableView\0sample_item_checked\0\0"
    "QStandardItem*\0_selected_item\0"
    "variable_item_checked\0event_item_checked\0"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_TableView[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       3,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    1,   29,    2, 0x08,
       5,    1,   32,    2, 0x08,
       6,    1,   35,    2, 0x08,

 // slots: parameters
    QMetaType::Void, 0x80000000 | 3,    4,
    QMetaType::Void, 0x80000000 | 3,    4,
    QMetaType::Void, 0x80000000 | 3,    4,

       0        // eod
};

void TableView::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        TableView *_t = static_cast<TableView *>(_o);
        switch (_id) {
        case 0: _t->sample_item_checked((*reinterpret_cast< QStandardItem*(*)>(_a[1]))); break;
        case 1: _t->variable_item_checked((*reinterpret_cast< QStandardItem*(*)>(_a[1]))); break;
        case 2: _t->event_item_checked((*reinterpret_cast< QStandardItem*(*)>(_a[1]))); break;
        default: ;
        }
    }
}

const QMetaObject TableView::staticMetaObject = {
    { &QTableView::staticMetaObject, qt_meta_stringdata_TableView.data,
      qt_meta_data_TableView,  qt_static_metacall, 0, 0}
};


const QMetaObject *TableView::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *TableView::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_TableView.stringdata))
        return static_cast<void*>(const_cast< TableView*>(this));
    return QTableView::qt_metacast(_clname);
}

int TableView::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QTableView::qt_metacall(_c, _id, _a);
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
QT_END_MOC_NAMESPACE
