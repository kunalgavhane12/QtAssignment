import QtQuick 2.0
import QtQuick.Controls 2.3
import QtQml 2.12

Item {
    signal login(string username, string password)
    width: 250
    height: 250

    Column{
        id: column
        anchors.fill: parent
        spacing: 10

        Label{
            id: lblUsername
            text: "User Name"
        }

        TextField{
            id: txtUsername
            width: parent.width
            placeholderText: "example@example.com"
            text: ""
        }

        Label{
            id: lblPassword
            text: "Password"
        }

        TextField{
            id: txtPassword
            width: parent.width
            echoMode: TextField.Password
            placeholderText: "Password"
            text: ""
        }

        Button{
            id: signInBtn
            text: "Sign In"
            anchors.horizontalCenter: parent.horizontalCenter
            width: parent.width
        }

        Button{
            id: signUpBtn
            text: "Sign Up"
            anchors.horizontalCenter: parent.horizontalCenter
            width: parent.width
        }

    }

    Connections{
        target: signInBtn
        onClicked: login(txtUsername.text, txtPassword.text)
    }

}
