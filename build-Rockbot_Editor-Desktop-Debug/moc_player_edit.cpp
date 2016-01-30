/****************************************************************************
** Meta object code from reading C++ file 'player_edit.h'
**
** Created by: The Qt Meta Object Compiler version 63 (Qt 4.8.6)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../editor/mainwindow_tab/player_edit.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'player_edit.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.6. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_player_edit[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
      35,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: signature, parameters, type, tag, flags
      13,   12,   12,   12, 0x0a,
      37,   12,   12,   12, 0x0a,
      61,   12,   12,   12, 0x0a,
      85,   12,   12,   12, 0x0a,
     106,   12,   12,   12, 0x0a,
     127,   12,   12,   12, 0x0a,
     148,   12,   12,   12, 0x0a,
     170,  164,   12,   12, 0x08,
     226,  221,   12,   12, 0x08,
     267,  221,   12,   12, 0x08,
     311,  303,   12,   12, 0x08,
     350,  221,   12,   12, 0x08,
     392,  303,   12,   12, 0x08,
     428,  164,   12,   12, 0x08,
     481,  221,   12,   12, 0x08,
     535,  221,   12,   12, 0x08,
     572,  221,   12,   12, 0x08,
     609,  221,   12,   12, 0x08,
     647,  221,   12,   12, 0x08,
     685,  221,   12,   12, 0x08,
     723,  221,   12,   12, 0x08,
     761,   12,   12,   12, 0x08,
     786,   12,   12,   12, 0x08,
     811,   12,   12,   12, 0x08,
     836,   12,   12,   12, 0x08,
     863,   12,   12,   12, 0x08,
     890,   12,   12,   12, 0x08,
     917,  164,   12,   12, 0x08,
     963,  164,   12,   12, 0x08,
    1008,  221,   12,   12, 0x08,
    1054,  221,   12,   12, 0x08,
    1092,  303,   12,   12, 0x08,
    1131,  303,   12,   12, 0x08,
    1167,  303,   12,   12, 0x08,
    1200,  221,   12,   12, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_player_edit[] = {
    "player_edit\0\0pick_player_keycolor1()\0"
    "pick_player_keycolor2()\0pick_player_keycolor3()\0"
    "pick_player_color1()\0pick_player_color2()\0"
    "pick_player_color3()\0pick_bg_color()\0"
    "index\0on_players_tab_list_combo_currentIndexChanged(int)\0"
    "arg1\0on_players_tab_name_textChanged(QString)\0"
    "on_players_tab_hp_valueChanged(int)\0"
    "checked\0on_players_tab_hasshield_toggled(bool)\0"
    "on_players_tab_maxshots_valueChanged(int)\0"
    "on_can_slide_checkbox_toggled(bool)\0"
    "on_players_tab_list_combo_2_currentIndexChanged(int)\0"
    "on_player_graphics_combo_currentIndexChanged(QString)\0"
    "on_player_sprite_w_valueChanged(int)\0"
    "on_player_sprite_h_valueChanged(int)\0"
    "on_player_hitarea_x_valueChanged(int)\0"
    "on_player_hitarea_y_valueChanged(int)\0"
    "on_player_hitarea_w_valueChanged(int)\0"
    "on_player_hitarea_h_valueChanged(int)\0"
    "on_key1_picker_clicked()\0"
    "on_key2_picker_clicked()\0"
    "on_key3_picker_clicked()\0"
    "on_color1_picker_clicked()\0"
    "on_color2_picker_clicked()\0"
    "on_color3_picker_clicked()\0"
    "on_chargedshot_combo_currentIndexChanged(int)\0"
    "on_weaponlist_combo_currentIndexChanged(int)\0"
    "on_players_tab_movespeed_valueChanged(double)\0"
    "on_damageModSpinBox_valueChanged(int)\0"
    "on_canDoubleJumpCheckBox_toggled(bool)\0"
    "on_CanAirDashCheckBox_toggled(bool)\0"
    "on_canShotDiagonal_toggled(bool)\0"
    "on_playerFace_comboBox_currentIndexChanged(QString)\0"
};

void player_edit::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        player_edit *_t = static_cast<player_edit *>(_o);
        switch (_id) {
        case 0: _t->pick_player_keycolor1(); break;
        case 1: _t->pick_player_keycolor2(); break;
        case 2: _t->pick_player_keycolor3(); break;
        case 3: _t->pick_player_color1(); break;
        case 4: _t->pick_player_color2(); break;
        case 5: _t->pick_player_color3(); break;
        case 6: _t->pick_bg_color(); break;
        case 7: _t->on_players_tab_list_combo_currentIndexChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 8: _t->on_players_tab_name_textChanged((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 9: _t->on_players_tab_hp_valueChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 10: _t->on_players_tab_hasshield_toggled((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 11: _t->on_players_tab_maxshots_valueChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 12: _t->on_can_slide_checkbox_toggled((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 13: _t->on_players_tab_list_combo_2_currentIndexChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 14: _t->on_player_graphics_combo_currentIndexChanged((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 15: _t->on_player_sprite_w_valueChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 16: _t->on_player_sprite_h_valueChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 17: _t->on_player_hitarea_x_valueChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 18: _t->on_player_hitarea_y_valueChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 19: _t->on_player_hitarea_w_valueChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 20: _t->on_player_hitarea_h_valueChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 21: _t->on_key1_picker_clicked(); break;
        case 22: _t->on_key2_picker_clicked(); break;
        case 23: _t->on_key3_picker_clicked(); break;
        case 24: _t->on_color1_picker_clicked(); break;
        case 25: _t->on_color2_picker_clicked(); break;
        case 26: _t->on_color3_picker_clicked(); break;
        case 27: _t->on_chargedshot_combo_currentIndexChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 28: _t->on_weaponlist_combo_currentIndexChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 29: _t->on_players_tab_movespeed_valueChanged((*reinterpret_cast< double(*)>(_a[1]))); break;
        case 30: _t->on_damageModSpinBox_valueChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 31: _t->on_canDoubleJumpCheckBox_toggled((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 32: _t->on_CanAirDashCheckBox_toggled((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 33: _t->on_canShotDiagonal_toggled((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 34: _t->on_playerFace_comboBox_currentIndexChanged((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        default: ;
        }
    }
}

const QMetaObjectExtraData player_edit::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject player_edit::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_player_edit,
      qt_meta_data_player_edit, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &player_edit::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *player_edit::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *player_edit::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_player_edit))
        return static_cast<void*>(const_cast< player_edit*>(this));
    return QWidget::qt_metacast(_clname);
}

int player_edit::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 35)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 35;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
