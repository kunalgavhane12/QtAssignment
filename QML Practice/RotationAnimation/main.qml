import QtQuick 2.12
import QtQuick.Window 2.12

Window {
    width: 640
    height: 480
    visible: true
    title: qsTr("Rotation and Rotation animation")

    Rectangle{
        id: myshape
        width: 200
        height: 200
//        radius: width
        color: "red"
        anchors.centerIn: parent

        Text {
            id: title
            text: Math.round(parent.rotation)
            anchors.centerIn: parent
            font.bold: true
            font.pointSize: 65
            color: "white"
        }

        RotationAnimation{
            id: animation
            target: myshape
            loops: Animation.Infinite
            from: myshape.rotation
            to: 360
            direction: RotationAnimation.Clockwise
            duration: 5000
            running: true
        }

        MouseArea {
            id: area
            anchors.fill: parent
            onClicked: {
                if(animation.paused)
                {
                    animation.resume()
                }
                else
                {
                    animation.pause()
                }
            }
        }

    }
}
