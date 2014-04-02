/****************************************************************************
** Meta object code from reading C++ file 'loadertermpage.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.1.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../XemlLab/XemlDesigner/XemlCSVLoader/loadertermpage.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'loadertermpage.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.1.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_LoaderTermPage_t {
    QByteArrayData data[11];
    char stringdata[114];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    offsetof(qt_meta_stringdata_LoaderTermPage_t, stringdata) + ofs \
        - idx * sizeof(QByteArrayData) \
    )
static const qt_meta_stringdata_LoaderTermPage_t qt_meta_stringdata_LoaderTermPage = {
    {
QT_MOC_LITERAL(0, 0, 14),
QT_MOC_LITERAL(1, 15, 17),
QT_MOC_LITERAL(2, 33, 0),
QT_MOC_LITERAL(3, 34, 16),
QT_MOC_LITERAL(4, 51, 5),
QT_MOC_LITERAL(5, 57, 5),
QT_MOC_LITERAL(6, 63, 8),
QT_MOC_LITERAL(7, 72, 12),
QT_MOC_LITERAL(8, 85, 10),
QT_MOC_LITERAL(9, 96, 8),
QT_MOC_LITERAL(10, 105, 7)
    },
    "LoaderTermPage\0send_details_term\0\0"
    "ItfOntologyTerm*\0_term\0_unit\0get_Term\0"
    "tree_changed\0_namespace\0finished\0"
    "removed\0"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_LoaderTermPage[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       5,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    2,   39,    2, 0x05,

 // slots: name, argc, parameters, tag, flags
       6,    1,   44,    2, 0x08,
       7,    1,   47,    2, 0x08,
       9,    0,   50,    2, 0x08,
      10,    0,   51,    2, 0x08,

 // signals: parameters
    QMetaType::Void, 0x80000000 | 3, QMetaType::QString,    4,    5,

 // slots: parameters
    QMetaType::Void, 0x80000000 | 3,    4,
    QMetaType::Void, QMetaType::QString,    8,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void LoaderTermPage::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        LoaderTermPage *_t = static_cast<LoaderTermPage *>(_o);
        switch (_id) {
        case 0: _t->send_details_term((*reinterpret_cast< ItfOntologyTerm*(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2]))); break;
        case 1: _t->get_Term((*reinterpret_cast< ItfOntologyTerm*(*)>(_a[1]))); break;
        case 2: _t->tree_changed((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 3: _t->finished(); break;
        case 4: _t->removed(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (LoaderTermPage::*_t)(ItfOntologyTerm * , QString );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&LoaderTermPage::send_details_term)) {
                *result = 0;
            }
        }
    }
}

const QMetaObject LoaderTermPage::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_LoaderTermPage.data,
      qt_meta_data_LoaderTermPage,  qt_static_metacall, 0, 0}
};


const QMetaObject *LoaderTermPage::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *LoaderTermPage::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_LoaderTermPage.stringdata))
        return static_cast<void*>(const_cast< LoaderTermPage*>(this));
    return QWidget::qt_metacast(_clname);
}

int LoaderTermPage::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 5)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 5;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 5)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 5;
    }
    return _id;
}

// SIGNAL 0
void LoaderTermPage::send_details_term(ItfOntologyTerm * _t1, QString _t2)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}
QT_END_MOC_NAMESPACE
