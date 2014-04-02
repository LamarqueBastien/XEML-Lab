/****************************************************************************
** Meta object code from reading C++ file 'individualintropage.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.1.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../XemlLab/XemlDesigner/PopulationLoader/individualintropage.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'individualintropage.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.1.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_IndividualIntroPage_t {
    QByteArrayData data[1];
    char stringdata[21];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    offsetof(qt_meta_stringdata_IndividualIntroPage_t, stringdata) + ofs \
        - idx * sizeof(QByteArrayData) \
    )
static const qt_meta_stringdata_IndividualIntroPage_t qt_meta_stringdata_IndividualIntroPage = {
    {
QT_MOC_LITERAL(0, 0, 19)
    },
    "IndividualIntroPage\0"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_IndividualIntroPage[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       0,    0, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

       0        // eod
};

void IndividualIntroPage::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    Q_UNUSED(_o);
    Q_UNUSED(_id);
    Q_UNUSED(_c);
    Q_UNUSED(_a);
}

const QMetaObject IndividualIntroPage::staticMetaObject = {
    { &QWizardPage::staticMetaObject, qt_meta_stringdata_IndividualIntroPage.data,
      qt_meta_data_IndividualIntroPage,  qt_static_metacall, 0, 0}
};


const QMetaObject *IndividualIntroPage::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *IndividualIntroPage::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_IndividualIntroPage.stringdata))
        return static_cast<void*>(const_cast< IndividualIntroPage*>(this));
    return QWizardPage::qt_metacast(_clname);
}

int IndividualIntroPage::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWizardPage::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    return _id;
}
QT_END_MOC_NAMESPACE
