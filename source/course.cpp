#include "course.h"

Course::Course(const int& id, Subject* subject, const QString &description, QObject *parent) : QObject(parent)
{
    m_id = id;
    m_subject = subject;
    m_description = description;
    m_lecturer = nullptr;
}


void Course::addStudent(Student *student) {
    m_students.append(student);
}

void Course::addLecturer(Lecturer *lecturer) {
    m_lecturer = lecturer;
}

int Course::id() const {
    return m_id;
}

bool Course::containsStudent(Student *student) {
    foreach (Student* temp, m_students) {
        if (temp->id() == student->id()) {
            return true;
        }
    }
    return false;
}

QString Course::subjectName() {
    return m_subject->name();
}

QString Course::lecturerName() {
    if (m_lecturer == nullptr) {
        return QString();
    }
    return m_lecturer->firstName() + " " + m_lecturer->lastName();
}

QVector<Student*> Course::students() {
    return m_students;
}

QString Course::description()
{
    return m_description;
}

void Course::deleteStudent(Student *student) {
    for (int i = 0; i < m_students.size(); ++i) {
        if (m_students[i]->id() == student->id()) {
            m_students.removeAt(i);
            break;
        }
    }
}

void Course::deleteLecturer(Lecturer* lecturer) {
    if(m_lecturer != nullptr && m_lecturer->id() == lecturer->id()) {
        m_lecturer = nullptr;
    }
}
