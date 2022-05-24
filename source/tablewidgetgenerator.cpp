#include "tablewidgetgenerator.h"
#include "address.h"

TableWidgetGenerator::TableWidgetGenerator(QObject *parent)
    : QObject{parent}
{

}

QTableWidget *TableWidgetGenerator::generateStudentsTable(QVector<Student*> students) {
    QTableWidget* result = new QTableWidget;
    result->setColumnCount(5);
    result->setColumnWidth(0, 150);
    result->setColumnWidth(1, 150);
    result->setColumnWidth(2, 100);
    result->setColumnWidth(3, 200);
    result->setColumnWidth(4, 300);
    result->setRowCount(students.size());
    for (int i = 0; i < students.size(); ++i) {
        QList<QTableWidgetItem*> studentInfo = getItems(students[i]);
        for (int j = 0; j < studentInfo.size(); ++j) {
            result->setItem(i, j, studentInfo[j]);
            result->setRowHeight(i, 70);
        }
    }
    result->verticalHeader()->setVisible(false);
    return result;
}

QList<QTableWidgetItem*> TableWidgetGenerator::getItems(Student *student) {
    QList<QTableWidgetItem*> result;
    result.append(getFilledItem(student->firstName()));
    result.append(getFilledItem(student->lastName()));
    result.append(getFilledItem(student->number()));
    result.append(getFilledItem(student->dateOfBirth().toString(Qt::DateFormat::LocalDate)));
    result.append(getFilledItem(student->address()->showAddress()));
    return result;
}

QTableWidgetItem* TableWidgetGenerator::getFilledItem(const QString& content) {
    QTableWidgetItem* result = new QTableWidgetItem(content);
    result->setFlags(result->flags() ^ Qt::ItemIsEditable);
    return result;
}

QTableWidget* TableWidgetGenerator::generateLecturersTable(QVector<Lecturer *> lecturers, QVector<Subject*> subjects) {
    QTableWidget* result = new QTableWidget;
    result->setColumnCount(5);
    result->setColumnWidth(0, 100);
    result->setColumnWidth(1, 100);
    result->setColumnWidth(2, 150);
    result->setColumnWidth(3, 300);
    result->setColumnWidth(4, 300);
    result->setRowCount(lecturers.size());
    for (int i = 0; i < lecturers.size(); ++i) {
        QStringList subjectsNames = Tools::getSubjectsForLecturers(subjects, lecturers[i]);
        int size = 3;
        if (subjectsNames.size() > 3) {
            size = subjectsNames.size();
        }
        result->setRowHeight(i, size * 30);
        result->setItem(i, 0, getFilledItem(lecturers[i]->firstName()));
        result->setItem(i, 1, getFilledItem(lecturers[i]->lastName()));
        result->setItem(i, 2, getFilledItem(lecturers[i]->dateOfBirth().toString(Qt::DateFormat::LocalDate)));
        result->setItem(i, 3, getFilledItem(lecturers[i]->address()->showAddress()));
        result->setItem(i, 4, getFilledItem(subjectsNames.join("\n")));
    }
    
    result->verticalHeader()->setVisible(false);
    return result;
}

QTableWidget* TableWidgetGenerator::generateCoursesTable(QVector<Course *> courses) {
    QTableWidget* result = new QTableWidget;
    result->setColumnCount(3);
    result->setColumnWidth(0, 300);
    result->setColumnWidth(1, 300);
    result->setColumnWidth(2, 400);
    result->setRowCount(courses.size());
    for (int i = 0; i < courses.size(); ++i) {
        QStringList students;
        foreach (Student* student, courses[i]->students()) {
            students.append(student->firstName() + " " + student->lastName());
        }
        int size = 1;
        if (students.size() > 3) {
            size += students.size() / 3;
        }
        result->setRowHeight(i, 30 * size);
        
        result->setItem(i, 0, getFilledItem(courses[i]->subjectName()));
        result->setItem(i, 1, getFilledItem(courses[i]->lecturerName()));
        result->setItem(i, 2, getFilledItem(students.join(", ")));
    }
    result->verticalHeader()->setVisible(false);
    return result;
}

QTableWidget* TableWidgetGenerator::generateSubjectsTable(QVector<Subject *> subjects) {
    QTableWidget* result = new QTableWidget;
    result->setColumnCount(2);
    result->setColumnWidth(0, 500);
    result->setColumnWidth(1, 500);
    result->setRowCount(subjects.size());
    for (int i = 0; i < subjects.size(); ++i) {
        QStringList lecturers;
        foreach (Lecturer* lecturer, subjects[i]->lecturers()) {
            lecturers.append(lecturer->firstName() + " " + lecturer->lastName());
        }
        int size = 1;
        if (lecturers.size() > 3) {
            size += lecturers.size() / 3;
        }
        result->setRowHeight(i, 30 * size);
        result->setItem(i, 0, getFilledItem(subjects[i]->name()));
        result->setItem(i, 1, getFilledItem(lecturers.join(", ")));
    }
    result->verticalHeader()->setVisible(false);
    result->setHorizontalHeaderLabels(QStringList() << "Nazwa przedmiotu" << "Wykładowcy");
    return result;
}


