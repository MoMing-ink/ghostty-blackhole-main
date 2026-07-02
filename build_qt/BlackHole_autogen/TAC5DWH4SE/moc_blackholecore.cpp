/****************************************************************************
** Meta object code from reading C++ file 'blackholecore.h'
**
** Created by: The Qt Meta Object Compiler version 69 (Qt 6.11.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../Blakhole_UI/core/blackholecore.h"
#include <QtCore/qmetatype.h>

#include <QtCore/qtmochelpers.h>

#include <memory>


#include <QtCore/qxptype_traits.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'blackholecore.h' doesn't include <QObject>."
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
struct qt_meta_tag_ZN11PresetModelE_t {};
} // unnamed namespace

template <> constexpr inline auto PresetModel::qt_create_metaobjectdata<qt_meta_tag_ZN11PresetModelE_t>()
{
    namespace QMC = QtMocConstants;
    QtMocHelpers::StringRefStorage qt_stringData {
        "PresetModel"
    };

    QtMocHelpers::UintData qt_methods {
    };
    QtMocHelpers::UintData qt_properties {
    };
    QtMocHelpers::UintData qt_enums {
    };
    return QtMocHelpers::metaObjectData<PresetModel, qt_meta_tag_ZN11PresetModelE_t>(QMC::MetaObjectFlag{}, qt_stringData,
            qt_methods, qt_properties, qt_enums);
}
Q_CONSTINIT const QMetaObject PresetModel::staticMetaObject = { {
    QMetaObject::SuperData::link<QAbstractListModel::staticMetaObject>(),
    qt_staticMetaObjectStaticContent<qt_meta_tag_ZN11PresetModelE_t>.stringdata,
    qt_staticMetaObjectStaticContent<qt_meta_tag_ZN11PresetModelE_t>.data,
    qt_static_metacall,
    nullptr,
    qt_staticMetaObjectRelocatingContent<qt_meta_tag_ZN11PresetModelE_t>.metaTypes,
    nullptr
} };

void PresetModel::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    auto *_t = static_cast<PresetModel *>(_o);
    (void)_t;
    (void)_c;
    (void)_id;
    (void)_a;
}

const QMetaObject *PresetModel::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *PresetModel::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_staticMetaObjectStaticContent<qt_meta_tag_ZN11PresetModelE_t>.strings))
        return static_cast<void*>(this);
    return QAbstractListModel::qt_metacast(_clname);
}

int PresetModel::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QAbstractListModel::qt_metacall(_c, _id, _a);
    return _id;
}
namespace {
struct qt_meta_tag_ZN15PresetListModelE_t {};
} // unnamed namespace

template <> constexpr inline auto PresetListModel::qt_create_metaobjectdata<qt_meta_tag_ZN15PresetListModelE_t>()
{
    namespace QMC = QtMocConstants;
    QtMocHelpers::StringRefStorage qt_stringData {
        "PresetListModel"
    };

    QtMocHelpers::UintData qt_methods {
    };
    QtMocHelpers::UintData qt_properties {
    };
    QtMocHelpers::UintData qt_enums {
    };
    return QtMocHelpers::metaObjectData<PresetListModel, qt_meta_tag_ZN15PresetListModelE_t>(QMC::MetaObjectFlag{}, qt_stringData,
            qt_methods, qt_properties, qt_enums);
}
Q_CONSTINIT const QMetaObject PresetListModel::staticMetaObject = { {
    QMetaObject::SuperData::link<QAbstractListModel::staticMetaObject>(),
    qt_staticMetaObjectStaticContent<qt_meta_tag_ZN15PresetListModelE_t>.stringdata,
    qt_staticMetaObjectStaticContent<qt_meta_tag_ZN15PresetListModelE_t>.data,
    qt_static_metacall,
    nullptr,
    qt_staticMetaObjectRelocatingContent<qt_meta_tag_ZN15PresetListModelE_t>.metaTypes,
    nullptr
} };

void PresetListModel::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    auto *_t = static_cast<PresetListModel *>(_o);
    (void)_t;
    (void)_c;
    (void)_id;
    (void)_a;
}

const QMetaObject *PresetListModel::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *PresetListModel::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_staticMetaObjectStaticContent<qt_meta_tag_ZN15PresetListModelE_t>.strings))
        return static_cast<void*>(this);
    return QAbstractListModel::qt_metacast(_clname);
}

int PresetListModel::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QAbstractListModel::qt_metacall(_c, _id, _a);
    return _id;
}
namespace {
struct qt_meta_tag_ZN13BlackHoleCoreE_t {};
} // unnamed namespace

template <> constexpr inline auto BlackHoleCore::qt_create_metaobjectdata<qt_meta_tag_ZN13BlackHoleCoreE_t>()
{
    namespace QMC = QtMocConstants;
    QtMocHelpers::StringRefStorage qt_stringData {
        "BlackHoleCore",
        "displayModeChanged",
        "",
        "idleSecondsChanged",
        "playModeChanged",
        "slotSecondsChanged",
        "videoAsIdleChanged",
        "autoStartChanged",
        "launchMinimizedChanged",
        "screenTargetChanged",
        "rendererRunningChanged",
        "systemActiveChanged",
        "currentPresetIndexChanged",
        "currentPresetChanged",
        "configLoaded",
        "configSaved",
        "rendererStarted",
        "rendererStopped",
        "rendererError",
        "msg",
        "currentListChanged",
        "followMouseChanged",
        "randomPathChanged",
        "animationSpeedChanged",
        "screenSwallowChanged",
        "distortionChanged",
        "holeSizeChanged",
        "growEnabledChanged",
        "initialSizeChanged",
        "idleWhitelistChanged",
        "idleBlacklistChanged",
        "scheduleEnabledChanged",
        "startHourChanged",
        "startMinuteChanged",
        "endHourChanged",
        "endMinuteChanged",
        "countdownEnabledChanged",
        "countdownMinutesChanged",
        "isDarkChanged",
        "followSystemChanged",
        "focusColorChanged",
        "skipExitDialogChanged",
        "defaultCloseActionChanged",
        "overrideHoleRadiusChanged",
        "overrideDiskGainChanged",
        "overrideDiskTempChanged",
        "overrideExposureChanged",
        "overrideSpdChanged",
        "overrideStarGainChanged",
        "overrideDiskInclChanged",
        "loadConfig",
        "saveConfig",
        "resetDefaults",
        "startRenderer",
        "stopRenderer",
        "applyAndStart",
        "stopAll",
        "selectPreset",
        "index",
        "updatePresetParam",
        "param",
        "value",
        "updateCurrentPresetParam",
        "movePreset",
        "from",
        "to",
        "copyPreset",
        "pastePreset",
        "removePreset",
        "createPresetList",
        "name",
        "renameCurrentList",
        "switchToList",
        "deleteCurrentList",
        "createPreset",
        "renameCurrentPreset",
        "checkIdle",
        "displayMode",
        "idleSeconds",
        "playMode",
        "slotSeconds",
        "videoAsIdle",
        "autoStart",
        "launchMinimized",
        "screenTarget",
        "rendererRunning",
        "systemActive",
        "currentPresetIndex",
        "presetModel",
        "QAbstractItemModel*",
        "presetListModel",
        "currentListName",
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
        "followMouse",
        "randomPath",
        "animationSpeed",
        "screenSwallow",
        "distortion",
        "holeSize",
        "growEnabled",
        "initialSize",
        "idleWhitelist",
        "idleBlacklist",
        "scheduleEnabled",
        "startHour",
        "startMinute",
        "endHour",
        "endMinute",
        "countdownEnabled",
        "countdownMinutes",
        "isDark",
        "followSystem",
        "focusColor",
        "QColor",
        "skipExitDialog",
        "defaultCloseAction",
        "overrideHoleRadius",
        "overrideDiskGain",
        "overrideDiskTemp",
        "overrideExposure",
        "overrideSpd",
        "overrideStarGain",
        "overrideDiskIncl"
    };

    QtMocHelpers::UintData qt_methods {
        // Signal 'displayModeChanged'
        QtMocHelpers::SignalData<void()>(1, 2, QMC::AccessPublic, QMetaType::Void),
        // Signal 'idleSecondsChanged'
        QtMocHelpers::SignalData<void()>(3, 2, QMC::AccessPublic, QMetaType::Void),
        // Signal 'playModeChanged'
        QtMocHelpers::SignalData<void()>(4, 2, QMC::AccessPublic, QMetaType::Void),
        // Signal 'slotSecondsChanged'
        QtMocHelpers::SignalData<void()>(5, 2, QMC::AccessPublic, QMetaType::Void),
        // Signal 'videoAsIdleChanged'
        QtMocHelpers::SignalData<void()>(6, 2, QMC::AccessPublic, QMetaType::Void),
        // Signal 'autoStartChanged'
        QtMocHelpers::SignalData<void()>(7, 2, QMC::AccessPublic, QMetaType::Void),
        // Signal 'launchMinimizedChanged'
        QtMocHelpers::SignalData<void()>(8, 2, QMC::AccessPublic, QMetaType::Void),
        // Signal 'screenTargetChanged'
        QtMocHelpers::SignalData<void()>(9, 2, QMC::AccessPublic, QMetaType::Void),
        // Signal 'rendererRunningChanged'
        QtMocHelpers::SignalData<void()>(10, 2, QMC::AccessPublic, QMetaType::Void),
        // Signal 'systemActiveChanged'
        QtMocHelpers::SignalData<void()>(11, 2, QMC::AccessPublic, QMetaType::Void),
        // Signal 'currentPresetIndexChanged'
        QtMocHelpers::SignalData<void()>(12, 2, QMC::AccessPublic, QMetaType::Void),
        // Signal 'currentPresetChanged'
        QtMocHelpers::SignalData<void()>(13, 2, QMC::AccessPublic, QMetaType::Void),
        // Signal 'configLoaded'
        QtMocHelpers::SignalData<void()>(14, 2, QMC::AccessPublic, QMetaType::Void),
        // Signal 'configSaved'
        QtMocHelpers::SignalData<void()>(15, 2, QMC::AccessPublic, QMetaType::Void),
        // Signal 'rendererStarted'
        QtMocHelpers::SignalData<void()>(16, 2, QMC::AccessPublic, QMetaType::Void),
        // Signal 'rendererStopped'
        QtMocHelpers::SignalData<void()>(17, 2, QMC::AccessPublic, QMetaType::Void),
        // Signal 'rendererError'
        QtMocHelpers::SignalData<void(const QString &)>(18, 2, QMC::AccessPublic, QMetaType::Void, {{
            { QMetaType::QString, 19 },
        }}),
        // Signal 'currentListChanged'
        QtMocHelpers::SignalData<void()>(20, 2, QMC::AccessPublic, QMetaType::Void),
        // Signal 'followMouseChanged'
        QtMocHelpers::SignalData<void()>(21, 2, QMC::AccessPublic, QMetaType::Void),
        // Signal 'randomPathChanged'
        QtMocHelpers::SignalData<void()>(22, 2, QMC::AccessPublic, QMetaType::Void),
        // Signal 'animationSpeedChanged'
        QtMocHelpers::SignalData<void()>(23, 2, QMC::AccessPublic, QMetaType::Void),
        // Signal 'screenSwallowChanged'
        QtMocHelpers::SignalData<void()>(24, 2, QMC::AccessPublic, QMetaType::Void),
        // Signal 'distortionChanged'
        QtMocHelpers::SignalData<void()>(25, 2, QMC::AccessPublic, QMetaType::Void),
        // Signal 'holeSizeChanged'
        QtMocHelpers::SignalData<void()>(26, 2, QMC::AccessPublic, QMetaType::Void),
        // Signal 'growEnabledChanged'
        QtMocHelpers::SignalData<void()>(27, 2, QMC::AccessPublic, QMetaType::Void),
        // Signal 'initialSizeChanged'
        QtMocHelpers::SignalData<void()>(28, 2, QMC::AccessPublic, QMetaType::Void),
        // Signal 'idleWhitelistChanged'
        QtMocHelpers::SignalData<void()>(29, 2, QMC::AccessPublic, QMetaType::Void),
        // Signal 'idleBlacklistChanged'
        QtMocHelpers::SignalData<void()>(30, 2, QMC::AccessPublic, QMetaType::Void),
        // Signal 'scheduleEnabledChanged'
        QtMocHelpers::SignalData<void()>(31, 2, QMC::AccessPublic, QMetaType::Void),
        // Signal 'startHourChanged'
        QtMocHelpers::SignalData<void()>(32, 2, QMC::AccessPublic, QMetaType::Void),
        // Signal 'startMinuteChanged'
        QtMocHelpers::SignalData<void()>(33, 2, QMC::AccessPublic, QMetaType::Void),
        // Signal 'endHourChanged'
        QtMocHelpers::SignalData<void()>(34, 2, QMC::AccessPublic, QMetaType::Void),
        // Signal 'endMinuteChanged'
        QtMocHelpers::SignalData<void()>(35, 2, QMC::AccessPublic, QMetaType::Void),
        // Signal 'countdownEnabledChanged'
        QtMocHelpers::SignalData<void()>(36, 2, QMC::AccessPublic, QMetaType::Void),
        // Signal 'countdownMinutesChanged'
        QtMocHelpers::SignalData<void()>(37, 2, QMC::AccessPublic, QMetaType::Void),
        // Signal 'isDarkChanged'
        QtMocHelpers::SignalData<void()>(38, 2, QMC::AccessPublic, QMetaType::Void),
        // Signal 'followSystemChanged'
        QtMocHelpers::SignalData<void()>(39, 2, QMC::AccessPublic, QMetaType::Void),
        // Signal 'focusColorChanged'
        QtMocHelpers::SignalData<void()>(40, 2, QMC::AccessPublic, QMetaType::Void),
        // Signal 'skipExitDialogChanged'
        QtMocHelpers::SignalData<void()>(41, 2, QMC::AccessPublic, QMetaType::Void),
        // Signal 'defaultCloseActionChanged'
        QtMocHelpers::SignalData<void()>(42, 2, QMC::AccessPublic, QMetaType::Void),
        // Signal 'overrideHoleRadiusChanged'
        QtMocHelpers::SignalData<void()>(43, 2, QMC::AccessPublic, QMetaType::Void),
        // Signal 'overrideDiskGainChanged'
        QtMocHelpers::SignalData<void()>(44, 2, QMC::AccessPublic, QMetaType::Void),
        // Signal 'overrideDiskTempChanged'
        QtMocHelpers::SignalData<void()>(45, 2, QMC::AccessPublic, QMetaType::Void),
        // Signal 'overrideExposureChanged'
        QtMocHelpers::SignalData<void()>(46, 2, QMC::AccessPublic, QMetaType::Void),
        // Signal 'overrideSpdChanged'
        QtMocHelpers::SignalData<void()>(47, 2, QMC::AccessPublic, QMetaType::Void),
        // Signal 'overrideStarGainChanged'
        QtMocHelpers::SignalData<void()>(48, 2, QMC::AccessPublic, QMetaType::Void),
        // Signal 'overrideDiskInclChanged'
        QtMocHelpers::SignalData<void()>(49, 2, QMC::AccessPublic, QMetaType::Void),
        // Slot 'loadConfig'
        QtMocHelpers::SlotData<void()>(50, 2, QMC::AccessPublic, QMetaType::Void),
        // Slot 'saveConfig'
        QtMocHelpers::SlotData<void()>(51, 2, QMC::AccessPublic, QMetaType::Void),
        // Slot 'resetDefaults'
        QtMocHelpers::SlotData<void()>(52, 2, QMC::AccessPublic, QMetaType::Void),
        // Slot 'startRenderer'
        QtMocHelpers::SlotData<void()>(53, 2, QMC::AccessPublic, QMetaType::Void),
        // Slot 'stopRenderer'
        QtMocHelpers::SlotData<void()>(54, 2, QMC::AccessPublic, QMetaType::Void),
        // Slot 'applyAndStart'
        QtMocHelpers::SlotData<void()>(55, 2, QMC::AccessPublic, QMetaType::Void),
        // Slot 'stopAll'
        QtMocHelpers::SlotData<void()>(56, 2, QMC::AccessPublic, QMetaType::Void),
        // Slot 'selectPreset'
        QtMocHelpers::SlotData<void(int)>(57, 2, QMC::AccessPublic, QMetaType::Void, {{
            { QMetaType::Int, 58 },
        }}),
        // Slot 'updatePresetParam'
        QtMocHelpers::SlotData<void(int, const QString &, float)>(59, 2, QMC::AccessPublic, QMetaType::Void, {{
            { QMetaType::Int, 58 }, { QMetaType::QString, 60 }, { QMetaType::Float, 61 },
        }}),
        // Slot 'updateCurrentPresetParam'
        QtMocHelpers::SlotData<void(const QString &, float)>(62, 2, QMC::AccessPublic, QMetaType::Void, {{
            { QMetaType::QString, 60 }, { QMetaType::Float, 61 },
        }}),
        // Slot 'movePreset'
        QtMocHelpers::SlotData<void(int, int)>(63, 2, QMC::AccessPublic, QMetaType::Void, {{
            { QMetaType::Int, 64 }, { QMetaType::Int, 65 },
        }}),
        // Slot 'copyPreset'
        QtMocHelpers::SlotData<void(int)>(66, 2, QMC::AccessPublic, QMetaType::Void, {{
            { QMetaType::Int, 58 },
        }}),
        // Slot 'pastePreset'
        QtMocHelpers::SlotData<void()>(67, 2, QMC::AccessPublic, QMetaType::Void),
        // Slot 'removePreset'
        QtMocHelpers::SlotData<void(int)>(68, 2, QMC::AccessPublic, QMetaType::Void, {{
            { QMetaType::Int, 58 },
        }}),
        // Slot 'createPresetList'
        QtMocHelpers::SlotData<void(const QString &)>(69, 2, QMC::AccessPublic, QMetaType::Void, {{
            { QMetaType::QString, 70 },
        }}),
        // Slot 'renameCurrentList'
        QtMocHelpers::SlotData<void(const QString &)>(71, 2, QMC::AccessPublic, QMetaType::Void, {{
            { QMetaType::QString, 70 },
        }}),
        // Slot 'switchToList'
        QtMocHelpers::SlotData<void(int)>(72, 2, QMC::AccessPublic, QMetaType::Void, {{
            { QMetaType::Int, 58 },
        }}),
        // Slot 'deleteCurrentList'
        QtMocHelpers::SlotData<void()>(73, 2, QMC::AccessPublic, QMetaType::Void),
        // Slot 'createPreset'
        QtMocHelpers::SlotData<void()>(74, 2, QMC::AccessPublic, QMetaType::Void),
        // Slot 'renameCurrentPreset'
        QtMocHelpers::SlotData<void(const QString &)>(75, 2, QMC::AccessPublic, QMetaType::Void, {{
            { QMetaType::QString, 70 },
        }}),
        // Slot 'checkIdle'
        QtMocHelpers::SlotData<void()>(76, 2, QMC::AccessPrivate, QMetaType::Void),
    };
    QtMocHelpers::UintData qt_properties {
        // property 'displayMode'
        QtMocHelpers::PropertyData<int>(77, QMetaType::Int, QMC::DefaultPropertyFlags | QMC::Writable | QMC::StdCppSet, 0),
        // property 'idleSeconds'
        QtMocHelpers::PropertyData<int>(78, QMetaType::Int, QMC::DefaultPropertyFlags | QMC::Writable | QMC::StdCppSet, 1),
        // property 'playMode'
        QtMocHelpers::PropertyData<int>(79, QMetaType::Int, QMC::DefaultPropertyFlags | QMC::Writable | QMC::StdCppSet, 2),
        // property 'slotSeconds'
        QtMocHelpers::PropertyData<float>(80, QMetaType::Float, QMC::DefaultPropertyFlags | QMC::Writable | QMC::StdCppSet, 3),
        // property 'videoAsIdle'
        QtMocHelpers::PropertyData<bool>(81, QMetaType::Bool, QMC::DefaultPropertyFlags | QMC::Writable | QMC::StdCppSet, 4),
        // property 'autoStart'
        QtMocHelpers::PropertyData<bool>(82, QMetaType::Bool, QMC::DefaultPropertyFlags | QMC::Writable | QMC::StdCppSet, 5),
        // property 'launchMinimized'
        QtMocHelpers::PropertyData<bool>(83, QMetaType::Bool, QMC::DefaultPropertyFlags | QMC::Writable | QMC::StdCppSet, 6),
        // property 'screenTarget'
        QtMocHelpers::PropertyData<int>(84, QMetaType::Int, QMC::DefaultPropertyFlags | QMC::Writable | QMC::StdCppSet, 7),
        // property 'rendererRunning'
        QtMocHelpers::PropertyData<bool>(85, QMetaType::Bool, QMC::DefaultPropertyFlags, 8),
        // property 'systemActive'
        QtMocHelpers::PropertyData<bool>(86, QMetaType::Bool, QMC::DefaultPropertyFlags, 9),
        // property 'currentPresetIndex'
        QtMocHelpers::PropertyData<int>(87, QMetaType::Int, QMC::DefaultPropertyFlags | QMC::Writable | QMC::StdCppSet, 10),
        // property 'presetModel'
        QtMocHelpers::PropertyData<QAbstractItemModel*>(88, 0x80000000 | 89, QMC::DefaultPropertyFlags | QMC::EnumOrFlag | QMC::Constant),
        // property 'presetListModel'
        QtMocHelpers::PropertyData<QAbstractItemModel*>(90, 0x80000000 | 89, QMC::DefaultPropertyFlags | QMC::EnumOrFlag | QMC::Constant),
        // property 'currentListName'
        QtMocHelpers::PropertyData<QString>(91, QMetaType::QString, QMC::DefaultPropertyFlags, 17),
        // property 'diskTemp'
        QtMocHelpers::PropertyData<float>(92, QMetaType::Float, QMC::DefaultPropertyFlags, 11),
        // property 'diskIncl'
        QtMocHelpers::PropertyData<float>(93, QMetaType::Float, QMC::DefaultPropertyFlags, 11),
        // property 'diskRoll'
        QtMocHelpers::PropertyData<float>(94, QMetaType::Float, QMC::DefaultPropertyFlags, 11),
        // property 'diskInner'
        QtMocHelpers::PropertyData<float>(95, QMetaType::Float, QMC::DefaultPropertyFlags, 11),
        // property 'diskOuter'
        QtMocHelpers::PropertyData<float>(96, QMetaType::Float, QMC::DefaultPropertyFlags, 11),
        // property 'diskOpac'
        QtMocHelpers::PropertyData<float>(97, QMetaType::Float, QMC::DefaultPropertyFlags, 11),
        // property 'diskDopp'
        QtMocHelpers::PropertyData<float>(98, QMetaType::Float, QMC::DefaultPropertyFlags, 11),
        // property 'diskBeam'
        QtMocHelpers::PropertyData<float>(99, QMetaType::Float, QMC::DefaultPropertyFlags, 11),
        // property 'diskGain'
        QtMocHelpers::PropertyData<float>(100, QMetaType::Float, QMC::DefaultPropertyFlags, 11),
        // property 'diskContr'
        QtMocHelpers::PropertyData<float>(101, QMetaType::Float, QMC::DefaultPropertyFlags, 11),
        // property 'diskWind'
        QtMocHelpers::PropertyData<float>(102, QMetaType::Float, QMC::DefaultPropertyFlags, 11),
        // property 'diskSpeed'
        QtMocHelpers::PropertyData<float>(103, QMetaType::Float, QMC::DefaultPropertyFlags, 11),
        // property 'diskExpo'
        QtMocHelpers::PropertyData<float>(104, QMetaType::Float, QMC::DefaultPropertyFlags, 11),
        // property 'diskStar'
        QtMocHelpers::PropertyData<float>(105, QMetaType::Float, QMC::DefaultPropertyFlags, 11),
        // property 'followMouse'
        QtMocHelpers::PropertyData<bool>(106, QMetaType::Bool, QMC::DefaultPropertyFlags | QMC::Writable | QMC::StdCppSet, 18),
        // property 'randomPath'
        QtMocHelpers::PropertyData<bool>(107, QMetaType::Bool, QMC::DefaultPropertyFlags | QMC::Writable | QMC::StdCppSet, 19),
        // property 'animationSpeed'
        QtMocHelpers::PropertyData<int>(108, QMetaType::Int, QMC::DefaultPropertyFlags | QMC::Writable | QMC::StdCppSet, 20),
        // property 'screenSwallow'
        QtMocHelpers::PropertyData<bool>(109, QMetaType::Bool, QMC::DefaultPropertyFlags | QMC::Writable | QMC::StdCppSet, 21),
        // property 'distortion'
        QtMocHelpers::PropertyData<float>(110, QMetaType::Float, QMC::DefaultPropertyFlags | QMC::Writable | QMC::StdCppSet, 22),
        // property 'holeSize'
        QtMocHelpers::PropertyData<float>(111, QMetaType::Float, QMC::DefaultPropertyFlags | QMC::Writable | QMC::StdCppSet, 23),
        // property 'growEnabled'
        QtMocHelpers::PropertyData<bool>(112, QMetaType::Bool, QMC::DefaultPropertyFlags | QMC::Writable | QMC::StdCppSet, 24),
        // property 'initialSize'
        QtMocHelpers::PropertyData<float>(113, QMetaType::Float, QMC::DefaultPropertyFlags | QMC::Writable | QMC::StdCppSet, 25),
        // property 'idleWhitelist'
        QtMocHelpers::PropertyData<QStringList>(114, QMetaType::QStringList, QMC::DefaultPropertyFlags | QMC::Writable | QMC::StdCppSet, 26),
        // property 'idleBlacklist'
        QtMocHelpers::PropertyData<QStringList>(115, QMetaType::QStringList, QMC::DefaultPropertyFlags | QMC::Writable | QMC::StdCppSet, 27),
        // property 'scheduleEnabled'
        QtMocHelpers::PropertyData<bool>(116, QMetaType::Bool, QMC::DefaultPropertyFlags | QMC::Writable | QMC::StdCppSet, 28),
        // property 'startHour'
        QtMocHelpers::PropertyData<int>(117, QMetaType::Int, QMC::DefaultPropertyFlags | QMC::Writable | QMC::StdCppSet, 29),
        // property 'startMinute'
        QtMocHelpers::PropertyData<int>(118, QMetaType::Int, QMC::DefaultPropertyFlags | QMC::Writable | QMC::StdCppSet, 30),
        // property 'endHour'
        QtMocHelpers::PropertyData<int>(119, QMetaType::Int, QMC::DefaultPropertyFlags | QMC::Writable | QMC::StdCppSet, 31),
        // property 'endMinute'
        QtMocHelpers::PropertyData<int>(120, QMetaType::Int, QMC::DefaultPropertyFlags | QMC::Writable | QMC::StdCppSet, 32),
        // property 'countdownEnabled'
        QtMocHelpers::PropertyData<bool>(121, QMetaType::Bool, QMC::DefaultPropertyFlags | QMC::Writable | QMC::StdCppSet, 33),
        // property 'countdownMinutes'
        QtMocHelpers::PropertyData<int>(122, QMetaType::Int, QMC::DefaultPropertyFlags | QMC::Writable | QMC::StdCppSet, 34),
        // property 'isDark'
        QtMocHelpers::PropertyData<bool>(123, QMetaType::Bool, QMC::DefaultPropertyFlags | QMC::Writable | QMC::StdCppSet, 35),
        // property 'followSystem'
        QtMocHelpers::PropertyData<bool>(124, QMetaType::Bool, QMC::DefaultPropertyFlags | QMC::Writable | QMC::StdCppSet, 36),
        // property 'focusColor'
        QtMocHelpers::PropertyData<QColor>(125, 0x80000000 | 126, QMC::DefaultPropertyFlags | QMC::Writable | QMC::EnumOrFlag | QMC::StdCppSet, 37),
        // property 'skipExitDialog'
        QtMocHelpers::PropertyData<bool>(127, QMetaType::Bool, QMC::DefaultPropertyFlags | QMC::Writable | QMC::StdCppSet, 38),
        // property 'defaultCloseAction'
        QtMocHelpers::PropertyData<int>(128, QMetaType::Int, QMC::DefaultPropertyFlags | QMC::Writable | QMC::StdCppSet, 39),
        // property 'overrideHoleRadius'
        QtMocHelpers::PropertyData<float>(129, QMetaType::Float, QMC::DefaultPropertyFlags | QMC::Writable | QMC::StdCppSet, 40),
        // property 'overrideDiskGain'
        QtMocHelpers::PropertyData<float>(130, QMetaType::Float, QMC::DefaultPropertyFlags | QMC::Writable | QMC::StdCppSet, 41),
        // property 'overrideDiskTemp'
        QtMocHelpers::PropertyData<float>(131, QMetaType::Float, QMC::DefaultPropertyFlags | QMC::Writable | QMC::StdCppSet, 42),
        // property 'overrideExposure'
        QtMocHelpers::PropertyData<float>(132, QMetaType::Float, QMC::DefaultPropertyFlags | QMC::Writable | QMC::StdCppSet, 43),
        // property 'overrideSpd'
        QtMocHelpers::PropertyData<float>(133, QMetaType::Float, QMC::DefaultPropertyFlags | QMC::Writable | QMC::StdCppSet, 44),
        // property 'overrideStarGain'
        QtMocHelpers::PropertyData<float>(134, QMetaType::Float, QMC::DefaultPropertyFlags | QMC::Writable | QMC::StdCppSet, 45),
        // property 'overrideDiskIncl'
        QtMocHelpers::PropertyData<float>(135, QMetaType::Float, QMC::DefaultPropertyFlags | QMC::Writable | QMC::StdCppSet, 46),
    };
    QtMocHelpers::UintData qt_enums {
    };
    return QtMocHelpers::metaObjectData<BlackHoleCore, qt_meta_tag_ZN13BlackHoleCoreE_t>(QMC::MetaObjectFlag{}, qt_stringData,
            qt_methods, qt_properties, qt_enums);
}
Q_CONSTINIT const QMetaObject BlackHoleCore::staticMetaObject = { {
    QMetaObject::SuperData::link<QObject::staticMetaObject>(),
    qt_staticMetaObjectStaticContent<qt_meta_tag_ZN13BlackHoleCoreE_t>.stringdata,
    qt_staticMetaObjectStaticContent<qt_meta_tag_ZN13BlackHoleCoreE_t>.data,
    qt_static_metacall,
    nullptr,
    qt_staticMetaObjectRelocatingContent<qt_meta_tag_ZN13BlackHoleCoreE_t>.metaTypes,
    nullptr
} };

void BlackHoleCore::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    auto *_t = static_cast<BlackHoleCore *>(_o);
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: _t->displayModeChanged(); break;
        case 1: _t->idleSecondsChanged(); break;
        case 2: _t->playModeChanged(); break;
        case 3: _t->slotSecondsChanged(); break;
        case 4: _t->videoAsIdleChanged(); break;
        case 5: _t->autoStartChanged(); break;
        case 6: _t->launchMinimizedChanged(); break;
        case 7: _t->screenTargetChanged(); break;
        case 8: _t->rendererRunningChanged(); break;
        case 9: _t->systemActiveChanged(); break;
        case 10: _t->currentPresetIndexChanged(); break;
        case 11: _t->currentPresetChanged(); break;
        case 12: _t->configLoaded(); break;
        case 13: _t->configSaved(); break;
        case 14: _t->rendererStarted(); break;
        case 15: _t->rendererStopped(); break;
        case 16: _t->rendererError((*reinterpret_cast<std::add_pointer_t<QString>>(_a[1]))); break;
        case 17: _t->currentListChanged(); break;
        case 18: _t->followMouseChanged(); break;
        case 19: _t->randomPathChanged(); break;
        case 20: _t->animationSpeedChanged(); break;
        case 21: _t->screenSwallowChanged(); break;
        case 22: _t->distortionChanged(); break;
        case 23: _t->holeSizeChanged(); break;
        case 24: _t->growEnabledChanged(); break;
        case 25: _t->initialSizeChanged(); break;
        case 26: _t->idleWhitelistChanged(); break;
        case 27: _t->idleBlacklistChanged(); break;
        case 28: _t->scheduleEnabledChanged(); break;
        case 29: _t->startHourChanged(); break;
        case 30: _t->startMinuteChanged(); break;
        case 31: _t->endHourChanged(); break;
        case 32: _t->endMinuteChanged(); break;
        case 33: _t->countdownEnabledChanged(); break;
        case 34: _t->countdownMinutesChanged(); break;
        case 35: _t->isDarkChanged(); break;
        case 36: _t->followSystemChanged(); break;
        case 37: _t->focusColorChanged(); break;
        case 38: _t->skipExitDialogChanged(); break;
        case 39: _t->defaultCloseActionChanged(); break;
        case 40: _t->overrideHoleRadiusChanged(); break;
        case 41: _t->overrideDiskGainChanged(); break;
        case 42: _t->overrideDiskTempChanged(); break;
        case 43: _t->overrideExposureChanged(); break;
        case 44: _t->overrideSpdChanged(); break;
        case 45: _t->overrideStarGainChanged(); break;
        case 46: _t->overrideDiskInclChanged(); break;
        case 47: _t->loadConfig(); break;
        case 48: _t->saveConfig(); break;
        case 49: _t->resetDefaults(); break;
        case 50: _t->startRenderer(); break;
        case 51: _t->stopRenderer(); break;
        case 52: _t->applyAndStart(); break;
        case 53: _t->stopAll(); break;
        case 54: _t->selectPreset((*reinterpret_cast<std::add_pointer_t<int>>(_a[1]))); break;
        case 55: _t->updatePresetParam((*reinterpret_cast<std::add_pointer_t<int>>(_a[1])),(*reinterpret_cast<std::add_pointer_t<QString>>(_a[2])),(*reinterpret_cast<std::add_pointer_t<float>>(_a[3]))); break;
        case 56: _t->updateCurrentPresetParam((*reinterpret_cast<std::add_pointer_t<QString>>(_a[1])),(*reinterpret_cast<std::add_pointer_t<float>>(_a[2]))); break;
        case 57: _t->movePreset((*reinterpret_cast<std::add_pointer_t<int>>(_a[1])),(*reinterpret_cast<std::add_pointer_t<int>>(_a[2]))); break;
        case 58: _t->copyPreset((*reinterpret_cast<std::add_pointer_t<int>>(_a[1]))); break;
        case 59: _t->pastePreset(); break;
        case 60: _t->removePreset((*reinterpret_cast<std::add_pointer_t<int>>(_a[1]))); break;
        case 61: _t->createPresetList((*reinterpret_cast<std::add_pointer_t<QString>>(_a[1]))); break;
        case 62: _t->renameCurrentList((*reinterpret_cast<std::add_pointer_t<QString>>(_a[1]))); break;
        case 63: _t->switchToList((*reinterpret_cast<std::add_pointer_t<int>>(_a[1]))); break;
        case 64: _t->deleteCurrentList(); break;
        case 65: _t->createPreset(); break;
        case 66: _t->renameCurrentPreset((*reinterpret_cast<std::add_pointer_t<QString>>(_a[1]))); break;
        case 67: _t->checkIdle(); break;
        default: ;
        }
    }
    if (_c == QMetaObject::IndexOfMethod) {
        if (QtMocHelpers::indexOfMethod<void (BlackHoleCore::*)()>(_a, &BlackHoleCore::displayModeChanged, 0))
            return;
        if (QtMocHelpers::indexOfMethod<void (BlackHoleCore::*)()>(_a, &BlackHoleCore::idleSecondsChanged, 1))
            return;
        if (QtMocHelpers::indexOfMethod<void (BlackHoleCore::*)()>(_a, &BlackHoleCore::playModeChanged, 2))
            return;
        if (QtMocHelpers::indexOfMethod<void (BlackHoleCore::*)()>(_a, &BlackHoleCore::slotSecondsChanged, 3))
            return;
        if (QtMocHelpers::indexOfMethod<void (BlackHoleCore::*)()>(_a, &BlackHoleCore::videoAsIdleChanged, 4))
            return;
        if (QtMocHelpers::indexOfMethod<void (BlackHoleCore::*)()>(_a, &BlackHoleCore::autoStartChanged, 5))
            return;
        if (QtMocHelpers::indexOfMethod<void (BlackHoleCore::*)()>(_a, &BlackHoleCore::launchMinimizedChanged, 6))
            return;
        if (QtMocHelpers::indexOfMethod<void (BlackHoleCore::*)()>(_a, &BlackHoleCore::screenTargetChanged, 7))
            return;
        if (QtMocHelpers::indexOfMethod<void (BlackHoleCore::*)()>(_a, &BlackHoleCore::rendererRunningChanged, 8))
            return;
        if (QtMocHelpers::indexOfMethod<void (BlackHoleCore::*)()>(_a, &BlackHoleCore::systemActiveChanged, 9))
            return;
        if (QtMocHelpers::indexOfMethod<void (BlackHoleCore::*)()>(_a, &BlackHoleCore::currentPresetIndexChanged, 10))
            return;
        if (QtMocHelpers::indexOfMethod<void (BlackHoleCore::*)()>(_a, &BlackHoleCore::currentPresetChanged, 11))
            return;
        if (QtMocHelpers::indexOfMethod<void (BlackHoleCore::*)()>(_a, &BlackHoleCore::configLoaded, 12))
            return;
        if (QtMocHelpers::indexOfMethod<void (BlackHoleCore::*)()>(_a, &BlackHoleCore::configSaved, 13))
            return;
        if (QtMocHelpers::indexOfMethod<void (BlackHoleCore::*)()>(_a, &BlackHoleCore::rendererStarted, 14))
            return;
        if (QtMocHelpers::indexOfMethod<void (BlackHoleCore::*)()>(_a, &BlackHoleCore::rendererStopped, 15))
            return;
        if (QtMocHelpers::indexOfMethod<void (BlackHoleCore::*)(const QString & )>(_a, &BlackHoleCore::rendererError, 16))
            return;
        if (QtMocHelpers::indexOfMethod<void (BlackHoleCore::*)()>(_a, &BlackHoleCore::currentListChanged, 17))
            return;
        if (QtMocHelpers::indexOfMethod<void (BlackHoleCore::*)()>(_a, &BlackHoleCore::followMouseChanged, 18))
            return;
        if (QtMocHelpers::indexOfMethod<void (BlackHoleCore::*)()>(_a, &BlackHoleCore::randomPathChanged, 19))
            return;
        if (QtMocHelpers::indexOfMethod<void (BlackHoleCore::*)()>(_a, &BlackHoleCore::animationSpeedChanged, 20))
            return;
        if (QtMocHelpers::indexOfMethod<void (BlackHoleCore::*)()>(_a, &BlackHoleCore::screenSwallowChanged, 21))
            return;
        if (QtMocHelpers::indexOfMethod<void (BlackHoleCore::*)()>(_a, &BlackHoleCore::distortionChanged, 22))
            return;
        if (QtMocHelpers::indexOfMethod<void (BlackHoleCore::*)()>(_a, &BlackHoleCore::holeSizeChanged, 23))
            return;
        if (QtMocHelpers::indexOfMethod<void (BlackHoleCore::*)()>(_a, &BlackHoleCore::growEnabledChanged, 24))
            return;
        if (QtMocHelpers::indexOfMethod<void (BlackHoleCore::*)()>(_a, &BlackHoleCore::initialSizeChanged, 25))
            return;
        if (QtMocHelpers::indexOfMethod<void (BlackHoleCore::*)()>(_a, &BlackHoleCore::idleWhitelistChanged, 26))
            return;
        if (QtMocHelpers::indexOfMethod<void (BlackHoleCore::*)()>(_a, &BlackHoleCore::idleBlacklistChanged, 27))
            return;
        if (QtMocHelpers::indexOfMethod<void (BlackHoleCore::*)()>(_a, &BlackHoleCore::scheduleEnabledChanged, 28))
            return;
        if (QtMocHelpers::indexOfMethod<void (BlackHoleCore::*)()>(_a, &BlackHoleCore::startHourChanged, 29))
            return;
        if (QtMocHelpers::indexOfMethod<void (BlackHoleCore::*)()>(_a, &BlackHoleCore::startMinuteChanged, 30))
            return;
        if (QtMocHelpers::indexOfMethod<void (BlackHoleCore::*)()>(_a, &BlackHoleCore::endHourChanged, 31))
            return;
        if (QtMocHelpers::indexOfMethod<void (BlackHoleCore::*)()>(_a, &BlackHoleCore::endMinuteChanged, 32))
            return;
        if (QtMocHelpers::indexOfMethod<void (BlackHoleCore::*)()>(_a, &BlackHoleCore::countdownEnabledChanged, 33))
            return;
        if (QtMocHelpers::indexOfMethod<void (BlackHoleCore::*)()>(_a, &BlackHoleCore::countdownMinutesChanged, 34))
            return;
        if (QtMocHelpers::indexOfMethod<void (BlackHoleCore::*)()>(_a, &BlackHoleCore::isDarkChanged, 35))
            return;
        if (QtMocHelpers::indexOfMethod<void (BlackHoleCore::*)()>(_a, &BlackHoleCore::followSystemChanged, 36))
            return;
        if (QtMocHelpers::indexOfMethod<void (BlackHoleCore::*)()>(_a, &BlackHoleCore::focusColorChanged, 37))
            return;
        if (QtMocHelpers::indexOfMethod<void (BlackHoleCore::*)()>(_a, &BlackHoleCore::skipExitDialogChanged, 38))
            return;
        if (QtMocHelpers::indexOfMethod<void (BlackHoleCore::*)()>(_a, &BlackHoleCore::defaultCloseActionChanged, 39))
            return;
        if (QtMocHelpers::indexOfMethod<void (BlackHoleCore::*)()>(_a, &BlackHoleCore::overrideHoleRadiusChanged, 40))
            return;
        if (QtMocHelpers::indexOfMethod<void (BlackHoleCore::*)()>(_a, &BlackHoleCore::overrideDiskGainChanged, 41))
            return;
        if (QtMocHelpers::indexOfMethod<void (BlackHoleCore::*)()>(_a, &BlackHoleCore::overrideDiskTempChanged, 42))
            return;
        if (QtMocHelpers::indexOfMethod<void (BlackHoleCore::*)()>(_a, &BlackHoleCore::overrideExposureChanged, 43))
            return;
        if (QtMocHelpers::indexOfMethod<void (BlackHoleCore::*)()>(_a, &BlackHoleCore::overrideSpdChanged, 44))
            return;
        if (QtMocHelpers::indexOfMethod<void (BlackHoleCore::*)()>(_a, &BlackHoleCore::overrideStarGainChanged, 45))
            return;
        if (QtMocHelpers::indexOfMethod<void (BlackHoleCore::*)()>(_a, &BlackHoleCore::overrideDiskInclChanged, 46))
            return;
    }
    if (_c == QMetaObject::RegisterPropertyMetaType) {
        switch (_id) {
        default: *reinterpret_cast<int*>(_a[0]) = -1; break;
        case 12:
        case 11:
            *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< QAbstractItemModel* >(); break;
        }
    }
    if (_c == QMetaObject::ReadProperty) {
        void *_v = _a[0];
        switch (_id) {
        case 0: *reinterpret_cast<int*>(_v) = _t->displayMode(); break;
        case 1: *reinterpret_cast<int*>(_v) = _t->idleSeconds(); break;
        case 2: *reinterpret_cast<int*>(_v) = _t->playMode(); break;
        case 3: *reinterpret_cast<float*>(_v) = _t->slotSeconds(); break;
        case 4: *reinterpret_cast<bool*>(_v) = _t->videoAsIdle(); break;
        case 5: *reinterpret_cast<bool*>(_v) = _t->autoStart(); break;
        case 6: *reinterpret_cast<bool*>(_v) = _t->launchMinimized(); break;
        case 7: *reinterpret_cast<int*>(_v) = _t->screenTarget(); break;
        case 8: *reinterpret_cast<bool*>(_v) = _t->rendererRunning(); break;
        case 9: *reinterpret_cast<bool*>(_v) = _t->isSystemActive(); break;
        case 10: *reinterpret_cast<int*>(_v) = _t->currentPresetIndex(); break;
        case 11: *reinterpret_cast<QAbstractItemModel**>(_v) = _t->presetModel(); break;
        case 12: *reinterpret_cast<QAbstractItemModel**>(_v) = _t->presetListModel(); break;
        case 13: *reinterpret_cast<QString*>(_v) = _t->currentListName(); break;
        case 14: *reinterpret_cast<float*>(_v) = _t->diskTemp(); break;
        case 15: *reinterpret_cast<float*>(_v) = _t->diskIncl(); break;
        case 16: *reinterpret_cast<float*>(_v) = _t->diskRoll(); break;
        case 17: *reinterpret_cast<float*>(_v) = _t->diskInner(); break;
        case 18: *reinterpret_cast<float*>(_v) = _t->diskOuter(); break;
        case 19: *reinterpret_cast<float*>(_v) = _t->diskOpac(); break;
        case 20: *reinterpret_cast<float*>(_v) = _t->diskDopp(); break;
        case 21: *reinterpret_cast<float*>(_v) = _t->diskBeam(); break;
        case 22: *reinterpret_cast<float*>(_v) = _t->diskGain(); break;
        case 23: *reinterpret_cast<float*>(_v) = _t->diskContr(); break;
        case 24: *reinterpret_cast<float*>(_v) = _t->diskWind(); break;
        case 25: *reinterpret_cast<float*>(_v) = _t->diskSpeed(); break;
        case 26: *reinterpret_cast<float*>(_v) = _t->diskExpo(); break;
        case 27: *reinterpret_cast<float*>(_v) = _t->diskStar(); break;
        case 28: *reinterpret_cast<bool*>(_v) = _t->followMouse(); break;
        case 29: *reinterpret_cast<bool*>(_v) = _t->randomPath(); break;
        case 30: *reinterpret_cast<int*>(_v) = _t->animationSpeed(); break;
        case 31: *reinterpret_cast<bool*>(_v) = _t->screenSwallow(); break;
        case 32: *reinterpret_cast<float*>(_v) = _t->distortion(); break;
        case 33: *reinterpret_cast<float*>(_v) = _t->holeSize(); break;
        case 34: *reinterpret_cast<bool*>(_v) = _t->growEnabled(); break;
        case 35: *reinterpret_cast<float*>(_v) = _t->initialSize(); break;
        case 36: *reinterpret_cast<QStringList*>(_v) = _t->idleWhitelist(); break;
        case 37: *reinterpret_cast<QStringList*>(_v) = _t->idleBlacklist(); break;
        case 38: *reinterpret_cast<bool*>(_v) = _t->scheduleEnabled(); break;
        case 39: *reinterpret_cast<int*>(_v) = _t->startHour(); break;
        case 40: *reinterpret_cast<int*>(_v) = _t->startMinute(); break;
        case 41: *reinterpret_cast<int*>(_v) = _t->endHour(); break;
        case 42: *reinterpret_cast<int*>(_v) = _t->endMinute(); break;
        case 43: *reinterpret_cast<bool*>(_v) = _t->countdownEnabled(); break;
        case 44: *reinterpret_cast<int*>(_v) = _t->countdownMinutes(); break;
        case 45: *reinterpret_cast<bool*>(_v) = _t->isDark(); break;
        case 46: *reinterpret_cast<bool*>(_v) = _t->followSystem(); break;
        case 47: *reinterpret_cast<QColor*>(_v) = _t->focusColor(); break;
        case 48: *reinterpret_cast<bool*>(_v) = _t->skipExitDialog(); break;
        case 49: *reinterpret_cast<int*>(_v) = _t->defaultCloseAction(); break;
        case 50: *reinterpret_cast<float*>(_v) = _t->overrideHoleRadius(); break;
        case 51: *reinterpret_cast<float*>(_v) = _t->overrideDiskGain(); break;
        case 52: *reinterpret_cast<float*>(_v) = _t->overrideDiskTemp(); break;
        case 53: *reinterpret_cast<float*>(_v) = _t->overrideExposure(); break;
        case 54: *reinterpret_cast<float*>(_v) = _t->overrideSpd(); break;
        case 55: *reinterpret_cast<float*>(_v) = _t->overrideStarGain(); break;
        case 56: *reinterpret_cast<float*>(_v) = _t->overrideDiskIncl(); break;
        default: break;
        }
    }
    if (_c == QMetaObject::WriteProperty) {
        void *_v = _a[0];
        switch (_id) {
        case 0: _t->setDisplayMode(*reinterpret_cast<int*>(_v)); break;
        case 1: _t->setIdleSeconds(*reinterpret_cast<int*>(_v)); break;
        case 2: _t->setPlayMode(*reinterpret_cast<int*>(_v)); break;
        case 3: _t->setSlotSeconds(*reinterpret_cast<float*>(_v)); break;
        case 4: _t->setVideoAsIdle(*reinterpret_cast<bool*>(_v)); break;
        case 5: _t->setAutoStart(*reinterpret_cast<bool*>(_v)); break;
        case 6: _t->setLaunchMinimized(*reinterpret_cast<bool*>(_v)); break;
        case 7: _t->setScreenTarget(*reinterpret_cast<int*>(_v)); break;
        case 10: _t->setCurrentPresetIndex(*reinterpret_cast<int*>(_v)); break;
        case 28: _t->setFollowMouse(*reinterpret_cast<bool*>(_v)); break;
        case 29: _t->setRandomPath(*reinterpret_cast<bool*>(_v)); break;
        case 30: _t->setAnimationSpeed(*reinterpret_cast<int*>(_v)); break;
        case 31: _t->setScreenSwallow(*reinterpret_cast<bool*>(_v)); break;
        case 32: _t->setDistortion(*reinterpret_cast<float*>(_v)); break;
        case 33: _t->setHoleSize(*reinterpret_cast<float*>(_v)); break;
        case 34: _t->setGrowEnabled(*reinterpret_cast<bool*>(_v)); break;
        case 35: _t->setInitialSize(*reinterpret_cast<float*>(_v)); break;
        case 36: _t->setIdleWhitelist(*reinterpret_cast<QStringList*>(_v)); break;
        case 37: _t->setIdleBlacklist(*reinterpret_cast<QStringList*>(_v)); break;
        case 38: _t->setScheduleEnabled(*reinterpret_cast<bool*>(_v)); break;
        case 39: _t->setStartHour(*reinterpret_cast<int*>(_v)); break;
        case 40: _t->setStartMinute(*reinterpret_cast<int*>(_v)); break;
        case 41: _t->setEndHour(*reinterpret_cast<int*>(_v)); break;
        case 42: _t->setEndMinute(*reinterpret_cast<int*>(_v)); break;
        case 43: _t->setCountdownEnabled(*reinterpret_cast<bool*>(_v)); break;
        case 44: _t->setCountdownMinutes(*reinterpret_cast<int*>(_v)); break;
        case 45: _t->setIsDark(*reinterpret_cast<bool*>(_v)); break;
        case 46: _t->setFollowSystem(*reinterpret_cast<bool*>(_v)); break;
        case 47: _t->setFocusColor(*reinterpret_cast<QColor*>(_v)); break;
        case 48: _t->setSkipExitDialog(*reinterpret_cast<bool*>(_v)); break;
        case 49: _t->setDefaultCloseAction(*reinterpret_cast<int*>(_v)); break;
        case 50: _t->setOverrideHoleRadius(*reinterpret_cast<float*>(_v)); break;
        case 51: _t->setOverrideDiskGain(*reinterpret_cast<float*>(_v)); break;
        case 52: _t->setOverrideDiskTemp(*reinterpret_cast<float*>(_v)); break;
        case 53: _t->setOverrideExposure(*reinterpret_cast<float*>(_v)); break;
        case 54: _t->setOverrideSpd(*reinterpret_cast<float*>(_v)); break;
        case 55: _t->setOverrideStarGain(*reinterpret_cast<float*>(_v)); break;
        case 56: _t->setOverrideDiskIncl(*reinterpret_cast<float*>(_v)); break;
        default: break;
        }
    }
}

const QMetaObject *BlackHoleCore::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *BlackHoleCore::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_staticMetaObjectStaticContent<qt_meta_tag_ZN13BlackHoleCoreE_t>.strings))
        return static_cast<void*>(this);
    return QObject::qt_metacast(_clname);
}

int BlackHoleCore::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 68)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 68;
    }
    if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 68)
            *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType();
        _id -= 68;
    }
    if (_c == QMetaObject::ReadProperty || _c == QMetaObject::WriteProperty
            || _c == QMetaObject::ResetProperty || _c == QMetaObject::BindableProperty
            || _c == QMetaObject::RegisterPropertyMetaType) {
        qt_static_metacall(this, _c, _id, _a);
        _id -= 57;
    }
    return _id;
}

// SIGNAL 0
void BlackHoleCore::displayModeChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 0, nullptr);
}

// SIGNAL 1
void BlackHoleCore::idleSecondsChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 1, nullptr);
}

// SIGNAL 2
void BlackHoleCore::playModeChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 2, nullptr);
}

// SIGNAL 3
void BlackHoleCore::slotSecondsChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 3, nullptr);
}

// SIGNAL 4
void BlackHoleCore::videoAsIdleChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 4, nullptr);
}

// SIGNAL 5
void BlackHoleCore::autoStartChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 5, nullptr);
}

// SIGNAL 6
void BlackHoleCore::launchMinimizedChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 6, nullptr);
}

// SIGNAL 7
void BlackHoleCore::screenTargetChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 7, nullptr);
}

// SIGNAL 8
void BlackHoleCore::rendererRunningChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 8, nullptr);
}

// SIGNAL 9
void BlackHoleCore::systemActiveChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 9, nullptr);
}

// SIGNAL 10
void BlackHoleCore::currentPresetIndexChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 10, nullptr);
}

// SIGNAL 11
void BlackHoleCore::currentPresetChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 11, nullptr);
}

// SIGNAL 12
void BlackHoleCore::configLoaded()
{
    QMetaObject::activate(this, &staticMetaObject, 12, nullptr);
}

// SIGNAL 13
void BlackHoleCore::configSaved()
{
    QMetaObject::activate(this, &staticMetaObject, 13, nullptr);
}

// SIGNAL 14
void BlackHoleCore::rendererStarted()
{
    QMetaObject::activate(this, &staticMetaObject, 14, nullptr);
}

// SIGNAL 15
void BlackHoleCore::rendererStopped()
{
    QMetaObject::activate(this, &staticMetaObject, 15, nullptr);
}

// SIGNAL 16
void BlackHoleCore::rendererError(const QString & _t1)
{
    QMetaObject::activate<void>(this, &staticMetaObject, 16, nullptr, _t1);
}

// SIGNAL 17
void BlackHoleCore::currentListChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 17, nullptr);
}

// SIGNAL 18
void BlackHoleCore::followMouseChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 18, nullptr);
}

// SIGNAL 19
void BlackHoleCore::randomPathChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 19, nullptr);
}

// SIGNAL 20
void BlackHoleCore::animationSpeedChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 20, nullptr);
}

// SIGNAL 21
void BlackHoleCore::screenSwallowChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 21, nullptr);
}

// SIGNAL 22
void BlackHoleCore::distortionChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 22, nullptr);
}

// SIGNAL 23
void BlackHoleCore::holeSizeChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 23, nullptr);
}

// SIGNAL 24
void BlackHoleCore::growEnabledChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 24, nullptr);
}

// SIGNAL 25
void BlackHoleCore::initialSizeChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 25, nullptr);
}

// SIGNAL 26
void BlackHoleCore::idleWhitelistChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 26, nullptr);
}

// SIGNAL 27
void BlackHoleCore::idleBlacklistChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 27, nullptr);
}

// SIGNAL 28
void BlackHoleCore::scheduleEnabledChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 28, nullptr);
}

// SIGNAL 29
void BlackHoleCore::startHourChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 29, nullptr);
}

// SIGNAL 30
void BlackHoleCore::startMinuteChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 30, nullptr);
}

// SIGNAL 31
void BlackHoleCore::endHourChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 31, nullptr);
}

// SIGNAL 32
void BlackHoleCore::endMinuteChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 32, nullptr);
}

// SIGNAL 33
void BlackHoleCore::countdownEnabledChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 33, nullptr);
}

// SIGNAL 34
void BlackHoleCore::countdownMinutesChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 34, nullptr);
}

// SIGNAL 35
void BlackHoleCore::isDarkChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 35, nullptr);
}

// SIGNAL 36
void BlackHoleCore::followSystemChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 36, nullptr);
}

// SIGNAL 37
void BlackHoleCore::focusColorChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 37, nullptr);
}

// SIGNAL 38
void BlackHoleCore::skipExitDialogChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 38, nullptr);
}

// SIGNAL 39
void BlackHoleCore::defaultCloseActionChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 39, nullptr);
}

// SIGNAL 40
void BlackHoleCore::overrideHoleRadiusChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 40, nullptr);
}

// SIGNAL 41
void BlackHoleCore::overrideDiskGainChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 41, nullptr);
}

// SIGNAL 42
void BlackHoleCore::overrideDiskTempChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 42, nullptr);
}

// SIGNAL 43
void BlackHoleCore::overrideExposureChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 43, nullptr);
}

// SIGNAL 44
void BlackHoleCore::overrideSpdChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 44, nullptr);
}

// SIGNAL 45
void BlackHoleCore::overrideStarGainChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 45, nullptr);
}

// SIGNAL 46
void BlackHoleCore::overrideDiskInclChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 46, nullptr);
}
QT_WARNING_POP
