#ifndef GRADE_H
#define GRADE_H

#include <QObject>
#include <QVariant>
#include "subject.h"
class Grade : public QObject
{
    Q_OBJECT
public:
    explicit Grade(const Subject& subject, const float& value, QObject *parent = nullptr);
    explicit Grade(const int& id, const QString& subject_name, const float& value, QObject *parent = nullptr);

    float value() const;
    int id() const;
    int subjectID() const;
    QString subjectName() const;

    void setValue(float value);

private:

    int m_id;
    float m_value;
    QString m_subject_name;
    int m_subject_id;


};

#endif // GRADE_H
