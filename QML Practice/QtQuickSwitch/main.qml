import QtQuick 2.12
import QtQuick.Controls 2.3
import QtQuick.Window 2.12
import QtQml 2.12

Window {
    width: 640
    height: 480
    visible: true
    title: qsTr("Switch")

    Column {
        id: column
        anchors.fill: parent

        Image {
            id: image
            width: 300
            height: 300
            anchors.verticalCenter: parent.verticalCenter
            source: "qrc:/qtquickplugin/images/template_image.png"
            anchors.horizontalCenter: parent.horizontalCenter
            fillMode: Image.PreserveAspectFit
        }

        Switch {
            id: switch1
            text: qsTr("Sad")
            anchors.bottom: parent.bottom
            font.pointSize: 10
            font.bold: true
            anchors.horizontalCenter: parent.horizontalCenter
            anchors.bottomMargin: 25

            onToggled: {
                if(checked)
                {
                    text = "Happy"
                    image.source = "qrc:/images/smile.jpg"

                }
                else
                {
                    text = "Sad"
                    image.source = "qrc:/images/sad.png"
                }
            }

        }
    }
}
