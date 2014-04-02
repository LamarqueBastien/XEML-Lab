/****************************************************************************
** Meta object code from reading C++ file 'infoballoontip.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.1.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../XemlLab/XemlDesigner/Views/Items/infoballoontip.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'infoballoontip.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.1.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_InfoBalloonTip_t {
    QByteArrayData data[12];
    char stringdata[118];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    offsetof(qt_meta_stringdata_InfoBalloonTip_t, stringdata) + ofs \
        - idx * sizeof(QByteArrayData) \
    )
static const qt_meta_stringdata_InfoBalloonTip_t qt_meta_stringdata_InfoBalloonTip = {
    {
QT_MOC_LITERAL(0, 0, 14),
QT_MOC_LITERAL(1, 15, 8),
QT_MOC_LITERAL(2, 24, 0),
QT_MOC_LITERAL(3, 25, 4),
QT_MOC_LITERAL(4, 30, 5),
QT_MOC_LITERAL(5, 36, 11),
QT_MOC_LITERAL(6, 48, 13),
QT_MOC_LITERAL(7, 62, 14),
QT_MOC_LITERAL(8, 77, 7),
QT_MOC_LITERAL(9, 85, 8),
QT_MOC_LITERAL(10, 94, 10),
QT_MOC_LITERAL(11, 105, 11)
    },
    "InfoBalloonTip\0finished\0\0show\0close\0"
    "my_arrowPos\0ArrowPosition\0ArrowPositions\0"
    "TopLeft\0TopRight\0BottomLeft\0BottomRight\0"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_InfoBalloonTip[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       3,   14, // methods
       1,   32, // properties
       1,   35, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    0,   29,    2, 0x05,

 // slots: name, argc, parameters, tag, flags
       3,    0,   30,    2, 0x0a,
       4,    0,   31,    2, 0x0a,

 // signals: parameters
    QMetaType::Void,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Bool,

 // properties: name, type, flags
       5, 0x80000000 | 6, 0x0009500b,

 // enums: name, flags, count, data
       7, 0x0,    4,   39,

 // enum data: key, value
       8, uint(InfoBalloonTip::TopLeft),
       9, uint(InfoBalloonTip::TopRight),
      10, uint(InfoBalloonTip::BottomLeft),
      11, uint(InfoBalloonTip::BottomRight),

       0        // eod
};

void InfoBalloonTip::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        InfoBalloonTip *_t = static_cast<InfoBalloonTip *>(_o);
        switch (_id) {
        case 0: _t->finished(); break;
        case 1: _t->show(); break;
        case 2: { bool _r = _t->close();
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = _r; }  break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (InfoBalloonTip::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&InfoBalloonTip::finished)) {
                *result = 0;
            }
        }
    }
}

const QMetaObject InfoBalloonTip::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_InfoBalloonTip.data,
      qt_meta_data_InfoBalloonTip,  qt_static_metacall, 0, 0}
};


const QMetaObject *InfoBalloonTip::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *InfoBalloonTip::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_InfoBalloonTip.stringdata))
        return static_cast<void*>(const_cast< InfoBalloonTip*>(this));
    return QWidget::qt_metacast(_clname);
}

int InfoBalloonTip::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
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
#ifndef QT_NO_PROPERTIES
      else if (_c == QMetaObject::ReadProperty) {
        void *_v = _a[0];
        switch (_id) {
        case 0: *reinterpret_cast< ArrowPosition*>(_v) = arrowPosition(); break;
        }
        _id -= 1;
    } else if (_c == QMetaObject::WriteProperty) {
        void *_v = _a[0];
        switch (_id) {
        case 0: setArrowPosition(*reinterpret_cast< ArrowPosition*>(_v)); break;
        }
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
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 1;
    }
#endif // QT_NO_PROPERTIES
    return _id;
}

// SIGNAL 0
void InfoBalloonTip::finished()
{
    QMetaObject::activate(this, &staticMetaObject, 0, 0);
}
QT_END_MOC_NAMESPACE
