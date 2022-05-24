#include "tools.h"
#include "subject.h"
#include "lecturer.h"

Tools::Tools(QObject *parent) : QObject(parent)
{

}


QDate Tools::formatDate(const QString &value) {
    QStringList list = value.split("-");
    int year = list[0].toInt();
    int month = list[1].toInt();
    int day = list[2].toInt();
    return QDate(year, month, day);
}

QTableWidgetItem* Tools::getFilledItem(const QString &content) {
    QTableWidgetItem* result = new QTableWidgetItem(content);
    result->setFlags(result->flags() ^ Qt::ItemIsEditable);
    return result;
}

QStringList Tools::getSubjectsForLecturers(QVector<Subject *> subjects, Lecturer *lecturer)
{
    QStringList result;
    foreach (Subject* subject, subjects) {
        foreach (Lecturer* temp, subject->lecturers()) {
            if (temp->id() == lecturer->id()) {
                result << subject->name();
            }
        }
    }
    return result;
}

QString Tools::dateToString(const QDate &date) {
    QString result;
    result = QString::number(date.year()) + "-" + QString::number(date.month()) + "-" + QString::number(date.day());
    qInfo() << result;
    return result;
}

QString Tools::incrementStudentNumber(int number) {
    number++;
    QString result = QString::number(number);
    for (int i = result.size(); i < 4; ++i) {
        result = "0" + result;
    }
    return result;
}