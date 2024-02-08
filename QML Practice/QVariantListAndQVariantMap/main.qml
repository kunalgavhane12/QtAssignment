import QtQuick 2.12
import QtQuick.Window 2.12
import QtQuick.Controls 2.4
import QtQml 2.0

Window {
    width: 640
    height: 480
    visible: true
    title: qsTr("QVariantList and QVariantMap")

    //JavaScript Function
    function arrayObjectFunc(array, object){
        console.log("----Printing Array----")
        array.forEach(function(element){
            console.log("Array Item : " + element)
        })

        console.log("---Printing Object---")
        for(var mKey in object){
            console.log("Object["+mKey+"] : " + object[mKey])
        }
    }

    Column{

        anchors.centerIn: parent

        Button{
            id: button1
            text: "Pass data to Cpp"
            onClicked: {
                var arr = ['Africa', 'Asia', 'Europe', 'North America'];
                var obj = {
                    firstName: "John",
                    lastName: "Doe",
                    location: "Earth"
                }

                CppClass.passFromQmlToCpp(arr,obj);

            }
        }
        Button{
            id: button2
//            anchors.top: button1.bottom
            text: "GetVariantListFromCpp"
            onClicked: {
                var data = CppClass.getVariantListFromCpp()

                data.forEach(function(element){
                    console.log("Array Item : "+ element)
                })
            }
        }
        Button{
            id: button3
//            anchors.top: button2.bottom
            text: "GetVariantMapFromCpp"
            onClicked: {
                var data = CppClass.getVariantMapFromCpp()
                for(var mKey in data){
                    console.log("Object["+mKey+"] : " + data[mKey])
                }

            }
        }
        Button{
            id:button4
            text:"TriggerCall"
            onClicked: {
                CppClass.triggerJSCall()
            }
        }
    }

}
