import QtQuick 2.7
import QtQuick.Controls 2.0
import QtQuick.Layouts 1.1

import "backend.js" as Backend

Page {
    id: loginPage

    signal registerClicked()

    background: Rectangle {
        color: backGroundColor
    }

    Rectangle {
        id: iconRect
        width: parent.width
        height: parent.height / 3
        color: backGroundColor

        Text {
            id: icontext
            text: qsTr("X-Bank")
            anchors.centerIn: parent
            font.pointSize: 100
            font.family: "fontawesome"
            color: mainAppColor
        }
    }

    ColumnLayout {
        width: parent.width
        anchors.top: iconRect.bottom
        spacing: 15

        TextField {
            id: loginUsername
            placeholderText: qsTr("User name")
            Layout.preferredWidth: parent.width - 20
            Layout.alignment: Qt.AlignHCenter
            color: mainTextColor
            font.pointSize: 14
            font.family: "fontawesome"
            leftPadding: 30
            background: Rectangle {
                implicitWidth: 200
                implicitHeight: 50
                radius: implicitHeight / 2
                color: "transparent"

                Text {
                    text: "\uf007"
                    font.pointSize: 14
                    font.family: "fontawesome"
                    color: mainAppColor
                    anchors.left: parent.left
                    anchors.verticalCenter: parent.verticalCenter
                    leftPadding: 10
                }

                Rectangle {
                    width: parent.width - 10
                    height: 1
                    anchors.horizontalCenter: parent.horizontalCenter
                    anchors.bottom: parent.bottom
                    color: mainAppColor
                }
            }
        }

        TextField {
            id: loginPassword
            placeholderText: qsTr("Password")
            Layout.preferredWidth: parent.width - 20
            Layout.alignment: Qt.AlignHCenter
            color: mainTextColor
            font.pointSize: 14
            font.family: "fontawesome"
            leftPadding: 30
            echoMode: TextField.PasswordEchoOnEdit
            background: Rectangle {
                implicitWidth: 200
                implicitHeight: 50
                radius: implicitHeight / 2
                color: "transparent"
                Text {
                    text: "\uf023"
                    font.pointSize: 14
                    font.family: "fontawesome"
                    color: mainAppColor
                    anchors.left: parent.left
                    anchors.verticalCenter: parent.verticalCenter
                    leftPadding: 10
                }

                Rectangle {
                    width: parent.width - 10
                    height: 1
                    anchors.horizontalCenter: parent.horizontalCenter
                    anchors.bottom: parent.bottom
                    color: mainAppColor
                }
            }
        }

        Item {
            height: 20
        }

        CButton{
            height: 50
            Layout.preferredWidth: loginPage.width - 20
            Layout.alignment: Qt.AlignHCenter
            name: "Log In"
            baseColor: mainAppColor
            borderColor: mainAppColor
            onClicked: {
                loginUser(loginUsername.text, loginPassword.text)
            }
        }

        CButton{
            height: 50
            Layout.preferredWidth: loginPage.width - 20
            Layout.alignment: Qt.AlignHCenter
            name: "Sign Up"
            baseColor: "transparent"
            borderColor: mainAppColor
            onClicked: stackView.push("qrc:/registerScreen.qml", {"uname": "arun", "pword": "some"}) //registerClicked()
        }

        Text {
            id: name
            text: '<html><style type="text/css"></style><a href="http://google.com">Forgot password?</a></html>' //qsTr("Forgot password?")
            linkColor: mainTextColor
            Layout.alignment: Qt.AlignHCenter
            font.pointSize: 14
            color: mainTextColor
            Layout.margins: 10
            onLinkActivated: forgotPassword()
        }
    }
}


/*

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

    GroupBox {
        id: groupBox
        width: 322
        height: 240
        anchors.verticalCenter: parent.verticalCenter
        anchors.horizontalCenter: parent.horizontalCenter
        font.pointSize: 10
        title: qsTr("SignIn")

        Label {
            id: lblUsername
            y: 5
            color: mainAppColor
            text: qsTr("User Name")
        }

        TextField {
            id: txtUsername
            y: 30
            width: 300
            color: mainTextColor
            placeholderText: "example@example.com"
        }

        Label {
            id: lblPassword
            y: 75
            color: mainAppColor
            text: qsTr("Password")
        }

        TextField {
            id: txtPassword
            y: 100
            width: 300
            color: mainTextColor
            placeholderText: "Enter password"
            echoMode: txtPassword.Password  //"Password"

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
*/

