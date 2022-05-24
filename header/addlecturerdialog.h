#ifndef ADDLECTURERDIALOG_H
#define ADDLECTURERDIALOG_H

#include <QDialog>
#include <QDate>
#include <QMessageBox>
#include "lecturer.h"
class Lecturer;
namespace Ui {
class AddLecturerDialog;
}

class AddLecturerDialog : public QDialog
{
    Q_OBJECT
    
public:
    explicit AddLecturerDialog(QWidget *parent = nullptr);
    ~AddLecturerDialog();
    
    Lecturer* getLecturer();
    
private slots:
    void on_buttonBox_accepted();
    
    void on_buttonBox_rejected();
    
    void on_cmbMonth_currentIndexChanged(int index);
    
    void on_cmbYear_currentIndexChanged(int index);
    
private:
    Ui::AddLecturerDialog *ui;
    
    bool check();
    
    void init();
    
    Lecturer* lecturer = nullptr;
    
    void updateCombo();
};

#endif // ADDLECTURERDIALOG_H
