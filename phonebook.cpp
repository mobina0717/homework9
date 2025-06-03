#include "phonebook.h"
#include "ui_phonebook.h"
#include <QMessageBox>
#include <QFileDialog>
#include <QShortcut>

PhoneBook::PhoneBook(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::PhoneBook)
{
    ui->setupUi(this);

    // تنظیم کلیدهای میانبر
    new QShortcut(QKeySequence("Ctrl+S"), this, SLOT(on_actionSave_triggered()));
    new QShortcut(QKeySequence("Ctrl+L"), this, SLOT(on_actionLoad_triggered()));
    new QShortcut(QKeySequence("Ctrl+E"), this, SLOT(on_actionExport_triggered()));
    new QShortcut(QKeySequence("Ctrl+I"), this, SLOT(on_actionImport_triggered()));

    // تنظیم رنگ دکمه‌ها
    ui->saveBtn->setStyleSheet("background-color: blue; color: white;");
    ui->loadBtn->setStyleSheet("background-color: green; color: white;");
    ui->importBtn->setStyleSheet("background-color: orange; color: white;");
    ui->exportBtn->setStyleSheet("background-color: red; color: white;");

    // اتصال دکمه‌های ذخیره/بارگذاری
    connect(ui->saveBtn, &QPushButton::clicked, this, &PhoneBook::on_actionSave_triggered);
    connect(ui->loadBtn, &QPushButton::clicked, this, &PhoneBook::on_actionLoad_triggered);
    connect(ui->importBtn, &QPushButton::clicked, this, &PhoneBook::on_actionImport_triggered);
    connect(ui->exportBtn, &QPushButton::clicked, this, &PhoneBook::on_actionExport_triggered);

    updateContactsList();
    updateFavoriteList();
}

PhoneBook::~PhoneBook()
{
    delete ui;
}

void PhoneBook::on_addContactBtn_clicked()
{
    QString name = ui->nameEdit->text().trimmed();
    if(name.isEmpty()) {
        QMessageBox::warning(this, "خطا", "لطفاً نام مخاطب را وارد کنید");
        return;
    }

    if(contacts.contains(name)) {
        QMessageBox::warning(this, "خطا", "مخاطب با این نام از قبل وجود دارد");
        return;
    }

    Contact newContact;
    newContact.name = name;
    contacts[name] = newContact;

    updateContactsList();
    ui->nameEdit->clear();
}

void PhoneBook::on_editContactBtn_clicked()
{
    QString oldName = ui->contactsList->currentItem()->text();
    QString newName = ui->nameEdit->text().trimmed();

    if(newName.isEmpty()) {
        QMessageBox::warning(this, "خطا", "لطفاً نام جدید را وارد کنید");
        return;
    }

    if(contacts.contains(newName)) {
        QMessageBox::warning(this, "خطا", "مخاطب با این نام از قبل وجود دارد");
        return;
    }

    Contact contact = contacts.take(oldName);
    contact.name = newName;
    contacts[newName] = contact;

    // به‌روزرسانی لیست علاقه‌مندی‌ها در صورت وجود
    int favIndex = favorites.indexOf(oldName);
    if(favIndex != -1) {
        favorites[favIndex] = newName;
    }

    updateContactsList();
    updateFavoriteList();
    ui->nameEdit->clear();
}

void PhoneBook::on_deleteContactBtn_clicked()
{
    QString name = ui->contactsList->currentItem()->text();

    contacts.remove(name);
    favorites.removeAll(name);

    updateContactsList();
    updateFavoriteList();
    ui->phoneNumbersList->clear();
}

void PhoneBook::on_addPhoneBtn_clicked()
{
    QString name = ui->contactsList->currentItem()->text();
    QString type = ui->phoneTypeEdit->text().trimmed();
    QString number = ui->phoneNumberEdit->text().trimmed();

    if(type.isEmpty() || number.isEmpty()) {
        QMessageBox::warning(this, "خطا", "لطفاً نوع و شماره تلفن را وارد کنید");
        return;
    }

    PhoneNumber newPhone;
    newPhone.type = type;
    newPhone.number = number;

    contacts[name].phoneNumbers.append(newPhone);
    showContactDetails(name);
    ui->phoneTypeEdit->clear();
    ui->phoneNumberEdit->clear();
}

void PhoneBook::on_editPhoneBtn_clicked()
{
    QString name = ui->contactsList->currentItem()->text();
    int index = ui->phoneNumbersList->currentRow();

    QString type = ui->phoneTypeEdit->text().trimmed();
    QString number = ui->phoneNumberEdit->text().trimmed();

    if(type.isEmpty() || number.isEmpty()) {
        QMessageBox::warning(this, "خطا", "لطفاً نوع و شماره تلفن را وارد کنید");
        return;
    }

    contacts[name].phoneNumbers[index].type = type;
    contacts[name].phoneNumbers[index].number = number;

    showContactDetails(name);
    ui->phoneTypeEdit->clear();
    ui->phoneNumberEdit->clear();
}

void PhoneBook::on_deletePhoneBtn_clicked()
{
    QString name = ui->contactsList->currentItem()->text();
    int index = ui->phoneNumbersList->currentRow();

    contacts[name].phoneNumbers.removeAt(index);
    showContactDetails(name);
}

void PhoneBook::on_addFavoriteBtn_clicked()
{
    QString name = ui->contactsList->currentItem()->text();

    if(!favorites.contains(name)) {
        favorites.append(name);
        updateFavoriteList();
    }
}

void PhoneBook::on_removeFavoriteBtn_clicked()
{
    QString name = ui->favoritesList->currentItem()->text();

    favorites.removeAll(name);
    updateFavoriteList();
}

void PhoneBook::on_moveUpBtn_clicked()
{
    int currentRow = ui->favoritesList->currentRow();
    if(currentRow > 0) {
        favorites.move(currentRow, currentRow - 1);
        updateFavoriteList();
        ui->favoritesList->setCurrentRow(currentRow - 1);
    }
}

void PhoneBook::on_moveDownBtn_clicked()
{
    int currentRow = ui->favoritesList->currentRow();
    if(currentRow < favorites.size() - 1) {
        favorites.move(currentRow, currentRow + 1);
        updateFavoriteList();
        ui->favoritesList->setCurrentRow(currentRow + 1);
    }
}

void PhoneBook::on_searchBtn_clicked()
{
    QString searchText = ui->searchEdit->text().trimmed().toLower();

    ui->contactsList->clear();

    QStringList contactNames = contacts.keys();
    contactNames.sort(Qt::CaseInsensitive);

    for(const QString &name : contactNames) {
        if(name.toLower().startsWith(searchText)) {
            ui->contactsList->addItem(name);
        }
    }
}

void PhoneBook::on_contactsList_currentItemChanged()
{
    if(ui->contactsList->currentItem()) {
        QString name = ui->contactsList->currentItem()->text();
        showContactDetails(name);
    }
}

void PhoneBook::on_actionSave_triggered()
{
    saveToFile("phonebook.json");
    QMessageBox::information(this, "ذخیره", "اطلاعات با موفقیت ذخیره شد");
}

void PhoneBook::on_actionLoad_triggered()
{
    loadFromFile("phonebook.json");
    QMessageBox::information(this, "بارگذاری", "اطلاعات با موفقیت بارگذاری شد");
}

void PhoneBook::on_actionExport_triggered()
{
    QString filename = QFileDialog::getSaveFileName(this, "صادر کردن مخاطبان", "", "JSON Files (*.json)");
    if(!filename.isEmpty()) {
        exportToFile(filename);
        QMessageBox::information(this, "صادر کردن", "اطلاعات با موفقیت صادر شد");
    }
}

void PhoneBook::on_actionImport_triggered()
{
    QString filename = QFileDialog::getOpenFileName(this, "وارد کردن مخاطبان", "", "JSON Files (*.json)");
    if(!filename.isEmpty()) {
        importFromFile(filename);
        QMessageBox::information(this, "وارد کردن", "اطلاعات با موفقیت وارد شد");
    }
}

void PhoneBook::updateContactsList()
{
    ui->contactsList->clear();

    QStringList contactNames = contacts.keys();
    contactNames.sort(Qt::CaseInsensitive);

    for(const QString &name : contactNames) {
        ui->contactsList->addItem(name);
    }
}

void PhoneBook::updateFavoriteList()
{
    ui->favoritesList->clear();

    for(const QString &name : favorites) {
        ui->favoritesList->addItem(name);
    }
}

void PhoneBook::updatePhoneNumbersList()
{
    ui->phoneNumbersList->clear();

    if(ui->contactsList->currentItem()) {
        QString name = ui->contactsList->currentItem()->text();
        for(const PhoneNumber &phone : contacts[name].phoneNumbers) {
            ui->phoneNumbersList->addItem(phone.type + ": " + phone.number);
        }
    }
}

void PhoneBook::showContactDetails(const QString &name)
{
    ui->nameEdit->setText(name);
    ui->phoneNumbersList->clear();

    for(const PhoneNumber &phone : contacts[name].phoneNumbers) {
        ui->phoneNumbersList->addItem(phone.type + ": " + phone.number);
    }
}

void PhoneBook::saveToFile(const QString &filename)
{
    QJsonObject json;
    QJsonArray contactsArray;
    QJsonArray favoritesArray;

    for(const Contact &contact : contacts) {
        QJsonObject contactObj;
        contactObj["name"] = contact.name;

        QJsonArray phonesArray;
        for(const PhoneNumber &phone : contact.phoneNumbers) {
            QJsonObject phoneObj;
            phoneObj["type"] = phone.type;
            phoneObj["number"] = phone.number;
            phonesArray.append(phoneObj);
        }

        contactObj["phones"] = phonesArray;
        contactsArray.append(contactObj);
    }

    for(const QString &fav : favorites) {
        favoritesArray.append(fav);
    }

    json["contacts"] = contactsArray;
    json["favorites"] = favoritesArray;

    QFile file(filename);
    if(file.open(QIODevice::WriteOnly)) {
        file.write(QJsonDocument(json).toJson());
        file.close();
    }
}

void PhoneBook::loadFromFile(const QString &filename)
{
    QFile file(filename);
    if(!file.open(QIODevice::ReadOnly)) {
        return;
    }

    QByteArray data = file.readAll();
    file.close();

    QJsonDocument doc = QJsonDocument::fromJson(data);
    QJsonObject json = doc.object();

    contacts.clear();
    favorites.clear();

    QJsonArray contactsArray = json["contacts"].toArray();
    for(const QJsonValue &contactVal : contactsArray) {
        QJsonObject contactObj = contactVal.toObject();
        Contact contact;
        contact.name = contactObj["name"].toString();

        QJsonArray phonesArray = contactObj["phones"].toArray();
        for(const QJsonValue &phoneVal : phonesArray) {
            QJsonObject phoneObj = phoneVal.toObject();
            PhoneNumber phone;
            phone.type = phoneObj["type"].toString();
            phone.number = phoneObj["number"].toString();
            contact.phoneNumbers.append(phone);
        }

        contacts[contact.name] = contact;
    }

    QJsonArray favoritesArray = json["favorites"].toArray();
    for(const QJsonValue &favVal : favoritesArray) {
        favorites.append(favVal.toString());
    }

    updateContactsList();
    updateFavoriteList();
}

void PhoneBook::exportToFile(const QString &filename)
{
    saveToFile(filename);
}

void PhoneBook::importFromFile(const QString &filename)
{
    loadFromFile(filename);
}
