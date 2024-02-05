import QtQuick 2.0
import QtQuick.Controls 2.3
import QtQml 2.12

Item {
    signal loginSuccessful()

    Rectangle{
        width: 396
        height: 258
        anchors.centerIn: parent
        color: "lightgrey"

        Column {
            id: column
            anchors.fill: parent
            spacing: 10

            Label {
                id: label
                text: qsTr("Username")
            }

            TextField {
                id: textField
                width: parent.width
                text: ""
            }

            Label {
                id: label1
                text: qsTr("Password")
            }

            TextField {
                id: textField1
                width: parent.width
                text: ""
            }

            Button {
                id: signInBtn
                width: parent.width
                text: qsTr("Sign In")
            }

            Button {
                id: signUpBtn
                width: parent.width
                text: qsTr("Sign Up")
            }
        }


    }

}

