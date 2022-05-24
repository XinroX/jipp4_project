#include "student.h"

Student::Student(const QString &first_name, const QString &last_name, const QString &password, const QDate &date_of_birth, const Address &address, const QString &number, QObject *parent) : Person(first_name, last_name, password, date_of_birth, address, parent)
{
    m_number = number;
    generateLogin();
}

Student::Student(const int &id, const QString &first_name, const QString &last_name, const QDate &date_of_birth, const Address &address, const QString &number, QObject *parent) : Person(id, first_name, last_name, date_of_birth, address, parent)
{
    m_number = number;
}


void Student::addGrade(Grade *grade) {
    m_grades.append(grade);
}


void Student::addGrade(float value, const Subject& subject) {
    Grade* grade = new Grade(subject, value);
    m_grades.append(grade);
}

QString Student::number() const {
    return m_number;
}

void Student::setNumber(QString number) {
    if (!number.isEmpty() && !number.isNull() && number.size() == 4) {
        m_number = number;
    }
}



void Student::generateLogin() {
    m_login = "s" + m_number + m_first_name[0].toLower() + m_last_name[0].toLower();
}

Student::~Student() {
}

QVector<Grade*> Student::grades() {
    return m_grades;
}



void Student::updateSignal() {
    QSqlQuery query;
    query.prepare("UPDATE student SET first_name=:first_name, last_name=:last_name, date_of_birth=:date_of_birth WHERE id=:id");
    query.bindValue(":first_name", m_first_name);
    query.bindValue(":last_name", m_last_name);
    query.bindValue(":date_of_birth", Tools::dateToString(m_date_of_birth));
    query.bindValue(":id", m_id);
    emit update(query);
}





