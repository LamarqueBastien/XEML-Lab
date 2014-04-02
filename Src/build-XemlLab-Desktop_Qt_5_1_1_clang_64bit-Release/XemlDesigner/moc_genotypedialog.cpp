/****************************************************************************
** Meta object code from reading C++ file 'genotypedialog.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.1.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../XemlLab/XemlDesigner/DialogWindows/genotypedialog.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'genotypedialog.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.1.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_GenotypeDialog_t {
    QByteArrayData data[24];
    char stringdata[343];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    offsetof(qt_meta_stringdata_GenotypeDialog_t, stringdata) + ofs \
        - idx * sizeof(QByteArrayData) \
    )
static const qt_meta_stringdata_GenotypeDialog_t qt_meta_stringdata_GenotypeDialog = {
    {
QT_MOC_LITERAL(0, 0, 14),
QT_MOC_LITERAL(1, 15, 14),
QT_MOC_LITERAL(2, 30, 0),
QT_MOC_LITERAL(3, 31, 16),
QT_MOC_LITERAL(4, 48, 5),
QT_MOC_LITERAL(5, 54, 15),
QT_MOC_LITERAL(6, 70, 12),
QT_MOC_LITERAL(7, 83, 11),
QT_MOC_LITERAL(8, 95, 9),
QT_MOC_LITERAL(9, 105, 26),
QT_MOC_LITERAL(10, 132, 17),
QT_MOC_LITERAL(11, 150, 4),
QT_MOC_LITERAL(12, 155, 19),
QT_MOC_LITERAL(13, 175, 16),
QT_MOC_LITERAL(14, 192, 20),
QT_MOC_LITERAL(15, 213, 21),
QT_MOC_LITERAL(16, 235, 4),
QT_MOC_LITERAL(17, 240, 6),
QT_MOC_LITERAL(18, 247, 10),
QT_MOC_LITERAL(19, 258, 15),
QT_MOC_LITERAL(20, 274, 17),
QT_MOC_LITERAL(21, 292, 14),
QT_MOC_LITERAL(22, 307, 18),
QT_MOC_LITERAL(23, 326, 15)
    },
    "GenotypeDialog\0genotype_added\0\0"
    "IndividualsPool*\0_pool\0genotype_edited\0"
    "ItfDocument*\0_currentdoc\0OkClicked\0"
    "on_add_individuals_clicked\0add_species_label\0"
    "text\0add_accession_label\0add_mutant_label\0"
    "add_transgenic_label\0add_tagged_annotation\0"
    "_tag\0_annot\0add_tag_id\0add_tag_species\0"
    "add_tag_accession\0add_tag_mutant\0"
    "add_tag_transgenic\0enabledOkButton\0"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_GenotypeDialog[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
      15,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       2,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   89,    2, 0x05,
       5,    1,   92,    2, 0x05,

 // slots: name, argc, parameters, tag, flags
       8,    0,   95,    2, 0x08,
       9,    0,   96,    2, 0x08,
      10,    1,   97,    2, 0x08,
      12,    1,  100,    2, 0x08,
      13,    1,  103,    2, 0x08,
      14,    1,  106,    2, 0x08,
      15,    2,  109,    2, 0x08,
      18,    0,  114,    2, 0x08,
      19,    0,  115,    2, 0x08,
      20,    0,  116,    2, 0x08,
      21,    0,  117,    2, 0x08,
      22,    0,  118,    2, 0x08,
      23,    1,  119,    2, 0x08,

 // signals: parameters
    QMetaType::Void, 0x80000000 | 3,    4,
    QMetaType::Void, 0x80000000 | 6,    7,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString,   11,
    QMetaType::Void, QMetaType::QString,   11,
    QMetaType::Void, QMetaType::QString,   11,
    QMetaType::Void, QMetaType::QString,   11,
    QMetaType::Void, QMetaType::QString, QMetaType::QString,   16,   17,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString,   11,

       0        // eod
};

void GenotypeDialog::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        GenotypeDialog *_t = static_cast<GenotypeDialog *>(_o);
        switch (_id) {
        case 0: _t->genotype_added((*reinterpret_cast< IndividualsPool*(*)>(_a[1]))); break;
        case 1: _t->genotype_edited((*reinterpret_cast< ItfDocument*(*)>(_a[1]))); break;
        case 2: _t->OkClicked(); break;
        case 3: _t->on_add_individuals_clicked(); break;
        case 4: _t->add_species_label((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 5: _t->add_accession_label((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 6: _t->add_mutant_label((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 7: _t->add_transgenic_label((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 8: _t->add_tagged_annotation((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2]))); break;
        case 9: _t->add_tag_id(); break;
        case 10: _t->add_tag_species(); break;
        case 11: _t->add_tag_accession(); break;
        case 12: _t->add_tag_mutant(); break;
        case 13: _t->add_tag_transgenic(); break;
        case 14: _t->enabledOkButton((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (GenotypeDialog::*_t)(IndividualsPool * );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&GenotypeDialog::genotype_added)) {
                *result = 0;
            }
        }
        {
            typedef void (GenotypeDialog::*_t)(ItfDocument * );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&GenotypeDialog::genotype_edited)) {
                *result = 1;
            }
        }
    }
}

const QMetaObject GenotypeDialog::staticMetaObject = {
    { &QDialog::staticMetaObject, qt_meta_stringdata_GenotypeDialog.data,
      qt_meta_data_GenotypeDialog,  qt_static_metacall, 0, 0}
};


const QMetaObject *GenotypeDialog::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *GenotypeDialog::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_GenotypeDialog.stringdata))
        return static_cast<void*>(const_cast< GenotypeDialog*>(this));
    return QDialog::qt_metacast(_clname);
}

int GenotypeDialog::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDialog::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 15)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 15;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 15)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 15;
    }
    return _id;
}

// SIGNAL 0
void GenotypeDialog::genotype_added(IndividualsPool * _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void GenotypeDialog::genotype_edited(ItfDocument * _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}
QT_END_MOC_NAMESPACE
