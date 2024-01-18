import QtQuick 2.0
import QtQuick.Controls 2.5

Page {

    Rectangle{
        id: rectangle
        color: "lightgrey"
        width: 100
        height: parent.height

        Column{
            id: column
            anchors.fill: parent

            Button{
                 width: 100
                 height: 50
                 text: "Home"
            }
            Button{
                width: 100
                height: 50
                text: "Deposit"
            }
            Button{
                width: 100
                height: 50
                text: "Transfer"
            }
            Button{
                width: 100
                height: 50
                text: "Details"
            }
            Button{
                width: 100
                height: 50
                text: "Logout"
                onClicked: stackView.push("qrc:/Login.qml")
            }

        }

    }
}

