#ifndef DBWRITER_H
#define DBWRITER_H

#include <QObject>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QTimer>
#include <QSqlError>
#include <QDebug>
#include <QMutex>
#include <QMutexLocker>
#include <QMessageBox>
#include "student.h"
#include "lecturer.h"
#include "tools.h"
class DBWriter : public QObject
{
    Q_OBJECT
public:
    explicit DBWriter(QMutex* mutex, QObject *parent = nullptr);
    
    ~DBWriter();
    
    bool open();
    void setup();
    
    
    bool insertStudent(Student* student);
    bool insertLecturer(Lecturer* lecturer);

    bool deleteStudent(Student* student);
    bool deleteLecturer(Lecturer* lecturer);
    
    void close();
signals:
    
public slots:
    void updatePerson(const QSqlQuery& query);
    void start();
    
private:
    QSqlDatabase db;
    QMutex* m_mutex;
    
    QVector<QSqlQuery> queries;
    QTimer* timer;
public slots:
    void executeQuery();
    void addQuery(QSqlQuery query);

};

#endif // DBWRITER_H
