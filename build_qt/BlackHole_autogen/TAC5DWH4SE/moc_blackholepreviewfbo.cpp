/****************************************************************************
** Meta object code from reading C++ file 'blackholepreviewfbo.h'
**
** Created by: The Qt Meta Object Compiler version 69 (Qt 6.11.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../Blakhole_UI/core/blackholepreviewfbo.h"
#include <QtCore/qmetatype.h>

#include <QtCore/qtmochelpers.h>

#include <memory>


#include <QtCore/qxptype_traits.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'blackholepreviewfbo.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 69
#error "This file was generated using the moc from 6.11.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

#ifndef Q_CONSTINIT
#define Q_CONSTINIT
#endif

QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
QT_WARNING_DISABLE_GCC("-Wuseless-cast")
namespace {
struct qt_meta_tag_ZN19BlackholePreviewFBOE_t {};
} // unnamed namespace

template <> constexpr inline auto BlackholePreviewFBO::qt_create_metaobjectdata<qt_meta_tag_ZN19BlackholePreviewFBOE_t>()
{
    namespace QMC = QtMocConstants;
    QtMocHelpers::StringRefStorage qt_stringData {
        "BlackholePreviewFBO",
        "diskTempChanged",
        "",
        "diskInclChanged",
        "diskRollChanged",
        "diskInnerChanged",
        "diskOuterChanged",
        "diskOpacChanged",
        "diskDoppChanged",
        "diskBeamChanged",
        "diskGainChanged",
        "diskContrChanged",
        "diskWindChanged",
        "diskSpeedChanged",
        "diskExpoChanged",
        "diskStarChanged",
        "runningChanged",
        "syncFromCore",
        "core",
        "diskTemp",
        "diskIncl",
        "diskRoll",
        "diskInner",
        "diskOuter",
        "diskOpac",
        "diskDopp",
        "diskBeam",
        "diskGain",
        "diskContr",
        "diskWind",
        "diskSpeed",
        "diskExpo",
        "diskStar",
        "running"
    };

    QtMocHelpers::UintData qt_methods {
        // Signal 'diskTempChanged'
        QtMocHelpers::SignalData<void()>(1, 2, QMC::AccessPublic, QMetaType::Void),
        // Signal 'diskInclChanged'
        QtMocHelpers::SignalData<void()>(3, 2, QMC::AccessPublic, QMetaType::Void),
        // Signal 'diskRollChanged'
        QtMocHelpers::SignalData<void()>(4, 2, QMC::AccessPublic, QMetaType::Void),
        // Signal 'diskInnerChanged'
        QtMocHelpers::SignalData<void()>(5, 2, QMC::AccessPublic, QMetaType::Void),
        // Signal 'diskOuterChanged'
        QtMocHelpers::SignalData<void()>(6, 2, QMC::AccessPublic, QMetaType::Void),
        // Signal 'diskOpacChanged'
        QtMocHelpers::SignalData<void()>(7, 2, QMC::AccessPublic, QMetaType::Void),
        // Signal 'diskDoppChanged'
        QtMocHelpers::SignalData<void()>(8, 2, QMC::AccessPublic, QMetaType::Void),
        // Signal 'diskBeamChanged'
        QtMocHelpers::SignalData<void()>(9, 2, QMC::AccessPublic, QMetaType::Void),
        // Signal 'diskGainChanged'
        QtMocHelpers::SignalData<void()>(10, 2, QMC::AccessPublic, QMetaType::Void),
        // Signal 'diskContrChanged'
        QtMocHelpers::SignalData<void()>(11, 2, QMC::AccessPublic, QMetaType::Void),
        // Signal 'diskWindChanged'
        QtMocHelpers::SignalData<void()>(12, 2, QMC::AccessPublic, QMetaType::Void),
        // Signal 'diskSpeedChanged'
        QtMocHelpers::SignalData<void()>(13, 2, QMC::AccessPublic, QMetaType::Void),
        // Signal 'diskExpoChanged'
        QtMocHelpers::SignalData<void()>(14, 2, QMC::AccessPublic, QMetaType::Void),
        // Signal 'diskStarChanged'
        QtMocHelpers::SignalData<void()>(15, 2, QMC::AccessPublic, QMetaType::Void),
        // Signal 'runningChanged'
        QtMocHelpers::SignalData<void()>(16, 2, QMC::AccessPublic, QMetaType::Void),
        // Method 'syncFromCore'
        QtMocHelpers::MethodData<void(QObject *)>(17, 2, QMC::AccessPublic, QMetaType::Void, {{
            { QMetaType::QObjectStar, 18 },
        }}),
    };
    QtMocHelpers::UintData qt_properties {
        // property 'diskTemp'
        QtMocHelpers::PropertyData<float>(19, QMetaType::Float, QMC::DefaultPropertyFlags | QMC::Writable | QMC::StdCppSet, 0),
        // property 'diskIncl'
        QtMocHelpers::PropertyData<float>(20, QMetaType::Float, QMC::DefaultPropertyFlags | QMC::Writable | QMC::StdCppSet, 1),
        // property 'diskRoll'
        QtMocHelpers::PropertyData<float>(21, QMetaType::Float, QMC::DefaultPropertyFlags | QMC::Writable | QMC::StdCppSet, 2),
        // property 'diskInner'
        QtMocHelpers::PropertyData<float>(22, QMetaType::Float, QMC::DefaultPropertyFlags | QMC::Writable | QMC::StdCppSet, 3),
        // property 'diskOuter'
        QtMocHelpers::PropertyData<float>(23, QMetaType::Float, QMC::DefaultPropertyFlags | QMC::Writable | QMC::StdCppSet, 4),
        // property 'diskOpac'
        QtMocHelpers::PropertyData<float>(24, QMetaType::Float, QMC::DefaultPropertyFlags | QMC::Writable | QMC::StdCppSet, 5),
        // property 'diskDopp'
        QtMocHelpers::PropertyData<float>(25, QMetaType::Float, QMC::DefaultPropertyFlags | QMC::Writable | QMC::StdCppSet, 6),
        // property 'diskBeam'
        QtMocHelpers::PropertyData<float>(26, QMetaType::Float, QMC::DefaultPropertyFlags | QMC::Writable | QMC::StdCppSet, 7),
        // property 'diskGain'
        QtMocHelpers::PropertyData<float>(27, QMetaType::Float, QMC::DefaultPropertyFlags | QMC::Writable | QMC::StdCppSet, 8),
        // property 'diskContr'
        QtMocHelpers::PropertyData<float>(28, QMetaType::Float, QMC::DefaultPropertyFlags | QMC::Writable | QMC::StdCppSet, 9),
        // property 'diskWind'
        QtMocHelpers::PropertyData<float>(29, QMetaType::Float, QMC::DefaultPropertyFlags | QMC::Writable | QMC::StdCppSet, 10),
        // property 'diskSpeed'
        QtMocHelpers::PropertyData<float>(30, QMetaType::Float, QMC::DefaultPropertyFlags | QMC::Writable | QMC::StdCppSet, 11),
        // property 'diskExpo'
        QtMocHelpers::PropertyData<float>(31, QMetaType::Float, QMC::DefaultPropertyFlags | QMC::Writable | QMC::StdCppSet, 12),
        // property 'diskStar'
        QtMocHelpers::PropertyData<float>(32, QMetaType::Float, QMC::DefaultPropertyFlags | QMC::Writable | QMC::StdCppSet, 13),
        // property 'running'
        QtMocHelpers::PropertyData<bool>(33, QMetaType::Bool, QMC::DefaultPropertyFlags | QMC::Writable | QMC::StdCppSet, 14),
    };
    QtMocHelpers::UintData qt_enums {
    };
    return QtMocHelpers::metaObjectData<BlackholePreviewFBO, qt_meta_tag_ZN19BlackholePreviewFBOE_t>(QMC::MetaObjectFlag{}, qt_stringData,
            qt_methods, qt_properties, qt_enums);
}
Q_CONSTINIT const QMetaObject BlackholePreviewFBO::staticMetaObject = { {
    QMetaObject::SuperData::link<QQuickFramebufferObject::staticMetaObject>(),
    qt_staticMetaObjectStaticContent<qt_meta_tag_ZN19BlackholePreviewFBOE_t>.stringdata,
    qt_staticMetaObjectStaticContent<qt_meta_tag_ZN19BlackholePreviewFBOE_t>.data,
    qt_static_metacall,
    nullptr,
    qt_staticMetaObjectRelocatingContent<qt_meta_tag_ZN19BlackholePreviewFBOE_t>.metaTypes,
    nullptr
} };

void BlackholePreviewFBO::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    auto *_t = static_cast<BlackholePreviewFBO *>(_o);
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: _t->diskTempChanged(); break;
        case 1: _t->diskInclChanged(); break;
        case 2: _t->diskRollChanged(); break;
        case 3: _t->diskInnerChanged(); break;
        case 4: _t->diskOuterChanged(); break;
        case 5: _t->diskOpacChanged(); break;
        case 6: _t->diskDoppChanged(); break;
        case 7: _t->diskBeamChanged(); break;
        case 8: _t->diskGainChanged(); break;
        case 9: _t->diskContrChanged(); break;
        case 10: _t->diskWindChanged(); break;
        case 11: _t->diskSpeedChanged(); break;
        case 12: _t->diskExpoChanged(); break;
        case 13: _t->diskStarChanged(); break;
        case 14: _t->runningChanged(); break;
        case 15: _t->syncFromCore((*reinterpret_cast<std::add_pointer_t<QObject*>>(_a[1]))); break;
        default: ;
        }
    }
    if (_c == QMetaObject::IndexOfMethod) {
        if (QtMocHelpers::indexOfMethod<void (BlackholePreviewFBO::*)()>(_a, &BlackholePreviewFBO::diskTempChanged, 0))
            return;
        if (QtMocHelpers::indexOfMethod<void (BlackholePreviewFBO::*)()>(_a, &BlackholePreviewFBO::diskInclChanged, 1))
            return;
        if (QtMocHelpers::indexOfMethod<void (BlackholePreviewFBO::*)()>(_a, &BlackholePreviewFBO::diskRollChanged, 2))
            return;
        if (QtMocHelpers::indexOfMethod<void (BlackholePreviewFBO::*)()>(_a, &BlackholePreviewFBO::diskInnerChanged, 3))
            return;
        if (QtMocHelpers::indexOfMethod<void (BlackholePreviewFBO::*)()>(_a, &BlackholePreviewFBO::diskOuterChanged, 4))
            return;
        if (QtMocHelpers::indexOfMethod<void (BlackholePreviewFBO::*)()>(_a, &BlackholePreviewFBO::diskOpacChanged, 5))
            return;
        if (QtMocHelpers::indexOfMethod<void (BlackholePreviewFBO::*)()>(_a, &BlackholePreviewFBO::diskDoppChanged, 6))
            return;
        if (QtMocHelpers::indexOfMethod<void (BlackholePreviewFBO::*)()>(_a, &BlackholePreviewFBO::diskBeamChanged, 7))
            return;
        if (QtMocHelpers::indexOfMethod<void (BlackholePreviewFBO::*)()>(_a, &BlackholePreviewFBO::diskGainChanged, 8))
            return;
        if (QtMocHelpers::indexOfMethod<void (BlackholePreviewFBO::*)()>(_a, &BlackholePreviewFBO::diskContrChanged, 9))
            return;
        if (QtMocHelpers::indexOfMethod<void (BlackholePreviewFBO::*)()>(_a, &BlackholePreviewFBO::diskWindChanged, 10))
            return;
        if (QtMocHelpers::indexOfMethod<void (BlackholePreviewFBO::*)()>(_a, &BlackholePreviewFBO::diskSpeedChanged, 11))
            return;
        if (QtMocHelpers::indexOfMethod<void (BlackholePreviewFBO::*)()>(_a, &BlackholePreviewFBO::diskExpoChanged, 12))
            return;
        if (QtMocHelpers::indexOfMethod<void (BlackholePreviewFBO::*)()>(_a, &BlackholePreviewFBO::diskStarChanged, 13))
            return;
        if (QtMocHelpers::indexOfMethod<void (BlackholePreviewFBO::*)()>(_a, &BlackholePreviewFBO::runningChanged, 14))
            return;
    }
    if (_c == QMetaObject::ReadProperty) {
        void *_v = _a[0];
        switch (_id) {
        case 0: *reinterpret_cast<float*>(_v) = _t->diskTemp(); break;
        case 1: *reinterpret_cast<float*>(_v) = _t->diskIncl(); break;
        case 2: *reinterpret_cast<float*>(_v) = _t->diskRoll(); break;
        case 3: *reinterpret_cast<float*>(_v) = _t->diskInner(); break;
        case 4: *reinterpret_cast<float*>(_v) = _t->diskOuter(); break;
        case 5: *reinterpret_cast<float*>(_v) = _t->diskOpac(); break;
        case 6: *reinterpret_cast<float*>(_v) = _t->diskDopp(); break;
        case 7: *reinterpret_cast<float*>(_v) = _t->diskBeam(); break;
        case 8: *reinterpret_cast<float*>(_v) = _t->diskGain(); break;
        case 9: *reinterpret_cast<float*>(_v) = _t->diskContr(); break;
        case 10: *reinterpret_cast<float*>(_v) = _t->diskWind(); break;
        case 11: *reinterpret_cast<float*>(_v) = _t->diskSpeed(); break;
        case 12: *reinterpret_cast<float*>(_v) = _t->diskExpo(); break;
        case 13: *reinterpret_cast<float*>(_v) = _t->diskStar(); break;
        case 14: *reinterpret_cast<bool*>(_v) = _t->running(); break;
        default: break;
        }
    }
    if (_c == QMetaObject::WriteProperty) {
        void *_v = _a[0];
        switch (_id) {
        case 0: _t->setDiskTemp(*reinterpret_cast<float*>(_v)); break;
        case 1: _t->setDiskIncl(*reinterpret_cast<float*>(_v)); break;
        case 2: _t->setDiskRoll(*reinterpret_cast<float*>(_v)); break;
        case 3: _t->setDiskInner(*reinterpret_cast<float*>(_v)); break;
        case 4: _t->setDiskOuter(*reinterpret_cast<float*>(_v)); break;
        case 5: _t->setDiskOpac(*reinterpret_cast<float*>(_v)); break;
        case 6: _t->setDiskDopp(*reinterpret_cast<float*>(_v)); break;
        case 7: _t->setDiskBeam(*reinterpret_cast<float*>(_v)); break;
        case 8: _t->setDiskGain(*reinterpret_cast<float*>(_v)); break;
        case 9: _t->setDiskContr(*reinterpret_cast<float*>(_v)); break;
        case 10: _t->setDiskWind(*reinterpret_cast<float*>(_v)); break;
        case 11: _t->setDiskSpeed(*reinterpret_cast<float*>(_v)); break;
        case 12: _t->setDiskExpo(*reinterpret_cast<float*>(_v)); break;
        case 13: _t->setDiskStar(*reinterpret_cast<float*>(_v)); break;
        case 14: _t->setRunning(*reinterpret_cast<bool*>(_v)); break;
        default: break;
        }
    }
}

const QMetaObject *BlackholePreviewFBO::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *BlackholePreviewFBO::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_staticMetaObjectStaticContent<qt_meta_tag_ZN19BlackholePreviewFBOE_t>.strings))
        return static_cast<void*>(this);
    return QQuickFramebufferObject::qt_metacast(_clname);
}

int BlackholePreviewFBO::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QQuickFramebufferObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 16)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 16;
    }
    if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 16)
            *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType();
        _id -= 16;
    }
    if (_c == QMetaObject::ReadProperty || _c == QMetaObject::WriteProperty
            || _c == QMetaObject::ResetProperty || _c == QMetaObject::BindableProperty
            || _c == QMetaObject::RegisterPropertyMetaType) {
        qt_static_metacall(this, _c, _id, _a);
        _id -= 15;
    }
    return _id;
}

// SIGNAL 0
void BlackholePreviewFBO::diskTempChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 0, nullptr);
}

// SIGNAL 1
void BlackholePreviewFBO::diskInclChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 1, nullptr);
}

// SIGNAL 2
void BlackholePreviewFBO::diskRollChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 2, nullptr);
}

// SIGNAL 3
void BlackholePreviewFBO::diskInnerChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 3, nullptr);
}

// SIGNAL 4
void BlackholePreviewFBO::diskOuterChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 4, nullptr);
}

// SIGNAL 5
void BlackholePreviewFBO::diskOpacChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 5, nullptr);
}

// SIGNAL 6
void BlackholePreviewFBO::diskDoppChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 6, nullptr);
}

// SIGNAL 7
void BlackholePreviewFBO::diskBeamChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 7, nullptr);
}

// SIGNAL 8
void BlackholePreviewFBO::diskGainChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 8, nullptr);
}

// SIGNAL 9
void BlackholePreviewFBO::diskContrChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 9, nullptr);
}

// SIGNAL 10
void BlackholePreviewFBO::diskWindChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 10, nullptr);
}

// SIGNAL 11
void BlackholePreviewFBO::diskSpeedChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 11, nullptr);
}

// SIGNAL 12
void BlackholePreviewFBO::diskExpoChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 12, nullptr);
}

// SIGNAL 13
void BlackholePreviewFBO::diskStarChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 13, nullptr);
}

// SIGNAL 14
void BlackholePreviewFBO::runningChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 14, nullptr);
}
QT_WARNING_POP
