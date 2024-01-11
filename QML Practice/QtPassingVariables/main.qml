import QtQml 2.12
import QtQuick 2.12
import QtQuick.Controls 2.5

ApplicationWindow {
    width: 640
    height: 480
    visible: true
    title: qsTr("Tabs")
    id: root

    property string name: ""
    property var page1: ({})
    property var page2: ({})

    SwipeView {
        id: swipeView
        anchors.fill: parent
        currentIndex: tabBar.currentIndex

//        Page1Form {
//        }

//        Page2Form {
//        }

        Component.onCompleted:{
            var component1 = Qt.createComponent("Page1Form.ui.qml")
            page1 = component1.createObject(swipeView,{name: root.name})

            var component2 = Qt.createComponent("Page2Form.ui.qml")
            page2 = component2.createObject(swipeView,{name: root.name})

            addItem(page1)
            addItem(page2)
        }

        onCurrentIndexChanged: {
            console.log(currentIndex)
            if(currentIndex === 0)
            {
                root.name = page2.name
                page1.name = root.name
            }
            if(currentIndex === 1)
            {
                root.name = page1.name
                page2.name = root.name
            }
        }
    }

    footer: TabBar {
        id: tabBar
        currentIndex: swipeView.currentIndex

        TabButton {
            text: qsTr("Page 1")
        }
        TabButton {
            text: qsTr("Page 2")
        }
    }
}
