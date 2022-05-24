#include "person.h"
#include "address.h"
#include "dbwriter.h"

Person::Person(const QString& first_name, const QString& last_name, const QString& password, const QDate& date_of_birth, const Address& address, QObject *parent) : QObject(parent)
{
    m_first_name = first_name;
    m_last_name = last_name;
    m_password = password;
    m_date_of_birth = date_of_birth;
    m_address = new Address(address, this);
}

Person::Person(const int &id, const QString &first_name, const QString &last_name, const QDate &date_of_birth, const Address &address, QObject *parent) :QObject(parent)
{
    m_id = id;
    m_first_name = first_name;
    m_last_name = last_name;
    m_date_of_birth = date_of_birth;
    m_address = new Address(address, this);
}

int Person::id() const {
    return m_id;
}

QString Person::firstName() const {
    return m_first_name;
}

QString Person::lastName() const {
    return m_last_name;
}

QString Person::login() const {
    return m_login;
}

QString Person::password() const {
    return m_password;
}

QDate Person::dateOfBirth() const {
    return m_date_of_birth;
}

Address* Person::address() {
    return m_address;
}

void Person::setFirstName(const QString& first_name) {
    if (!first_name.isEmpty() && !first_name.isNull()) {
        if (m_first_name != first_name) {
            m_first_name = first_name;
            updateSignal();
        }
    }
}

void Person::setLastName(const QString& last_name) {
    if (!last_name.isEmpty() && !last_name.isNull()) {
        if (m_last_name != last_name) {
            m_last_name = last_name;
        }
    }
}

void Person::setPassword(const QString& password) {
    if (!password.isEmpty() && !password.isNull()) {
        m_password = password;
    }
}

void Person::setDateOfBirth(const QDate& date) {
    if (!date.isNull() && date.isValid()) {
        if (date != m_date_of_birth) {
            m_date_of_birth = date;
            updateSignal();
        }
    }
}

void Person::setAddress(const Address& address) {
    delete m_address;
    m_address = new Address(address, this);
}

Person::~Person() {
    delete m_address;
    qInfo() << "test";
}


void Person::connectAddressToDBWriter(DBWriter *db) {
    connect(m_address, &Address::update, db, &DBWriter::addQuery);
}
