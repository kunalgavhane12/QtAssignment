import QtQuick 2.0
import QtQuick.Controls 2.5

Page {
    id: profilePage
    background: Rectangle{
        color: "pink"
    }

    Button{
        width: 100
        height: 60
        text: "Log Out"
        onClicked:   stackView.push("qrc:/login.qml")
    }
}
