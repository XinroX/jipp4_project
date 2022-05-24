#ifndef PERSON_H
#define PERSON_H
#pragma once
#include <QObject>
#include <QDate>
#include <QSqlQuery>

class DBWriter;
class Address;
class Person : public QObject
{
    Q_OBJECT
public:
    
    explicit Person(const QString& first_name, const QString& last_name, const QString& password, const QDate& date_of_birth,const Address& address, QObject *parent = nullptr);
    
    explicit Person(const int& id, const QString& first_name, const QString& last_name, const QDate& date_of_birth,const Address& address, QObject *parent = nullptr);
signals:

public:

    void connectAddressToDBWriter(DBWriter* db);
    
    virtual Address* address();
    virtual void setAddress(const Address& address);

    virtual ~Person();


    virtual QString firstName() const;
    virtual QString lastName() const;
    virtual QString login() const;
    virtual QString password() const;
    virtual QDate dateOfBirth() const;
    virtual int id() const;

    virtual void setFirstName(const QString& first_name);
    virtual void setLastName(const QString& last_name);
    virtual void setPassword(const QString& password);
    virtual void setDateOfBirth(const QDate& date);

    virtual void generateLogin() = 0;
protected:
    int m_id;
    QString m_first_name;
    QString m_last_name;
    QString m_login;
    QString m_password;
    QDate m_date_of_birth;
    Address* m_address;
    virtual void updateSignal() = 0;
signals:
    void update(QSqlQuery query);
};

#endif // PERSON_H
