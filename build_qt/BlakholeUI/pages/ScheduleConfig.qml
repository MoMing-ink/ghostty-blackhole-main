// ScheduleConfig.qml — 定时显示设置页面
import QtQuick
import QtQuick.Controls
import QtQuick.Layouts
import ".." as Root
import "../components" as Components

Item {
    id: schedPage

    anchors.fill: parent
    anchors.margins: 20

    property var bhCore: null

    property bool scheduleEnabled: bhCore ? bhCore.scheduleEnabled : false
    property int startHour: bhCore ? bhCore.startHour : 8
    property int startMinute: bhCore ? bhCore.startMinute : 0
    property int endHour: bhCore ? bhCore.endHour : 22
    property int endMinute: bhCore ? bhCore.endMinute : 0
    property bool countdownEnabled: bhCore ? bhCore.countdownEnabled : false
    property int countdownMinutes: bhCore ? bhCore.countdownMinutes : 30

    ColumnLayout {
        anchors.fill: parent
        spacing: 16

        // === 标题 ===
        RowLayout {
            Layout.fillWidth: true
            Text {
                text: "\uf017"
                font.family: iconFont.name
                font.pixelSize: 22
                color: theme.focusColor
            }
            Text {
                text: "定时显示"
                font.pixelSize: 22
                font.bold: true
                color: theme.focusColor
            }
            Item { Layout.fillWidth: true }
        }

        // === 时间段调度 ===
        Rectangle {
            Layout.fillWidth: true
            Layout.preferredHeight: timeCard.implicitHeight + 24
            radius: 16
            color: theme.secondaryColor
            opacity: 0.85

            ColumnLayout {
                id: timeCard
                anchors.fill: parent
                anchors.margins: 20
                spacing: 8

                Text {
                    text: "\uf073  时间段调度"
                    font.family: iconFont.name
                    font.pixelSize: 14
                    color: theme.focusColor
                    font.bold: true
                }

                Rectangle {
                    Layout.fillWidth: true
                    height: 1
                    color: theme.borderColor
                    opacity: 0.2
                }

                // 启用开关
                RowLayout {
                    Layout.fillWidth: true
                    spacing: 12
                    Text {
                        text: "启用定时显示"
                        font.pixelSize: 14
                        color: theme.textColor
                        Layout.fillWidth: true
                    }
                    CheckBox {
                        id: schedCheck
                        checked: schedPage.scheduleEnabled
                        onToggled: {
                            schedPage.scheduleEnabled = checked
                            if (bhCore) bhCore.scheduleEnabled = checked
                        }
                        indicator: Rectangle {
                            implicitWidth: 20; implicitHeight: 20
                            x: schedCheck.leftPadding; y: parent.height / 2 - height / 2
                            radius: 4
                            color: schedCheck.checked ? theme.focusColor : "transparent"
                            border.color: schedCheck.checked ? theme.focusColor : theme.borderColor
                            border.width: 2
                            Behavior on color { ColorAnimation { duration: 120 } }
                            Text {
                                anchors.centerIn: parent; text: "\uf00c"
                                font.family: iconFont.name; font.pixelSize: 12
                                color: "#ffffff"; visible: schedCheck.checked
                            }
                        }
                    }
                }

                // 开始时间
                RowLayout {
                    Layout.fillWidth: true
                    spacing: 12
                    opacity: schedPage.scheduleEnabled ? 1.0 : 0.4
                    enabled: schedPage.scheduleEnabled

                    Text {
                        text: "开始时间"
                        font.pixelSize: 14; color: theme.textColor
                        Layout.preferredWidth: 80
                    }

                    SpinBox {
                        id: startHSpin
                        from: 0; to: 23; value: schedPage.startHour
                        editable: true; width: 70; height: 32
                        textFromValue: function(v, l) { return String(v).padStart(2, "0") }
                        valueFromText: function(t) { return parseInt(t) }
                        onValueChanged: { schedPage.startHour = value; if (bhCore) bhCore.startHour = value }
                        contentItem: TextInput {
                            text: startHSpin.displayText
                            font: startHSpin.font
                            color: theme.textColor
                            selectionColor: theme.focusColor
                            selectedTextColor: "#ffffff"
                            horizontalAlignment: Qt.AlignHCenter
                            verticalAlignment: Qt.AlignVCenter
                            readOnly: !startHSpin.editable
                            validator: startHSpin.validator
                            inputMethodHints: Qt.ImhFormattedNumbersOnly
                        }
                        background: Rectangle {
                            implicitWidth: 70; implicitHeight: 32
                            radius: 6; color: theme.secondaryColor
                            border.color: theme.borderColor; border.width: 1
                        }
                    }

                    Text { text: ":"; font.pixelSize: 16; color: theme.textColor; font.bold: true }

                    SpinBox {
                        id: startMSpin
                        from: 0; to: 59; stepSize: 5; value: schedPage.startMinute
                        editable: true; width: 70; height: 32
                        textFromValue: function(v, l) { return String(v).padStart(2, "0") }
                        valueFromText: function(t) { return parseInt(t) }
                        onValueChanged: { schedPage.startMinute = value; if (bhCore) bhCore.startMinute = value }
                        contentItem: TextInput {
                            text: startMSpin.displayText
                            font: startMSpin.font
                            color: theme.textColor
                            selectionColor: theme.focusColor
                            selectedTextColor: "#ffffff"
                            horizontalAlignment: Qt.AlignHCenter
                            verticalAlignment: Qt.AlignVCenter
                            readOnly: !startMSpin.editable
                            validator: startMSpin.validator
                            inputMethodHints: Qt.ImhFormattedNumbersOnly
                        }
                        background: Rectangle {
                            implicitWidth: 70; implicitHeight: 32
                            radius: 6; color: theme.secondaryColor
                            border.color: theme.borderColor; border.width: 1
                        }
                    }
                }

                // 结束时间
                RowLayout {
                    Layout.fillWidth: true
                    spacing: 12
                    opacity: schedPage.scheduleEnabled ? 1.0 : 0.4
                    enabled: schedPage.scheduleEnabled

                    Text {
                        text: "结束时间"
                        font.pixelSize: 14; color: theme.textColor
                        Layout.preferredWidth: 80
                    }

                    SpinBox {
                        id: endHSpin
                        from: 0; to: 23; value: schedPage.endHour
                        editable: true; width: 70; height: 32
                        textFromValue: function(v, l) { return String(v).padStart(2, "0") }
                        valueFromText: function(t) { return parseInt(t) }
                        onValueChanged: { schedPage.endHour = value; if (bhCore) bhCore.endHour = value }
                        contentItem: TextInput {
                            text: endHSpin.displayText
                            font: endHSpin.font
                            color: theme.textColor
                            selectionColor: theme.focusColor
                            selectedTextColor: "#ffffff"
                            horizontalAlignment: Qt.AlignHCenter
                            verticalAlignment: Qt.AlignVCenter
                            readOnly: !endHSpin.editable
                            validator: endHSpin.validator
                            inputMethodHints: Qt.ImhFormattedNumbersOnly
                        }
                        background: Rectangle {
                            implicitWidth: 70; implicitHeight: 32
                            radius: 6; color: theme.secondaryColor
                            border.color: theme.borderColor; border.width: 1
                        }
                    }

                    Text { text: ":"; font.pixelSize: 16; color: theme.textColor; font.bold: true }

                    SpinBox {
                        id: endMSpin
                        from: 0; to: 59; stepSize: 5; value: schedPage.endMinute
                        editable: true; width: 70; height: 32
                        textFromValue: function(v, l) { return String(v).padStart(2, "0") }
                        valueFromText: function(t) { return parseInt(t) }
                        onValueChanged: { schedPage.endMinute = value; if (bhCore) bhCore.endMinute = value }
                        contentItem: TextInput {
                            text: endMSpin.displayText
                            font: endMSpin.font
                            color: theme.textColor
                            selectionColor: theme.focusColor
                            selectedTextColor: "#ffffff"
                            horizontalAlignment: Qt.AlignHCenter
                            verticalAlignment: Qt.AlignVCenter
                            readOnly: !endMSpin.editable
                            validator: endMSpin.validator
                            inputMethodHints: Qt.ImhFormattedNumbersOnly
                        }
                        background: Rectangle {
                            implicitWidth: 70; implicitHeight: 32
                            radius: 6; color: theme.secondaryColor
                            border.color: theme.borderColor; border.width: 1
                        }
                    }
                }

                // 时段摘要
                Text {
                    text: "黑洞将在 " + String(schedPage.startHour).padStart(2, "0") + ":"
                        + String(schedPage.startMinute).padStart(2, "0") + " — "
                        + String(schedPage.endHour).padStart(2, "0") + ":"
                        + String(schedPage.endMinute).padStart(2, "0") + " 之间显示"
                    font.pixelSize: 12
                    color: Qt.rgba(theme.textColor.r, theme.textColor.g, theme.textColor.b, 0.50)
                    Layout.fillWidth: true
                }
            }
        }

        // === 倒计时模式 ===
        Rectangle {
            Layout.fillWidth: true
            Layout.preferredHeight: cntCard.implicitHeight + 24
            radius: 16
            color: theme.secondaryColor
            opacity: 0.85

            ColumnLayout {
                id: cntCard
                anchors.fill: parent
                anchors.margins: 20
                spacing: 8

                Text {
                    text: "\uf252  倒计时模式"
                    font.family: iconFont.name
                    font.pixelSize: 14
                    color: theme.focusColor
                    font.bold: true
                }

                Rectangle {
                    Layout.fillWidth: true
                    height: 1
                    color: theme.borderColor
                    opacity: 0.2
                }

                RowLayout {
                    Layout.fillWidth: true
                    spacing: 12
                    Text {
                        text: "启用倒计时"
                        font.pixelSize: 14
                        color: theme.textColor
                        Layout.fillWidth: true
                    }
                    CheckBox {
                        id: cntCheck
                        checked: schedPage.countdownEnabled
                        onToggled: {
                            schedPage.countdownEnabled = checked
                            if (bhCore) bhCore.countdownEnabled = checked
                        }
                        indicator: Rectangle {
                            implicitWidth: 20; implicitHeight: 20
                            x: cntCheck.leftPadding; y: parent.height / 2 - height / 2
                            radius: 4
                            color: cntCheck.checked ? theme.focusColor : "transparent"
                            border.color: cntCheck.checked ? theme.focusColor : theme.borderColor
                            border.width: 2
                            Behavior on color { ColorAnimation { duration: 120 } }
                            Text {
                                anchors.centerIn: parent; text: "\uf00c"
                                font.family: iconFont.name; font.pixelSize: 12
                                color: "#ffffff"; visible: cntCheck.checked
                            }
                        }
                    }
                }

                RowLayout {
                    Layout.fillWidth: true
                    spacing: 12
                    opacity: schedPage.countdownEnabled ? 1.0 : 0.4
                    enabled: schedPage.countdownEnabled

                    Text {
                        text: "倒计时间隔"
                        font.pixelSize: 14; color: theme.textColor
                        Layout.preferredWidth: 80
                    }

                    SpinBox {
                        id: cntSpin
                        from: 1; to: 1440; stepSize: 5; value: schedPage.countdownMinutes
                        editable: true; width: 90; height: 32
                        onValueChanged: { schedPage.countdownMinutes = value; if (bhCore) bhCore.countdownMinutes = value }
                        contentItem: TextInput {
                            text: cntSpin.displayText
                            font: cntSpin.font
                            color: theme.textColor
                            selectionColor: theme.focusColor
                            selectedTextColor: "#ffffff"
                            horizontalAlignment: Qt.AlignHCenter
                            verticalAlignment: Qt.AlignVCenter
                            readOnly: !cntSpin.editable
                            validator: cntSpin.validator
                            inputMethodHints: Qt.ImhFormattedNumbersOnly
                        }
                        background: Rectangle {
                            implicitWidth: 90; implicitHeight: 32
                            radius: 6; color: theme.secondaryColor
                            border.color: theme.borderColor; border.width: 1
                        }
                    }

                    Text {
                        text: "分钟"
                        font.pixelSize: 14; color: theme.textColor
                    }
                }
            }
        }

        Item { Layout.fillHeight: true }
    }
}
