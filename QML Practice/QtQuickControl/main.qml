import QtQuick 2.12
import QtQuick.Window 2.12
import QtQuick.Controls 2.12

Window {
    id: window
    width: 640
    height: 480
    visible: true
    title: qsTr("Progress Qt Quick Controls")

    BusyIndicator {
        id: busyIndicator
        x: 290
        y: 228
        anchors.verticalCenter: parent.verticalCenter
        anchors.horizontalCenter: parent.horizontalCenter
    }

    Dial {
        id: dial
        x: 38
        y: 203
    }

    CheckBox {
        id: checkBox
        x: 451
        y: 113
        text: qsTr("Check Box")
    }

    DelayButton {
        id: delayButton
        x: 451
        y: 210
        text: qsTr("Delay Button")
    }

    Label {
        id: label
        x: 79
        y: 96
        width: 195
        height: 14
        text: qsTr("Prograss = ") + busyIndicator.running

        MouseArea {
            id: mouseArea
            width: 100
            height: 100
            anchors.fill: parent

            onClicked: {
                if(busyIndicator.running == true)
                {
                    console.log("Turnning off")
                    busyIndicator.running = false
                }
                else
                {
                    console.log("Turnning On")
                    busyIndicator.running = true
                }
            }
        }
    }
}
