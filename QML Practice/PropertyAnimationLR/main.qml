import QtQuick 2.12
import QtQuick.Window 2.12

Window {
    width: 640
    height: 480
    visible: true
    title: qsTr("Property Animation")
    id: root

    Rectangle{
        id: myshape
        width: 100
        height: 100
        radius: width
        color: "red"
        x:0
        y: (parent.height/2 ) - (height/2)

        PropertyAnimation{
            id: animationRight
            target: myshape
            property: "x"
            to: root.width - myshape.width
            duration: 5000
        }

        PropertyAnimation{
            id: animationLeft
            target: myshape
            property: "x"
            to:0
            duration: 5000
        }

        MouseArea{
            anchors.fill: parent
            onClicked: {
                if(myshape.x===0)
                {
                    animationRight.start()
                }
                else
                {
                    animationLeft.start()
                }
            }
        }
    }
}
