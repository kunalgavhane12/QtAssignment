import QtQuick 2.12
import QtQuick.Window 2.12
import QtQuick.Controls 2.4

Window {
    width: 640
    height: 480
    visible: true
    title: qsTr("Q_Property Demo")

    Column{
        spacing: 20
        Text {
            id: titleID
            width: 500
            text: Movie.title
            font.pointSize: 20
            anchors.horizontalCenter: parent.horizontalCenter
        }

        Text {
            id: mainCharId
            width: 500
            text: Movie.mainCharacter
            font.pointSize: 20
            anchors.horizontalCenter: parent.horizontalCenter
        }

        Row{
            anchors.horizontalCenter: parent.horizontalCenter
            TextField {
                id: titleTextFieldId
                width: 300
            }
            Button{
                width:200
                id: button
                text: "Change Title"
                onClicked:{
                    Movie.title = titleTextFieldId.text

                }
            }
        }

        Row{
            anchors.horizontalCenter: parent.horizontalCenter
            TextField {
                id: maintitleTextFieldId
                width: 300
            }
            Button{
                width:200
                id: button1
                text: "Change Main Character"
                onClicked:{
                    Movie.mainCharacter = maintitleTextFieldId.text

                }
            }
        }
    }
}
