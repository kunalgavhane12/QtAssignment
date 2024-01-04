import QtQuick 2.12
import QtQuick.Window 2.12

Window {
    id: root
    width: 640
    height: 480
    visible: true
    title: qsTr("Scale and Sequential Animation")

    Rectangle{
        id: myShape
        width: 200
        height: 200
        color: "red"
        anchors.centerIn: parent
        clip: true

        Text {
            id: title
            text: "KUNAL"
            font.bold: true
            font.pointSize: 66
            anchors.centerIn: parent
            color: "white"
            rotation: -45
        }
    }

    SequentialAnimation{
        id: animation
        running: true
        loops: Animation.Infinite

        ScaleAnimator{
            id: aniShrink
            target: myShape
            from: 1
            to: 0.5
            duration: 2000
            running: true
        }

        ScaleAnimator{
            id: aniGrow
            target: myShape
            from: 0.5
            to: 1
            duration: 2000
            running: true
        }
    }
}
