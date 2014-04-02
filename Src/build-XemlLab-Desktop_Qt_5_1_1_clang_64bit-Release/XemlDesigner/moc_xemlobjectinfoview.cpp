/****************************************************************************
** Meta object code from reading C++ file 'xemlobjectinfoview.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.1.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../XemlLab/XemlDesigner/Views/xemlobjectinfoview.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'xemlobjectinfoview.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.1.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_XemlObjectInfoView_t {
    QByteArrayData data[13];
    char stringdata[156];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    offsetof(qt_meta_stringdata_XemlObjectInfoView_t, stringdata) + ofs \
        - idx * sizeof(QByteArrayData) \
    )
static const qt_meta_stringdata_XemlObjectInfoView_t qt_meta_stringdata_XemlObjectInfoView = {
    {
QT_MOC_LITERAL(0, 0, 18),
QT_MOC_LITERAL(1, 19, 16),
QT_MOC_LITERAL(2, 36, 0),
QT_MOC_LITERAL(3, 37, 6),
QT_MOC_LITERAL(4, 44, 12),
QT_MOC_LITERAL(5, 57, 14),
QT_MOC_LITERAL(6, 72, 15),
QT_MOC_LITERAL(7, 88, 14),
QT_MOC_LITERAL(8, 103, 7),
QT_MOC_LITERAL(9, 111, 19),
QT_MOC_LITERAL(10, 131, 6),
QT_MOC_LITERAL(11, 138, 4),
QT_MOC_LITERAL(12, 143, 11)
    },
    "XemlObjectInfoView\0on_label_changed\0"
    "\0_label\0refresh_view\0add_annotation\0"
    "set_object_info\0QGraphicsItem*\0_object\0"
    "on_annotation_added\0_annot\0_tag\0"
    "change_name\0"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_XemlObjectInfoView[] = {

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
       4,    0,   47,    2, 0x05,

 // slots: name, argc, parameters, tag, flags
       5,    0,   48,    2, 0x0a,
       6,    1,   49,    2, 0x0a,
       9,    2,   52,    2, 0x0a,
      12,    1,   57,    2, 0x0a,

 // signals: parameters
    QMetaType::Void, QMetaType::QString,    3,
    QMetaType::Void,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 7,    8,
    QMetaType::Void, QMetaType::QString, QMetaType::QString,   10,   11,
    QMetaType::Void, QMetaType::QString,    3,

       0        // eod
};

void XemlObjectInfoView::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        XemlObjectInfoView *_t = static_cast<XemlObjectInfoView *>(_o);
        switch (_id) {
        case 0: _t->on_label_changed((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 1: _t->refresh_view(); break;
        case 2: _t->add_annotation(); break;
        case 3: _t->set_object_info((*reinterpret_cast< QGraphicsItem*(*)>(_a[1]))); break;
        case 4: _t->on_annotation_added((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2]))); break;
        case 5: _t->change_name((*reinterpret_cast< QString(*)>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        switch (_id) {
        default: *reinterpret_cast<int*>(_a[0]) = -1; break;
        case 3:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< QGraphicsItem* >(); break;
            }
            break;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (XemlObjectInfoView::*_t)(QString );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&XemlObjectInfoView::on_label_changed)) {
                *result = 0;
            }
        }
        {
            typedef void (XemlObjectInfoView::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&XemlObjectInfoView::refresh_view)) {
                *result = 1;
            }
        }
    }
}

const QMetaObject XemlObjectInfoView::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_XemlObjectInfoView.data,
      qt_meta_data_XemlObjectInfoView,  qt_static_metacall, 0, 0}
};


const QMetaObject *XemlObjectInfoView::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *XemlObjectInfoView::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_XemlObjectInfoView.stringdata))
        return static_cast<void*>(const_cast< XemlObjectInfoView*>(this));
    return QWidget::qt_metacast(_clname);
}

int XemlObjectInfoView::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
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
            qt_static_metacall(this, _c, _id, _a);
        _id -= 6;
    }
    return _id;
}

// SIGNAL 0
void XemlObjectInfoView::on_label_changed(QString _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void XemlObjectInfoView::refresh_view()
{
    QMetaObject::activate(this, &staticMetaObject, 1, 0);
}
QT_END_MOC_NAMESPACE
