import QtQuick 2.12
import QtQuick.Window 2.12

Window {
    width: 640
    height: 480
    visible: true
    title: qsTr("Hello World")

    Rectangle{
        id: background
        color: "black"
        anchors.fill: parent
        focus: true

        Rectangle{
            id: rect1
            color: "red"
            width: 100
            height: 100
            anchors.centerIn: parent
        }

        Rectangle{
            id: outline
            color: "transparent"
            width: 100
            height: 100
            border.color: "Yellow"
            border.width: 5
            anchors.centerIn: parent
        }

        Keys.onUpPressed: rect1.height += 10
        Keys.onDownPressed: rect1.height -= 10
        Keys.onRightPressed: rect1.width += 10
        Keys.onLeftPressed: rect1.width -= 10
    }
}
