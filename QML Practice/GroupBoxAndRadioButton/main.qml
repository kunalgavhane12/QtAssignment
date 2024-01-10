import QtQuick 2.12
import QtQuick.Window 2.12
import QtQuick.Controls 2.3
import QtQml 2.12

Window {
    id: window
    width: 640
    height: 480
    visible: true
    title: qsTr("GroupBox and Radio Button")

    property string strDrink: ""
    property string strFood: ""

    Popup{
        id: popup
        anchors.centerIn: parent
        width: 200
        height: 150
        modal: true
        focus: true
        closePolicy: Popup.CloseOnEscape | Popup.CloseOnPressOutside

        Column{
            anchors.fill: parent
            spacing: 25
            Label{
                id: ldlDetails
                text: strFood + " With " + strDrink
            }

            Button{
                id: closeButton
                text: "Close"
                onClicked: {
//                    popup.close()
                    popup.visible = false
                }

            }
        }

    }

    Row {
        id: row
        width: 432
        height: 196
        spacing: 25
        anchors.verticalCenter: parent.verticalCenter
        anchors.horizontalCenter: parent.horizontalCenter

        GroupBox {
            id: groupBox
            width: 200
            height: 190
            title: qsTr("Foods")

            Column {
                id: colFood
                spacing: 5
                anchors.fill: parent

                RadioButton {
                    id: rdoFish
                    text: qsTr("Fish")
                }

                RadioButton {
                    id: rdoSteak
                    text: qsTr("Steak")
                }

                RadioButton {
                    id: rdoVegan
                    text: qsTr("Vegan")
                }
            }
        }

        GroupBox {
            id: groupBox1
            width: 200
            height: 190
            title: qsTr("Drinks")

            Column {
                id: colDrink
                spacing: 5
                anchors.fill: parent

                RadioButton {
                    id: rdoWater
                    text: qsTr("Water")
                }

                RadioButton {
                    id: rdoWine
                    text: qsTr("Wine")
                }

                RadioButton {
                    id: rdoSoda
                    text: qsTr("Soda")
                }
            }
        }
    }

    Button {
        id: button
        x: 270
        y: 367
        text: qsTr("Click Me")
        anchors.horizontalCenterOffset: -10
        anchors.horizontalCenter: parent.horizontalCenter

        Connections {
            target: button
            onClicked:{
                for(var i = 0; i < colFood.children.length ; i++ )
                {
                    var rdo = colFood.children[i]

                    if(rdo.checked)
                        strFood = rdo.text
                }
                for(var i = 0; i < colDrink.children.length ; i++ )
                {
                    var rdo = colDrink.children[i]

                    if(rdo.checked)
                        strDrink = rdo.text
                }
//                popup.open()
                popup.visible = true
            }
        }
    }
}

/*##^##
Designer {
    D{i:0;formeditorZoom:0.9}D{i:3}D{i:8}
}
##^##*/
