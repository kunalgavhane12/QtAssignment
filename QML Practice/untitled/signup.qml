import QtQuick 2.0
import QtQuick.Controls 2.5

Page {
    id: signupPage
    background: Rectangle{
        color: "yellow"
        width: parent.width
        height: parent.height
    }

    Column {
        id: column
        width: 594
        height: 434
        anchors.verticalCenter: parent.verticalCenter
        anchors.horizontalCenter: parent.horizontalCenter

        Row {
            id: row
            y: 421
            width: 447
            height: 51
            anchors.left: parent.left
            anchors.bottom: parent.bottom
            spacing: 15

            Button {
                id: button
                text: qsTr("Button")
            }

            Button {
                id: button1
                text: qsTr("Button")
            }
        }
    }


}
