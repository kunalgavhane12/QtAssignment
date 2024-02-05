import QtQuick 2.0
import QtQuick.Controls 2.3

import "backend.js" as Backend

Item {
    id: item1

    Rectangle{
        id: rectangle

        color: "lightgrey"
        anchors.fill: parent
        Column {
            id: column
            y: 0
            width: 463
            height: 342
            anchors.verticalCenter: parent.verticalCenter
            anchors.horizontalCenter: parent.horizontalCenter
            spacing: 5

            Label {
                id: lblName
                text: qsTr("Name")
            }

            TextField {
                id: txtName
                width: parent.width
                text: ""
            }
            Label {
                id: lblEmail
                text: "Email"
            }

            TextField {
                id: txtEmail
                width: parent.width
                text: ""
            }
            Label {
                id: lblPword
                text: qsTr("Password")
            }

            TextField {
                id: txtPword
                width: parent.width
                text: ""
            }
            Label {
                id: lblPword1
                text: qsTr("Confirm Password")
            }

            TextField {
                id: txtPword1
                width: parent.width
                text: ""
            }

            Button{
                text: "Register"
                width: parent.width
                anchors.horizontalCenter: parent.horizontalCenter
                onClicked: {
                    registerUser(txtName.text, txtEmail.text, txtPword.text, txtPword1.text)
                }
            }

            Button{
                text: "Cancel"
                anchors.horizontalCenter: parent.horizontalCenter
                width: parent.width
                onClicked: stackView.push("qrc:/Login.qml")
            }
        }
    }

    function registerUser(name, email, pword, pword1){

        if(Backend.validateRegisterCredentials(name, email, pword, pword1))
        {
            popup.popMessage = "Missing credentials!"
            popup.open()
            return
        }

        if(pword !== pword1)
        {
            popup.popMessage = "Password does not match!."
            popup.open()
            return
        }

        if(!Backend.isValidEmail(email))
        {
            popup.popMessage = "Invalid email!"
            popup.open()
            return
        }

        if(!Backend.isValidPassword(pword) || !Backend.isValidPassword(pword1))
        {
            popup.popMessage = "Password must have at least one digit, one lowercase, one uppercase,
 one special character and be at least 8 character long."
            popup.open()
            return
        }
        else
        {
            popup.popMessage = "Your sign up was successful ."
            popup.open()
            stackView.push("qrc:/Login.qml")
        }

    }

}

