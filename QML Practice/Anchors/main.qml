import QtQuick 2.12
import QtQuick.Window 2.12

Window {
    width: 640
    height: 480
    visible: true
    title: qsTr("Anchors World")

    MyShape{
        id: shapeControl
        anchors.centerIn: parent
        text: "center"
    }

    MyShape {
        id:shapeTop
        text: "Top"
        color: "red"
        anchors.bottom: shapeControl.top
        anchors.left: shapeControl.left
    }

    MyShape {
        id: shapeBottom
        text: "Bottom"
        color: "Yellow"
        anchors.top: shapeControl.bottom
        anchors.left: shapeControl.left
    }

    MyShape {
        id: shapeRight
        text: "Right"
        color: "blue"
        anchors.top: shapeControl.top
        anchors.right: shapeControl.left
    }

    MyShape {
        id: shapeLeft
        text: "Left"
        color: "Green"
        anchors.top: shapeControl.top
        anchors.left: shapeControl.right
    }
}
