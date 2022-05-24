#ifndef EMPLOYEE_H
#define EMPLOYEE_H

#include <QObject>
#include <QFile>
#include <QTextStream>
#include "person.h"

class Employee : public Person
{
    Q_OBJECT
public:
    explicit Employee(const QString& first_name, const QString& last_name, const QString& password, const QDate& date_of_birth, const Address& address,QObject *parent = nullptr);
    explicit Employee(const int& id, const QString& first_name, const QString& last_name, const QDate& date_of_birth, const Address& address, QObject* parent = nullptr);

    virtual ~Employee();
signals:
    void update(QSqlQuery query);
public:
    virtual void generateLogin() override;
protected:
    virtual void updateSignal() override;
    
};

#endif // EMPLOYEE_H
