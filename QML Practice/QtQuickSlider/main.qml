import QtQuick 2.12
import QtQuick.Window 2.12
import QtQuick.Controls 2.3
import QtQml 2.12

Window {
    id: window
    width: 640
    height: 480
    visible: true
    title: qsTr("Hello World")

    Grid {
        id: grid
        width: 544
        height: 94
        anchors.verticalCenter: parent.verticalCenter
        spacing: 25
        anchors.horizontalCenter: parent.horizontalCenter
        rows: 0
        columns: 2

        Slider {
            id: slider
            width: 300
            stepSize: 0.05
            value: 0

            Connections {
                target: slider
                onMoved: label.text = Math.round(slider.value * 100)
            }
        }

        Label {
            id: label
            text: qsTr("0")
            font.pointSize: 26
            font.bold: true
        }
    }

}


