/****************************************************************************
** Meta object code from reading C++ file 'dialognpcedit.h'
**
** Created by: The Qt Meta Object Compiler version 63 (Qt 4.8.6)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../editor/dialognpcedit.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'dialognpcedit.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.6. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_DialogNPCEdit[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
       8,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: signature, parameters, type, tag, flags
      15,   14,   14,   14, 0x05,

 // slots: signature, parameters, type, tag, flags
      35,   14,   14,   14, 0x08,
      64,   14,   14,   14, 0x08,
      94,   88,   14,   14, 0x08,
     137,   14,   14,   14, 0x08,
     185,   14,   14,   14, 0x08,
     227,   14,   14,   14, 0x08,
     269,   14,   14,   14, 0x0a,

       0        // eod
};

static const char qt_meta_stringdata_DialogNPCEdit[] = {
    "DialogNPCEdit\0\0finishedNPCEditor()\0"
    "on_spinBox_valueChanged(int)\0"
    "on_buttonBox_accepted()\0index\0"
    "on_frameTypeCombo_currentIndexChanged(int)\0"
    "on_npcListCombobox_currentIndexChanged(QString)\0"
    "on_npcGraphicSizeSpin_h_valueChanged(int)\0"
    "on_npcGraphicSizeSpin_w_valueChanged(int)\0"
    "setNPCFrame()\0"
};

void DialogNPCEdit::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        DialogNPCEdit *_t = static_cast<DialogNPCEdit *>(_o);
        switch (_id) {
        case 0: _t->finishedNPCEditor(); break;
        case 1: _t->on_spinBox_valueChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 2: _t->on_buttonBox_accepted(); break;
        case 3: _t->on_frameTypeCombo_currentIndexChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 4: _t->on_npcListCombobox_currentIndexChanged((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 5: _t->on_npcGraphicSizeSpin_h_valueChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 6: _t->on_npcGraphicSizeSpin_w_valueChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 7: _t->setNPCFrame(); break;
        default: ;
        }
    }
}

const QMetaObjectExtraData DialogNPCEdit::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject DialogNPCEdit::staticMetaObject = {
    { &QDialog::staticMetaObject, qt_meta_stringdata_DialogNPCEdit,
      qt_meta_data_DialogNPCEdit, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &DialogNPCEdit::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *DialogNPCEdit::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *DialogNPCEdit::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_DialogNPCEdit))
        return static_cast<void*>(const_cast< DialogNPCEdit*>(this));
    return QDialog::qt_metacast(_clname);
}

int DialogNPCEdit::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDialog::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 8)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 8;
    }
    return _id;
}

// SIGNAL 0
void DialogNPCEdit::finishedNPCEditor()
{
    QMetaObject::activate(this, &staticMetaObject, 0, 0);
}
QT_END_MOC_NAMESPACE
