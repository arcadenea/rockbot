/****************************************************************************
** Meta object code from reading C++ file 'npc_edit.h'
**
** Created by: The Qt Meta Object Compiler version 63 (Qt 4.8.6)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../editor/mainwindow_tab/npc_edit.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'npc_edit.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.6. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_npc_edit[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
      41,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: signature, parameters, type, tag, flags
      16,   10,    9,    9, 0x08,
      77,   72,    9,    9, 0x08,
     135,   72,    9,    9, 0x08,
     182,   72,    9,    9, 0x08,
     230,   72,    9,    9, 0x08,
     275,   72,    9,    9, 0x08,
     323,  315,    9,    9, 0x08,
     362,   10,    9,    9, 0x08,
     414,   10,    9,    9, 0x08,
     462,   72,    9,    9, 0x08,
     506,   72,    9,    9, 0x08,
     546,   10,    9,    9, 0x08,
     597,   72,    9,    9, 0x08,
     646,   10,    9,    9, 0x08,
     701,   72,    9,    9, 0x08,
     751,   10,    9,    9, 0x08,
     799,   10,    9,    9, 0x08,
     822,    9,    9,    9, 0x08,
     846,    9,    9,    9, 0x08,
     867,    9,    9,    9, 0x08,
     901,  890,    9,    9, 0x08,
     948,   72,    9,    9, 0x08,
     993,   72,    9,    9, 0x08,
    1032,   72,    9,    9, 0x08,
    1071,   72,    9,    9, 0x08,
    1110,   72,    9,    9, 0x08,
    1149,   10,    9,    9, 0x08,
    1198,   10,    9,    9, 0x08,
    1247,   10,    9,    9, 0x08,
    1284,  315,    9,    9, 0x08,
    1317,   72,    9,    9, 0x08,
    1351,   72,    9,    9, 0x08,
    1385,  315,    9,    9, 0x08,
    1411,   72,    9,    9, 0x08,
    1450,   72,    9,    9, 0x08,
    1489,   72,    9,    9, 0x08,
    1528,   72,    9,    9, 0x08,
    1567,  315,    9,    9, 0x08,
    1603,   72,    9,    9, 0x08,
    1645,    9,    9,    9, 0x08,
    1674,    9,    9,    9, 0x0a,

       0        // eod
};

static const char qt_meta_stringdata_npc_edit[] = {
    "npc_edit\0\0index\0"
    "on_npc_edit_tab_selectnpccombo_currentIndexChanged(int)\0"
    "arg1\0on_npc_edit_tab_graphiccombo_currentIndexChanged(QString)\0"
    "on_npc_edit_tab_graphicwidth_valueChanged(int)\0"
    "on_npc_edit_tab_graphicheight_valueChanged(int)\0"
    "on_npc_edit_tab_NpcName_textChanged(QString)\0"
    "on_npc_edit_tab_NpcHP_valueChanged(int)\0"
    "checked\0on_npc_edit_tab_canshoot_toggled(bool)\0"
    "on_npc_edit_tab_shieldtype_currentIndexChanged(int)\0"
    "on_npc_edit_tab_iatype_currentIndexChanged(int)\0"
    "on_npc_edit_tab_movespeed_valueChanged(int)\0"
    "on_npc_edit_tab_range_valueChanged(int)\0"
    "on_npc_edit_tab_frametype_currentIndexChanged(int)\0"
    "on_bg_graphic_combo_currentIndexChanged(QString)\0"
    "on_npc_edit_tab_weakness_list_currentIndexChanged(int)\0"
    "on_npc_edit_tab_weakness_points_valueChanged(int)\0"
    "on_frame_list_selector_currentIndexChanged(int)\0"
    "reload_frame_list(int)\0on_pushButton_clicked()\0"
    "on_frameUp_clicked()\0on_frameDown_clicked()\0"
    "currentRow\0on_frameList_listWidget_currentRowChanged(int)\0"
    "on_sprite_duration_spinBox_valueChanged(int)\0"
    "on_sprite_colision_x_valueChanged(int)\0"
    "on_sprite_colision_y_valueChanged(int)\0"
    "on_sprite_colision_w_valueChanged(int)\0"
    "on_sprite_colision_h_valueChanged(int)\0"
    "on_projectile1_comboBox_currentIndexChanged(int)\0"
    "on_projectile2_comboBox_currentIndexChanged(int)\0"
    "on_ai_chain_currentIndexChanged(int)\0"
    "on_isBoss_checkBox_toggled(bool)\0"
    "on_sprite_pos_x_valueChanged(int)\0"
    "on_sprite_pos_y_valueChanged(int)\0"
    "on_checkBox_toggled(bool)\0"
    "on_hitarea_x_spinBox_valueChanged(int)\0"
    "on_hitarea_y_spinBox_valueChanged(int)\0"
    "on_hitarea_w_spinBox_valueChanged(int)\0"
    "on_hitarea_h_spinBox_valueChanged(int)\0"
    "on_isSubBoss_checkbox_toggled(bool)\0"
    "on_respawn_time_spinBox_valueChanged(int)\0"
    "on_AddFrame_Button_clicked()\0"
    "set_npc_frame()\0"
};

void npc_edit::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        npc_edit *_t = static_cast<npc_edit *>(_o);
        switch (_id) {
        case 0: _t->on_npc_edit_tab_selectnpccombo_currentIndexChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 1: _t->on_npc_edit_tab_graphiccombo_currentIndexChanged((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 2: _t->on_npc_edit_tab_graphicwidth_valueChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 3: _t->on_npc_edit_tab_graphicheight_valueChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 4: _t->on_npc_edit_tab_NpcName_textChanged((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 5: _t->on_npc_edit_tab_NpcHP_valueChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 6: _t->on_npc_edit_tab_canshoot_toggled((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 7: _t->on_npc_edit_tab_shieldtype_currentIndexChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 8: _t->on_npc_edit_tab_iatype_currentIndexChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 9: _t->on_npc_edit_tab_movespeed_valueChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 10: _t->on_npc_edit_tab_range_valueChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 11: _t->on_npc_edit_tab_frametype_currentIndexChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 12: _t->on_bg_graphic_combo_currentIndexChanged((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 13: _t->on_npc_edit_tab_weakness_list_currentIndexChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 14: _t->on_npc_edit_tab_weakness_points_valueChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 15: _t->on_frame_list_selector_currentIndexChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 16: _t->reload_frame_list((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 17: _t->on_pushButton_clicked(); break;
        case 18: _t->on_frameUp_clicked(); break;
        case 19: _t->on_frameDown_clicked(); break;
        case 20: _t->on_frameList_listWidget_currentRowChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 21: _t->on_sprite_duration_spinBox_valueChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 22: _t->on_sprite_colision_x_valueChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 23: _t->on_sprite_colision_y_valueChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 24: _t->on_sprite_colision_w_valueChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 25: _t->on_sprite_colision_h_valueChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 26: _t->on_projectile1_comboBox_currentIndexChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 27: _t->on_projectile2_comboBox_currentIndexChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 28: _t->on_ai_chain_currentIndexChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 29: _t->on_isBoss_checkBox_toggled((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 30: _t->on_sprite_pos_x_valueChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 31: _t->on_sprite_pos_y_valueChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 32: _t->on_checkBox_toggled((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 33: _t->on_hitarea_x_spinBox_valueChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 34: _t->on_hitarea_y_spinBox_valueChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 35: _t->on_hitarea_w_spinBox_valueChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 36: _t->on_hitarea_h_spinBox_valueChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 37: _t->on_isSubBoss_checkbox_toggled((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 38: _t->on_respawn_time_spinBox_valueChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 39: _t->on_AddFrame_Button_clicked(); break;
        case 40: _t->set_npc_frame(); break;
        default: ;
        }
    }
}

const QMetaObjectExtraData npc_edit::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject npc_edit::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_npc_edit,
      qt_meta_data_npc_edit, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &npc_edit::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *npc_edit::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *npc_edit::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_npc_edit))
        return static_cast<void*>(const_cast< npc_edit*>(this));
    return QWidget::qt_metacast(_clname);
}

int npc_edit::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 41)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 41;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
