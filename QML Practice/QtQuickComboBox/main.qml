import QtQuick 2.12
import QtQuick.Window 2.12
import QtQuick.Controls 2.3

Window {
    id: window
    width: 640
    height: 480
    visible: true
    title: qsTr("ComboBox")

    Column {
        id: column
        width: 157
        height: 185
        anchors.verticalCenter: parent.verticalCenter
        anchors.verticalCenterOffset: 1
        anchors.horizontalCenterOffset: 1
        spacing: 20
        anchors.horizontalCenter: parent.horizontalCenter

        Label {
            id: lblFood
            color: "#ed041d"
            text: qsTr("Selected Item")
            styleColor: "#060505"
            font.pointSize: 15
            font.bold: true
        }

        ComboBox {
            id: cmbFood
            model: ['Pizza', 'Steak', 'Pasta']
            onCurrentTextChanged: lblFood.text = cmbFood.currentText
        }

        Label {
            id: lblPeople
            color: "#ed041d"
            text: qsTr("Selected Item")
            styleColor: "#060505"
            font.pointSize: 15
            font.bold: true
        }

        ComboBox {
            id: cmbPeople
            editable: true
            textRole: "text"
            model: ListModel{
                id: listmodel
                ListElement{text:"a"; age: "0"}
                ListElement{text:"b"; age: "30"}
                ListElement{text:"c"; age: "40"}
                ListElement{text:"d"; age: "50"}
           }
            onCurrentIndexChanged: lblPeople.text = model.get(currentIndex).text + " = " + model.get(currentIndex).age

            onAccepted: {
                if(find(editText) === -1)
                {
                    model.append({"text": editText, "age": "0"})
                    currentIndex = find(editText)
                }
            }
        }
    }
}

/*##^##
Designer {
    D{i:0;formeditorZoom:0.9}
}
##^##*/
