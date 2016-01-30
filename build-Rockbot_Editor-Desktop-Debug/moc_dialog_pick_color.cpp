/****************************************************************************
** Meta object code from reading C++ file 'dialog_pick_color.h'
**
** Created by: The Qt Meta Object Compiler version 63 (Qt 4.8.6)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../editor/dialog_pick_color.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'dialog_pick_color.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.6. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_dialog_pick_color[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
       3,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: signature, parameters, type, tag, flags
      19,   18,   18,   18, 0x05,

 // slots: signature, parameters, type, tag, flags
      38,   30,   18,   18, 0x0a,
      51,   18,   18,   18, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_dialog_pick_color[] = {
    "dialog_pick_color\0\0accepted()\0color_n\0"
    "clicked(int)\0on_buttonBox_accepted()\0"
};

void dialog_pick_color::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        dialog_pick_color *_t = static_cast<dialog_pick_color *>(_o);
        switch (_id) {
        case 0: _t->accepted(); break;
        case 1: _t->clicked((*reinterpret_cast< const int(*)>(_a[1]))); break;
        case 2: _t->on_buttonBox_accepted(); break;
        default: ;
        }
    }
}

const QMetaObjectExtraData dialog_pick_color::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject dialog_pick_color::staticMetaObject = {
    { &QDialog::staticMetaObject, qt_meta_stringdata_dialog_pick_color,
      qt_meta_data_dialog_pick_color, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &dialog_pick_color::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *dialog_pick_color::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *dialog_pick_color::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_dialog_pick_color))
        return static_cast<void*>(const_cast< dialog_pick_color*>(this));
    return QDialog::qt_metacast(_clname);
}

int dialog_pick_color::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDialog::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 3)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 3;
    }
    return _id;
}

// SIGNAL 0
void dialog_pick_color::accepted()
{
    QMetaObject::activate(this, &staticMetaObject, 0, 0);
}
QT_END_MOC_NAMESPACE
