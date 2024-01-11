import QtQuick 2.12
import QtQuick.Controls 2.12

Page {
    width: 600
    height: 400
    title: qsTr("Page 3")

    Grid {
        id: grid
        width: 265
        height: 135
        anchors.centerIn: parent
        spacing: 10
        columns: 2

        Label {
            text: "First Name"
        }

        TextField {
            id: txtFirstName
            text: ""
        }

        Label {
            text: "Last Name"
        }
        TextField {
            id: txtLastName
            text: ""
        }
    }

    Button {
        id: button
        x: 266
        y: 273
        text: qsTr("Submit")
    }
}
