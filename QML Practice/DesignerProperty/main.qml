import QtQuick 2.12
import QtQuick.Window 2.12
import CalculatorStateMachine 1.0

Window {
    width: 640
    height: 480
    visible: true
    property CalculatorStateMachine calculatorStateMachine: null
    title: qsTr("Hello World")

    Rectangle {
        id: rectangle
        x: 130
        y: 123
        width: 131
        height: 73
        opacity: none.none
        color: "#a55cff"
        radius: 10
        border.color: "#f7000000"
        border.width: 5
        z: none.none
        parent: none.none
        border.objectName: none.none
        border.pixelAligned: none.none
        property string property0: "none.none"
        gradient: Gradient {
            orientation: Gradient.Vertical
            GradientStop {
                position: 0
                color: "#2219b4"
            }

            GradientStop {
                position: 1
                color: "#000000"
            }
        }

        Rectangle {
            id: rectangle2
            x: 303
            y: 0
            width: 131
            height: 73
            radius: 10
            border.color: "#f7000000"
            border.width: 5
            gradient: Gradient {
                orientation: Gradient.Vertical
                GradientStop {
                    position: 0
                    color: "#ff0000"
                }

                GradientStop {
                    position: 1
                    color: "#000000"
                }
            }

            Rectangle {
                id: rectangle1
                x: -145
                y: 0
                width: 131
                height: 73
                color: none.none
                radius: 10
                border.color: "#f7000000"
                border.width: 5
                property string property0: "none.none"
                gradient: Gradient {
                    orientation: Gradient.Vertical
                    GradientStop {
                        position: 0
                        color: "#3f8a4c"
                    }

                    GradientStop {
                        position: 1
                        color: "#000000"
                    }
                }

            }
        }
    }

}

