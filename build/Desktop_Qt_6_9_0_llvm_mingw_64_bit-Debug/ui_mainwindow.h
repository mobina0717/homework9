/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.9.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *actionSave;
    QAction *actionLoad;
    QAction *actionExport;
    QAction *actionImport;
    QWidget *centralwidget;
    QHBoxLayout *horizontalLayout;
    QTabWidget *tabWidget;
    QWidget *tabContacts;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout_2;
    QListWidget *contactsList;
    QListWidget *favoritesList;
    QHBoxLayout *horizontalLayout_3;
    QPushButton *addContactBtn;
    QPushButton *editContactBtn;
    QPushButton *deleteContactBtn;
    QPushButton *searchBtn;
    QPushButton *showAllBtn;
    QWidget *tabDetails;
    QVBoxLayout *verticalLayout_2;
    QLabel *nameLabel;
    QListWidget *phonesList;
    QHBoxLayout *horizontalLayout_4;
    QPushButton *addPhoneBtn;
    QPushButton *editPhoneBtn;
    QPushButton *deletePhoneBtn;
    QHBoxLayout *horizontalLayout_5;
    QPushButton *favoriteBtn;
    QPushButton *moveUpBtn;
    QPushButton *moveDownBtn;
    QMenuBar *menubar;
    QMenu *menuFile;
    QStatusBar *statusbar;
    QToolBar *toolBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(800, 600);
        actionSave = new QAction(MainWindow);
        actionSave->setObjectName("actionSave");
        actionLoad = new QAction(MainWindow);
        actionLoad->setObjectName("actionLoad");
        actionExport = new QAction(MainWindow);
        actionExport->setObjectName("actionExport");
        actionImport = new QAction(MainWindow);
        actionImport->setObjectName("actionImport");
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        horizontalLayout = new QHBoxLayout(centralwidget);
        horizontalLayout->setObjectName("horizontalLayout");
        tabWidget = new QTabWidget(centralwidget);
        tabWidget->setObjectName("tabWidget");
        tabContacts = new QWidget();
        tabContacts->setObjectName("tabContacts");
        verticalLayout = new QVBoxLayout(tabContacts);
        verticalLayout->setObjectName("verticalLayout");
        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName("horizontalLayout_2");
        contactsList = new QListWidget(tabContacts);
        contactsList->setObjectName("contactsList");

        horizontalLayout_2->addWidget(contactsList);

        favoritesList = new QListWidget(tabContacts);
        favoritesList->setObjectName("favoritesList");

        horizontalLayout_2->addWidget(favoritesList);


        verticalLayout->addLayout(horizontalLayout_2);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName("horizontalLayout_3");
        addContactBtn = new QPushButton(tabContacts);
        addContactBtn->setObjectName("addContactBtn");

        horizontalLayout_3->addWidget(addContactBtn);

        editContactBtn = new QPushButton(tabContacts);
        editContactBtn->setObjectName("editContactBtn");

        horizontalLayout_3->addWidget(editContactBtn);

        deleteContactBtn = new QPushButton(tabContacts);
        deleteContactBtn->setObjectName("deleteContactBtn");

        horizontalLayout_3->addWidget(deleteContactBtn);

        searchBtn = new QPushButton(tabContacts);
        searchBtn->setObjectName("searchBtn");

        horizontalLayout_3->addWidget(searchBtn);

        showAllBtn = new QPushButton(tabContacts);
        showAllBtn->setObjectName("showAllBtn");

        horizontalLayout_3->addWidget(showAllBtn);


        verticalLayout->addLayout(horizontalLayout_3);

        tabWidget->addTab(tabContacts, QString());
        tabDetails = new QWidget();
        tabDetails->setObjectName("tabDetails");
        verticalLayout_2 = new QVBoxLayout(tabDetails);
        verticalLayout_2->setObjectName("verticalLayout_2");
        nameLabel = new QLabel(tabDetails);
        nameLabel->setObjectName("nameLabel");

        verticalLayout_2->addWidget(nameLabel);

        phonesList = new QListWidget(tabDetails);
        phonesList->setObjectName("phonesList");

        verticalLayout_2->addWidget(phonesList);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setObjectName("horizontalLayout_4");
        addPhoneBtn = new QPushButton(tabDetails);
        addPhoneBtn->setObjectName("addPhoneBtn");

        horizontalLayout_4->addWidget(addPhoneBtn);

        editPhoneBtn = new QPushButton(tabDetails);
        editPhoneBtn->setObjectName("editPhoneBtn");

        horizontalLayout_4->addWidget(editPhoneBtn);

        deletePhoneBtn = new QPushButton(tabDetails);
        deletePhoneBtn->setObjectName("deletePhoneBtn");

        horizontalLayout_4->addWidget(deletePhoneBtn);


        verticalLayout_2->addLayout(horizontalLayout_4);

        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setObjectName("horizontalLayout_5");
        favoriteBtn = new QPushButton(tabDetails);
        favoriteBtn->setObjectName("favoriteBtn");

        horizontalLayout_5->addWidget(favoriteBtn);

        moveUpBtn = new QPushButton(tabDetails);
        moveUpBtn->setObjectName("moveUpBtn");

        horizontalLayout_5->addWidget(moveUpBtn);

        moveDownBtn = new QPushButton(tabDetails);
        moveDownBtn->setObjectName("moveDownBtn");

        horizontalLayout_5->addWidget(moveDownBtn);


        verticalLayout_2->addLayout(horizontalLayout_5);

        tabWidget->addTab(tabDetails, QString());

        horizontalLayout->addWidget(tabWidget);

        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 800, 25));
        menuFile = new QMenu(menubar);
        menuFile->setObjectName("menuFile");
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName("statusbar");
        MainWindow->setStatusBar(statusbar);
        toolBar = new QToolBar(MainWindow);
        toolBar->setObjectName("toolBar");
        MainWindow->addToolBar(Qt::ToolBarArea::TopToolBarArea, toolBar);

        menubar->addAction(menuFile->menuAction());
        menuFile->addAction(actionSave);
        menuFile->addAction(actionLoad);
        menuFile->addAction(actionExport);
        menuFile->addAction(actionImport);
        toolBar->addAction(actionSave);
        toolBar->addAction(actionLoad);
        toolBar->addAction(actionExport);
        toolBar->addAction(actionImport);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "\330\257\331\201\330\252\330\261\332\206\331\207 \330\252\331\204\331\201\331\206 \331\276\333\214\330\264\330\261\331\201\330\252\331\207", nullptr));
        actionSave->setText(QCoreApplication::translate("MainWindow", "\330\260\330\256\333\214\330\261\331\207", nullptr));
#if QT_CONFIG(shortcut)
        actionSave->setShortcut(QCoreApplication::translate("MainWindow", "Ctrl+S", nullptr));
#endif // QT_CONFIG(shortcut)
        actionLoad->setText(QCoreApplication::translate("MainWindow", "\330\250\330\247\330\261\332\257\330\260\330\247\330\261\333\214", nullptr));
#if QT_CONFIG(shortcut)
        actionLoad->setShortcut(QCoreApplication::translate("MainWindow", "Ctrl+L", nullptr));
#endif // QT_CONFIG(shortcut)
        actionExport->setText(QCoreApplication::translate("MainWindow", "\330\265\330\247\330\257\330\261 \332\251\330\261\330\257\331\206", nullptr));
#if QT_CONFIG(shortcut)
        actionExport->setShortcut(QCoreApplication::translate("MainWindow", "Ctrl+E", nullptr));
#endif // QT_CONFIG(shortcut)
        actionImport->setText(QCoreApplication::translate("MainWindow", "\331\210\330\247\330\261\330\257 \332\251\330\261\330\257\331\206", nullptr));
#if QT_CONFIG(shortcut)
        actionImport->setShortcut(QCoreApplication::translate("MainWindow", "Ctrl+I", nullptr));
#endif // QT_CONFIG(shortcut)
        addContactBtn->setText(QCoreApplication::translate("MainWindow", "\330\247\330\266\330\247\331\201\331\207 \332\251\330\261\330\257\331\206 \331\205\330\256\330\247\330\267\330\250", nullptr));
        editContactBtn->setText(QCoreApplication::translate("MainWindow", "\331\210\333\214\330\261\330\247\333\214\330\264 \331\205\330\256\330\247\330\267\330\250", nullptr));
        deleteContactBtn->setText(QCoreApplication::translate("MainWindow", "\330\255\330\260\331\201 \331\205\330\256\330\247\330\267\330\250", nullptr));
        searchBtn->setText(QCoreApplication::translate("MainWindow", "\330\254\330\263\330\252\330\254\331\210", nullptr));
        showAllBtn->setText(QCoreApplication::translate("MainWindow", "\331\206\331\205\330\247\333\214\330\264 \331\207\331\205\331\207", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tabContacts), QCoreApplication::translate("MainWindow", "\331\205\330\256\330\247\330\267\330\250\333\214\331\206", nullptr));
        nameLabel->setText(QCoreApplication::translate("MainWindow", "\331\206\330\247\331\205: ", nullptr));
        addPhoneBtn->setText(QCoreApplication::translate("MainWindow", "\330\247\330\266\330\247\331\201\331\207 \332\251\330\261\330\257\331\206 \330\264\331\205\330\247\330\261\331\207", nullptr));
        editPhoneBtn->setText(QCoreApplication::translate("MainWindow", "\331\210\333\214\330\261\330\247\333\214\330\264 \330\264\331\205\330\247\330\261\331\207", nullptr));
        deletePhoneBtn->setText(QCoreApplication::translate("MainWindow", "\330\255\330\260\331\201 \330\264\331\205\330\247\330\261\331\207", nullptr));
        favoriteBtn->setText(QCoreApplication::translate("MainWindow", "\330\247\330\266\330\247\331\201\331\207 \330\250\331\207 \331\205\331\210\330\261\330\257\330\271\331\204\330\247\331\202\331\207\342\200\214\331\207\330\247", nullptr));
        moveUpBtn->setText(QCoreApplication::translate("MainWindow", "\330\255\330\261\332\251\330\252 \330\250\331\207 \330\250\330\247\331\204\330\247", nullptr));
        moveDownBtn->setText(QCoreApplication::translate("MainWindow", "\330\255\330\261\332\251\330\252 \330\250\331\207 \331\276\330\247\333\214\333\214\331\206", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tabDetails), QCoreApplication::translate("MainWindow", "\330\254\330\262\330\246\333\214\330\247\330\252 \331\205\330\256\330\247\330\267\330\250", nullptr));
        menuFile->setTitle(QCoreApplication::translate("MainWindow", "\331\201\330\247\333\214\331\204", nullptr));
        toolBar->setWindowTitle(QCoreApplication::translate("MainWindow", "toolBar", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
