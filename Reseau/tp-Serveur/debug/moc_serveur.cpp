/****************************************************************************
** Meta object code from reading C++ file 'serveur.h'
**
** Created: Tue 29. Nov 17:14:15 2011
**      by: The Qt Meta Object Compiler version 61 (Qt 4.5.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../serveur.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'serveur.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 61
#error "This file was generated using the moc from 4.5.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_Serveur[] = {

 // content:
       2,       // revision
       0,       // classname
       0,    0, // classinfo
       1,   12, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors

 // slots: signature, parameters, type, tag, flags
       9,    8,    8,    8, 0x09,

       0        // eod
};

static const char qt_meta_stringdata_Serveur[] = {
    "Serveur\0\0connexionAuServeur()\0"
};

const QMetaObject Serveur::staticMetaObject = {
    { &QTcpServer::staticMetaObject, qt_meta_stringdata_Serveur,
      qt_meta_data_Serveur, 0 }
};

const QMetaObject *Serveur::metaObject() const
{
    return &staticMetaObject;
}

void *Serveur::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_Serveur))
        return static_cast<void*>(const_cast< Serveur*>(this));
    return QTcpServer::qt_metacast(_clname);
}

int Serveur::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
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
