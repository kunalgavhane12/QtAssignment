import QtQuick 2.12
import QtQuick.Window 2.12
import QtQuick.Controls 2.3

Window {
    id: window
    width: 640
    height: 480
    visible: true
    title: qsTr("Frames And POPUP")

    Popup{
        id: popup
        anchors.centerIn: parent

        width:200
        height: 200
        modal: true
        focus: true
        closePolicy: Popup.CloseOnEscape | Popup.CloseOnPressOutside

        Column{
            spacing: 25
            anchors.fill: parent

            Label{
                id: lblButter
                text: "Butter =" + chkButter.checked
            }
            Label{
                id: lblSyrup
                text: "Syrup =" + chkSyrup.checked
            }
            Label{
                id: lblFruit
                text: "Fruit =" + chkFruit.checked
            }
            Button{
                id: closeButton
                text: "Close"
                onClicked: popup.visible = false
//                onClicked: popup.close()
            }
        }
    }

    Frame {
        id: frame
        width: 134
        height: 268
        anchors.verticalCenter: parent.verticalCenter
        anchors.horizontalCenter: parent.horizontalCenter


        Column {
            id: column
            anchors.fill: parent
            spacing: 25

            CheckBox {
                id: chkButter
                text: qsTr("Butter")
            }

            CheckBox {
                id: chkSyrup
                text: qsTr("Syrup")
            }

            CheckBox {
                id: chkFruit
                text: qsTr("Fruit")
            }

            Button {
                id: button
                text: qsTr("Save")
//                onClicked: popup.open()
                onClicked: popup.visible = true
            }
        }

    }
}
