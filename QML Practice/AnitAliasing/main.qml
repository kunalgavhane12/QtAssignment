import QtQuick 2.12
import QtQuick.Window 2.12

Window {
    width: 640
    height: 480
    visible: true
    title: qsTr("Hello World")

    Row {

        anchors.centerIn: parent
        spacing: 5

        Rectangle{
            width: 200
            height: 200
            border.color: "red"
            border.width: 20
            radius: width

            Text {
                anchors.centerIn: parent
                text: "Turn On"
            }
        }

        Rectangle{
            width: 200
            height: 200
            border.color: "red"
            border.width: 20
            radius: width
            antialiasing: false
            Text {
                anchors.centerIn: parent
                text: "Turn Off"
            }
        }
    }
}
