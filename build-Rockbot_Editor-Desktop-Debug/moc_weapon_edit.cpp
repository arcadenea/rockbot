/****************************************************************************
** Meta object code from reading C++ file 'weapon_edit.h'
**
** Created by: The Qt Meta Object Compiler version 63 (Qt 4.8.6)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../editor/mainwindow_tab/weapon_edit.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'weapon_edit.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.6. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_weapon_edit[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
       4,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: signature, parameters, type, tag, flags
      19,   13,   12,   12, 0x08,
      72,   67,   12,   12, 0x08,
     108,   13,   12,   12, 0x08,
     159,   67,   12,   12, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_weapon_edit[] = {
    "weapon_edit\0\0index\0"
    "on_weapon_select_combo_currentIndexChanged(int)\0"
    "arg1\0on_weapon_name_textChanged(QString)\0"
    "on_weapon_projectile_type_currentIndexChanged(int)\0"
    "on_weapon_damage_valueChanged(int)\0"
};

void weapon_edit::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        weapon_edit *_t = static_cast<weapon_edit *>(_o);
        switch (_id) {
        case 0: _t->on_weapon_select_combo_currentIndexChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 1: _t->on_weapon_name_textChanged((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 2: _t->on_weapon_projectile_type_currentIndexChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 3: _t->on_weapon_damage_valueChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        default: ;
        }
    }
}

const QMetaObjectExtraData weapon_edit::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject weapon_edit::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_weapon_edit,
      qt_meta_data_weapon_edit, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &weapon_edit::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *weapon_edit::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *weapon_edit::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_weapon_edit))
        return static_cast<void*>(const_cast< weapon_edit*>(this));
    return QWidget::qt_metacast(_clname);
}

int weapon_edit::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 4)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 4;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
