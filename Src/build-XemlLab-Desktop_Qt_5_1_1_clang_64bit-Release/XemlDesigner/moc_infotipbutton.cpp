/****************************************************************************
** Meta object code from reading C++ file 'infotipbutton.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.1.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../XemlLab/XemlDesigner/Views/Items/infotipbutton.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'infotipbutton.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.1.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_InfoTipButton_t {
    QByteArrayData data[4];
    char stringdata[43];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    offsetof(qt_meta_stringdata_InfoTipButton_t, stringdata) + ofs \
        - idx * sizeof(QByteArrayData) \
    )
static const qt_meta_stringdata_InfoTipButton_t qt_meta_stringdata_InfoTipButton = {
    {
QT_MOC_LITERAL(0, 0, 13),
QT_MOC_LITERAL(1, 14, 14),
QT_MOC_LITERAL(2, 29, 5),
QT_MOC_LITERAL(3, 35, 6)
    },
    "InfoTipButton\0TipButtonRoles\0Close\0"
    "Config\0"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_InfoTipButton[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       0,    0, // methods
       0,    0, // properties
       1,   14, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // enums: name, flags, count, data
       1, 0x0,    2,   18,

 // enum data: key, value
       2, uint(InfoTipButton::Close),
       3, uint(InfoTipButton::Config),

       0        // eod
};

void InfoTipButton::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    Q_UNUSED(_o);
    Q_UNUSED(_id);
    Q_UNUSED(_c);
    Q_UNUSED(_a);
}

const QMetaObject InfoTipButton::staticMetaObject = {
    { &QPushButton::staticMetaObject, qt_meta_stringdata_InfoTipButton.data,
      qt_meta_data_InfoTipButton,  qt_static_metacall, 0, 0}
};


const QMetaObject *InfoTipButton::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *InfoTipButton::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_InfoTipButton.stringdata))
        return static_cast<void*>(const_cast< InfoTipButton*>(this));
    return QPushButton::qt_metacast(_clname);
}

int InfoTipButton::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QPushButton::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    return _id;
}
QT_END_MOC_NAMESPACE
