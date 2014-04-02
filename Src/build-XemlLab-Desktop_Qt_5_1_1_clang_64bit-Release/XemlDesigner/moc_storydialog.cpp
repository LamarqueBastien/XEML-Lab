/****************************************************************************
** Meta object code from reading C++ file 'storydialog.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.1.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../XemlLab/XemlDesigner/DialogWindows/storydialog.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'storydialog.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.1.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_StoryDialog_t {
    QByteArrayData data[10];
    char stringdata[100];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    offsetof(qt_meta_stringdata_StoryDialog_t, stringdata) + ofs \
        - idx * sizeof(QByteArrayData) \
    )
static const qt_meta_stringdata_StoryDialog_t qt_meta_stringdata_StoryDialog = {
    {
QT_MOC_LITERAL(0, 0, 11),
QT_MOC_LITERAL(1, 12, 9),
QT_MOC_LITERAL(2, 22, 0),
QT_MOC_LITERAL(3, 23, 5),
QT_MOC_LITERAL(4, 29, 15),
QT_MOC_LITERAL(5, 45, 9),
QT_MOC_LITERAL(6, 55, 9),
QT_MOC_LITERAL(7, 65, 15),
QT_MOC_LITERAL(8, 81, 4),
QT_MOC_LITERAL(9, 86, 12)
    },
    "StoryDialog\0new_story\0\0_text\0"
    "new_story_split\0OkClicked\0show_help\0"
    "enabledOkButton\0text\0ResetClicked\0"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_StoryDialog[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       6,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       2,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   44,    2, 0x05,
       4,    1,   47,    2, 0x05,

 // slots: name, argc, parameters, tag, flags
       5,    0,   50,    2, 0x08,
       6,    0,   51,    2, 0x08,
       7,    1,   52,    2, 0x08,
       9,    0,   55,    2, 0x08,

 // signals: parameters
    QMetaType::Void, QMetaType::QString,    3,
    QMetaType::Void, QMetaType::QString,    3,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString,    8,
    QMetaType::Void,

       0        // eod
};

void StoryDialog::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        StoryDialog *_t = static_cast<StoryDialog *>(_o);
        switch (_id) {
        case 0: _t->new_story((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 1: _t->new_story_split((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 2: _t->OkClicked(); break;
        case 3: _t->show_help(); break;
        case 4: _t->enabledOkButton((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 5: _t->ResetClicked(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (StoryDialog::*_t)(QString );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&StoryDialog::new_story)) {
                *result = 0;
            }
        }
        {
            typedef void (StoryDialog::*_t)(QString );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&StoryDialog::new_story_split)) {
                *result = 1;
            }
        }
    }
}

const QMetaObject StoryDialog::staticMetaObject = {
    { &QDialog::staticMetaObject, qt_meta_stringdata_StoryDialog.data,
      qt_meta_data_StoryDialog,  qt_static_metacall, 0, 0}
};


const QMetaObject *StoryDialog::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *StoryDialog::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_StoryDialog.stringdata))
        return static_cast<void*>(const_cast< StoryDialog*>(this));
    return QDialog::qt_metacast(_clname);
}

int StoryDialog::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDialog::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 6)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 6;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 6)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 6;
    }
    return _id;
}

// SIGNAL 0
void StoryDialog::new_story(QString _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void StoryDialog::new_story_split(QString _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}
QT_END_MOC_NAMESPACE
