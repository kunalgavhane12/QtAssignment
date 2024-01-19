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
        color: "red"
        x: 150
        y: 0
        width: parent.width - x
        height: parent.height


    }
}
