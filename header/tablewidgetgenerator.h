#ifndef TABLEWIDGETGENERATOR_H
#define TABLEWIDGETGENERATOR_H

#include <QObject>
#include <QVector>
#include <QList>
#include <QTableWidget>
#include <QTableWidgetItem>
#include <QHeaderView>
#include "lecturer.h"
#include "course.h"


class TableWidgetGenerator : public QObject
{
    Q_OBJECT
private:
    explicit TableWidgetGenerator(QObject *parent = nullptr);
public:
    static QTableWidget* generateStudentsTable(QVector<Student*> students);
    static QTableWidget* generateLecturersTable(QVector<Lecturer*> lecturers, QVector<Subject*> subjects);

    static QList<QTableWidgetItem *> getItems(Student *student);
    static QList<QTableWidgetItem*> getItems(Lecturer* lecturer, int* size);
    static QTableWidgetItem* getFilledItem(const QString& content);
    
    static QTableWidget* generateCoursesTable(QVector<Course*> courses);
    static QTableWidget* generateSubjectsTable(QVector<Subject*> subjects);
signals:

};

#endif // TABLEWIDGETGENERATOR_H
