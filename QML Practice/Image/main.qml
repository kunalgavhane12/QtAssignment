import QtQuick 2.12
import QtQuick.Window 2.12

Window {
    width: 640
    height: 480
    visible: true
    title: qsTr("Hello World")

    property real middle: height / 2

    Image {
        id: localImage
        source: "qrc:/images/C:/Users/Dell/Pictures/smile.png"

        width: 300
        fillMode: Image.PreserveAspectFit

        x: 300
        y: middle - 100
    }

    Image {
        id: remoteImage
        source: "https://upload.wikimedia.org/wikipedia/commons/f/fc/Qt_logo_2013.svg"
        width: 100
        fillMode: Image.PreserveAspectFit
        x: 100
        y: middle
        onProgressChanged: console.log(remoteImage.progress)
        onStatusChanged: if(remoteImage.status == Image.Ready) console.log("Remote image was loaded")
    }
}
