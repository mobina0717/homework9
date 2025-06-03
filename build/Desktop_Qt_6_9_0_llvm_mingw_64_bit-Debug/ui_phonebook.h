/********************************************************************************
** Form generated from reading UI file 'phonebook.ui'
**
** Created by: Qt User Interface Compiler version 6.9.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_PHONEBOOK_H
#define UI_PHONEBOOK_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_PhoneBook
{
public:
    QAction *actionSave;
    QAction *actionLoad;
    QAction *actionExport;
    QAction *actionImport;
    QWidget *centralwidget;
    QGridLayout *gridLayout;
    QLineEdit *searchEdit;
    QPushButton *searchBtn;
    QListWidget *contactsList;
    QVBoxLayout *verticalLayout;
    QLineEdit *nameEdit;
    QPushButton *addContactBtn;
    QPushButton *editContactBtn;
    QPushButton *deleteContactBtn;
    QLineEdit *phoneTypeEdit;
    QLineEdit *phoneNumberEdit;
    QPushButton *addPhoneBtn;
    QPushButton *editPhoneBtn;
    QPushButton *deletePhoneBtn;
    QSpacerItem *verticalSpacer;
    QVBoxLayout *verticalLayout_2;
    QListWidget *phoneNumbersList;
    QListWidget *favoritesList;
    QPushButton *addFavoriteBtn;
    QPushButton *removeFavoriteBtn;
    QPushButton *moveUpBtn;
    QPushButton *moveDownBtn;
    QPushButton *saveBtn;
    QPushButton *loadBtn;
    QPushButton *exportBtn;
    QPushButton *importBtn;
    QMenuBar *menubar;
    QMenu *menuFile;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *PhoneBook)
    {
        if (PhoneBook->objectName().isEmpty())
            PhoneBook->setObjectName("PhoneBook");
        PhoneBook->resize(800, 600);
        actionSave = new QAction(PhoneBook);
        actionSave->setObjectName("actionSave");
        actionLoad = new QAction(PhoneBook);
        actionLoad->setObjectName("actionLoad");
        actionExport = new QAction(PhoneBook);
        actionExport->setObjectName("actionExport");
        actionImport = new QAction(PhoneBook);
        actionImport->setObjectName("actionImport");
        centralwidget = new QWidget(PhoneBook);
        centralwidget->setObjectName("centralwidget");
        gridLayout = new QGridLayout(centralwidget);
        gridLayout->setObjectName("gridLayout");
        searchEdit = new QLineEdit(centralwidget);
        searchEdit->setObjectName("searchEdit");

        gridLayout->addWidget(searchEdit, 0, 0, 1, 3);

        searchBtn = new QPushButton(centralwidget);
        searchBtn->setObjectName("searchBtn");

        gridLayout->addWidget(searchBtn, 1, 0, 1, 3);

        contactsList = new QListWidget(centralwidget);
        contactsList->setObjectName("contactsList");

        gridLayout->addWidget(contactsList, 2, 0, 1, 1);

        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName("verticalLayout");
        nameEdit = new QLineEdit(centralwidget);
        nameEdit->setObjectName("nameEdit");

        verticalLayout->addWidget(nameEdit);

        addContactBtn = new QPushButton(centralwidget);
        addContactBtn->setObjectName("addContactBtn");

        verticalLayout->addWidget(addContactBtn);

        editContactBtn = new QPushButton(centralwidget);
        editContactBtn->setObjectName("editContactBtn");

        verticalLayout->addWidget(editContactBtn);

        deleteContactBtn = new QPushButton(centralwidget);
        deleteContactBtn->setObjectName("deleteContactBtn");

        verticalLayout->addWidget(deleteContactBtn);

        phoneTypeEdit = new QLineEdit(centralwidget);
        phoneTypeEdit->setObjectName("phoneTypeEdit");

        verticalLayout->addWidget(phoneTypeEdit);

        phoneNumberEdit = new QLineEdit(centralwidget);
        phoneNumberEdit->setObjectName("phoneNumberEdit");

        verticalLayout->addWidget(phoneNumberEdit);

        addPhoneBtn = new QPushButton(centralwidget);
        addPhoneBtn->setObjectName("addPhoneBtn");

        verticalLayout->addWidget(addPhoneBtn);

        editPhoneBtn = new QPushButton(centralwidget);
        editPhoneBtn->setObjectName("editPhoneBtn");

        verticalLayout->addWidget(editPhoneBtn);

        deletePhoneBtn = new QPushButton(centralwidget);
        deletePhoneBtn->setObjectName("deletePhoneBtn");

        verticalLayout->addWidget(deletePhoneBtn);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Expanding);

        verticalLayout->addItem(verticalSpacer);


        gridLayout->addLayout(verticalLayout, 2, 1, 1, 1);

        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setObjectName("verticalLayout_2");
        phoneNumbersList = new QListWidget(centralwidget);
        phoneNumbersList->setObjectName("phoneNumbersList");

        verticalLayout_2->addWidget(phoneNumbersList);

        favoritesList = new QListWidget(centralwidget);
        favoritesList->setObjectName("favoritesList");

        verticalLayout_2->addWidget(favoritesList);

        addFavoriteBtn = new QPushButton(centralwidget);
        addFavoriteBtn->setObjectName("addFavoriteBtn");

        verticalLayout_2->addWidget(addFavoriteBtn);

        removeFavoriteBtn = new QPushButton(centralwidget);
        removeFavoriteBtn->setObjectName("removeFavoriteBtn");

        verticalLayout_2->addWidget(removeFavoriteBtn);

        moveUpBtn = new QPushButton(centralwidget);
        moveUpBtn->setObjectName("moveUpBtn");

        verticalLayout_2->addWidget(moveUpBtn);

        moveDownBtn = new QPushButton(centralwidget);
        moveDownBtn->setObjectName("moveDownBtn");

        verticalLayout_2->addWidget(moveDownBtn);


        gridLayout->addLayout(verticalLayout_2, 2, 2, 1, 1);

        saveBtn = new QPushButton(centralwidget);
        saveBtn->setObjectName("saveBtn");

        gridLayout->addWidget(saveBtn, 3, 0, 1, 1);

        loadBtn = new QPushButton(centralwidget);
        loadBtn->setObjectName("loadBtn");

        gridLayout->addWidget(loadBtn, 3, 1, 1, 1);

        exportBtn = new QPushButton(centralwidget);
        exportBtn->setObjectName("exportBtn");

        gridLayout->addWidget(exportBtn, 3, 2, 1, 1);

        importBtn = new QPushButton(centralwidget);
        importBtn->setObjectName("importBtn");

        gridLayout->addWidget(importBtn, 4, 0, 1, 3);

        PhoneBook->setCentralWidget(centralwidget);
        menubar = new QMenuBar(PhoneBook);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 800, 22));
        menuFile = new QMenu(menubar);
        menuFile->setObjectName("menuFile");
        PhoneBook->setMenuBar(menubar);
        statusbar = new QStatusBar(PhoneBook);
        statusbar->setObjectName("statusbar");
        PhoneBook->setStatusBar(statusbar);

        menubar->addAction(menuFile->menuAction());
        menuFile->addAction(actionSave);
        menuFile->addAction(actionLoad);
        menuFile->addAction(actionExport);
        menuFile->addAction(actionImport);

        retranslateUi(PhoneBook);

        QMetaObject::connectSlotsByName(PhoneBook);
    } // setupUi

    void retranslateUi(QMainWindow *PhoneBook)
    {
        PhoneBook->setWindowTitle(QCoreApplication::translate("PhoneBook", "\330\257\331\201\330\252\330\261\332\206\331\207 \330\252\331\204\331\201\331\206", nullptr));
        actionSave->setText(QCoreApplication::translate("PhoneBook", "\330\260\330\256\333\214\330\261\331\207", nullptr));
#if QT_CONFIG(shortcut)
        actionSave->setShortcut(QCoreApplication::translate("PhoneBook", "Ctrl+S", nullptr));
#endif // QT_CONFIG(shortcut)
        actionLoad->setText(QCoreApplication::translate("PhoneBook", "\330\250\330\247\330\261\332\257\330\260\330\247\330\261\333\214", nullptr));
#if QT_CONFIG(shortcut)
        actionLoad->setShortcut(QCoreApplication::translate("PhoneBook", "Ctrl+L", nullptr));
#endif // QT_CONFIG(shortcut)
        actionExport->setText(QCoreApplication::translate("PhoneBook", "\330\265\330\247\330\257\330\261 \332\251\330\261\330\257\331\206", nullptr));
#if QT_CONFIG(shortcut)
        actionExport->setShortcut(QCoreApplication::translate("PhoneBook", "Ctrl+E", nullptr));
#endif // QT_CONFIG(shortcut)
        actionImport->setText(QCoreApplication::translate("PhoneBook", "\331\210\330\247\330\261\330\257 \332\251\330\261\330\257\331\206", nullptr));
#if QT_CONFIG(shortcut)
        actionImport->setShortcut(QCoreApplication::translate("PhoneBook", "Ctrl+I", nullptr));
#endif // QT_CONFIG(shortcut)
        searchEdit->setPlaceholderText(QCoreApplication::translate("PhoneBook", "\330\254\330\263\330\252\330\254\331\210\333\214 \331\205\330\256\330\247\330\267\330\250...", nullptr));
        searchBtn->setText(QCoreApplication::translate("PhoneBook", "\330\254\330\263\330\252\330\254\331\210", nullptr));
        nameEdit->setPlaceholderText(QCoreApplication::translate("PhoneBook", "\331\206\330\247\331\205 \331\205\330\256\330\247\330\267\330\250", nullptr));
        addContactBtn->setText(QCoreApplication::translate("PhoneBook", "\330\247\330\266\330\247\331\201\331\207 \332\251\330\261\330\257\331\206 \331\205\330\256\330\247\330\267\330\250", nullptr));
        editContactBtn->setText(QCoreApplication::translate("PhoneBook", "\331\210\333\214\330\261\330\247\333\214\330\264 \331\205\330\256\330\247\330\267\330\250", nullptr));
        deleteContactBtn->setText(QCoreApplication::translate("PhoneBook", "\330\255\330\260\331\201 \331\205\330\256\330\247\330\267\330\250", nullptr));
        phoneTypeEdit->setPlaceholderText(QCoreApplication::translate("PhoneBook", "\331\206\331\210\330\271 \330\264\331\205\330\247\330\261\331\207 (\331\205\330\253\331\204: \330\256\330\247\331\206\331\207\330\214 \331\205\331\210\330\250\330\247\333\214\331\204\330\214 \332\251\330\247\330\261)", nullptr));
        phoneNumberEdit->setPlaceholderText(QCoreApplication::translate("PhoneBook", "\330\264\331\205\330\247\330\261\331\207 \330\252\331\204\331\201\331\206", nullptr));
        addPhoneBtn->setText(QCoreApplication::translate("PhoneBook", "\330\247\330\266\330\247\331\201\331\207 \332\251\330\261\330\257\331\206 \330\264\331\205\330\247\330\261\331\207", nullptr));
        editPhoneBtn->setText(QCoreApplication::translate("PhoneBook", "\331\210\333\214\330\261\330\247\333\214\330\264 \330\264\331\205\330\247\330\261\331\207", nullptr));
        deletePhoneBtn->setText(QCoreApplication::translate("PhoneBook", "\330\255\330\260\331\201 \330\264\331\205\330\247\330\261\331\207", nullptr));
        addFavoriteBtn->setText(QCoreApplication::translate("PhoneBook", "\330\247\330\266\330\247\331\201\331\207 \330\250\331\207 \330\271\331\204\330\247\331\202\331\207\342\200\214\331\205\331\206\330\257\333\214\342\200\214\331\207\330\247", nullptr));
        removeFavoriteBtn->setText(QCoreApplication::translate("PhoneBook", "\330\255\330\260\331\201 \330\247\330\262 \330\271\331\204\330\247\331\202\331\207\342\200\214\331\205\331\206\330\257\333\214\342\200\214\331\207\330\247", nullptr));
        moveUpBtn->setText(QCoreApplication::translate("PhoneBook", "\330\254\330\247\330\250\330\254\330\247 \330\250\331\207 \330\250\330\247\331\204\330\247", nullptr));
        moveDownBtn->setText(QCoreApplication::translate("PhoneBook", "\330\254\330\247\330\250\330\254\330\247 \330\250\331\207 \331\276\330\247\333\214\333\214\331\206", nullptr));
        saveBtn->setText(QCoreApplication::translate("PhoneBook", "\330\260\330\256\333\214\330\261\331\207 (Ctrl+S)", nullptr));
        loadBtn->setText(QCoreApplication::translate("PhoneBook", "\330\250\330\247\330\261\332\257\330\260\330\247\330\261\333\214 (Ctrl+L)", nullptr));
        exportBtn->setText(QCoreApplication::translate("PhoneBook", "\330\265\330\247\330\257\330\261 \332\251\330\261\330\257\331\206 (Ctrl+E)", nullptr));
        importBtn->setText(QCoreApplication::translate("PhoneBook", "\331\210\330\247\330\261\330\257 \332\251\330\261\330\257\331\206 (Ctrl+I)", nullptr));
        menuFile->setTitle(QCoreApplication::translate("PhoneBook", "\331\201\330\247\333\214\331\204", nullptr));
    } // retranslateUi

};

namespace Ui {
    class PhoneBook: public Ui_PhoneBook {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_PHONEBOOK_H
