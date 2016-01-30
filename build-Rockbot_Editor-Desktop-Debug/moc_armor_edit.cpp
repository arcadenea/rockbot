/****************************************************************************
** Meta object code from reading C++ file 'armor_edit.h'
**
** Created by: The Qt Meta Object Compiler version 63 (Qt 4.8.6)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../editor/mainwindow_tab/armor_edit.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'armor_edit.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.6. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_armor_edit[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
      12,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: signature, parameters, type, tag, flags
      18,   12,   11,   11, 0x08,
      62,   12,   11,   11, 0x08,
     107,   12,   11,   11, 0x08,
     152,   12,   11,   11, 0x08,
     196,   12,   11,   11, 0x08,
     241,   12,   11,   11, 0x08,
     286,   12,   11,   11, 0x08,
     330,   12,   11,   11, 0x08,
     375,   12,   11,   11, 0x08,
     420,   12,   11,   11, 0x08,
     464,   12,   11,   11, 0x08,
     509,   12,   11,   11, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_armor_edit[] = {
    "armor_edit\0\0index\0"
    "on_p1_arm_comboBox_currentIndexChanged(int)\0"
    "on_p1_body_comboBox_currentIndexChanged(int)\0"
    "on_p1_legs_comboBox_currentIndexChanged(int)\0"
    "on_p2_arm_comboBox_currentIndexChanged(int)\0"
    "on_p2_body_comboBox_currentIndexChanged(int)\0"
    "on_p2_legs_comboBox_currentIndexChanged(int)\0"
    "on_p3_arm_comboBox_currentIndexChanged(int)\0"
    "on_p3_body_comboBox_currentIndexChanged(int)\0"
    "on_p3_legs_comboBox_currentIndexChanged(int)\0"
    "on_p4_arm_comboBox_currentIndexChanged(int)\0"
    "on_p4_body_comboBox_currentIndexChanged(int)\0"
    "on_p4_legs_comboBox_currentIndexChanged(int)\0"
};

void armor_edit::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        armor_edit *_t = static_cast<armor_edit *>(_o);
        switch (_id) {
        case 0: _t->on_p1_arm_comboBox_currentIndexChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 1: _t->on_p1_body_comboBox_currentIndexChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 2: _t->on_p1_legs_comboBox_currentIndexChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 3: _t->on_p2_arm_comboBox_currentIndexChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 4: _t->on_p2_body_comboBox_currentIndexChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 5: _t->on_p2_legs_comboBox_currentIndexChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 6: _t->on_p3_arm_comboBox_currentIndexChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 7: _t->on_p3_body_comboBox_currentIndexChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 8: _t->on_p3_legs_comboBox_currentIndexChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 9: _t->on_p4_arm_comboBox_currentIndexChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 10: _t->on_p4_body_comboBox_currentIndexChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 11: _t->on_p4_legs_comboBox_currentIndexChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        default: ;
        }
    }
}

const QMetaObjectExtraData armor_edit::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject armor_edit::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_armor_edit,
      qt_meta_data_armor_edit, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &armor_edit::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *armor_edit::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *armor_edit::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_armor_edit))
        return static_cast<void*>(const_cast< armor_edit*>(this));
    return QWidget::qt_metacast(_clname);
}

int armor_edit::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 12)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 12;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
