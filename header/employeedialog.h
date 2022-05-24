#ifndef EMPLOYEEDIALOG_H
#define EMPLOYEEDIALOG_H
#pragma once
#include <QDialog>
#include <QFile>
#include <QMessageBox>
#include <QTextStream>
#include <QDate>
#include <QTableWidget>
#include <QTableWidgetItem>
#include <QHeaderView>
#include <QPushButton>
#include <QFont>
#include <QGridLayout>
#include <QThread>
#include <QVBoxLayout>
#include <QSqlDatabase>
#include <QTimer>
#include "dbwriter.h"
#include "dbreader.h"
#include "loadform.h"
#include "course.h"
#include "connector.h"
#include "addlecturerdialog.h"
#include "addstudentdialog.h"

namespace Ui {
class EmployeeDialog;
}

class EmployeeDialog : public QDialog
{
    Q_OBJECT

public:
    explicit EmployeeDialog(Person* person, QWidget *parent = nullptr);

    ~EmployeeDialog();

private:
    Ui::EmployeeDialog *ui;
    Person* employee;
    DBReader* db;
    QTableWidget* studentsTab;
    QTableWidget* lecturersTab;
    QTableWidget* coursesTab;
    QTableWidget* subjectsTab;
    QThread* dbThread;
    LoadForm* loadForm;
    QLayout* m_layout;
    QMutex m_mutex;
    
    DBWriter* dbWriter;

    
    QVector<Student*> m_students;
    QVector<Lecturer*> m_lecturers;
    QVector<Subject*> m_subjects;
    QVector<Course*> m_courses;

    bool showDeleteDialog();
    
    QString studentNumber;


    void addButtons();
    int actualIndex = 0;

private slots:
    void reinit();
    void init();
    void editStudent();
    void deleteStudent();
    void editLecturer();
    void deleteLecturer();
    
    void addStudent();
    void addLecturer();


};

#endif // EMPLOYEEDIALOG_H
