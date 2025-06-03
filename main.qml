import QtQuick 2.15
import QtQuick.Controls 2.15
import QtQuick.Layouts 1.15
import QtQuick.Window 2.15

ApplicationWindow {
    id: mainWindow
    width: 400
    height: 300
    visible: true
    title: qsTr("سیستم احراز هویت کاربر")

    property var users: []

    Rectangle {
        anchors.fill: parent
        gradient: Gradient {
            GradientStop { position: 0; color: "#f5f7fa" }
            GradientStop { position: 1; color: "#c3cfe2" }
        }

        ColumnLayout {
            anchors.centerIn: parent
            spacing: 30

            Text {
                text: "سیستم احراز هویت کاربر"
                font.pixelSize: 24
                font.bold: true
                Layout.alignment: Qt.AlignHCenter
                color: "#333"
            }

            RowLayout {
                spacing: 20
                Layout.alignment: Qt.AlignHCenter

                Button {
                    text: "ورود"
                    background: Rectangle {
                        color: "#4CAF50"
                        radius: 5
                    }
                    contentItem: Text {
                        text: parent.text
                        color: "white"
                        horizontalAlignment: Text.AlignHCenter
                    }
                    onClicked: loginPopup.open()
                }

                Button {
                    text: "ثبت‌نام"
                    background: Rectangle {
                        color: "#2196F3"
                        radius: 5
                    }
                    contentItem: Text {
                        text: parent.text
                        color: "white"
                        horizontalAlignment: Text.AlignHCenter
                    }
                    onClicked: registerPopup.open()
                }
            }
        }
    }

    Popup {
        id: registerPopup
        width: 350
        height: 450
        modal: true
        focus: true
        closePolicy: Popup.CloseOnEscape | Popup.CloseOnPressOutside

        ColumnLayout {
            anchors.fill: parent
            anchors.margins: 15
            spacing: 10

            Label {
                text: "ثبت نام کاربر جدید"
                font.bold: true
                font.pixelSize: 16
                Layout.alignment: Qt.AlignHCenter
            }

            TextField {
                id: regUsername
                placeholderText: "نام کاربری"
                Layout.fillWidth: true
            }

            TextField {
                id: regPassword
                placeholderText: "رمز عبور"
                echoMode: TextField.Password
                Layout.fillWidth: true
            }

            TextField {
                id: regFullName
                placeholderText: "نام کامل"
                Layout.fillWidth: true
            }

            TextField {
                id: regEmail
                placeholderText: "ایمیل"
                Layout.fillWidth: true
                inputMethodHints: Qt.ImhEmailCharactersOnly
            }

            TextField {
                id: regAge
                placeholderText: "سن"
                validator: IntValidator { bottom: 13 }
                Layout.fillWidth: true
                inputMethodHints: Qt.ImhDigitsOnly

                onTextChanged: {
                    if(text && parseInt(text) < 13) {
                        ageError.visible = true
                    } else {
                        ageError.visible = false
                    }
                }
            }

            Label {
                id: ageError
                text: "سن باید حداقل ۱۳ سال باشد"
                color: "red"
                visible: false
                font.pixelSize: 12
            }

            ComboBox {
                id: regGender
                model: ["مرد", "زن"]
                Layout.fillWidth: true
            }

            Label {
                id: regError
                color: "red"
                visible: false
                Layout.fillWidth: true
                wrapMode: Text.Wrap
            }

            RowLayout {
                Layout.alignment: Qt.AlignRight
                spacing: 10

                Button {
                    text: "انصراف"
                    onClicked: registerPopup.close()
                }

                Button {
                    text: "ثبت نام"
                    background: Rectangle {
                        color: "#2196F3"
                        radius: 5
                    }
                    contentItem: Text {
                        text: parent.text
                        color: "white"
                        horizontalAlignment: Text.AlignHCenter
                    }
                    onClicked: {
                        if(regAge.text === "" || parseInt(regAge.text) < 13) {
                            regError.text = "لطفاً سن معتبر وارد کنید (حداقل ۱۳ سال)"
                            regError.visible = true
                            return
                        }

                        if(regUsername.text === "" || regPassword.text === "") {
                            regError.text = "لطفاً نام کاربری و رمز عبور را وارد کنید"
                            regError.visible = true
                            return
                        }

                        var newUser = {
                            username: regUsername.text,
                            password: regPassword.text,
                            fullname: regFullName.text,
                            email: regEmail.text,
                            age: parseInt(regAge.text),
                            gender: regGender.currentText
                        }

                        mainWindow.users.push(newUser)
                        registerPopup.close()
                        successPopup.text = "ثبت نام با موفقیت انجام شد!"
                        successPopup.open()
                    }
                }
            }
        }
    }

    Popup {
        id: loginPopup
        width: 300
        height: 200
        modal: true
        focus: true

        ColumnLayout {
            anchors.fill: parent
            anchors.margins: 15
            spacing: 10

            Label {
                text: "ورود به سیستم"
                font.bold: true
                font.pixelSize: 16
                Layout.alignment: Qt.AlignHCenter
            }

            TextField {
                id: loginUsername
                placeholderText: "نام کاربری"
                Layout.fillWidth: true
            }

            TextField {
                id: loginPassword
                placeholderText: "رمز عبور"
                echoMode: TextField.Password
                Layout.fillWidth: true
            }

            Label {
                id: loginError
                color: "red"
                visible: false
                Layout.fillWidth: true
            }

            RowLayout {
                Layout.alignment: Qt.AlignRight
                spacing: 10

                Button {
                    text: "انصراف"
                    onClicked: loginPopup.close()
                }

                Button {
                    text: "ورود"
                    background: Rectangle {
                        color: "#4CAF50"
                        radius: 5
                    }
                    contentItem: Text {
                        text: parent.text
                        color: "white"
                        horizontalAlignment: Text.AlignHCenter
                    }
                    onClicked: {
                        var userFound = false
                        for(var i = 0; i < mainWindow.users.length; i++) {
                            if(mainWindow.users[i].username === loginUsername.text &&
                               mainWindow.users[i].password === loginPassword.text) {
                                userFound = true
                                break
                            }
                        }

                        if(userFound) {
                            successPopup.text = "خوش آمدید، " + loginUsername.text + "!"
                            successPopup.open()
                            loginPopup.close()
                        } else {
                            loginError.text = "نام کاربری یا رمز عبور اشتباه است"
                            loginError.visible = true
                        }
                    }
                }
            }
        }
    }

    Popup {
        id: successPopup
        width: 250
        height: 100
        modal: true
        x: (parent.width - width) / 2
        y: (parent.height - height) / 2

        property alias text: successText.text

        Label {
            id: successText
            anchors.centerIn: parent
            font.pixelSize: 14
        }

        Button {
            text: "تأیید"
            anchors.bottom: parent.bottom
            anchors.horizontalCenter: parent.horizontalCenter
            onClicked: successPopup.close()
        }
    }
}
