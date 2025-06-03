#ifndef PHONEBOOK_H
#define PHONEBOOK_H

#include <QMainWindow>
#include <QMap>
#include <QList>
#include <QString>
#include <QFile>
#include <QJsonObject>
#include <QJsonArray>
#include <QJsonDocument>

QT_BEGIN_NAMESPACE
namespace Ui { class PhoneBook; }
QT_END_NAMESPACE

class PhoneBook : public QMainWindow
{
    Q_OBJECT

public:
    PhoneBook(QWidget *parent = nullptr);
    ~PhoneBook();

private slots:
    void on_addContactBtn_clicked();
    void on_editContactBtn_clicked();
    void on_deleteContactBtn_clicked();
    void on_addPhoneBtn_clicked();
    void on_editPhoneBtn_clicked();
    void on_deletePhoneBtn_clicked();
    void on_addFavoriteBtn_clicked();
    void on_removeFavoriteBtn_clicked();
    void on_moveUpBtn_clicked();
    void on_moveDownBtn_clicked();
    void on_searchBtn_clicked();
    void on_contactsList_currentItemChanged();
    void on_actionSave_triggered();
    void on_actionLoad_triggered();
    void on_actionExport_triggered();
    void on_actionImport_triggered();

private:
    Ui::PhoneBook *ui;

    struct PhoneNumber {
        QString type;
        QString number;
    };

    struct Contact {
        QString name;
        QList<PhoneNumber> phoneNumbers;
    };

    QMap<QString, Contact> contacts;
    QList<QString> favorites;

    void updateContactsList();
    void updateFavoriteList();
    void updatePhoneNumbersList();
    void saveToFile(const QString &filename);
    void loadFromFile(const QString &filename);
    void exportToFile(const QString &filename);
    void importFromFile(const QString &filename);
    void showContactDetails(const QString &name);
};

#endif // PHONEBOOK_H
