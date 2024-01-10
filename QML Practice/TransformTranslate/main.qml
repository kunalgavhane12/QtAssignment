import QtQuick 2.12
import QtQuick.Window 2.12

Window {
    width: 640
    height: 480
    visible: true
    title: qsTr("Transform and Translate Animation")

    Item{
        id: root
        rotation: 0
        anchors.centerIn: parent

        Rectangle{
            id: yellowRect
            color: "yellow"
            width: 300
            height: 300
            radius: width
            opacity: 0.5
            border.width: 2
            border.color: "black"
            anchors.centerIn: parent
            transform: Translate{ x: -100}
        }

        Rectangle{
            id: redRect
            color: "red"
            width: 300
            height: 300
            radius: width
            opacity: 0.5
            border.width: 2
            border.color: "black"
            anchors.centerIn: parent
            transform: Translate{ x: 100; y: -100}
        }

        Rectangle{
            id: greenRect
            color: "green"
            width: 300
            height: 300
            radius: width
            opacity: 0.5
            border.width: 2
            border.color: "black"
            anchors.centerIn: parent
            transform: Translate{ x: 100; y: 100}
        }

        Rectangle{
            id: centerCircle
            color: "white"
            width: 50
            height: 50
            radius: width
            opacity: 1
            border.width: 2
            border.color: "black"
            anchors.centerIn: parent

            Rectangle{
                id: ceterArea
                color: "gray"
                width: 5
                height: 5
                radius: width
                border.width: 2
                border.color: "black"
                anchors.centerIn: parent
            }

        }
        RotationAnimation{
            target: root
            from: 360
            to: 0
            duration: 5000
            direction:RotationAnimator.Counterclockwise
            loops: Animation.Infinite
            running: true
        }


    }
}
