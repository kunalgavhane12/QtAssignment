import QtQuick 2.12
import QtQuick.Controls 2.3
import QtQuick.Window 2.12
import QtQml 2.12

Window {
    id: window
    width: 640
    height: 480
    visible: true
    title: qsTr("Range Slider")

    Column {
        id: column
        width: 436
        height: 126
        anchors.verticalCenter: parent.verticalCenter
        anchors.verticalCenterOffset: -15
        anchors.horizontalCenterOffset: 0
        spacing: 25
        anchors.horizontalCenter: parent.horizontalCenter

        RangeSlider {
            id: rangeSlider
            anchors.verticalCenter: parent.verticalCenter
            anchors.horizontalCenter: parent.horizontalCenter
            second.value: 0.75
            first.value: 0.25

            Connections {
                target: rangeSlider.first
               onValueChanged:{
                   label.text = Math.round(rangeSlider.first.value * 100) + " to " +Math.round(rangeSlider.second.value * 100)
               }
            }

            Connections {
                target: rangeSlider.second
                onValueChanged:{
                    label.text = Math.round(rangeSlider.first.value * 100) + " to " +Math.round(rangeSlider.second.value * 100)
                }
            }
        }

        Label {
            id: label
            text: qsTr("X to Y")
            font.pointSize: 25
            font.bold: true
            anchors.horizontalCenter: parent.horizontalCenter
        }
    }
}
