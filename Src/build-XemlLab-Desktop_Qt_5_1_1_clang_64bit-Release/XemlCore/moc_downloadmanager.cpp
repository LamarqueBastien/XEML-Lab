/****************************************************************************
** Meta object code from reading C++ file 'downloadmanager.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.1.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../XemlLab/XemlCore/Manager/downloadmanager.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#include <QtCore/QList>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'downloadmanager.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.1.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_Xeml__Document__Manager__DownloadManager_t {
    QByteArrayData data[19];
    char stringdata[268];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    offsetof(qt_meta_stringdata_Xeml__Document__Manager__DownloadManager_t, stringdata) + ofs \
        - idx * sizeof(QByteArrayData) \
    )
static const qt_meta_stringdata_Xeml__Document__Manager__DownloadManager_t qt_meta_stringdata_Xeml__Document__Manager__DownloadManager = {
    {
QT_MOC_LITERAL(0, 0, 40),
QT_MOC_LITERAL(1, 41, 9),
QT_MOC_LITERAL(2, 51, 0),
QT_MOC_LITERAL(3, 52, 10),
QT_MOC_LITERAL(4, 63, 4),
QT_MOC_LITERAL(5, 68, 12),
QT_MOC_LITERAL(6, 81, 7),
QT_MOC_LITERAL(7, 89, 14),
QT_MOC_LITERAL(8, 104, 12),
QT_MOC_LITERAL(9, 117, 13),
QT_MOC_LITERAL(10, 131, 22),
QT_MOC_LITERAL(11, 154, 9),
QT_MOC_LITERAL(12, 164, 10),
QT_MOC_LITERAL(13, 175, 26),
QT_MOC_LITERAL(14, 202, 14),
QT_MOC_LITERAL(15, 217, 15),
QT_MOC_LITERAL(16, 233, 9),
QT_MOC_LITERAL(17, 243, 16),
QT_MOC_LITERAL(18, 260, 6)
    },
    "Xeml::Document::Manager::DownloadManager\0"
    "monSignal\0\0monSignal2\0quit\0downloadFile\0"
    "display\0cancelDownload\0httpFinished\0"
    "httpReadyRead\0updateDataReadProgress\0"
    "bytesRead\0totalBytes\0slotAuthenticationRequired\0"
    "QNetworkReply*\0QAuthenticator*\0sslErrors\0"
    "QList<QSslError>\0errors\0"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_Xeml__Document__Manager__DownloadManager[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
      11,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       2,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    0,   69,    2, 0x05,
       3,    0,   70,    2, 0x05,

 // slots: name, argc, parameters, tag, flags
       4,    0,   71,    2, 0x08,
       5,    0,   72,    2, 0x08,
       6,    0,   73,    2, 0x08,
       7,    0,   74,    2, 0x08,
       8,    0,   75,    2, 0x08,
       9,    0,   76,    2, 0x08,
      10,    2,   77,    2, 0x08,
      13,    2,   82,    2, 0x08,
      16,    2,   87,    2, 0x08,

 // signals: parameters
    QMetaType::Void,
    QMetaType::Void,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::LongLong, QMetaType::LongLong,   11,   12,
    QMetaType::Void, 0x80000000 | 14, 0x80000000 | 15,    2,    2,
    QMetaType::Void, 0x80000000 | 14, 0x80000000 | 17,    2,   18,

       0        // eod
};

void Xeml::Document::Manager::DownloadManager::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        DownloadManager *_t = static_cast<DownloadManager *>(_o);
        switch (_id) {
        case 0: _t->monSignal(); break;
        case 1: _t->monSignal2(); break;
        case 2: _t->quit(); break;
        case 3: _t->downloadFile(); break;
        case 4: _t->display(); break;
        case 5: _t->cancelDownload(); break;
        case 6: _t->httpFinished(); break;
        case 7: _t->httpReadyRead(); break;
        case 8: _t->updateDataReadProgress((*reinterpret_cast< qint64(*)>(_a[1])),(*reinterpret_cast< qint64(*)>(_a[2]))); break;
        case 9: _t->slotAuthenticationRequired((*reinterpret_cast< QNetworkReply*(*)>(_a[1])),(*reinterpret_cast< QAuthenticator*(*)>(_a[2]))); break;
        case 10: _t->sslErrors((*reinterpret_cast< QNetworkReply*(*)>(_a[1])),(*reinterpret_cast< const QList<QSslError>(*)>(_a[2]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (DownloadManager::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&DownloadManager::monSignal)) {
                *result = 0;
            }
        }
        {
            typedef void (DownloadManager::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&DownloadManager::monSignal2)) {
                *result = 1;
            }
        }
    }
}

const QMetaObject Xeml::Document::Manager::DownloadManager::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_Xeml__Document__Manager__DownloadManager.data,
      qt_meta_data_Xeml__Document__Manager__DownloadManager,  qt_static_metacall, 0, 0}
};


const QMetaObject *Xeml::Document::Manager::DownloadManager::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *Xeml::Document::Manager::DownloadManager::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_Xeml__Document__Manager__DownloadManager.stringdata))
        return static_cast<void*>(const_cast< DownloadManager*>(this));
    return QObject::qt_metacast(_clname);
}

int Xeml::Document::Manager::DownloadManager::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 11)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 11;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 11)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 11;
    }
    return _id;
}

// SIGNAL 0
void Xeml::Document::Manager::DownloadManager::monSignal()
{
    QMetaObject::activate(this, &staticMetaObject, 0, 0);
}

// SIGNAL 1
void Xeml::Document::Manager::DownloadManager::monSignal2()
{
    QMetaObject::activate(this, &staticMetaObject, 1, 0);
}
QT_END_MOC_NAMESPACE
