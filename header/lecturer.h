#ifndef LECTURER_H
#define LECTURER_H
#include <QObject>
#include <QVector>
#include <QDebug>
#include <QSqlQuery>
#include "employee.h"
#include "tools.h"

class Lecturer : public Employee
{
    Q_OBJECT
public:
    explicit Lecturer(const Lecturer& lecturer, QObject *parent = nullptr);
    explicit Lecturer(const QString& first_name, const QString& last_name, const QString& password, const QDate& date_of_birth, const Address& address, QObject* parent = nullptr);
    explicit Lecturer(const int& id, const QString& first_name, const QString& last_name, const QDate& date_of_birth, const Address& address, QObject* parent = nullptr);
    virtual ~Lecturer();
    

protected:
    void updateSignal() override;
signals:
    void update(QSqlQuery query);
};

#endif // LECTURER_H
