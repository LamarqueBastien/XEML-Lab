/****************************************************************************
** Meta object code from reading C++ file 'graphicstoryview.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.1.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../XemlLab/XemlDesigner/Views/GraphicStoryView/graphicstoryview.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'graphicstoryview.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.1.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_GraphicStoryView_t {
    QByteArrayData data[21];
    char stringdata[233];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    offsetof(qt_meta_stringdata_GraphicStoryView_t, stringdata) + ofs \
        - idx * sizeof(QByteArrayData) \
    )
static const qt_meta_stringdata_GraphicStoryView_t qt_meta_stringdata_GraphicStoryView = {
    {
QT_MOC_LITERAL(0, 0, 16),
QT_MOC_LITERAL(1, 17, 17),
QT_MOC_LITERAL(2, 35, 0),
QT_MOC_LITERAL(3, 36, 6),
QT_MOC_LITERAL(4, 43, 10),
QT_MOC_LITERAL(5, 54, 6),
QT_MOC_LITERAL(6, 61, 16),
QT_MOC_LITERAL(7, 78, 11),
QT_MOC_LITERAL(8, 90, 6),
QT_MOC_LITERAL(9, 97, 1),
QT_MOC_LITERAL(10, 99, 14),
QT_MOC_LITERAL(11, 114, 17),
QT_MOC_LITERAL(12, 132, 3),
QT_MOC_LITERAL(13, 136, 12),
QT_MOC_LITERAL(14, 149, 11),
QT_MOC_LITERAL(15, 161, 13),
QT_MOC_LITERAL(16, 175, 15),
QT_MOC_LITERAL(17, 191, 14),
QT_MOC_LITERAL(18, 206, 9),
QT_MOC_LITERAL(19, 216, 2),
QT_MOC_LITERAL(20, 219, 12)
    },
    "GraphicStoryView\0story_split_added\0\0"
    "_label\0StoryBase*\0_story\0story_root_added\0"
    "event_added\0Event*\0e\0obsPoint_added\0"
    "ObservationPoint*\0_op\0emit_zoom_in\0"
    "_zoomFactor\0emit_zoom_out\0add_split_story\0"
    "add_root_story\0add_event\0_e\0add_obsPoint\0"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_GraphicStoryView[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
      10,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       6,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    2,   64,    2, 0x05,
       6,    2,   69,    2, 0x05,
       7,    1,   74,    2, 0x05,
      10,    1,   77,    2, 0x05,
      13,    1,   80,    2, 0x05,
      15,    1,   83,    2, 0x05,

 // slots: name, argc, parameters, tag, flags
      16,    2,   86,    2, 0x08,
      17,    2,   91,    2, 0x08,
      18,    1,   96,    2, 0x08,
      20,    1,   99,    2, 0x08,

 // signals: parameters
    QMetaType::Void, QMetaType::QString, 0x80000000 | 4,    3,    5,
    QMetaType::Void, QMetaType::QString, 0x80000000 | 4,    3,    5,
    QMetaType::Void, 0x80000000 | 8,    9,
    QMetaType::Void, 0x80000000 | 11,   12,
    QMetaType::Void, QMetaType::Int,   14,
    QMetaType::Void, QMetaType::Int,   14,

 // slots: parameters
    QMetaType::Void, QMetaType::QString, 0x80000000 | 4,    3,    5,
    QMetaType::Void, QMetaType::QString, 0x80000000 | 4,    3,    5,
    QMetaType::Void, 0x80000000 | 8,   19,
    QMetaType::Void, 0x80000000 | 11,   12,

       0        // eod
};

void GraphicStoryView::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        GraphicStoryView *_t = static_cast<GraphicStoryView *>(_o);
        switch (_id) {
        case 0: _t->story_split_added((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< StoryBase*(*)>(_a[2]))); break;
        case 1: _t->story_root_added((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< StoryBase*(*)>(_a[2]))); break;
        case 2: _t->event_added((*reinterpret_cast< Event*(*)>(_a[1]))); break;
        case 3: _t->obsPoint_added((*reinterpret_cast< ObservationPoint*(*)>(_a[1]))); break;
        case 4: _t->emit_zoom_in((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 5: _t->emit_zoom_out((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 6: _t->add_split_story((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< StoryBase*(*)>(_a[2]))); break;
        case 7: _t->add_root_story((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< StoryBase*(*)>(_a[2]))); break;
        case 8: _t->add_event((*reinterpret_cast< Event*(*)>(_a[1]))); break;
        case 9: _t->add_obsPoint((*reinterpret_cast< ObservationPoint*(*)>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (GraphicStoryView::*_t)(QString , StoryBase * );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&GraphicStoryView::story_split_added)) {
                *result = 0;
            }
        }
        {
            typedef void (GraphicStoryView::*_t)(QString , StoryBase * );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&GraphicStoryView::story_root_added)) {
                *result = 1;
            }
        }
        {
            typedef void (GraphicStoryView::*_t)(Event * );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&GraphicStoryView::event_added)) {
                *result = 2;
            }
        }
        {
            typedef void (GraphicStoryView::*_t)(ObservationPoint * );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&GraphicStoryView::obsPoint_added)) {
                *result = 3;
            }
        }
        {
            typedef void (GraphicStoryView::*_t)(int );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&GraphicStoryView::emit_zoom_in)) {
                *result = 4;
            }
        }
        {
            typedef void (GraphicStoryView::*_t)(int );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&GraphicStoryView::emit_zoom_out)) {
                *result = 5;
            }
        }
    }
}

const QMetaObject GraphicStoryView::staticMetaObject = {
    { &QGraphicsView::staticMetaObject, qt_meta_stringdata_GraphicStoryView.data,
      qt_meta_data_GraphicStoryView,  qt_static_metacall, 0, 0}
};


const QMetaObject *GraphicStoryView::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *GraphicStoryView::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_GraphicStoryView.stringdata))
        return static_cast<void*>(const_cast< GraphicStoryView*>(this));
    return QGraphicsView::qt_metacast(_clname);
}

int GraphicStoryView::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QGraphicsView::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 10)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 10;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 10)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 10;
    }
    return _id;
}

// SIGNAL 0
void GraphicStoryView::story_split_added(QString _t1, StoryBase * _t2)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void GraphicStoryView::story_root_added(QString _t1, StoryBase * _t2)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void GraphicStoryView::event_added(Event * _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}

// SIGNAL 3
void GraphicStoryView::obsPoint_added(ObservationPoint * _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 3, _a);
}

// SIGNAL 4
void GraphicStoryView::emit_zoom_in(int _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 4, _a);
}

// SIGNAL 5
void GraphicStoryView::emit_zoom_out(int _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 5, _a);
}
QT_END_MOC_NAMESPACE
