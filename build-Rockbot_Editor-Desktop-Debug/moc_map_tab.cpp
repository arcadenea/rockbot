/****************************************************************************
** Meta object code from reading C++ file 'map_tab.h'
**
** Created by: The Qt Meta Object Compiler version 63 (Qt 4.8.6)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../editor/mainwindow_tab/map_tab.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'map_tab.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.6. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_map_tab[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
      26,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: signature, parameters, type, tag, flags
       9,    8,    8,    8, 0x0a,
      31,   25,    8,    8, 0x08,
      74,   25,    8,    8, 0x08,
     120,  115,    8,    8, 0x08,
     149,   25,    8,    8, 0x08,
     197,  186,    8,    8, 0x08,
     236,  186,    8,    8, 0x08,
     277,   25,    8,    8, 0x08,
     325,   25,    8,    8, 0x08,
     387,  379,    8,    8, 0x08,
     423,  379,    8,    8, 0x08,
     461,  186,    8,    8, 0x08,
     504,    8,    8,    8, 0x08,
     531,  115,    8,    8, 0x08,
     576,  115,    8,    8, 0x08,
     610,  115,    8,    8, 0x08,
     641,  115,    8,    8, 0x08,
     686,  115,    8,    8, 0x08,
     720,  115,    8,    8, 0x08,
     751,  379,    8,    8, 0x08,
     777,  379,    8,    8, 0x08,
     805,  379,    8,    8, 0x08,
     833,   25,    8,    8, 0x08,
     888,  115,    8,    8, 0x08,
     947,  115,    8,    8, 0x08,
     992,   25,    8,    8, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_map_tab[] = {
    "map_tab\0\0pick_bg_color()\0index\0"
    "on_stageListCombo_currentIndexChanged(int)\0"
    "on_mapListCombo_currentIndexChanged(int)\0"
    "arg1\0on_spinBox_valueChanged(int)\0"
    "on_comboBox_currentIndexChanged(int)\0"
    "currentRow\0on_listWidget_2_currentRowChanged(int)\0"
    "on_npc_listWidget_currentRowChanged(int)\0"
    "on_npc_direction_combo_currentIndexChanged(int)\0"
    "on_link_orientation_combobox_currentIndexChanged(int)\0"
    "checked\0on_link_bidi_checkbox_toggled(bool)\0"
    "on_link_isdoor_checkbox_toggled(bool)\0"
    "on_objectListWidget_currentRowChanged(int)\0"
    "on_bg_color_pick_clicked()\0"
    "on_bg1_filename_currentIndexChanged(QString)\0"
    "on_bg1_speed_valueChanged(double)\0"
    "on_bg1_y_pos_valueChanged(int)\0"
    "on_bg2_filename_currentIndexChanged(QString)\0"
    "on_bg2_speed_valueChanged(double)\0"
    "on_bg2_y_pos_valueChanged(int)\0"
    "on_checkBox_toggled(bool)\0"
    "on_checkBox_2_toggled(bool)\0"
    "on_checkBox_3_toggled(bool)\0"
    "on_current_anim_tile_combobox_currentIndexChanged(int)\0"
    "on_anim_tile_graphic_combobox_currentIndexChanged(QString)\0"
    "on_anim_tile_delay_spinbox_valueChanged(int)\0"
    "on_object_direction_combo_currentIndexChanged(int)\0"
};

void map_tab::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        map_tab *_t = static_cast<map_tab *>(_o);
        switch (_id) {
        case 0: _t->pick_bg_color(); break;
        case 1: _t->on_stageListCombo_currentIndexChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 2: _t->on_mapListCombo_currentIndexChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 3: _t->on_spinBox_valueChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 4: _t->on_comboBox_currentIndexChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 5: _t->on_listWidget_2_currentRowChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 6: _t->on_npc_listWidget_currentRowChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 7: _t->on_npc_direction_combo_currentIndexChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 8: _t->on_link_orientation_combobox_currentIndexChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 9: _t->on_link_bidi_checkbox_toggled((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 10: _t->on_link_isdoor_checkbox_toggled((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 11: _t->on_objectListWidget_currentRowChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 12: _t->on_bg_color_pick_clicked(); break;
        case 13: _t->on_bg1_filename_currentIndexChanged((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 14: _t->on_bg1_speed_valueChanged((*reinterpret_cast< double(*)>(_a[1]))); break;
        case 15: _t->on_bg1_y_pos_valueChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 16: _t->on_bg2_filename_currentIndexChanged((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 17: _t->on_bg2_speed_valueChanged((*reinterpret_cast< double(*)>(_a[1]))); break;
        case 18: _t->on_bg2_y_pos_valueChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 19: _t->on_checkBox_toggled((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 20: _t->on_checkBox_2_toggled((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 21: _t->on_checkBox_3_toggled((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 22: _t->on_current_anim_tile_combobox_currentIndexChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 23: _t->on_anim_tile_graphic_combobox_currentIndexChanged((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 24: _t->on_anim_tile_delay_spinbox_valueChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 25: _t->on_object_direction_combo_currentIndexChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        default: ;
        }
    }
}

const QMetaObjectExtraData map_tab::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject map_tab::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_map_tab,
      qt_meta_data_map_tab, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &map_tab::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *map_tab::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *map_tab::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_map_tab))
        return static_cast<void*>(const_cast< map_tab*>(this));
    return QWidget::qt_metacast(_clname);
}

int map_tab::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 26)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 26;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
