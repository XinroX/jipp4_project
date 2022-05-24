#include "subject.h"

Subject::Subject(const Subject& subject, QObject *parent) : QObject(parent)
{
    m_id = subject.m_id;
    m_name = subject.m_name;
}

Subject::Subject(const int& id, const QString& name, QObject* parent) : QObject(parent) {
    m_id = id;
    m_name = name;
}



int Subject::id() const {
    return m_id;
}

void Subject::addLecturer(Lecturer* lecturer) {
    m_lecturers.append(lecturer);
}

QString Subject::name() const {
    return m_name;
}

void Subject::setName(const QString& value) {
    if (!value.isEmpty() && !value.isNull()) {
        m_name = value;
    }
}

QVector<Lecturer*> Subject::lecturers() const{
    return m_lecturers;
}

void Subject::deleteLecturer(Lecturer* lecturer) {
    for (int i = 0; i < m_lecturers.size(); ++i) {
        if (m_lecturers[i]->id() == lecturer->id()) {
            m_lecturers.removeAt(i);
            break;
        }
    }
}