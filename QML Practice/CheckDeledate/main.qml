import QtQuick 2.12
import QtQuick.Window 2.12
import QtQuick.Controls 2.3

Window {
    width: 640
    height: 480
    visible: true
    title: qsTr("Hello World")

    Column{
        id: column
        width: 200
        height: 400
        anchors.centerIn: parent

        Label{
            id: label
            text: qsTr("Selected here")
            font.bold: true
            font.pointSize: 25
        }

        ListView{
            width: 200
            height: 200

            model: ["option A", "option B", "option C"]

            delegate: CheckDelegate{
                text: modelData
                onCheckStateChanged: label.text = index + " - " + modelData + " = " + checked
            }
        }
    }
}
