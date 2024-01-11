import QtQuick 2.12
import QtQuick.Controls 2.5

Page {
    width: 600
    height: 400

    header: Label {
        text: qsTr("Page 2")
        font.pixelSize: Qt.application.font.pixelSize * 2
        padding: 10
    }

    Label {
        color: "#dd09a213"
        text: qsTr("You are on Page 2.")
        font.bold: true
        font.pointSize: 20
        anchors.centerIn: parent
    }
}
