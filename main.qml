import QtQuick 2.3
import QtQuick.Window 2.2
import QtQuick.Controls 1.2

Window {
    visible: true
    width: 360
    height: 360

    MouseArea {
        anchors.rightMargin: 0
        anchors.bottomMargin: 0
        anchors.leftMargin: 0
        anchors.topMargin: 0
        anchors.fill: parent

        Text {
            id: textTitle
            x: 62
            y: 40
            text: qsTr("PrimeZone Cup (Deezer Test)")
            horizontalAlignment: Text.AlignHCenter
            font.pixelSize: 18
        }
        Text {
            id: textLogin
            x: 48
            y: 100
            width: 65
            height: 20
            text: qsTr("Login :")
            font.pixelSize: 18
        }

        TextField {
            id: textEditLogin
            x: 151
            y: 100
            width: 172
            height: 30
            placeholderText: qsTr("Enter Login")
            font.pixelSize: 18
        }

        Text {
            id: textPassword
            x: 48
            y: 152
            width: 65
            height: 20
            text: qsTr("Password :")
            font.pixelSize: 18
        }

        TextField {
            id: textEditPassword
            x: 151
            y: 147
            width: 172
            height: 30
            placeholderText: qsTr("Enter password")
            echoMode: TextInput.Password
            font.pixelSize: 18
        }

        Button {
            id: buttonValid
            x: 137
            y: 204
            text: qsTr("Connectez-vous")
            onClicked: {
                Qt.quit();
            }
        }
    }
}
