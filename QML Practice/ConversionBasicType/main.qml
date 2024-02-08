import QtQuick 2.12
import QtQuick.Window 2.12
import QtQuick.Controls 2.4
import QtQml 2.0

Window {
    width: 640
    height: 480
    visible: true
    title: qsTr("Data Convsersion: Basic Types")

    Connections {
        target: CppClass

        onSendInt:{
            console.log("Received Int: " + param + " ,type is: " + typeof param)
        }

        onSendDouble:{
            console.log("Received Double: " + d + " , type is: " + typeof d)
        }

        onSendBoolRealFloat:{
            console.log("Received Bool: " + a + " , type is: " + typeof a)
            console.log("Received Real: " + b + " , type is: " + typeof b)
            console.log("Received Float: " + c + " , type is: " + typeof c)

        }
        onSendStringUrl:{
            console.log("Received String: " + s + " , type is: " + typeof s)
            console.log("Received URl: " + url + " , type is: " + typeof url)
        }
        onSendColorFont:{
            console.log("Received Color: " + c + " , type is: " + typeof c)
            console.log("Received Font: " + cf + " , type is: " + typeof cf.family)

            console.log("Color Component: Red: " + c.r + " ,Green: " + c.g + " , blue: " + c.b)
            console.log("Font Family: " + cf.family)
            console.log("Font Bold: " + cf.bold)

            mrect.color = c
            mButton.font = cf
        }
        onSendDate:{
            console.log("Received Date: " + d + " , type is: " + typeof d)
            console.log("Year is: " + d.getFullYear())
            console.log("Month is: " + d.getUTCMonth())
            console.log("Day is: " + d.getDay())
            console.log("The Day of the Month is: " + d.getDate())

        }
        onSendPoint:{
            console.log("Received Point: " + p + "type is " + typeof p)
            console.log("Received PointF: " + pf + "type is " + typeof pf)

            console.log("Point.x: " + p.x + "\npoint.y: " + p.y
                        + "\npointF.x: " + pf.x + "\npointF.y: " + pf.y)
        }
        onSendSize:{
            console.log("Received Size: " + s + " type is " + typeof s)
            console.log("Received SizeF: " + sf + " type is " + typeof sf)

            console.log("Size.width: " + s.width + " Size.height: " + s.height
                        + "\nSizeF.width: " + sf.x + " SizeF.height: " + sf.height)
        }
        onSendRect:{
            console.log("Received Rect: " + r + " type is " + typeof r)
            console.log("Received RectF: " + rf + " type is " + typeof rf)

            console.log("Rect.x: " + r.x + " Rect.y: " + r.y +
                        "\nRect.width: " + r.width + " Rect.height: " + r.height
                        + "\nRectF.x: " + rf.x + " RectF.y: " + rf.y +
                        "\nRectF.width: " + rf.width + " RectF.height: " + rf.height)
        }

    }

    Rectangle{
        id: mrect
        anchors.horizontalCenter:  parent.horizontalCenter
        color: "black"
        width: 200
        height: 200
        radius: 20
    }

    Button{
        id: mButton
        text: "Click Me!"
        anchors.centerIn: parent
        onClicked: {
//            CppClass.cppSlot()
            CppClass.receivedPoint(Qt.point(200,300))
            CppClass.receivedRect(Qt.rect(40.10,40,100,100))
        }
    }

}
