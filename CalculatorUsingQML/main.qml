import QtQuick 2.12
import QtQuick.Window 2.12

Window {
    width: 300
    height: 400
    visible: true
    title: qsTr("Calculator")

    Display {
        id: display
        text: "0"
        color: "white"
    }

    Grid {
        anchors.topMargin: 5
        anchors.top: display.bottom
        anchors.left: display.left
        height: 300
        spacing: 1
        rows: 5
        columns: 4

        Button {
            id: ac
            text: "AC"
        }
        Button {
            id: bracketleft
            text: "("
        }
        Button {
            id: bracketright
            text: ")"
        }
        Button {
            id: backspace
            text: "DEL"
        }
        Button {
            id: seven
            text: "7"
        }
        Button {
            id: eight
            text: "8"
        }
        Button {
            id: nine
            text: "9"
        }
        Button {
            id: divide
            text: "/"
        }
        Button {
            id: four
            text: "4"
        }
        Button {
            id: five
            text: "5"
        }
        Button {
            id: six
            text: "6"
        }
        Button {
            id: multiply
            text: "*"
        }
        Button {
            id: one
            text: "1"
        }
        Button {
            id: two
            text: "2"
        }
        Button {
            id: three
            text: "3"
        }
        Button {
            id: addition
            text: "+"
        }
        Button {
            id: percentage
            text: "%"
        }
        Button {
            id: zero
            text: "0"
        }
        Button {
            id: dot
            text: "."
        }
        Button {
            id: equalto
            text: "="
        }
    }
}

