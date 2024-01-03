import QtQuick 2.12
import QtQuick.Window 2.12

Window {
    width: 640
    height: 480
    visible: true
    title: qsTr("Hello World")

    Rectangle {
        color: "Pink"
        anchors.centerIn: parent
        width: 300
        height: 400

        clip: true

        Flow{
            anchors.centerIn: parent

            flow:Flow.LeftToRight
            spacing: 5

            MyShape{ color: "red"}
            MyShape{ color: "yellow"}
            MyShape{ color: "green"}
            MyShape{ color: "blue"}
            MyShape{ color: "gray"}
            MyShape{ color: "teal"}
            MyShape{ color: "brown"}
            MyShape{ color: "black"}
            MyShape{ color: "pink"}
        }
    }

}
