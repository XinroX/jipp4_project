#ifndef STUDENT_H
#define STUDENT_H

#include <QObject>
#include <QVector>
#include <QFile>
#include <QTextStream>
#include <QSqlQuery>
#include "person.h"
#include "grade.h"

class Student : public Person
{
    Q_OBJECT
public:
    explicit Student(const QString& first_name, const QString& last_name, const QString& password, const QDate& date_of_birth, const Address& address, const QString& number, QObject *parent = nullptr);
    explicit Student(const int& id, const QString& first_name, const QString& last_name, const QDate& date_of_birth, const Address& address, const QString& number, QObject *parent = nullptr);
    void addGrade(Grade* grade);
    void addGrade(float value, const Subject& subject);



    virtual ~Student();

    QVector<Grade*> grades();

    virtual QString number() const;

    virtual void setNumber(QString number);

protected:
    QString m_number;
    QVector<Grade*> m_grades;
public:
    void generateLogin() override;
protected:
    virtual void updateSignal() override;

signals:
    void update(QSqlQuery query);



};

#endif // STUDENT_H
