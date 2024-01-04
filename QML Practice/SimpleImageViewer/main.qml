import QtQuick 2.12
import QtQuick.Window 2.12

Window {
    width: 640
    height: 480
    visible: true
    title: qsTr("Image Viewer")
    id: root

    property color bgcolor: "#5A6263"
    property color buttoncolor: "green"
    property color hovorcolor: "lightgreen"
    property color clickcolor: "yellow"
    property int size: 100

    Rectangle {
        id: background
        color: root.buttoncolor
        width: 100
        height: parent.height

        Column{
            id: column
            anchors.fill: parent

            HoverButton{
                width: 100
                height: 50
                title.text: "Dog"
                color: root.buttoncolor
                hoverColor: root.hovorcolor
                clickColor: root.clickcolor

                area.onPressed: image.source = "qrc:/image/C:/Users/Dell/Pictures/dog.jpg"
            }

            HoverButton{
                width: 100
                height: 50
                title.text: "Peacock"
                color: root.buttoncolor
                hoverColor: root.hovorcolor
                clickColor: root.clickcolor

                area.onPressed: image.source = "qrc:/image/C:/Users/Dell/Pictures/peacock.jpg"
            }

            HoverButton{
                width: 100
                height: 50
                title.text: "Tiger"
                color: root.buttoncolor
                hoverColor: root.hovorcolor
                clickColor: root.clickcolor

                area.onPressed: image.source = "qrc:/image/C:/Users/Dell/Pictures/tiger.jpg"
            }
        }
    }

    Rectangle {
        id: rectangle
        color: root.bgcolor
        x: 100
        y: 0
        width: parent.width - x
        height: parent.height

        Image {
            id: image
            anchors.margins: 25
            anchors.fill: parent
            fillMode: Image.PreserveAspectFit
            source: "qrc:/image/C:/Users/Dell/Pictures/dog.jpg"
        }
    }
}
