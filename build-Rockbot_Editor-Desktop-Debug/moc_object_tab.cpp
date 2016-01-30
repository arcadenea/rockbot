/****************************************************************************
** Meta object code from reading C++ file 'object_tab.h'
**
** Created by: The Qt Meta Object Compiler version 63 (Qt 4.8.6)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../editor/mainwindow_tab/object_tab.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'object_tab.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.6. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_object_tab[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
      13,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: signature, parameters, type, tag, flags
      17,   12,   11,   11, 0x08,
      73,   67,   11,   11, 0x08,
     118,   12,   11,   11, 0x08,
     147,   67,   11,   11, 0x08,
     186,   12,   11,   11, 0x08,
     213,   12,   11,   11, 0x08,
     244,   12,   11,   11, 0x08,
     275,   12,   11,   11, 0x08,
     310,  302,   11,   11, 0x08,
     354,  302,   11,   11, 0x08,
     395,   12,   11,   11, 0x08,
     439,  302,   11,   11, 0x08,
     483,   12,   11,   11, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_object_tab[] = {
    "object_tab\0\0arg1\0"
    "on_graphicfile_combo_currentIndexChanged(QString)\0"
    "index\0on_objectlist_combo_currentIndexChanged(int)\0"
    "on_name_textChanged(QString)\0"
    "on_type_combo_currentIndexChanged(int)\0"
    "on_limit_valueChanged(int)\0"
    "on_graphic_w_valueChanged(int)\0"
    "on_graphic_h_valueChanged(int)\0"
    "on_speed_valueChanged(int)\0checked\0"
    "on_animate_on_active_checkbox_toggled(bool)\0"
    "on_animation_loop_checkbox_toggled(bool)\0"
    "on_frame_duration_spinbox_valueChanged(int)\0"
    "on_animation_reverse_checkbox_toggled(bool)\0"
    "on_timer_valueChanged(int)\0"
};

void object_tab::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        object_tab *_t = static_cast<object_tab *>(_o);
        switch (_id) {
        case 0: _t->on_graphicfile_combo_currentIndexChanged((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 1: _t->on_objectlist_combo_currentIndexChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 2: _t->on_name_textChanged((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 3: _t->on_type_combo_currentIndexChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 4: _t->on_limit_valueChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 5: _t->on_graphic_w_valueChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 6: _t->on_graphic_h_valueChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 7: _t->on_speed_valueChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 8: _t->on_animate_on_active_checkbox_toggled((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 9: _t->on_animation_loop_checkbox_toggled((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 10: _t->on_frame_duration_spinbox_valueChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 11: _t->on_animation_reverse_checkbox_toggled((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 12: _t->on_timer_valueChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        default: ;
        }
    }
}

const QMetaObjectExtraData object_tab::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject object_tab::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_object_tab,
      qt_meta_data_object_tab, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &object_tab::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *object_tab::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *object_tab::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_object_tab))
        return static_cast<void*>(const_cast< object_tab*>(this));
    return QWidget::qt_metacast(_clname);
}

int object_tab::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 13)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 13;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
