import QtQuick 2.0

Item {
    id: root
    signal clicked
    property color color: "white"
    property color hoverColor: "gray"
    property color textColor: "white"
    property color clickColor: "gray"
    property color textHover: "Black"
    property string text: title.text
    property string expression: ""
//    property string op: ""
    property alias area: mouseArea

//    property real num1: 0
//    property real num2: 0
    property real result: 0

    width: 72
    height: 50

    Rectangle {
        color: root.color
        anchors.fill: parent
        radius: width
        border.color: "black"
        anchors.topMargin: 5
        anchors.leftMargin: 5

        Text {
            text: root.text
            font.bold: true
            font.pointSize: 10
            anchors.centerIn: parent
        }

        MouseArea {
            id:mouseArea
            anchors.fill: parent
            hoverEnabled: true

            onEntered:{
                parent.color = root.hoverColor
                title.color = root.textHover
            }

            onExited: {
                parent.color = root.color
                title.color = root.textColor
            }

            onPressed: parent.color = root.hoverColor
            onReleased: parent.color = root.color

            onClicked: root.clicked()
        }
    }
}
