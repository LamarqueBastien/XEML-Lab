/****************************************************************************
** Meta object code from reading C++ file 'experimentdialog.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.1.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../XemlLab/XemlDesigner/DialogWindows/experimentdialog.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'experimentdialog.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.1.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_ExperimentDialog_t {
    QByteArrayData data[10];
    char stringdata[128];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    offsetof(qt_meta_stringdata_ExperimentDialog_t, stringdata) + ofs \
        - idx * sizeof(QByteArrayData) \
    )
static const qt_meta_stringdata_ExperimentDialog_t qt_meta_stringdata_ExperimentDialog = {
    {
QT_MOC_LITERAL(0, 0, 16),
QT_MOC_LITERAL(1, 17, 15),
QT_MOC_LITERAL(2, 33, 0),
QT_MOC_LITERAL(3, 34, 9),
QT_MOC_LITERAL(4, 44, 12),
QT_MOC_LITERAL(5, 57, 22),
QT_MOC_LITERAL(6, 80, 8),
QT_MOC_LITERAL(7, 89, 16),
QT_MOC_LITERAL(8, 106, 15),
QT_MOC_LITERAL(9, 122, 4)
    },
    "ExperimentDialog\0set_up_finished\0\0"
    "OkClicked\0ResetClicked\0avoid_endTime_reachout\0"
    "_newTime\0avoid_equal_time\0enabledOkButton\0"
    "text\0"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_ExperimentDialog[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       6,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    0,   44,    2, 0x05,

 // slots: name, argc, parameters, tag, flags
       3,    0,   45,    2, 0x08,
       4,    0,   46,    2, 0x08,
       5,    1,   47,    2, 0x08,
       7,    1,   50,    2, 0x08,
       8,    1,   53,    2, 0x08,

 // signals: parameters
    QMetaType::Void,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QDateTime,    6,
    QMetaType::Void, QMetaType::QDateTime,    6,
    QMetaType::Void, QMetaType::QString,    9,

       0        // eod
};

void ExperimentDialog::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        ExperimentDialog *_t = static_cast<ExperimentDialog *>(_o);
        switch (_id) {
        case 0: _t->set_up_finished(); break;
        case 1: _t->OkClicked(); break;
        case 2: _t->ResetClicked(); break;
        case 3: _t->avoid_endTime_reachout((*reinterpret_cast< QDateTime(*)>(_a[1]))); break;
        case 4: _t->avoid_equal_time((*reinterpret_cast< QDateTime(*)>(_a[1]))); break;
        case 5: _t->enabledOkButton((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (ExperimentDialog::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&ExperimentDialog::set_up_finished)) {
                *result = 0;
            }
        }
    }
}

const QMetaObject ExperimentDialog::staticMetaObject = {
    { &QDialog::staticMetaObject, qt_meta_stringdata_ExperimentDialog.data,
      qt_meta_data_ExperimentDialog,  qt_static_metacall, 0, 0}
};


const QMetaObject *ExperimentDialog::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *ExperimentDialog::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_ExperimentDialog.stringdata))
        return static_cast<void*>(const_cast< ExperimentDialog*>(this));
    return QDialog::qt_metacast(_clname);
}

int ExperimentDialog::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
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
void ExperimentDialog::set_up_finished()
{
    QMetaObject::activate(this, &staticMetaObject, 0, 0);
}
QT_END_MOC_NAMESPACE
