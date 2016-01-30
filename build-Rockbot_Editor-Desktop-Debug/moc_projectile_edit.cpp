/****************************************************************************
** Meta object code from reading C++ file 'projectile_edit.h'
**
** Created by: The Qt Meta Object Compiler version 63 (Qt 4.8.6)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../editor/mainwindow_tab/projectile_edit.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'projectile_edit.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.6. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_projectile_edit[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
      11,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: signature, parameters, type, tag, flags
      23,   17,   16,   16, 0x08,
      77,   72,   16,   16, 0x08,
     106,   72,   16,   16, 0x08,
     155,   17,   16,   16, 0x08,
     194,   72,   16,   16, 0x08,
     221,   72,   16,   16, 0x08,
     256,  248,   16,   16, 0x08,
     304,   72,   16,   16, 0x08,
     352,   72,   16,   16, 0x08,
     383,   72,   16,   16, 0x08,
     410,   72,   16,   16, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_projectile_edit[] = {
    "projectile_edit\0\0index\0"
    "on_projectileList_combo_currentIndexChanged(int)\0"
    "arg1\0on_name_textChanged(QString)\0"
    "on_graphic_filename_currentIndexChanged(QString)\0"
    "on_trajectory_currentIndexChanged(int)\0"
    "on_img_w_valueChanged(int)\0"
    "on_img_h_valueChanged(int)\0checked\0"
    "on_projectileDestructibleCheckBox_toggled(bool)\0"
    "on_projectileHitPointsSpinBox_valueChanged(int)\0"
    "on_max_shots_valueChanged(int)\0"
    "on_speed_valueChanged(int)\0"
    "on_damage_valueChanged(int)\0"
};

void projectile_edit::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        projectile_edit *_t = static_cast<projectile_edit *>(_o);
        switch (_id) {
        case 0: _t->on_projectileList_combo_currentIndexChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 1: _t->on_name_textChanged((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 2: _t->on_graphic_filename_currentIndexChanged((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 3: _t->on_trajectory_currentIndexChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 4: _t->on_img_w_valueChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 5: _t->on_img_h_valueChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 6: _t->on_projectileDestructibleCheckBox_toggled((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 7: _t->on_projectileHitPointsSpinBox_valueChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 8: _t->on_max_shots_valueChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 9: _t->on_speed_valueChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 10: _t->on_damage_valueChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        default: ;
        }
    }
}

const QMetaObjectExtraData projectile_edit::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject projectile_edit::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_projectile_edit,
      qt_meta_data_projectile_edit, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &projectile_edit::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *projectile_edit::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *projectile_edit::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_projectile_edit))
        return static_cast<void*>(const_cast< projectile_edit*>(this));
    return QWidget::qt_metacast(_clname);
}

int projectile_edit::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 11)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 11;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
