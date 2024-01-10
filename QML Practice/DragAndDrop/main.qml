import QtQuick 2.12
import QtQuick.Window 2.12

Window {
    id: root
    width: 640
    height: 480
    visible: true
    title: qsTr("Hello World")

    property string theykey: "special key here"
    property color ballon: "orange"
    property color balloff: "yellow"
    property color goalOn: "red"
    property color goalOff: "green"

    DropArea{
        id: dropZone
        anchors.top: parent.top
        anchors.right: parent.right
        anchors.bottom: parent.bottom
        width: 300
        Drag.keys: [theykey]

        onDropped: {
            console.log("dropped!")
            goal.color = goalOn
        }

        Rectangle{
            id: goal
            anchors.fill: parent
            color: goalOff
            border.color:"black"
            border.width: 5
        }
    }

    Rectangle{
        id: ball
        width: 100
        height: 100
        radius: width
        x: 25
        y:(parent.height/2) - (height/2)
        color: balloff
        border.width: 5
        border.color: "black"

        Drag.active: dragArea.drag.active
        Drag.keys: [theykey]

        Text {
            id: title
            anchors.centerIn: parent
            text: Math.round(parent.x) + "x" + Math.round(parent.y)
        }

        MouseArea{
            id: dragArea
            anchors.fill: parent
            drag.target: parent

            onPressed: {
                parent.color = ballon
                goal.color = goalOff
            }

            onReleased: {
                parent.color = balloff
                parent.Drag.drop()
            }
        }
    }

}
