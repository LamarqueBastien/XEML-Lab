/****************************************************************************
** Meta object code from reading C++ file 'observationpointpanel.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.1.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../XemlLab/XemlDesigner/PanelWindows/observationpointpanel.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'observationpointpanel.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.1.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_ObservationPointPanel_t {
    QByteArrayData data[7];
    char stringdata[93];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    offsetof(qt_meta_stringdata_ObservationPointPanel_t, stringdata) + ofs \
        - idx * sizeof(QByteArrayData) \
    )
static const qt_meta_stringdata_ObservationPointPanel_t qt_meta_stringdata_ObservationPointPanel = {
    {
QT_MOC_LITERAL(0, 0, 21),
QT_MOC_LITERAL(1, 22, 15),
QT_MOC_LITERAL(2, 38, 0),
QT_MOC_LITERAL(3, 39, 21),
QT_MOC_LITERAL(4, 61, 4),
QT_MOC_LITERAL(5, 66, 15),
QT_MOC_LITERAL(6, 82, 9)
    },
    "ObservationPointPanel\0on_close_window\0"
    "\0display_selected_item\0_QMI\0remove_obsPoint\0"
    "show_help\0"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_ObservationPointPanel[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       4,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    0,   34,    2, 0x05,

 // slots: name, argc, parameters, tag, flags
       3,    1,   35,    2, 0x08,
       5,    0,   38,    2, 0x08,
       6,    0,   39,    2, 0x08,

 // signals: parameters
    QMetaType::Void,

 // slots: parameters
    QMetaType::Void, QMetaType::QModelIndex,    4,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void ObservationPointPanel::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        ObservationPointPanel *_t = static_cast<ObservationPointPanel *>(_o);
        switch (_id) {
        case 0: _t->on_close_window(); break;
        case 1: _t->display_selected_item((*reinterpret_cast< QModelIndex(*)>(_a[1]))); break;
        case 2: _t->remove_obsPoint(); break;
        case 3: _t->show_help(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (ObservationPointPanel::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&ObservationPointPanel::on_close_window)) {
                *result = 0;
            }
        }
    }
}

const QMetaObject ObservationPointPanel::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_ObservationPointPanel.data,
      qt_meta_data_ObservationPointPanel,  qt_static_metacall, 0, 0}
};


const QMetaObject *ObservationPointPanel::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *ObservationPointPanel::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_ObservationPointPanel.stringdata))
        return static_cast<void*>(const_cast< ObservationPointPanel*>(this));
    return QWidget::qt_metacast(_clname);
}

int ObservationPointPanel::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 4)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 4;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 4)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 4;
    }
    return _id;
}

// SIGNAL 0
void ObservationPointPanel::on_close_window()
{
    QMetaObject::activate(this, &staticMetaObject, 0, 0);
}
QT_END_MOC_NAMESPACE
