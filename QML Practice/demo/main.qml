import QtQuick 2.12
import QtQuick.Window 2.12

Window {
    width: 640
    height: 480
    visible: true
    title: qsTr("Hello World")

    Image {
        id: name
        source: "F:/kunal/Kunal/Fullstacks Edureka/my pic/4.png"
        width: 150
        height: 100
        opacity: 0.25
        anchors.centerIn: parent
    }

    TextInput{
        id:myInput
        text: "Hello world"
        anchors.centerIn: parent
    }
}
