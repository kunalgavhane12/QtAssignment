import QtQuick 2.12
import QtQuick.Controls 2.5
import QtQml 2.12

ApplicationWindow {
    width: 640
    height: 480
    visible: true
    title: qsTr("Scroll")

    Component {
        id: delegate
        Item{
            id: item
            width: 200
            height: 50
            Column{
                anchors.fill: parent
                spacing: 5

                Label{
                    text: name
                    font.bold: true
                }
                Label{
                    text: number
                    font.bold: true
                }
            }
        }

    }

    ListModel{
        id: model
        ListElement{
            name: "Kunal Gavhane"
            number: "7517417619"
        }
        ListElement{
            name: "Kunal Gavhane"
            number: "9922257744"
        }
        ListElement{
            name: " Kunal Gavhane"
            number: "7517417619"
        }
        ListElement{
            name: "Kunal Gavhane"
            number: "7517417619"
        }
        ListElement{
            name: "Kunal Gavhane"
            number: "7517417619"
        }
        ListElement{
            name: "Kunal Gavhane"
            number: "7517417619"
        }
        ListElement{
            name: "Kunal Gavhane"
            number: "7517417619"
        }
        ListElement{
            name: "Kunal Gavhane"
            number: "7517417619"
        }
        ListElement{
            name: "Kunal Gavhane"
            number: "7517417619"
        }
        ListElement{
            name: "Kunal Gavhane"
            number: "7517417619"
        }
        ListElement{
            name: "Kunal Gavhane"
            number: "7517417619"
        }
        ListElement{
            name: "Kunal Gavhane"
            number: "7517417619"
        }
        ListElement{
            name: "Kunal Gavhane"
            number: "7517417619"
        }
        ListElement{
            name: "Kunal Gavhane"
            number: "7517417619"
        }
        ListElement{
            name: "Kunal Gavhane"
            number: "7517417619"
        }
        ListElement{
            name: "Kunal Gavhane"
            number: "7517417619"
        }
        ListElement{
            name: "Kunal Gavhane"
            number: "7517417619"
        }
        ListElement{
            name: "Kunal Gavhane"
            number: "7517417619"
        }
        ListElement{
            name: "Kunal Gavhane"
            number: "7517417619"
        }
    }

    ScrollView {
        anchors.fill: parent

        ListView {
            width: parent.width
            model: model
            delegate: delegate
        }
    }
}
