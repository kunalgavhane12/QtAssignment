import QtQuick 2.12
import QtQuick.Window 2.12
import QtQuick.Controls 2.5
import com.blikoon.counter 1.0
Window {
    width: 640
    height: 480
    visible: true
    title: qsTr("Counter Type Demo")

    Counter{
        id: mCounter
    }

    Column{
        anchors.centerIn: parent
        spacing: 10

        Rectangle{
            width: 200
            height: 200
            color: "red"
            radius: height

            Text {
                anchors.centerIn:  parent
                id: textId
                text: mCounter.count
                color: "white"
                font.pointSize: 30
            }

        }
        Button{
            width: 200
            text: "Start"
            onClicked: {
                mCounter.start()
            }
        }
        Button{
            width: 200
            text: "Up"
            onClicked: {

                mCounter.up = true
            }
        }
        Button{
            width: 200
            text: "Down"
            onClicked: {
                mCounter.up = false
            }
        }
        Button{
            width: 200
            text: "Stop"
            onClicked: {
                mCounter.stop()
            }
        }
    }
}
