import QtQuick 2.12
import QtQuick.Window 2.12

Window {
    width: 640
    height: 480
    visible: true
    title: qsTr("Hello World")

    Grid {
        anchors.centerIn: parent
        spacing: 2
        rows: 3
        columns: 3

        MyShape { color: "red"}
        MyShape { color: "yellow"}
        MyShape { color: "green"}
        MyShape { color: "blue"}
        MyShape { color: "black"}
        MyShape { color: "pink"}
        MyShape { color: "teal"}
        MyShape { color: "orange"}
        MyShape { color: "brown"}
    }
}
