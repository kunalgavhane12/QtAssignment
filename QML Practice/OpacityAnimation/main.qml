import QtQuick 2.12
import QtQuick.Window 2.12

Window {
    width: 640
    height: 480
    visible: true
    title: qsTr("Opacity and OpacityAnimation")

    Image {
        id: ghost
        source: "qrc:/Image/C:/Users/Dell/Pictures/ghost.jpeg"
        anchors.fill: parent
        opacity: 0
    }

    SequentialAnimation{
        loops: Animation.Infinite
        running: true

        OpacityAnimator{
            target: ghost
            from: 0
            to: 1
            duration: 3000
        }
        OpacityAnimator{
            target: ghost
            from: 1
            to: 0
            duration: 6000
        }
    }
}
