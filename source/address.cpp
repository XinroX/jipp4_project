#include "address.h"

Address::Address(const int& id, const QString& country, const QString& city, const QString& zip_code, const QString& street, const QString& house_number, const QString& apartment_number, QObject *parent) : QObject(parent) {
    m_id = id;
    m_country = country;
    m_city = city;
    m_zip_code = zip_code;
    m_street = street;
    m_house_number = house_number;
    m_apartment_number = apartment_number;
}

Address::Address(const int& id, const QString& country, const QString& city, const QString& zip_code, const QString& street, const QString& house_number, QObject *parent) : QObject(parent){
    m_id = id;
    m_country = country;
    m_city = city;
    m_zip_code = zip_code;
    m_street = street;
    m_house_number = house_number;
    m_apartment_number = QString();
}

Address::Address(const Address& address, QObject* parent) : QObject(parent) {
    m_id = address.id();
    m_country = address.m_country;
    m_city = address.m_city;
    m_zip_code = address.m_zip_code;
    m_street = address.m_street;
    m_house_number = address.m_house_number;
    if (address.m_apartment_number.isEmpty() || address.m_apartment_number.isNull()) {
        m_apartment_number = QString();
    }
    else {
        m_apartment_number = address.m_apartment_number;
    }
}

Address::Address(const QString &country, const QString &city, const QString &zip_code, const QString &street, const QString &house_number, QObject *parent) : QObject(parent)
{
    m_country = country;
    m_city = city;
    m_zip_code = zip_code;
    m_street = street;
    m_house_number = house_number;
    m_apartment_number = QString();
}

Address::Address(const QString &country, const QString &city, const QString &zip_code, const QString &street, const QString &house_number, const QString &apartment_number, QObject *parent)
{
    m_country = country;
    m_city = city;
    m_zip_code = zip_code;
    m_street = street;
    m_house_number = house_number;
    m_apartment_number = apartment_number;
}



QString Address::showAddress() {
    QString result = m_country + QString("\r\n") + m_zip_code + ", " + m_city + "\r\n" + m_street + " " + m_house_number;
    if (!m_apartment_number.isEmpty()) {
        result += "/" + m_apartment_number;
    }
    result += "\r\n";
    return result;
}

int Address::id() const {
    return m_id;
}

QString Address::country() const {
    return m_country;
}

QString Address::city() const {
    return m_city;
}

QString Address::zipCode() const {
    return m_zip_code;
}

QString Address::street() const {
    return m_street;
}

QString Address::houseNumber() const {
    return m_house_number;
}

QString Address::apartmentNumber() const {
    return m_apartment_number;
}

void Address::setCountry(const QString& country) {
    if (!country.isEmpty() && !country.isNull()) {
        m_country = country;
        updateAddress();
    }
}

void Address::setCity(const QString& city) {
    if (!city.isEmpty() && !city.isNull()) {
        m_city = city;
        updateAddress();
    }
}

void Address::setZipCode(const QString& zip_code) {
    if (!zip_code.isEmpty() && !zip_code.isNull()) {
        m_zip_code = zip_code;
        updateAddress();
    }
}

void Address::setStreet(const QString& street) {
    if (!street.isEmpty() && !street.isNull()) {
        m_street = street;
        updateAddress();
    }
}

void Address::setHouseNumber(const QString& house_number) {
    if (!house_number.isEmpty() && !house_number.isNull()) {
        m_house_number = house_number;
        updateAddress();
    }
}

void Address::setApartmentNumber(const QString& apartment_number) {
    if (!apartment_number.isEmpty() && !apartment_number.isNull()) {
        m_apartment_number = apartment_number;
        updateAddress();
    }
}

void Address::updateAddress() {
    QSqlQuery query;
    query.prepare("UPDATE address SET country=:country, city=:city, zip_code=:zip_code, street=:street, house_number=:house_number, apratment_number=:apartment_number WHERE id=:id");
    query.bindValue(":country", m_country);
    query.bindValue(":city", m_city);
    query.bindValue(":zip_code", m_zip_code);
    query.bindValue(":street", m_street);
    query.bindValue(":house_number", m_house_number);
    if (!m_apartment_number.isEmpty() && !m_apartment_number.isNull()) {
        query.bindValue(":apartment_number", m_apartment_number);
    }
    query.bindValue(":id", m_id);
    emit update(query);
}











