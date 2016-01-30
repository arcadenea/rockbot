/****************************************************************************
** Meta object code from reading C++ file 'dialogobjectedit.h'
**
** Created by: The Qt Meta Object Compiler version 63 (Qt 4.8.6)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../editor/dialogobjectedit.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'dialogobjectedit.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.6. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_DialogObjectEdit[] = {

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
      18,   17,   17,   17, 0x05,

 // slots: signature, parameters, type, tag, flags
      41,   17,   17,   17, 0x0a,
      58,   17,   17,   17, 0x08,
      82,   17,   17,   17, 0x08,
     133,   17,   17,   17, 0x08,
     175,   17,   17,   17, 0x08,
     217,   17,   17,   17, 0x08,
     246,  241,   17,   17, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_DialogObjectEdit[] = {
    "DialogObjectEdit\0\0finishedObjectEditor()\0"
    "setObjectFrame()\0on_buttonBox_rejected()\0"
    "on_objectListCombobox_currentIndexChanged(QString)\0"
    "on_npcGraphicSizeSpin_h_valueChanged(int)\0"
    "on_npcGraphicSizeSpin_w_valueChanged(int)\0"
    "on_buttonBox_accepted()\0arg1\0"
    "on_NpcName_textChanged(QString)\0"
};

void DialogObjectEdit::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        DialogObjectEdit *_t = static_cast<DialogObjectEdit *>(_o);
        switch (_id) {
        case 0: _t->finishedObjectEditor(); break;
        case 1: _t->setObjectFrame(); break;
        case 2: _t->on_buttonBox_rejected(); break;
        case 3: _t->on_objectListCombobox_currentIndexChanged((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 4: _t->on_npcGraphicSizeSpin_h_valueChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 5: _t->on_npcGraphicSizeSpin_w_valueChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 6: _t->on_buttonBox_accepted(); break;
        case 7: _t->on_NpcName_textChanged((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        default: ;
        }
    }
}

const QMetaObjectExtraData DialogObjectEdit::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject DialogObjectEdit::staticMetaObject = {
    { &QDialog::staticMetaObject, qt_meta_stringdata_DialogObjectEdit,
      qt_meta_data_DialogObjectEdit, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &DialogObjectEdit::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *DialogObjectEdit::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *DialogObjectEdit::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_DialogObjectEdit))
        return static_cast<void*>(const_cast< DialogObjectEdit*>(this));
    return QDialog::qt_metacast(_clname);
}

int DialogObjectEdit::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
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
void DialogObjectEdit::finishedObjectEditor()
{
    QMetaObject::activate(this, &staticMetaObject, 0, 0);
}
QT_END_MOC_NAMESPACE
