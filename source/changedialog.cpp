#include "changedialog.h"
#include "ui_changedialog.h"
#include "address.h"

ChangeDialog::ChangeDialog(Person *person, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ChangeDialog)
{
    ui->setupUi(this);
    this->person = person;
    init();
}

ChangeDialog::~ChangeDialog()
{
    delete ui;
}

void ChangeDialog::init() {
    ui->txtName->setText(person->firstName());
    ui->txtLastName->setText(person->lastName());
    QDate date = person->dateOfBirth();
    qDebug() << date;
    for (int i = 1; i <= date.daysInMonth(); ++i) {
        ui->cmbDay->addItem(QString::number(i));
    }
    for (int i = 1; i <= 12; ++i) {
        ui->cmbMonth->addItem(QString::number(i));
    }
    ui->cmbMonth->setCurrentIndex(date.month() - 1);
    for (int i = 1800; i <= QDate::currentDate().year(); ++i) {
        ui->cmbYear->addItem(QString::number(i));
    }
    ui->cmbDay->setCurrentIndex(date.day() - 1);
    ui->cmbMonth->setCurrentIndex(date.month() - 1);
    ui->cmbYear->setCurrentIndex(date.year() - 1800);
    ui->cmbCountry->addItem("Polska");
    ui->txtCity->setText(person->address()->city());
    ui->txtZipCode->setText(person->address()->zipCode());
    ui->txtStreet->setText(person->address()->street());
    ui->txtHouseNumber->setText(person->address()->houseNumber());
    QString apartment_number = person->address()->apartmentNumber();
    if (!apartment_number.isNull() && !apartment_number.isEmpty()) {
        ui->txtApartmentNumber->setText(apartment_number);
    }
}

bool ChangeDialog::check() {
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
        address = new Address(person->address()->id(), country, city, zip_code, street, house_number);
    }
    else {
        address = new Address(person->address()->id(), country, city, zip_code, street, house_number, apartment_number);
    }
    person->setAddress(*address);
    delete address;
    person->setFirstName(first_name);
    person->setLastName(last_name);
    person->setDateOfBirth(date_of_birth);
    return true;
}

void ChangeDialog::updateCombo() {
    int day = ui->cmbDay->currentIndex() + 1;
    int month = ui->cmbMonth->currentIndex() + 1;
    int year = ui->cmbYear->currentIndex() + 1800;
    qDebug() << day << " " << month << " " << year;
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

void ChangeDialog::on_cmbMonth_currentIndexChanged(int index)
{
    updateCombo();
}

void ChangeDialog::on_cmbYear_currentIndexChanged(int index)
{
    updateCombo();
}

void ChangeDialog::on_buttonBox_accepted()
{
    if (!check()) {
        QMessageBox::critical(this, "Nieprawidłowe dane", "Proszę wprowadzić prawidłowe dane");
        return;
    }
    accept();
}

void ChangeDialog::on_buttonBox_rejected()
{
    reject();
}

