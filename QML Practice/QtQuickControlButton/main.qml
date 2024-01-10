import QtQuick 2.12
import QtQuick.Window 2.12
import QtQuick.Controls 2.12
import QtQml 2.12

Window {
    width: 640
    height: 480
    visible: true
    color: "#7d6faa"
    title: qsTr("Qt Quick Control Button")

    Row {
        id: row
        x: 0
        y: -1
        width: 640
        height: 45
        spacing: 5

        Button {
            id: button
            x: 36
            y: 7
            text: qsTr("Tiger")

            Connections {
                target: button
                onClicked: image.source = "qrc:/image/C:/Users/Dell/Pictures/tiger.jpg"
            }
        }

        Button {
            id: button1
            x: 161
            y: 7
            text: qsTr("Smile")

            Connections {
                target: button1
                onClicked: image.source = "qrc:/image/C:/Users/Dell/Pictures/smile.png"
            }
        }

        Button {
            id: button2
            x: 285
            y: 7
            text: qsTr("Peacock")

            Connections {
                target: button2
                onClicked: image.source = "qrc:/image/C:/Users/Dell/Pictures/peacock.jpg"
            }
        }

        Button {
            id: button3
            x: 399
            y: 7
            text: qsTr("Dog")

            Connections {
                target: button3
               onClicked: image.source = "qrc:/image/C:/Users/Dell/Pictures/dog.jpg"
            }
        }
    }

    Image {
        id: image
        x: 0
        y: 48
        width: 640
        height: 430
        source: "qrc:/qtquickplugin/images/template_image.png"
        fillMode: Image.PreserveAspectFit
    }


}



/*##^##
Designer {
    D{i:0;formeditorZoom:0.75}D{i:2}D{i:4}D{i:6}D{i:8}
}
##^##*/
