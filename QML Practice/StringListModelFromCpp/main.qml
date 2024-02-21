import QtQuick 2.12
import QtQuick.Window 2.12

Window {
    width: 640
    height: 480
    visible: true
    title: qsTr("String List Model From C++")

    ListView{
        id: mListview
        anchors.fill: parent
        model: contienetModel
        delegate: Rectangle{
            height: 50
            width: parent.width
            radius: 10
            color: "dodgerblue"
            border.color: "cyan"

            Text {
                text: modelData
                font.pointSize: 20
                anchors.centerIn: parent
                anchors.horizontalCenter: parent.horizontalCenter
            }
        }
    }
}
