/****************************************************************************
** Meta object code from reading C++ file 'loaderdatetimepage.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.1.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../XemlLab/XemlDesigner/XemlCSVLoader/loaderdatetimepage.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'loaderdatetimepage.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.1.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_LoaderDateTimePage_t {
    QByteArrayData data[7];
    char stringdata[77];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    offsetof(qt_meta_stringdata_LoaderDateTimePage_t, stringdata) + ofs \
        - idx * sizeof(QByteArrayData) \
    )
static const qt_meta_stringdata_LoaderDateTimePage_t qt_meta_stringdata_LoaderDateTimePage = {
    {
QT_MOC_LITERAL(0, 0, 18),
QT_MOC_LITERAL(1, 19, 20),
QT_MOC_LITERAL(2, 40, 0),
QT_MOC_LITERAL(3, 41, 7),
QT_MOC_LITERAL(4, 49, 4),
QT_MOC_LITERAL(5, 54, 5),
QT_MOC_LITERAL(6, 60, 15)
    },
    "LoaderDateTimePage\0delimitered_dateTime\0"
    "\0_column\0_row\0_time\0set_up_finished\0"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_LoaderDateTimePage[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       2,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    3,   24,    2, 0x05,

 // slots: name, argc, parameters, tag, flags
       6,    0,   31,    2, 0x08,

 // signals: parameters
    QMetaType::Void, QMetaType::Int, QMetaType::Int, QMetaType::QString,    3,    4,    5,

 // slots: parameters
    QMetaType::Void,

       0        // eod
};

void LoaderDateTimePage::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        LoaderDateTimePage *_t = static_cast<LoaderDateTimePage *>(_o);
        switch (_id) {
        case 0: _t->delimitered_dateTime((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2])),(*reinterpret_cast< QString(*)>(_a[3]))); break;
        case 1: _t->set_up_finished(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (LoaderDateTimePage::*_t)(int , int , QString );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&LoaderDateTimePage::delimitered_dateTime)) {
                *result = 0;
            }
        }
    }
}

const QMetaObject LoaderDateTimePage::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_LoaderDateTimePage.data,
      qt_meta_data_LoaderDateTimePage,  qt_static_metacall, 0, 0}
};


const QMetaObject *LoaderDateTimePage::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *LoaderDateTimePage::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_LoaderDateTimePage.stringdata))
        return static_cast<void*>(const_cast< LoaderDateTimePage*>(this));
    return QWidget::qt_metacast(_clname);
}

int LoaderDateTimePage::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
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
    return _id;
}

// SIGNAL 0
void LoaderDateTimePage::delimitered_dateTime(int _t1, int _t2, QString _t3)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)), const_cast<void*>(reinterpret_cast<const void*>(&_t3)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}
QT_END_MOC_NAMESPACE
