#include "program.h"

Program::Program(int argc, char *argv[], QObject *parent) : QObject(parent)
{
    m_app = new QApplication(argc, argv);
    qRegisterMetaType<QSqlQuery>();
}

void Program::setup() {
    LoginDialog w;
    int result = w.exec();
    if (result == 0) {
        m_app->exit();
        return;
    }
    int dialogNum = w.chooseDialog();
    Person* person = w.getUser();
    changeDialog(dialogNum, person);
}



Program::~Program() {
    delete m_app;
}



void Program::changeDialog(int index, Person* person) {
    switch(index) {
        case 0:
            showStudentDialog(person);
            break;
        case 1:
            showEmployeeDialog(person);
            break;
    }
}



void Program::showStudentDialog(Person* person) {
    m_actual_dialog = new StudentDialog(person);
    m_actual_dialog->exec();
}

void Program::showEmployeeDialog(Person* person) {
    m_actual_dialog = new EmployeeDialog(person);
    m_actual_dialog->exec();
}

