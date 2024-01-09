import QtQuick 2.12
import QtQuick.Window 2.12


Window {
    width: 300
    height: 400
    visible: true
    title: qsTr("Calculator")

    property int count: 0

    Display {
        id: display
        color: "white"
    }

    function updateDisplay(value)
    {
        var lastChar = display.displayText.charAt(display.displayText.length - 1);

        if(display.displayText === "0")
        {
            console.log("count: ",count)

            display.displayText = value
        }
        else if (value === "+" || value === "-" || value === "*" || value === "/")
        {
            count = 0
            if(lastChar === ".")
            {
                display.displayText += "0" + value

            }
            else
            {
                display.displayText += value
            }

        }
        else if (value === "(")
        {
            count = 0
            if(lastChar >= "0" && lastChar <= "9")
            {
                display.displayText += "*" + value

            }
            else
            {
                display.displayText += value

            }

        }
        else if (lastChar === ")")
        {
            count = 0
            display.displayText += "*" + value
        }
        else
        {
            console.log("count: ",count)

            display.displayText += value
        }
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
            onClicked:
            {
                display.displayText = "0"
            }
        }

        Button {
            id: bracketleft
            text: "("
            onClicked:
            {
                updateDisplay(text);
            }
        }

        Button {
            id: bracketright
            text: ")"
            onClicked:
            {
                updateDisplay(text);
            }
        }

        Button {
            id: backspace
            text: "DEL"
            onClicked:
            {
                display.displayText = display.displayText.slice(0, -1);
            }
        }

        Button {
            id: seven
            text: "7"
            onClicked:
            {
                updateDisplay(text);
            }
        }

        Button {
            id: eight
            text: "8"
            onClicked:
            {
                updateDisplay(text);
            }
        }

        Button {
            id: nine
            text: "9"
            onClicked:
            {
                updateDisplay(text);
            }
        }

        Button {
            id: divide
            text: "/"
            onClicked:
            {
                updateDisplay(text);
            }
        }

        Button {
            id: four
            text: "4"
            onClicked:
            {
                updateDisplay(text);
            }
        }

        Button {
            id: five
            text: "5"
            onClicked:
            {
                updateDisplay(text);
            }
        }

        Button {
            id: six
            text: "6"
            onClicked:
            {
                updateDisplay(text);
            }
        }

        Button {
            id: multiply
            text: "*"
            onClicked:
            {
                updateDisplay(text);
            }
        }

        Button {
            id: one
            text: "1"
            onClicked:
            {
                updateDisplay(text);
            }
        }

        Button {
            id: two
            text: "2"
            onClicked:
            {
                updateDisplay(text);
            }
        }

        Button {
            id: three
            text: "3"
            onClicked:
            {
                updateDisplay(text);
            }
        }

        Button {
            id: addition
            text: "+"
            onClicked:
            {
                updateDisplay(text);
            }
        }

        Button {
            id: percentage
            text: "%"
            onClicked:
            {
                updateDisplay(text);
            }
        }

        Button {
            id: zero
            text: "0"
            onClicked:
            {
                updateDisplay(text);
            }
        }

        Button {
            id: dot
            text: "."

            onClicked:
            {
                console.log("count: ",count)

                var lastChar = display.displayText.charAt(display.displayText.length - 1);

                if (display.displayText === "0")
                {
                    count = 1
                    display.displayText += text;
                }
                else if (lastChar === "+" || lastChar === "-" || lastChar === "*" || lastChar === "/")
                {
                    count = 1
                    updateDisplay("0" + text);
                }
                else if (lastChar >= "0" && lastChar <= "9" && count == 0 )
                {
                    count = 1
                    updateDisplay(text);
                }
                else
                {

                }
            }
        }

        Button {
            id: equalto
            text: "="
            expression: display.displayText
            onClicked:
            {
                result = eval(expression)
                display.displayText = result.toString();
            }
        }
    }
}
