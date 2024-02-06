import QtQml 2.0
import QtQuick 2.12
import QtQuick.Window 2.12
import QtQuick.Controls 2.5

Window {
    width: 640
    height: 480
    visible: true
    title: qsTr("Connection C++ Signal and slots")

    Connections{
        target: CppSignalSender
        onCallQml:{
            console.log("This is QML : callQml signal cougth")
            mText.text = parameter
        }
        onCppTimer:{
            mRectText.text = value
        }
    }

    Column{

        Rectangle{
            width: 200
            height: 200
            color: "red"
            radius: 20

            Text {
                id: mRectText
                text: qsTr("0")
                anchors.centerIn: parent
                color: "white"
                font.pointSize: 20
            }
        }

        Button{
            text: "Call C++ Method"
            onClicked: {
                CppSignalSender.cppSlot();
            }

        }
        Text {
            id: mText
            text: qsTr("Default")
        }
    }
}
