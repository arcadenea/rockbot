/****************************************************************************
** Meta object code from reading C++ file 'editorarea.h'
**
** Created by: The Qt Meta Object Compiler version 63 (Qt 4.8.6)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../editor/editorarea.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'editorarea.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.6. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_EditorArea[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
       3,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: signature, parameters, type, tag, flags
      12,   11,   11,   11, 0x0a,
      32,   25,   11,   11, 0x0a,
      48,   46,   11,   11, 0x0a,

       0        // eod
};

static const char qt_meta_stringdata_EditorArea[] = {
    "EditorArea\0\0changeTile()\0game_n\0"
    "saveGame(int)\0,\0addObjectToMap(int,int)\0"
};

void EditorArea::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        EditorArea *_t = static_cast<EditorArea *>(_o);
        switch (_id) {
        case 0: _t->changeTile(); break;
        case 1: _t->saveGame((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 2: _t->addObjectToMap((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        default: ;
        }
    }
}

const QMetaObjectExtraData EditorArea::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject EditorArea::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_EditorArea,
      qt_meta_data_EditorArea, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &EditorArea::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *EditorArea::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *EditorArea::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_EditorArea))
        return static_cast<void*>(const_cast< EditorArea*>(this));
    return QWidget::qt_metacast(_clname);
}

int EditorArea::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 3)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 3;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
