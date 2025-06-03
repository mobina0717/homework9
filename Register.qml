import QtQuick 2.15
import QtQuick.Controls 2.15
import QtQuick.Layouts 1.15

Dialog {
    id: registerDialog
    modal: true
    title: "ثبت‌نام کاربر جدید"
    standardButtons: DialogButtonBox.Cancel

    property alias users: users
    signal userRegistered(var userData)

    width: Math.min(400, parent.width * 0.9)
    height: Math.min(500, parent.height * 0.9)

    function validate() {
        if (usernameField.text.trim() === "") {
            errorText.text = "نام کاربری نمی‌تواند خالی باشد"
            return false
        }
        if (passwordField.text.trim() === "") {
            errorText.text = "رمز عبور نمی‌تواند خالی باشد"
            return false
        }
        if (fullnameField.text.trim() === "") {
            errorText.text = "نام کامل نمی‌تواند خالی باشد"
            return false
        }
        if (emailField.text.trim() === "") {
            errorText.text = "ایمیل نمی‌تواند خالی باشد"
            return false
        }
        if (ageField.text === "" || parseInt(ageField.text) < 13) {
            errorText.text = "سن باید بیشتر یا مساوی ۱۳ سال باشد"
            return false
        }
        return true
    }

    contentItem: ColumnLayout {
        spacing: 15

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

        TextField {
            id: fullnameField
            placeholderText: "نام کامل"
            Layout.fillWidth: true
            selectByMouse: true
        }

        TextField {
            id: emailField
            placeholderText: "ایمیل"
            inputMethodHints: Qt.ImhEmailCharactersOnly
            Layout.fillWidth: true
            selectByMouse: true
        }

        TextField {
            id: ageField
            placeholderText: "سن"
            validator: IntValidator { bottom: 13 }
            inputMethodHints: Qt.ImhDigitsOnly
            Layout.fillWidth: true
            selectByMouse: true
        }

        ComboBox {
            id: genderField
            model: ["مرد", "زن"]
            currentIndex: 0
            Layout.fillWidth: true
        }

        Text {
            id: errorText
            color: "red"
            visible: text !== ""
            Layout.fillWidth: true
            wrapMode: Text.Wrap
        }

        Button {
            text: "ثبت‌نام"
            Layout.fillWidth: true
            background: Rectangle {
                color: "#2196F3"
                radius: 5
            }
            contentItem: Text {
                text: parent.text
                color: "white"
                horizontalAlignment: Text.AlignHCenter
                verticalAlignment: Text.AlignVCenter
            }
            onClicked: {
                if (validate()) {
                    var userData = {
                        username: usernameField.text,
                        password: passwordField.text,
                        fullname: fullnameField.text,
                        email: emailField.text,
                        age: parseInt(ageField.text),
                        gender: genderField.currentText
                    }
                    registerDialog.userRegistered(userData)
                    registerDialog.close()
                }
            }
        }
    }

    Behavior on opacity {
        NumberAnimation { duration: 200 }
    }
}
