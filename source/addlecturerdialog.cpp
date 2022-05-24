#include "addlecturerdialog.h"
#include "ui_addlecturerdialog.h"
#include "address.h"

AddLecturerDialog::AddLecturerDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::AddLecturerDialog)
{
    ui->setupUi(this);
    init();
}

AddLecturerDialog::~AddLecturerDialog()
{
    delete ui;
}

void AddLecturerDialog::init() {
    ui->cmbCountry->addItem("Polska");
    QDate date = QDate::currentDate();
    for (int i = 1; i <= date.daysInMonth(); ++i) {
        ui->cmbDay->addItem(QString::number(i));
    }
    for (int i = 1; i <= 12; ++i) {
        ui->cmbMonth->addItem(QString::number(i));
    }
    for (int i = 1800; i <= date.year(); ++i) {
        ui->cmbYear->addItem(QString::number(i));
    }
    ui->cmbDay->setCurrentIndex(date.day() - 1);
    ui->cmbMonth->setCurrentIndex(date.month() - 1);
    ui->cmbYear->setCurrentIndex(date.year() - 1800);
}

Lecturer* AddLecturerDialog::getLecturer() {
    return lecturer;
}

void AddLecturerDialog::on_buttonBox_accepted()
{
    if (!check()) {
        QMessageBox::critical(this, "Błąd", "Proszę wprowadzić dane");
        return;
    }
    accept();
}


void AddLecturerDialog::on_buttonBox_rejected()
{
    reject();
}

bool AddLecturerDialog::check() {
    QString first_name = ui->txtName->text();
    if (first_name.isEmpty() || first_name.isNull()) {
        return false;
    }
    QString last_name = ui->txtLastName->text();
    if (last_name.isEmpty() || last_name.isNull()) {
        return false;
    }
    int day = ui->cmbDay->currentText().toInt();
    int month = ui->cmbMonth->currentText().toInt();
    int year = ui->cmbYear->currentText().toInt();
    QDate date_of_birth(year, month, day);
    QString country = ui->cmbCountry->currentText();
    if (country.isEmpty() || country.isNull()) {
        return false;
    }
    QString city = ui->txtCity->text();
    if (city.isEmpty() || city.isNull()) {
        return false;
    }
    QString zip_code = ui->txtZipCode->text();
    if (zip_code.isEmpty() || zip_code.isNull()) {
        return false;
    }
    QString street = ui->txtStreet->text();
    if (street.isEmpty() || street.isNull()) {
        return false;
    }
    QString house_number = ui->txtHouseNumber->text();
    if (house_number.isEmpty() || house_number.isNull()) {
        return false;
    }
    QString apartment_number = ui->txtApartmentNumber->text();
    Address* address = nullptr;
    if (apartment_number.isEmpty() || apartment_number.isNull()) {
        address = new Address(country, city, zip_code, street, house_number);
    }
    else {
        address = new Address(country, city, zip_code, street, house_number, apartment_number);
    }
    lecturer = new Lecturer(first_name, last_name, "123", date_of_birth, *address);
    delete address;
    lecturer->generateLogin();
    qInfo() << "login: " << lecturer->login();
    return true;
}

void AddLecturerDialog::on_cmbMonth_currentIndexChanged(int index)
{
    updateCombo();
}


void AddLecturerDialog::on_cmbYear_currentIndexChanged(int index)
{
    updateCombo();
}

void AddLecturerDialog::updateCombo() {
    int day = ui->cmbDay->currentIndex() + 1;
    int month = ui->cmbMonth->currentIndex() + 1;
    int year = ui->cmbYear->currentIndex() + 1800;
    QDate date(year, month, day);
    int index = ui->cmbDay->currentIndex();
    ui->cmbDay->clear();
    for (int i = 1; i <= date.daysInMonth(); ++i) {
        ui->cmbDay->addItem(QString::number(i));
    }
    if (index < date.daysInMonth()) {
        ui->cmbDay->setCurrentIndex(index);
    }
    else {
        ui->cmbDay->setCurrentIndex(ui->cmbDay->count() - 1);
    }
}
