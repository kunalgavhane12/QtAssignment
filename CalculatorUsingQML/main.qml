import QtQuick 2.12
import QtQuick.Window 2.12

Window {
    width: 300
    height: 400
    visible: true
    title: qsTr("Calculator")

    Display {
        id: display
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
            onClicked:{
                display.displayText = "0"
            }
        }
        Button {
            id: bracketleft
            text: "("
            onClicked:{
                if(display.displayText === "0")
                {
                    display.displayText = text
                }
                else
                {
                    display.displayText += text
                }
            }
        }
        Button {
            id: bracketright
            text: ")"
            onClicked:{
                if(display.displayText === "0")
                {
                    display.displayText = text
                }
                else
                {
                    display.displayText += text
                }
            }
        }
        Button {
            id: backspace
            text: "DEL"
            onClicked:{
                display.displayText = display.displayText.slice(0, -1);
            }
        }
        Button {
            id: seven
            text: "7"
            onClicked:{
                if(display.displayText === "0")
                {
                    display.displayText = text
                }
                else
                {
                    display.displayText += text
                }
            }
        }
        Button {
            id: eight
            text: "8"
            onClicked:{
                if(display.displayText === "0")
                {
                    display.displayText = text
                }
                else
                {
                    display.displayText += text
                }
            }
        }
        Button {
            id: nine
            text: "9"
            onClicked:{
                if(display.displayText === "0")
                {
                    display.displayText = text
                }
                else
                {
                    display.displayText += text
                }
            }
        }
        Button {
            id: divide
            text: "/"
            onClicked:{
                display.displayText += "/"
            }
        }
        Button {
            id: four
            text: "4"
            onClicked:{
                if(display.displayText === "0")
                {
                    display.displayText = text
                }
                else
                {
                    display.displayText += text
                }
            }
        }
        Button {
            id: five
            text: "5"
            onClicked:{
                if(display.displayText === "0")
                {
                    display.displayText = text
                }
                else
                {
                    display.displayText += text
                }
            }
        }
        Button {
            id: six
            text: "6"
            onClicked:{
                if(display.displayText === "0")
                {
                    display.displayText = text
                }
                else
                {
                    display.displayText += text
                }
            }
        }
        Button {
            id: multiply
            text: "*"
            onClicked:{
                display.displayText += "*"
            }
        }
        Button {
            id: one
            text: "1"
            onClicked:{
                if(display.displayText === "0")
                {
                    display.displayText = text
                }
                else
                {
                    display.displayText += text
                }
            }
        }
        Button {
            id: two
            text: "2"
            onClicked:{
                if(display.displayText === "0")
                {
                    display.displayText = text
                }
                else
                {
                    display.displayText += text
                }
            }
        }
        Button {
            id: three
            text: "3"
            onClicked:{
                if(display.displayText === "0")
                {
                    display.displayText = text
                }
                else
                {
                    display.displayText += text
                }
            }
        }
        Button {
            id: addition
            text: "+"
            onClicked:{
                display.displayText += "+"
            }
        }
        Button {
            id: percentage
            text: "%"
            onClicked:{
                display.displayText += "%"
            }
        }
        Button {
            id: zero
            text: "0"
            onClicked:{
                if(display.displayText === "0")
                {
                    display.displayText = text
                }
                else
                {
                    display.displayText += text
                }
            }
        }
        Button {
            id: dot
            text: "."

            onClicked:{

                if(display.displayText === "0" )
                {
                    display.displayText += text
                }
                else
                {
                    display.displayText += text
                }
            }

        }
        Button {
            id: equalto
            text: "="
            expression : display.displayText
            onClicked:{
                result = eval(expression)
                display.displayText = result.toString();
            }
        }
    }

    //    function updateDisplay(value)
    //    {
    //        if(display.displayText === "0")
    //        {
    //            display.displayText = text
    //        }
    //        else
    //        {
    //            display.displayText += text
    //        }
    //    }
}

