import QtQuick 2.12
import QtQuick.Window 2.12
import QtQuick.Controls 2.5
import QtQml 2.0

Window {
    width: 640
    height: 480
    visible: true
    title: qsTr("Call C++ from qml")

    Column{
        spacing: 10
        Button{
            text: "C++ call Method"
            onClicked: {
                BWorker.regulerMethod()
                BWorker.cppSlot()
            }
        }
        Rectangle{
            width: txtname.implicitWidth +20
            height:20
            color: "beige"
            Text {
                id: txtname
                text: BWorker.regularMethodWithReturn("kunalGavhane", 29)
            }
        }
    }

    Component.onCompleted:{
        BWorker.cppSlot();
    }

}
