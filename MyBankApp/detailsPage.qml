import QtQuick 2.0
import QtQuick.Controls 2.5

Page {

     Rectangle{
        id: menu
        color: "lightgrey"
        width: 150
        height: parent.height

        Column{
            id: column
            anchors.fill: parent

            Button{
                 width: 150
                 height: 50
                 text: "Home"
                 onClicked: stackView.push("qrc:/accountPage.qml")

            }
            Button{
                width: 150
                height: 50
                text: "Deposit"
              onClicked: stackView.push("qrc:/depositPage.qml")

            }
            Button{
                width: 150
                height: 50
                text: "Transfer"
                onClicked: stackView.push("qrc:/transferPage.qml")
            }
            Button{
                width: 150
                height: 50
                text: "Details"
                onClicked: stackView.push("qrc:/detailsPage.qml")

            }
            Button{
                width: 150
                height: 50
                text: "Logout"
                onClicked: stackView.push("qrc:/Login.qml")
            }

        }

    }

    Rectangle {
        id: rectangle
        color: "lightgrey"
        x: 150
        y: 0
        width: parent.width - x
        height: parent.height

        Label{
            text: root.username
            anchors.right: parent.right
            anchors.rightMargin: 0
        }

        Column {
            width: 463
            height: 342
            anchors.verticalCenter: parent.verticalCenter
            anchors.horizontalCenter: parent.horizontalCenter
            spacing: 10

            Label {
                id: lblName
                text: qsTr("Name : ")
            }

            Label {
                id: lblEmail
                text: "Email :"
            }

            Label {
                id: lblPword
                text: qsTr("Account Number :")
            }

            Label {
                id: lblPword1
                text: qsTr("Account Balance :")
            }

        }

        Column {
            width: 274
            height: 342
            anchors.verticalCenter: parent.verticalCenter
            anchors.horizontalCenter: parent.horizontalCenter
            spacing: 10

            Label {
                text: root.name
            }

            Label {
                text: root.username
            }

            Label {
                text: root.accountNumber
            }

            Label {
                text: root.accountBalance
            }

        }
    }
}
