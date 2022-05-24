#ifndef TOOLS_H
#define TOOLS_H
#pragma once
#include <QObject>
#include <QDate>
#include <QString>
#include <QTableWidgetItem>
#include <QVariant>
#include <QVector>

class Subject;
class Lecturer;
class Tools : public QObject
{
    Q_OBJECT
public:
    explicit Tools(QObject *parent = nullptr);

    static QDate formatDate(const QString& value);
    static QString dateToString(const QDate& date);
    static QString incrementStudentNumber(int number);

    static QTableWidgetItem* getFilledItem(const QString& content);
    
    static QStringList getSubjectsForLecturers(QVector<Subject*> subjects, Lecturer* lecturer);
signals:

};

#endif // TOOLS_H
