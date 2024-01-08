import QtQuick 2.0

Item {
    id: root
    signal clicked
    property color color: "white"
    property color hoverColor: "gray"
    property color textColor: "white"
    property color clickColor: "gray"
    property color textHover: "Black"
    property string text: title.text
    property string expression: ""
    property string op: ""
    property alias area: mouseArea

    property real num1: 0
    property real num2: 0
    property double result: 0

    width: 72
    height: 50

    Rectangle {
        color: root.color
        anchors.fill: parent
        radius: width
        border.color: "black"
        anchors.topMargin: 5
        anchors.leftMargin: 5

        Text {
            text: root.text
            font.bold: true
            font.pointSize: 10
            anchors.centerIn: parent
        }

        MouseArea {
            id:mouseArea
            anchors.fill: parent
            hoverEnabled: true

            onEntered:{
                parent.color = root.hoverColor
                title.color = root.textHover
            }

            onExited: {
                parent.color = root.color
                title.color = root.textColor
            }

            onPressed: parent.color = root.hoverColor
            onReleased: parent.color = root.color

            onClicked: root.clicked()

/*            onClicked:{
                if(display.displayText === "0" && root.text !== ".")
                {
                    display.displayText = root.text
                }
                else if(root.text === "AC")
                {
                    display.displayText = ""
                }
                else if(root.text === "DEL")
                {
                    display.displayText = display.displayText.slice(0, -1);
                }
                else if(root.text === "+" || root.text === "-" || root.text === "*" || root.text === "/")
                {
                    console.log("Operator pressed:", root.text);
                    op = root.text

                    display.displayText = display.displayText + root.text

                }
                else if(root.text === "=")
                {
                    expression = display.displayText
                    result = eval(expression)
                    display.displayText = result.toString();
                }
                else
                {
                    display.displayText = display.displayText + root.text
                }
            }
*/
        }
    }
}
