#include "lecturer.h"

Lecturer::Lecturer(const Lecturer &lecturer, QObject *parent) : Employee(lecturer.m_id, lecturer.m_first_name, lecturer.m_last_name, lecturer.m_date_of_birth, *lecturer.m_address, parent)
{

}

Lecturer::Lecturer(const int &id, const QString &first_name, const QString &last_name, const QDate &date_of_birth, const Address &address, QObject *parent) : Employee(id, first_name, last_name, date_of_birth, address, parent)
{

}

Lecturer::Lecturer(const QString& first_name, const QString& last_name, const QString& password, const QDate& date_of_birth, const Address& address, QObject* parent) : Employee(first_name, last_name, password, date_of_birth, address, parent)
{
    
}


Lecturer::~Lecturer() {
    qInfo() << "test";
}

void Lecturer::updateSignal() {
    QSqlQuery query;
    query.prepare("UPDATE lecturer SET first_name=:first_name, last_name=:last_name, date_of_birth=:date_of_birth WHERE id=:id");
    query.bindValue(":first_name", m_first_name);
    query.bindValue(":last_name", m_last_name);
    query.bindValue(":date_of_birth", Tools::dateToString(m_date_of_birth));
    query.bindValue(":id", m_id);
    emit update(query);
}