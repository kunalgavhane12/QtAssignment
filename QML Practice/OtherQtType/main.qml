import QtQuick 2.12
import QtQuick.Window 2.12
import QtQuick.Controls 2.4
import QtQml 2.0

Window {
    width: 640
    height: 480
    visible: true
    title: qsTr("String Date and Time")


    property string mValue: "Clicked %1 times, double is %2"
    property int clickCount: 0

    Connections{
        target: CppClass
        onSendDateTime:{
            console.log("Received datetime: "+ datetime)
            console.log("Year: "+ datetime.getFullYear())
            console.log("...", datetime.toGMTString())
        }
        onSendTime:{
            console.log("Received Time: " + time)
        }
    }

    Button{
        id: mButton
        text: "Click Me!"
        onClicked: {
//            CppClass.cppSlot() //C++ to Qml

            //Qc++ to QtQuick
            var date = new Date()
            CppClass.timeSlot(date)
            CppClass.dateTimeSlot(date)

            clickCount++;
            mButton.text = mValue.arg(clickCount).arg(clickCount * 2)
        }
    }
    Component.onCompleted: {
        var mDate = new Date()
        print(mDate.toLocaleDateString())
        print(mDate.toLocaleDateString(Qt.locale("de_DE")))
    }
}
