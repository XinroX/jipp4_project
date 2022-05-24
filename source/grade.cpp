#include "grade.h"

Grade::Grade(const Subject& subject, const float& value, QObject *parent) : QObject(parent)
{
    m_subject_name = subject.name();
    m_value = value;
}

Grade::Grade(const int& id, const QString& subject_name, const float& value, QObject *parent) : QObject(parent)
{
    m_id = id;
    m_subject_name = subject_name;
    m_value = value;
}

int Grade::id() const {
    return m_id;
}



float Grade::value() const {
    return m_value;
}


void Grade::setValue(float value) {
    if (value == 2 || value == 3 || value == 3.5 || value == 4 || value == 4.5 || value == 5) {
        m_value = value;
    }
}

int Grade::subjectID() const {
    return m_subject_id;
}

QString Grade::subjectName() const {
    return m_subject_name;
}
