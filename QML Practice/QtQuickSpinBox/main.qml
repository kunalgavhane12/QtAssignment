import QtQuick 2.12
import QtQuick.Controls 2.3
import QtQuick.Window 2.12
import QtQml 2.12

Window {
    id: window
    width: 640
    height: 480
    visible: true
    title: qsTr("SpinBox")

    Grid {
        id: grid
        width: 227
        height: 43
        anchors.verticalCenter: parent.verticalCenter
        anchors.horizontalCenter: parent.horizontalCenter
        spacing: 25
        columns: 2

        SpinBox {
            id: spinBox
            onValueModified: label.text = target.value
        }

        Label {
            id: label
            text: spinBox.value
            font.bold: true
            font.pointSize: 25
        }
    }

//    Connections {
//        target: spinBox
//        onValueModified: label.text = target.value
//    }
}


