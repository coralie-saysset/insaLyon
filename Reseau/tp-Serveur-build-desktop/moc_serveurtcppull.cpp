/****************************************************************************
** Meta object code from reading C++ file 'serveurtcppull.h'
**
** Created: Wed Dec 7 23:54:12 2011
**      by: The Qt Meta Object Compiler version 62 (Qt 4.7.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../tp-Serveur/serveurtcppull.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'serveurtcppull.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 62
#error "This file was generated using the moc from 4.7.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_ServeurTcpPull[] = {

 // content:
       5,       // revision
       0,       // classname
       0,    0, // classinfo
       1,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: signature, parameters, type, tag, flags
      16,   15,   15,   15, 0x09,

       0        // eod
};

static const char qt_meta_stringdata_ServeurTcpPull[] = {
    "ServeurTcpPull\0\0connexionAuServeur()\0"
};

const QMetaObject ServeurTcpPull::staticMetaObject = {
    { &QTcpServer::staticMetaObject, qt_meta_stringdata_ServeurTcpPull,
      qt_meta_data_ServeurTcpPull, 0 }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &ServeurTcpPull::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *ServeurTcpPull::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *ServeurTcpPull::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_ServeurTcpPull))
        return static_cast<void*>(const_cast< ServeurTcpPull*>(this));
    return QTcpServer::qt_metacast(_clname);
}

int ServeurTcpPull::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QTcpServer::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: connexionAuServeur(); break;
        default: ;
        }
        _id -= 1;
    }
    return _id;
}
QT_END_MOC_NAMESPACE