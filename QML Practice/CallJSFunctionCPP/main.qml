import QtQuick 2.12
import QtQuick.Window 2.12
import QtQuick.Controls 2.4

Window {
    width: 640
    height: 480
    visible: true
    title: qsTr("Call JS from C++")

    function qmlJSFunction(param){
        console.log("QML Talking, C++ called me with parameter: " + param + "returning back")
        return "This is qml, over to you c++, thank for the call."
    }

    Button{
        id : mButton
        text : "Call Qml Function from c++"
        onClicked: {
            QmlJsCaller.cppMethod("Qml Calling ");
        }
    }
}
