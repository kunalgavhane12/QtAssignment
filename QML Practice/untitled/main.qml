import QtQuick 2.12
import QtQuick.Window 2.12
import QtQuick.Controls 2.5
import QtQml 2.12

Window {
    width: 640
    height: 480
    visible: true
    title: qsTr("World")

    property color bgColor: "red"
    property color textColor: "black"

    StackView{
        id: stackView
        focus: true
        anchors.fill: parent
    }

    Component.onCompleted: {
          stackView.push("qrc:/login.qml")
    }
}
