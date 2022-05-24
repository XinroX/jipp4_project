#ifndef PROGRAM_H
#define PROGRAM_H

#include <QObject>
#include <QApplication>
#include <QPushButton>
#include <QDebug>
#include "logindialog.h"
#include "studentdialog.h"
#include "employeedialog.h"

class Program : public QObject
{
    Q_OBJECT
public:
    explicit Program(int argc, char *argv[], QObject *parent = nullptr);
    void setup();


    ~Program();
signals:


private:
    QApplication* m_app;
    QDialog* m_actual_dialog;

    void showStudentDialog(Person* person);
    void showEmployeeDialog(Person* person);
    //void showLecturerDialog(QString path);
    void changeDialog(int index, Person* person);
};
Q_DECLARE_METATYPE(QSqlQuery)
#endif // PROGRAM_H
