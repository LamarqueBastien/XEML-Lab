/****************************************************************************
** Meta object code from reading C++ file 'loaderontologypage.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.1.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../XemlLab/XemlDesigner/XemlCSVLoader/loaderontologypage.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'loaderontologypage.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.1.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_LoaderOntologyPage_t {
    QByteArrayData data[15];
    char stringdata[150];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    offsetof(qt_meta_stringdata_LoaderOntologyPage_t, stringdata) + ofs \
        - idx * sizeof(QByteArrayData) \
    )
static const qt_meta_stringdata_LoaderOntologyPage_t qt_meta_stringdata_LoaderOntologyPage = {
    {
QT_MOC_LITERAL(0, 0, 18),
QT_MOC_LITERAL(1, 19, 9),
QT_MOC_LITERAL(2, 29, 0),
QT_MOC_LITERAL(3, 30, 7),
QT_MOC_LITERAL(4, 38, 4),
QT_MOC_LITERAL(5, 43, 16),
QT_MOC_LITERAL(6, 60, 5),
QT_MOC_LITERAL(7, 66, 5),
QT_MOC_LITERAL(8, 72, 10),
QT_MOC_LITERAL(9, 83, 10),
QT_MOC_LITERAL(10, 94, 6),
QT_MOC_LITERAL(11, 101, 19),
QT_MOC_LITERAL(12, 121, 8),
QT_MOC_LITERAL(13, 130, 8),
QT_MOC_LITERAL(14, 139, 9)
    },
    "LoaderOntologyPage\0send_term\0\0_column\0"
    "_row\0ItfOntologyTerm*\0_term\0_unit\0"
    "send_story\0StoryNode*\0_story\0"
    "send_term_and_story\0get_term\0finished\0"
    "get_story\0"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_LoaderOntologyPage[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       6,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       3,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    4,   44,    2, 0x05,
       8,    3,   53,    2, 0x05,
      11,    5,   60,    2, 0x05,

 // slots: name, argc, parameters, tag, flags
      12,    2,   71,    2, 0x08,
      13,    0,   76,    2, 0x08,
      14,    3,   77,    2, 0x08,

 // signals: parameters
    QMetaType::Void, QMetaType::Int, QMetaType::Int, 0x80000000 | 5, QMetaType::QString,    3,    4,    6,    7,
    QMetaType::Void, QMetaType::Int, QMetaType::Int, 0x80000000 | 9,    3,    4,   10,
    QMetaType::Void, QMetaType::Int, QMetaType::Int, 0x80000000 | 9, 0x80000000 | 5, QMetaType::QString,    3,    4,   10,    6,    7,

 // slots: parameters
    QMetaType::Void, 0x80000000 | 5, QMetaType::QString,    6,    7,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int, QMetaType::Int, 0x80000000 | 9,    3,    4,   10,

       0        // eod
};

void LoaderOntologyPage::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        LoaderOntologyPage *_t = static_cast<LoaderOntologyPage *>(_o);
        switch (_id) {
        case 0: _t->send_term((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2])),(*reinterpret_cast< ItfOntologyTerm*(*)>(_a[3])),(*reinterpret_cast< QString(*)>(_a[4]))); break;
        case 1: _t->send_story((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2])),(*reinterpret_cast< StoryNode*(*)>(_a[3]))); break;
        case 2: _t->send_term_and_story((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2])),(*reinterpret_cast< StoryNode*(*)>(_a[3])),(*reinterpret_cast< ItfOntologyTerm*(*)>(_a[4])),(*reinterpret_cast< QString(*)>(_a[5]))); break;
        case 3: _t->get_term((*reinterpret_cast< ItfOntologyTerm*(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2]))); break;
        case 4: _t->finished(); break;
        case 5: _t->get_story((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2])),(*reinterpret_cast< StoryNode*(*)>(_a[3]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (LoaderOntologyPage::*_t)(int , int , ItfOntologyTerm * , QString );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&LoaderOntologyPage::send_term)) {
                *result = 0;
            }
        }
        {
            typedef void (LoaderOntologyPage::*_t)(int , int , StoryNode * );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&LoaderOntologyPage::send_story)) {
                *result = 1;
            }
        }
        {
            typedef void (LoaderOntologyPage::*_t)(int , int , StoryNode * , ItfOntologyTerm * , QString );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&LoaderOntologyPage::send_term_and_story)) {
                *result = 2;
            }
        }
    }
}

const QMetaObject LoaderOntologyPage::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_LoaderOntologyPage.data,
      qt_meta_data_LoaderOntologyPage,  qt_static_metacall, 0, 0}
};


const QMetaObject *LoaderOntologyPage::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *LoaderOntologyPage::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_LoaderOntologyPage.stringdata))
        return static_cast<void*>(const_cast< LoaderOntologyPage*>(this));
    return QWidget::qt_metacast(_clname);
}

int LoaderOntologyPage::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
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
void LoaderOntologyPage::send_term(int _t1, int _t2, ItfOntologyTerm * _t3, QString _t4)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)), const_cast<void*>(reinterpret_cast<const void*>(&_t3)), const_cast<void*>(reinterpret_cast<const void*>(&_t4)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void LoaderOntologyPage::send_story(int _t1, int _t2, StoryNode * _t3)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)), const_cast<void*>(reinterpret_cast<const void*>(&_t3)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void LoaderOntologyPage::send_term_and_story(int _t1, int _t2, StoryNode * _t3, ItfOntologyTerm * _t4, QString _t5)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)), const_cast<void*>(reinterpret_cast<const void*>(&_t3)), const_cast<void*>(reinterpret_cast<const void*>(&_t4)), const_cast<void*>(reinterpret_cast<const void*>(&_t5)) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}
QT_END_MOC_NAMESPACE
