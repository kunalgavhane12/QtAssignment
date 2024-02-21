import QtQuick 2.12
import QtQuick.Window 2.12
import QtQuick.Controls 2.4
import QtQuick.Layouts 1.4

Window {
    width: 640
    height: 480
    visible: true
    title: qsTr("Rest Client Api")

    ColumnLayout{
        anchors.fill: parent
        spacing: 0

        ListView{
            id: mListView
            model: Wrapper
            delegate: Rectangle{
                width: parent.width
                height: textId.implicitHeight + 30
                color: "beige"
                border.color: "yellowgreen"
                radius: 5

                Text {
                    id: textId
                    width: parent.width
                    height: parent.height
                    text: modelData
                    font.pointSize: 13
                    anchors.centerIn: parent
                    wrapMode: Text.WordWrap
                    verticalAlignment: Text.AlignVCenter
                    horizontalAlignment: Text.AlignHCenter
                }
            }
            Layout.fillHeight: true
            Layout.fillWidth: true
        }

        SpinBox{
            id: spinBox
            Layout.fillWidth: true
            value: 0
        }

        Button{
            id: mButton
            text: "Fetch"
            Layout.fillWidth: true
            onClicked: {
                Wrapper.fetchPosts(5);
            }
        }

        Button{
            id: mButton1
            text: "RemoveLast"
            Layout.fillWidth: true
            onClicked: {
                Wrapper.removeLast()

            }

        }
    }

}
