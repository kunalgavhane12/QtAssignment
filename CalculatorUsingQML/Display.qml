import QtQuick 2.0

Item {
    id: root
    property color color: "gray"
    property string text: title

    width: 300
    height: 100

    Rectangle {
        color: root.color
        anchors.fill: parent

        Text {
            text: root.text
            anchors.fill: parent
            anchors.leftMargin: 2
            anchors.rightMargin: 3
            horizontalAlignment: Text.AlignRight
            verticalAlignment: Text.AlignVCenter
            color: "black"
            font.bold: true
            font.pointSize: 20
            fontSizeMode: Text.Fit
            anchors.centerIn: parent
        }

        MouseArea {
            anchors.fill: parent
        }
    }
}
