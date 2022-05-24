#ifndef SUBJECT_H
#define SUBJECT_H
#pragma once
#include <QObject>
#include <QVector>
#include "lecturer.h"
class Lecturer;
class Subject : public QObject
{
    Q_OBJECT
public:
    explicit Subject(const Subject& subject, QObject *parent = nullptr);
    explicit Subject(const int& id, const QString& name, QObject* parent = nullptr);




    void addLecturer(Lecturer* lecturer);
    QVector<Lecturer*> lecturers() const;
    
    void deleteLecturer(Lecturer* lecturer);



    virtual int id() const;
    virtual QString name() const;
    virtual void setName(const QString& value);

protected:
    int m_id;
    QString m_name;
    QVector<Lecturer*> m_lecturers;

};

#endif // SUBJECT_H
