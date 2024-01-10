import QtQuick 2.12
import QtQuick.Controls 2.3
import QtQuick.Window 2.12
import QtQml 2.12

Window {
    id: root
    width: 640
    height: 480
    visible: true
    title: qsTr("Round Button")

    property int value: 0

    Row {
        id: row
        width: 236
        height: 51
        anchors.verticalCenter: parent.verticalCenter
        spacing: 10
        anchors.horizontalCenter: parent.horizontalCenter

        RoundButton {
            id: roundButton
            text: "-"
            anchors.verticalCenter: parent.verticalCenter
            font.pointSize: 15
            font.bold: true

            onClicked: value--
        }

        RoundButton {
            id: roundButton1
            text: "+"
            anchors.verticalCenter: parent.verticalCenter
            font.bold: true
            font.pointSize: 15

            onClicked: value++
        }

        Label {
            id: label
            text: "Value: " + root.value
            anchors.verticalCenter: parent.verticalCenter
            font.pointSize: 25
            font.bold: true
        }
    }
}
