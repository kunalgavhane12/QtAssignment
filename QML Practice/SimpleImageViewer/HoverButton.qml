import QtQuick 2.0

Item {
    id: root
    property color color: "red"
    property color hoverColor: "pink"
    property color textColor: "white"
    property color clickColor: "gray"
    property color textHover: "Black"
    property alias title: display
    property alias area: mouseArea

    Rectangle{
        height: root.height
        width: root.width
        color: root.color
        clip: true

        Text {
            id: display
            text: ""
            anchors.centerIn: parent
            color: root.textColor
            font.bold: true
        }

        MouseArea {
            id:mouseArea
            anchors.fill: parent
            hoverEnabled: true

            onEntered:{
                parent.color = root.hoverColor
                display.color = root.textHover
            }

            onExited: {
                parent.color = root.color
                display.color = root.textColor
            }

            onPressed: parent.color = root.color
            onReleased: parent.color = root.hoverColor
        }
    }
}
