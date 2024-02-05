import QtQuick 2.0
import QtQuick.Controls 2.5

Page {
    id: loginPage
    background: Rectangle{
        color: bgColor
        width: parent.width
        height: parent.height
    }
    Column{
        spacing: 10
        Button{
            width: 100
            height: 60
            text: "Sign In"
            onClicked:   stackView.push("qrc:/profile.qml")
        }

        Button{
            width: 100
            height: 60
            text: "Sign Up"
            onClicked:   stackView.push("qrc:/signup.qml")
        }
    }
}
