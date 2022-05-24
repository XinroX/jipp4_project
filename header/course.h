#ifndef COURSE_H
#define COURSE_H

#include <QObject>
#include "student.h"

class Course : public QObject
{
    Q_OBJECT
public:
    explicit Course(const int& id, Subject* subject, const QString& description, QObject *parent = nullptr);


    void addStudent(Student* student);
    void addLecturer(Lecturer* lecturer);
    QString subjectName();
    QString lecturerName();

    QVector<Student*> students();
    
    QString description();

    bool containsStudent(Student* student);

    int id() const;

protected:
    int m_id;
    QVector<Student*> m_students;
    Lecturer* m_lecturer;
    Subject* m_subject;
    QString m_description;
    bool m_finished;
public slots:
    void deleteStudent(Student* student);
    void deleteLecturer(Lecturer* lecturer);

};

#endif // COURSE_H
