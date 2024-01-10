import QtQuick 2.12
import QtQuick.Window 2.12
import QtQuick.Controls 2.3
import QtQml 2.12

Window {
    id: window
    width: 640
    height: 480
    visible: true
    title: qsTr("QtQuick Dial Button")

    Column {
        id: column
        width: 200
        height: 400
        anchors.verticalCenter: parent.verticalCenter
        spacing: 0
        anchors.horizontalCenter: parent.horizontalCenter

        Label {
            id: label
            text: qsTr("Value")
            font.pointSize: 25
            font.bold: true
            anchors.horizontalCenter: parent.horizontalCenter
        }

        Dial {
            id: dial
            anchors.verticalCenter: parent.verticalCenter
            anchors.horizontalCenter: parent.horizontalCenter

//            onMoved: label.text = Math.round(dial.value * 100)

        }
    }
    Connections {
        target: dial
        onMoved: label.text = Math.round(dial.value * 100)
    }
 }

/*##^##
Designer {
    D{i:0;formeditorZoom:0.66}
}
##^##*/
