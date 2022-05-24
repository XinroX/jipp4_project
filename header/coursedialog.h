#ifndef COURSEDIALOG_H
#define COURSEDIALOG_H

#include <QDialog>
#include <QPushButton>
#include <QLabel>
#include <QVBoxLayout>
#include <QGridLayout>
#include "course.h"
namespace Ui {
class CourseDialog;
}

class CourseDialog : public QDialog
{
    Q_OBJECT
    
public:
    explicit CourseDialog(QWidget *parent = nullptr);
    explicit CourseDialog(Course* course, QWidget* parent = nullptr);
    ~CourseDialog();
    
    void initStudentView();
    
private:
    Ui::CourseDialog *ui;
    
    void init();
    Course* course;
    
};

#endif // COURSEDIALOG_H
