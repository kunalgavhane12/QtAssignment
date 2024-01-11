import QtQuick 2.12
import QtQuick.Window 2.12
import "code.js" as Code
import QtQml 2.12

Window {
    width: 640
    height: 480
    visible: true
    title: qsTr("Javascript Connection")
    id: root

    Component.onCompleted: {
        Code.startup(root, box)
        area.clicked.connect(Code.clicked)
    }

    Rectangle{
        id: box
        color: Code.swapColor(area) //"red"
        width: 100
        height: 100
        x: 0
        y: (parent.height/2) - (height/2)


        MouseArea{
            id: area
            anchors.fill: parent
//            onClicked: Code.performClick(root,box)
        }
    }
}
