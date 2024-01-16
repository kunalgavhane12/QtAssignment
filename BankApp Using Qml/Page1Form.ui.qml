import QtQuick 2.12
import QtQuick.Controls 2.5

Page {
    width: 600
    height: 400
    property string username: "admin"
    property string password: "admin"
    property string  status: "LOGIN FAILED"

    GroupBox {
        id: groupBox
        width: 322
        height: 240
        anchors.verticalCenter: parent.verticalCenter
        anchors.horizontalCenter: parent.horizontalCenter
        font.pointSize: 10
        title: qsTr("SignIn")

        Popup{
            id: popup
            width:200
            height: 200
            modal: true
            focus: true
            anchors.centerIn: parent
            closePolicy: Popup.CloseOnEscape | Popup.CloseOnPressOutside

            Column{
                spacing: 25
                anchors.fill: parent

                Label{
                    id: statusLabel
                    text: status
                    font.bold: true
                }
                Button{
                    id: closeButton
                    text: "Close"
                    onClicked: popup.visible = false
              }
            }
        }

        Label {
            id: lblUsername
            y: 5
            text: qsTr("User Name")
        }

        TextField {
            id: txtUsername
            y: 30
            width: 300
            placeholderText: "Enter username"
        }

        Label {
            id: lblPassword
            y: 75
            text: qsTr("Password")
        }

        TextField {
            id: txtPassword
            y: 100
            width: 300
            placeholderText: "Enter password"
            echoMode: "Password"

        }

        Button {
            id: btnLogin
            x: 60
            y: 155
            text: qsTr("Login")
            onClicked: {
                var tempcode = txtUsername.text
                var tempcode1 = txtPassword.text
                if(tempcode === password && tempcode1 === username)
                    status = "LOGIN SUCCESSFUL"
                popup.visible = true
            }
        }

        Button {
            id: btnReset
            x: 180
            y: 155
            text: qsTr("Reset")
            onClicked: {
                txtUsername.text = ""
                txtPassword.text = ""
            }

        }
    }
}
