import QtQuick 2.12
import QtQuick.Controls 2.5

Page {
    width: 600
    height: 400

    header: Label {
        text: qsTr("Page 3")
        font.pixelSize: Qt.application.font.pixelSize * 2
        padding: 10
    }

    Label {
        color: "#dd6a0775"
        text: qsTr("You are on Page 3.")
        font.bold: true
        font.pointSize: 20
        anchors.centerIn: parent
    }
}
