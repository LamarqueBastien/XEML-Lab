/****************************************************************************
** Meta object code from reading C++ file 'loaderparamsettingpage.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.1.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../XemlLab/XemlDesigner/XemlCSVLoader/loaderparamsettingpage.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'loaderparamsettingpage.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.1.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_LoaderParamSettingPage_t {
    QByteArrayData data[21];
    char stringdata[317];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    offsetof(qt_meta_stringdata_LoaderParamSettingPage_t, stringdata) + ofs \
        - idx * sizeof(QByteArrayData) \
    )
static const qt_meta_stringdata_LoaderParamSettingPage_t qt_meta_stringdata_LoaderParamSettingPage = {
    {
QT_MOC_LITERAL(0, 0, 22),
QT_MOC_LITERAL(1, 23, 18),
QT_MOC_LITERAL(2, 42, 0),
QT_MOC_LITERAL(3, 43, 18),
QT_MOC_LITERAL(4, 62, 22),
QT_MOC_LITERAL(5, 85, 6),
QT_MOC_LITERAL(6, 92, 4),
QT_MOC_LITERAL(7, 97, 16),
QT_MOC_LITERAL(8, 114, 5),
QT_MOC_LITERAL(9, 120, 5),
QT_MOC_LITERAL(10, 126, 23),
QT_MOC_LITERAL(11, 150, 10),
QT_MOC_LITERAL(12, 161, 10),
QT_MOC_LITERAL(13, 172, 22),
QT_MOC_LITERAL(14, 195, 5),
QT_MOC_LITERAL(15, 201, 32),
QT_MOC_LITERAL(16, 234, 16),
QT_MOC_LITERAL(17, 251, 6),
QT_MOC_LITERAL(18, 258, 9),
QT_MOC_LITERAL(19, 268, 35),
QT_MOC_LITERAL(20, 304, 11)
    },
    "LoaderParamSettingPage\0set_paramater_type\0"
    "\0_is_time_parameter\0store_information_term\0"
    "column\0_row\0ItfOntologyTerm*\0_term\0"
    "_unit\0store_information_story\0StoryNode*\0"
    "_storynode\0store_information_time\0"
    "_date\0store_information_term_and_story\0"
    "on_item_selected\0_index\0send_data\0"
    "std::vector<std::vector<QString>*>*\0"
    "_vectorData\0"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_LoaderParamSettingPage[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       7,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    1,   49,    2, 0x08,
       4,    4,   52,    2, 0x08,
      10,    3,   61,    2, 0x08,
      13,    3,   68,    2, 0x08,
      15,    5,   75,    2, 0x08,
      16,    1,   86,    2, 0x08,
      18,    1,   89,    2, 0x08,

 // slots: parameters
    QMetaType::Void, QMetaType::Bool,    3,
    QMetaType::Void, QMetaType::Int, QMetaType::Int, 0x80000000 | 7, QMetaType::QString,    5,    6,    8,    9,
    QMetaType::Void, QMetaType::Int, QMetaType::Int, 0x80000000 | 11,    5,    6,   12,
    QMetaType::Void, QMetaType::Int, QMetaType::Int, QMetaType::QString,    5,    6,   14,
    QMetaType::Void, QMetaType::Int, QMetaType::Int, 0x80000000 | 11, 0x80000000 | 7, QMetaType::QString,    5,    6,   12,    8,    9,
    QMetaType::Void, QMetaType::QModelIndex,   17,
    QMetaType::Void, 0x80000000 | 19,   20,

       0        // eod
};

void LoaderParamSettingPage::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        LoaderParamSettingPage *_t = static_cast<LoaderParamSettingPage *>(_o);
        switch (_id) {
        case 0: _t->set_paramater_type((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 1: _t->store_information_term((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2])),(*reinterpret_cast< ItfOntologyTerm*(*)>(_a[3])),(*reinterpret_cast< QString(*)>(_a[4]))); break;
        case 2: _t->store_information_story((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2])),(*reinterpret_cast< StoryNode*(*)>(_a[3]))); break;
        case 3: _t->store_information_time((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2])),(*reinterpret_cast< QString(*)>(_a[3]))); break;
        case 4: _t->store_information_term_and_story((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2])),(*reinterpret_cast< StoryNode*(*)>(_a[3])),(*reinterpret_cast< ItfOntologyTerm*(*)>(_a[4])),(*reinterpret_cast< QString(*)>(_a[5]))); break;
        case 5: _t->on_item_selected((*reinterpret_cast< QModelIndex(*)>(_a[1]))); break;
        case 6: _t->send_data((*reinterpret_cast< std::vector<std::vector<QString>*>*(*)>(_a[1]))); break;
        default: ;
        }
    }
}

const QMetaObject LoaderParamSettingPage::staticMetaObject = {
    { &QWizardPage::staticMetaObject, qt_meta_stringdata_LoaderParamSettingPage.data,
      qt_meta_data_LoaderParamSettingPage,  qt_static_metacall, 0, 0}
};


const QMetaObject *LoaderParamSettingPage::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *LoaderParamSettingPage::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_LoaderParamSettingPage.stringdata))
        return static_cast<void*>(const_cast< LoaderParamSettingPage*>(this));
    return QWizardPage::qt_metacast(_clname);
}

int LoaderParamSettingPage::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWizardPage::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 7)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 7;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 7)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 7;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
