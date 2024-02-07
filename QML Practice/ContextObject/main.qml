import QtQuick 2.12
import QtQuick.Window 2.12

Window {
    width: 640
    height: 480
    visible: true
    title: qsTr("Qml ContextObject Demo")

    Rectangle{
        id: mRect1
        width: mText.implicitWidth + 20
        height: mText.implicitHeight + 20
        color: "beige"
        border.color: "yellowgreen"

        Text {
            id: mText
            anchors.centerIn: parent
            text: lastname
            font.pixelSize: 20
        }
    }

    Rectangle{
        id: mRect2
        anchors.left: mRect1.right
        anchors.leftMargin: 5
        width: mText1.implicitWidth + 20
        height: mText1.implicitHeight + 20
        color: "beige"
        border.color: "yellowgreen"

        Text {
            id: mText1
            text: firstname
            anchors.centerIn: parent
            font.pixelSize: 20
        }
    }
}
