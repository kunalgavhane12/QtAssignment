import QtQuick 2.0
import QtQuick.Controls 2.3
import QtQml 2.12
import QtQuick.Layouts 1.12

import "backend.js" as Backend

Page {
    signal login()

    background: Rectangle {
        color: backgroundColor
    }

    Rectangle{
        width: 400
        height: 258
        anchors.centerIn: parent
        color: "lightgrey"


        Column {
            id: column
            anchors.fill: parent
            spacing: 10
            Label{
                id: lblUsername
                text: "Username"
                font.pointSize: 12

            }

            TextField{
                id: loginUsername
                width: parent.width
                placeholderText: "example@example.com"
                text: ""
            }

            Label{
                id: lblPassword
                text: "Password"
                font.pointSize: 12
            }

            TextField{
                id: loginPassword
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
                onClicked:{

                    loginUser(loginUsername.text, loginPassword.text)
                }
            }

            Button{
                id: signUpBtn
                text: "Sign Up"
                anchors.horizontalCenter: parent.horizontalCenter
                width: parent.width
                onClicked: stackView.push("qrc:/signUp.qml")
            }

        }

    }

}
