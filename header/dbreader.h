#ifndef DBREADER_H
#define DBREADER_H

#include <QObject>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QVector>
#include <QThread>
#include <QTableWidget>
#include <QDebug>
#include "lecturer.h"
#include "student.h"
#include "course.h"
#include "changedialog.h"
#include "tablewidgetgenerator.h"

class DBReader : public QObject
{
    Q_OBJECT
public:
    explicit DBReader(QObject *parent = nullptr);
    ~DBReader();
    bool open();
    void close();
    QTableWidget* getStudentsTable();
    QTableWidget* getLecturersTable();
    QTableWidget* getCoursesTable();
    
    ChangeDialog* getStudentChangeDialog(int index);
    ChangeDialog* getLecturerChangeDialog(int index);
    
    void deleteStudent(int index);
    void deleteLecturer(int index);
    
    QVector<Student*> students();
    QVector<Lecturer*> lecturers();
    QVector<Subject*> subjects();
    QVector<Course*> courses();
    
    void setup();
    
    QString getMaxStudentNumber();

private:
    QSqlDatabase db;
    QVector<Student*> m_students;
    QVector<Lecturer*> m_lecturers;
    QVector<Subject*> m_subjects;
    QVector<Course*> m_courses;

    void readStudents();
    void readLecturers();
    void readSubjects();
    void readCourses();

    void addLecturersToSubjects();
    void addStudentsToCourses();
    void addLecturersToCourses();

    void getGradesForStudent(Student* student);
public:
    QVector<Course*> getCoursesForStudent(Student* student);


    Student* findStudent(const QString& login, const QString& password);
    Lecturer* findLecturer(const QString& login, const QString& password);
    Employee* findEmployee(const QString& login, const QString& password);
    
    void showThread();
    
signals:
    void ready();

public slots:
    void readAll();
};

#endif // DBREADER_H
