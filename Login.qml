import QtQuick 2.15
import QtQuick.Controls 2.15
import QtQuick.Layouts 1.15

Dialog {
    id: loginDialog
    modal: true
    title: "ورود به سیستم"
    standardButtons: DialogButtonBox.Cancel

    property var users: []

    width: Math.min(350, parent.width * 0.9)
    height: Math.min(300, parent.height * 0.9)

    function authenticate(username, password) {
        for (var i = 0; i < users.length; i++) {
            if (users[i].username === username && users[i].password === password) {
                return users[i]
            }
        }
        return null
    }

    contentItem: ColumnLayout {
        spacing: 20

        TextField {
            id: usernameField
            placeholderText: "نام کاربری"
            Layout.fillWidth: true
            selectByMouse: true
        }

        TextField {
            id: passwordField
            placeholderText: "رمز عبور"
            echoMode: TextField.Password
            Layout.fillWidth: true
            selectByMouse: true
        }

        Text {
            id: errorText
            color: "red"
            visible: text !== ""
            Layout.fillWidth: true
            wrapMode: Text.Wrap
        }

        Button {
            text: "ورود"
            Layout.fillWidth: true
            background: Rectangle {
                color: "#4CAF50"
                radius: 5
            }
            contentItem: Text {
                text: parent.text
                color: "white"
                horizontalAlignment: Text.AlignHCenter
                verticalAlignment: Text.AlignVCenter
            }
            onClicked: {
                var user = authenticate(usernameField.text, passwordField.text)
                if (user) {
                    welcomeDialog.username = user.username
                    welcomeDialog.open()
                    loginDialog.close()
                } else {
                    errorText.text = "اطلاعات وارد شده نامعتبر است"
                }
            }
        }
    }

    Dialog {
        id: welcomeDialog
        modal: true
        title: "خوش آمدید"
        standardButtons: DialogButtonBox.Ok
        width: Math.min(300, parent.width * 0.8)

        property string username: ""

        Label {
            text: "خوش آمدید، " + welcomeDialog.username + "!"
            font.pixelSize: 16
            anchors.centerIn: parent
        }
    }

    Behavior on opacity {
        NumberAnimation { duration: 200 }
    }
}
