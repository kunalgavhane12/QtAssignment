import QtQuick 2.12
import QtQuick.Window 2.12
import QtQuick.Controls 2.3
import QtQml 2.12

Window {
    width: 640
    height: 480
    visible: true
    title: qsTr("Hello World")

    Row {
        id: row
        anchors.fill: parent

        Column {
            id: column
            width: 200
            height: 400
            spacing: 10

            CheckBox {
                id: checkBox
                text: qsTr("Normal")
            }

            CheckBox {
                id: checkBox1
                text: qsTr("Not Checkable")
            }

            CheckBox {
                id: checkBox2
                text: qsTr("Tristate")
                tristate: true
            }

            CheckBox {
                id: checkBox3
                text: qsTr("Exclusive")
            }

            CheckBox {
                id: checkBox4
                text: qsTr("Repeater")
            }

            Button {
                id: button
                text: qsTr("Reset")

            }

            Column {
                id: column1
                width: 200
                height: 400
            }
        }

        Column {
            id: column2
            width: parent.width - x
            height: 480

            Label {
                id: label
                text: qsTr("Status here")
                anchors.verticalCenter: parent.verticalCenter
                font.pointSize: 35
                font.bold: true
                anchors.horizontalCenter: parent.horizontalCenter
            }
        }
    }

    Connections {
        target: button
        onClicked: {
            checkBox.checkState = Qt.Unchecked
            checkBox1.checkState = Qt.Unchecked
            checkBox2.checkState = Qt.Unchecked
            checkBox3.checkState = Qt.Unchecked
            checkBox4.checkState = Qt.Unchecked
        }
    }

    Connections{
        target: checkBox
        onClicked:{
            label.text = "CheckBox = " + target.checkState
        }
    }
    Connections{
        target: checkBox1
        onClicked:{
            label.text = "CheckBox = " + target.checkState
        }
    }
    Connections{
        target: checkBox2
        onClicked:{
            label.text = "CheckBox = " + target.checkState
        }
    }
    Connections{
        target: checkBox3
        onClicked:{
            label.text = "CheckBox = " + target.checkState
        }
    }
    Connections{
        target: checkBox4
        onClicked:{
            label.text = "CheckBox = " + target.checkState
        }
    }
}

/*##^##
Designer {
    D{i:0;formeditorZoom:0.66}D{i:1}
}
##^##*/
