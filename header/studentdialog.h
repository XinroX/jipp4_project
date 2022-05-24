#ifndef STUDENTDIALOG_H
#define STUDENTDIALOG_H

#include <QDialog>
#include <QWidget>
#include <QVBoxLayout>
#include <QLabel>
#include <QGridLayout>
#include <QSpacerItem>
#include <QTableWidget>
#include <QTableWidgetItem>
#include <QHeaderView>
#include <QStringList>
#include <QPushButton>
#include "student.h"
#include "coursedialog.h"
#include "dbreader.h"

namespace Ui {
class StudentDialog;
}

class StudentDialog : public QDialog
{
    Q_OBJECT

public:
    explicit StudentDialog(Person* student, QWidget *parent = nullptr);
    ~StudentDialog();

private:
    Ui::StudentDialog *ui;
    Student* student;
    QVector<Course*> m_courses;
    CourseDialog* courseDialog = nullptr;
    
    void init();
    void addInfoTab();
    void addGradesTab();
    void addCoursesTab();
    
private slots:
    void btnMoreClicked();
    //void courseDialogClose();
};

#endif // STUDENTDIALOG_H
