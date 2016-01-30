/****************************************************************************
** Meta object code from reading C++ file 'tab_image.h'
**
** Created by: The Qt Meta Object Compiler version 63 (Qt 4.8.6)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../editor/scenes/tab_image.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'tab_image.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.6. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_tab_image[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
       9,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: signature, parameters, type, tag, flags
      11,   10,   10,   10, 0x08,
      41,   35,   10,   10, 0x08,
      90,   85,   10,   10, 0x08,
     121,   85,   10,   10, 0x08,
     152,   85,   10,   10, 0x08,
     187,   85,   10,   10, 0x08,
     222,   85,   10,   10, 0x08,
     265,  257,   10,   10, 0x08,
     300,   85,   10,   10, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_tab_image[] = {
    "tab_image\0\0on_add_Button_clicked()\0"
    "index\0on_select_comboBox_currentIndexChanged(int)\0"
    "arg1\0on_x_spinBox_valueChanged(int)\0"
    "on_y_spinBox_valueChanged(int)\0"
    "on_destx_spinBox_valueChanged(int)\0"
    "on_desty_spinBox_valueChanged(int)\0"
    "on_delay_spinBox_valueChanged(int)\0"
    "checked\0on_blocking_checkBox_toggled(bool)\0"
    "on_filename_comboBox_currentIndexChanged(QString)\0"
};

void tab_image::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        tab_image *_t = static_cast<tab_image *>(_o);
        switch (_id) {
        case 0: _t->on_add_Button_clicked(); break;
        case 1: _t->on_select_comboBox_currentIndexChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 2: _t->on_x_spinBox_valueChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 3: _t->on_y_spinBox_valueChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 4: _t->on_destx_spinBox_valueChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 5: _t->on_desty_spinBox_valueChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 6: _t->on_delay_spinBox_valueChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 7: _t->on_blocking_checkBox_toggled((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 8: _t->on_filename_comboBox_currentIndexChanged((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        default: ;
        }
    }
}

const QMetaObjectExtraData tab_image::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject tab_image::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_tab_image,
      qt_meta_data_tab_image, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &tab_image::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *tab_image::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *tab_image::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_tab_image))
        return static_cast<void*>(const_cast< tab_image*>(this));
    return QWidget::qt_metacast(_clname);
}

int tab_image::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 9)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 9;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
