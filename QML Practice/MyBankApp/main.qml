import QtQuick 2.12
import QtQuick.Window 2.12
import QtQuick.Controls 2.3
import QtQml 2.12

import "backend.js" as Backend

Window {
    width: 640
    height: 480
    visible: true
    title: qsTr("Bank App")
    id: root

    property color backgroundColor: "lightgrey"
    property color textColor: "black"
    property color appColor: "blue"
    property color popupBackgroundColor: "red"
    property color popupTextColor: "black"
    property string username: "admin@gmail.com"
    property string password: "Admin@123"
    property string name: "Admin"
    property string accountBalance: "0.00"
    property string accountNumber: "123456789"
    property var dataBase


    StackView{
        id: stackView
        focus: true
        anchors.fill: parent
    }

    Component.onCompleted: {
        stackView.push("qrc:/Login.qml")
        dataBase = userDatabase()
    }

    Popup{

        id: popup
        property alias popMessage: message.text

        background: Rectangle{
            implicitHeight: 60
            implicitWidth: root.width
            color: popupBackgroundColor
        }
        y: (root.height - 60)
        modal: true
        focus: true
        closePolicy: Popup.CloseOnEscape | Popup.CloseOnPressOutside

        Text {
            id: message
            anchors.centerIn: parent
            font.pointSize: 12
            color: popupTextColor
        }
        onOpened: popupClose.start()
    }
    Timer{
        id: popupClose
        interval: 2000
        onTriggered: popup.close()
    }

    function userDatabase(){
        var db = LocalStorage.openDatabaseSync("Bank", "1.0", "Bank Details", 1000000)
        db.transaction(function(tx) {
            tx.executeSql('CREATE TABLE IF NOT EXISTS UserDetails(AccountNumber INT, Name TEXT, Email TEXT, Balance REAL, Username TEXT, Password TEXT)');
        })

        return db;

    }

    function loginUser(uname, pword){

        if(Backend.validateUserCredentials(uname, pword))
        {
            popup.popMessage = "Missing credentials!"
            popup.open()
            return
        }

        if(!Backend.isValidEmail(uname))
        {
            popup.popMessage = "Invalid email!"
            popup.open()
            return
        }

        if(!Backend.isValidPassword(pword))
        {
            popup.popMessage = "Password must have at least one digit, one lowercase, one uppercase,
 one special character and be at least 8 character long."
            popup.open()
            return
        }

        if(username === uname && password === pword)
        {
            stackView.replace("qrc:/accountPage.qml")
            //current user details assign
            /*name = uname
            username =uname
            accountBalance = balance
            accountNumber = AccountNumber*/

        }
        else
        {
            popup.popMessage = "Invalid credentials!"
            popup.open()
        }
    }

}
