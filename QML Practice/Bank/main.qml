import QtQuick 2.0
import QtQuick.Controls 2.3

ApplicationWindow {
    id: window
    width: 640
    height: 480
    visible: true
    title: qsTr("Bank Application")
    color: "lightgrey"

   StackView {
        id: stackView
        anchors.fill: parent
        initialItem: LoginPage{
            onLoginSuccessful:stackView.push(LoginPage)
        }
    }
}
