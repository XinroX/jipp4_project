#ifndef ADDSTUDENTDIALOG_H
#define ADDSTUDENTDIALOG_H
#pragma once
#include <QDialog>
#include <QMessageBox>
#include <QDate>
#include <QComboBox>
#include "student.h"
#include "tools.h"

namespace Ui {
class AddStudentDialog;
}

class AddStudentDialog : public QDialog
{
    Q_OBJECT
    
public:
    explicit AddStudentDialog(QString* number, QWidget *parent = nullptr);
    ~AddStudentDialog();
    
    Student* getStudent();

    
private slots:
    void on_buttonBox_accepted();
    void updateCombo();
    
    
    void on_cmbMonth_currentIndexChanged(int index);
    
    void on_cmbYear_currentIndexChanged(int index);
    
    void on_buttonBox_rejected();
    
private:
    Ui::AddStudentDialog *ui;
    QString* studentNumber;
    Student* student = nullptr;
    
    
    void init();
    
    
    bool check();
    
signals:
    void plsGiveMeNumber();
};

#endif // ADDSTUDENTDIALOG_H
