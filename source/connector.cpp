#include "connector.h"

Connector::Connector(QObject *parent)
    : QObject{parent}
{
    
}

void Connector::ConnectStudentsToDBWriter(QVector<Student *> students, DBWriter *db) {
    foreach (Student* student, students) {
        connect(student, &Student::update, db, &DBWriter::addQuery);
        student->connectAddressToDBWriter(db);
    }
}

void Connector::ConnectLecturersToDBWriter(QVector<Lecturer *> lecturers, DBWriter *db) {
    foreach (Lecturer* lecturer, lecturers) {
        connect(lecturer, &Lecturer::update, db, &DBWriter::addQuery);
        lecturer->connectAddressToDBWriter(db);
    }
}