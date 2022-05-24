#include "employee.h"

Employee::Employee(const QString& first_name, const QString& last_name, const QString& password, const QDate& date_of_birth, const Address& address, QObject *parent) : Person(first_name, last_name, password, date_of_birth, address, parent)
{
    generateLogin();
}

Employee::Employee(const int &id, const QString &first_name, const QString &last_name, const QDate &date_of_birth, const Address &address, QObject *parent) : Person(id, first_name, last_name, date_of_birth, address, parent)
{

}


Employee::~Employee() {

}


void Employee::generateLogin() {
    m_login = m_first_name[0].toLower() + m_last_name.toLower();
}




void Employee::updateSignal() {
    
}