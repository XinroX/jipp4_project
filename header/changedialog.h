#ifndef CHANGEDIALOG_H
#define CHANGEDIALOG_H
#pragma once
#include <QDialog>
#include <QStackedWidget>
#include <QVBoxLayout>
#include <QMessageBox>
#include "student.h"

namespace Ui {
class ChangeDialog;
}

class ChangeDialog : public QDialog
{
    Q_OBJECT

public:
    explicit ChangeDialog(Person* person, QWidget *parent = nullptr);
    ~ChangeDialog();


private slots:
    void on_cmbMonth_currentIndexChanged(int index);

    void on_cmbYear_currentIndexChanged(int index);

    void on_buttonBox_accepted();

    void on_buttonBox_rejected();

private:
    Ui::ChangeDialog *ui;
    Person* person;


    void init();
    void updateCombo();
    bool check();
  
};

#endif // CHANGEDIALOG_H
