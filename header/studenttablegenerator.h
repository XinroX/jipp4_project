#ifndef STUDENTTABLEGENERATOR_H
#define STUDENTTABLEGENERATOR_H

#include <QObject>
#include <QWidget>
#include <QGridLayout>
#include <QLabel>
#include <QPushButton>
#include <QHeaderView>
#include "student.h"
#include "course.h"

class StudentTableGenerator : public QObject
{
    Q_OBJECT
public:
    explicit StudentTableGenerator(Student* student, QVector<Course*> courses, QObject *parent = nullptr);

    QTabWidget* getStudentTab();

private:
    QTabWidget* m_student_tab;
    Student* m_student;
    QVector<Course*> m_courses;
    QWidget* generateStudentInfoTable();
    QTableWidget* generateStudentGradesTableWidget();
    QTableWidget* generateStudentCoursesTableWidget();

};

#endif // STUDENTTABLEGENERATOR_H
