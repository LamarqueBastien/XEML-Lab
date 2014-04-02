/****************************************************************************
** Meta object code from reading C++ file 'loaderstorypage.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.1.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../XemlLab/XemlDesigner/XemlCSVLoader/loaderstorypage.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'loaderstorypage.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.1.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_LoaderStoryPage_t {
    QByteArrayData data[13];
    char stringdata[144];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    offsetof(qt_meta_stringdata_LoaderStoryPage_t, stringdata) + ofs \
        - idx * sizeof(QByteArrayData) \
    )
static const qt_meta_stringdata_LoaderStoryPage_t qt_meta_stringdata_LoaderStoryPage = {
    {
QT_MOC_LITERAL(0, 0, 15),
QT_MOC_LITERAL(1, 16, 18),
QT_MOC_LITERAL(2, 35, 0),
QT_MOC_LITERAL(3, 36, 7),
QT_MOC_LITERAL(4, 44, 4),
QT_MOC_LITERAL(5, 49, 10),
QT_MOC_LITERAL(6, 60, 17),
QT_MOC_LITERAL(7, 78, 17),
QT_MOC_LITERAL(8, 96, 4),
QT_MOC_LITERAL(9, 101, 15),
QT_MOC_LITERAL(10, 117, 10),
QT_MOC_LITERAL(11, 128, 6),
QT_MOC_LITERAL(12, 135, 7)
    },
    "LoaderStoryPage\0send_details_story\0\0"
    "_column\0_row\0StoryNode*\0current_storyNode\0"
    "on_story_selected\0_idx\0set_up_finished\0"
    "_storyname\0closed\0removed\0"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_LoaderStoryPage[] = {

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
       1,    3,   39,    2, 0x05,

 // slots: name, argc, parameters, tag, flags
       7,    1,   46,    2, 0x08,
       9,    1,   49,    2, 0x08,
      11,    1,   52,    2, 0x08,
      12,    0,   55,    2, 0x08,

 // signals: parameters
    QMetaType::Void, QMetaType::Int, QMetaType::Int, 0x80000000 | 5,    3,    4,    6,

 // slots: parameters
    QMetaType::Void, QMetaType::QModelIndex,    8,
    QMetaType::Void, QMetaType::QString,   10,
    QMetaType::Void, QMetaType::Bool,    2,
    QMetaType::Void,

       0        // eod
};

void LoaderStoryPage::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        LoaderStoryPage *_t = static_cast<LoaderStoryPage *>(_o);
        switch (_id) {
        case 0: _t->send_details_story((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2])),(*reinterpret_cast< StoryNode*(*)>(_a[3]))); break;
        case 1: _t->on_story_selected((*reinterpret_cast< QModelIndex(*)>(_a[1]))); break;
        case 2: _t->set_up_finished((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 3: _t->closed((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 4: _t->removed(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (LoaderStoryPage::*_t)(int , int , StoryNode * );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&LoaderStoryPage::send_details_story)) {
                *result = 0;
            }
        }
    }
}

const QMetaObject LoaderStoryPage::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_LoaderStoryPage.data,
      qt_meta_data_LoaderStoryPage,  qt_static_metacall, 0, 0}
};


const QMetaObject *LoaderStoryPage::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *LoaderStoryPage::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_LoaderStoryPage.stringdata))
        return static_cast<void*>(const_cast< LoaderStoryPage*>(this));
    return QWidget::qt_metacast(_clname);
}

int LoaderStoryPage::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
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
void LoaderStoryPage::send_details_story(int _t1, int _t2, StoryNode * _t3)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)), const_cast<void*>(reinterpret_cast<const void*>(&_t3)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}
QT_END_MOC_NAMESPACE
