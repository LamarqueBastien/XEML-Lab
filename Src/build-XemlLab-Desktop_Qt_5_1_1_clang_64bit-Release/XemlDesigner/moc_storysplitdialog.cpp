/****************************************************************************
** Meta object code from reading C++ file 'storysplitdialog.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.1.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../XemlLab/XemlDesigner/DialogWindows/storysplitdialog.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'storysplitdialog.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.1.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_StorySplitDialog_t {
    QByteArrayData data[10];
    char stringdata[114];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    offsetof(qt_meta_stringdata_StorySplitDialog_t, stringdata) + ofs \
        - idx * sizeof(QByteArrayData) \
    )
static const qt_meta_stringdata_StorySplitDialog_t qt_meta_stringdata_StorySplitDialog = {
    {
QT_MOC_LITERAL(0, 0, 16),
QT_MOC_LITERAL(1, 17, 13),
QT_MOC_LITERAL(2, 31, 0),
QT_MOC_LITERAL(3, 32, 17),
QT_MOC_LITERAL(4, 50, 5),
QT_MOC_LITERAL(5, 56, 9),
QT_MOC_LITERAL(6, 66, 9),
QT_MOC_LITERAL(7, 76, 15),
QT_MOC_LITERAL(8, 92, 4),
QT_MOC_LITERAL(9, 97, 15)
    },
    "StorySplitDialog\0storysplitset\0\0"
    "_element_selected\0_text\0_datetime\0"
    "OkClicked\0enabledOkButton\0text\0"
    "valid_date_time\0"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_StorySplitDialog[] = {

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
       1,    3,   34,    2, 0x05,

 // slots: name, argc, parameters, tag, flags
       6,    0,   41,    2, 0x08,
       7,    1,   42,    2, 0x08,
       9,    1,   45,    2, 0x08,

 // signals: parameters
    QMetaType::Void, QMetaType::QString, QMetaType::QString, QMetaType::QDateTime,    3,    4,    5,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString,    8,
    QMetaType::Void, QMetaType::QDateTime,    2,

       0        // eod
};

void StorySplitDialog::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        StorySplitDialog *_t = static_cast<StorySplitDialog *>(_o);
        switch (_id) {
        case 0: _t->storysplitset((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2])),(*reinterpret_cast< QDateTime(*)>(_a[3]))); break;
        case 1: _t->OkClicked(); break;
        case 2: _t->enabledOkButton((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 3: _t->valid_date_time((*reinterpret_cast< QDateTime(*)>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (StorySplitDialog::*_t)(QString , QString , QDateTime );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&StorySplitDialog::storysplitset)) {
                *result = 0;
            }
        }
    }
}

const QMetaObject StorySplitDialog::staticMetaObject = {
    { &QDialog::staticMetaObject, qt_meta_stringdata_StorySplitDialog.data,
      qt_meta_data_StorySplitDialog,  qt_static_metacall, 0, 0}
};


const QMetaObject *StorySplitDialog::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *StorySplitDialog::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_StorySplitDialog.stringdata))
        return static_cast<void*>(const_cast< StorySplitDialog*>(this));
    return QDialog::qt_metacast(_clname);
}

int StorySplitDialog::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDialog::qt_metacall(_c, _id, _a);
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
void StorySplitDialog::storysplitset(QString _t1, QString _t2, QDateTime _t3)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)), const_cast<void*>(reinterpret_cast<const void*>(&_t3)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}
QT_END_MOC_NAMESPACE
