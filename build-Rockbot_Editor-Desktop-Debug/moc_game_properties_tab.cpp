/****************************************************************************
** Meta object code from reading C++ file 'game_properties_tab.h'
**
** Created by: The Qt Meta Object Compiler version 63 (Qt 4.8.6)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../editor/mainwindow_tab/game_properties_tab.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'game_properties_tab.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.6. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_game_properties_tab[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
       6,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: signature, parameters, type, tag, flags
      27,   21,   20,   20, 0x08,
      75,   21,   20,   20, 0x08,
     123,   21,   20,   20, 0x08,
     174,   21,   20,   20, 0x08,
     230,  225,   20,   20, 0x08,
     284,  225,   20,   20, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_game_properties_tab[] = {
    "game_properties_tab\0\0index\0"
    "on_special_item1_combo_currentIndexChanged(int)\0"
    "on_special_item2_combo_currentIndexChanged(int)\0"
    "on_semicharged_shot_combo_currentIndexChanged(int)\0"
    "on_stagefaces_stage_combo_currentIndexChanged(int)\0"
    "arg1\0on_stagefaces_face_combo_currentIndexChanged(QString)\0"
    "on_lineEdit_textChanged(QString)\0"
};

void game_properties_tab::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        game_properties_tab *_t = static_cast<game_properties_tab *>(_o);
        switch (_id) {
        case 0: _t->on_special_item1_combo_currentIndexChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 1: _t->on_special_item2_combo_currentIndexChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 2: _t->on_semicharged_shot_combo_currentIndexChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 3: _t->on_stagefaces_stage_combo_currentIndexChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 4: _t->on_stagefaces_face_combo_currentIndexChanged((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 5: _t->on_lineEdit_textChanged((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        default: ;
        }
    }
}

const QMetaObjectExtraData game_properties_tab::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject game_properties_tab::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_game_properties_tab,
      qt_meta_data_game_properties_tab, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &game_properties_tab::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *game_properties_tab::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *game_properties_tab::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_game_properties_tab))
        return static_cast<void*>(const_cast< game_properties_tab*>(this));
    return QWidget::qt_metacast(_clname);
}

int game_properties_tab::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 6)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 6;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
