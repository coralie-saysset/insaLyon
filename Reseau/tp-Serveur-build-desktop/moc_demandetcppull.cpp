/****************************************************************************
** Meta object code from reading C++ file 'demandetcppull.h'
**
** Created: Wed Dec 7 23:54:12 2011
**      by: The Qt Meta Object Compiler version 62 (Qt 4.7.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../tp-Serveur/demandetcppull.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'demandetcppull.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 62
#error "This file was generated using the moc from 4.7.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_DemandeTcpPull[] = {

 // content:
       5,       // revision
       0,       // classname
       0,    0, // classinfo
       3,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: signature, parameters, type, tag, flags
      16,   15,   15,   15, 0x05,

 // slots: signature, parameters, type, tag, flags
      34,   15,   15,   15, 0x09,
      48,   15,   15,   15, 0x09,

       0        // eod
};

static const char qt_meta_stringdata_DemandeTcpPull[] = {
    "DemandeTcpPull\0\0requeteComplete()\0"
    "requeteRecu()\0traiterRequete()\0"
};

const QMetaObject DemandeTcpPull::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_DemandeTcpPull,
      qt_meta_data_DemandeTcpPull, 0 }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &DemandeTcpPull::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *DemandeTcpPull::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *DemandeTcpPull::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_DemandeTcpPull))
        return static_cast<void*>(const_cast< DemandeTcpPull*>(this));
    return QObject::qt_metacast(_clname);
}

int DemandeTcpPull::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: requeteComplete(); break;
        case 1: requeteRecu(); break;
        case 2: traiterRequete(); break;
        default: ;
        }
        _id -= 3;
    }
    return _id;
}

// SIGNAL 0
void DemandeTcpPull::requeteComplete()
{
    QMetaObject::activate(this, &staticMetaObject, 0, 0);
}
QT_END_MOC_NAMESPACE
