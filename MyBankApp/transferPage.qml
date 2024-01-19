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
            y: 10
            anchors.horizontalCenter: parent.horizontalCenter
            spacing: 5

            Label {
                id: lblName
                text: qsTr("Name")
            }

            TextField {
                id: txtName
                width: parent.width
                text: root.name
            }
            Label {
                id: lblAccount
                text: "Account Number"
            }

            TextField {
                id: txtAccount
                width: parent.width
                text: root.accountNumber
            }

            Label {
                id: lblName1
                text: "Beneficiary Name"
            }

            TextField {
                id: txtName2
                width: parent.width
                text: ""
            }
            Label {
                id: lblAccount2
                text: "Beneficiary Account Number"
            }

            TextField {
                id: txtAccount2
                width: parent.width
                text: ""
            }

            Label {
                id: lblAmount
                text: "Amount"
            }

            TextField {
                id: txtAmount
                width: parent.width
                text: ""
            }

            Button{
                text: "Transfer"
                width: parent.width
                anchors.horizontalCenter: parent.horizontalCenter

            }

            Button{
                text: "Cancel"
                anchors.horizontalCenter: parent.horizontalCenter
                width: parent.width
                onClicked: stackView.push("qrc:/accountPage.qml")
            }

        }
    }
}
