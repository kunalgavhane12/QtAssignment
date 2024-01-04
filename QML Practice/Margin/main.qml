import QtQuick 2.12
import QtQuick.Window 2.12

Window {
    width: 640
    height: 480
    visible: true
    title: qsTr("Margin")

    Rectangle{
        width: 300
        height: 400
        color: "red"
        anchors.centerIn: parent


        Rectangle{
            width: 60
            height: 40
            color: "black"
            radius: width

            Text {
                id: name
                text: qsTr("1")
                color: "white"
                anchors.centerIn: parent
            }

            anchors.margins: 50
            anchors.left: parent.left
            anchors.bottom: parent.bottom
            anchors.leftMargin: 15
        }
    }

}
