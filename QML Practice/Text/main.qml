import QtQuick 2.12
import QtQuick.Window 2.12

Window {
    width: 640
    height: 480
    visible: true
    title: qsTr("Hello World")

    Text {
        id: myText
        text: qsTr("<html><b>Hello</b> <i><font color='green'>World</font></i></html><br>
<a href='http://www.google.com'>Google link</a>")
        anchors.centerIn: parent
        font.pointSize: 35
        color: "red"
        linkColor: "blue"

        onLinkHovered: {
            console.log("Hover: " + link)
            if(link)
            {
                myText.font.bold = true
            }
            else
            {
                myText.font.bold = false
            }
        }
        onLinkActivated: Qt.openUrlExternally(link)
    }
}
