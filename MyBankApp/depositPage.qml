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

        Column {
            anchors.centerIn: parent
            width: 400
            height: 258
            spacing: 5
            Label{
                id: name
                text: "Name"
                font.pointSize: 12
            }

            TextField{
                id: txtname
                width: parent.width
                placeholderText: "Name"
                text: ""
            }
            Label{
                id: accountNO
                text: "Account Number"
                font.pointSize: 12
            }

            TextField{
                id: txtaccountNO
                width: parent.width
                placeholderText: "Enter Account Number"
                text: ""
            }

            Label{
                id: ldlDeposit
                text: "Deposit Amount"
                font.pointSize: 12
            }

            TextField{
                id: txtDeposit
                width: parent.width
                echoMode: TextField.Password
                placeholderText: "0.00"
                text: ""
            }

            Button{
                id: depositBtn
                text: "Deposit"
                anchors.horizontalCenter: parent.horizontalCenter
                width: parent.width
            }

            Button{
                id: cancelBtn
                text: "Cancel"
                anchors.horizontalCenter: parent.horizontalCenter
                width: parent.width

            }
        }




    }
}
