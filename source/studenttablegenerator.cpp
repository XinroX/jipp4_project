#include "studenttablegenerator.h"
#include "address.h"
#include "tablewidgetgenerator.h"

StudentTableGenerator::StudentTableGenerator(Student* student, QVector<Course*> courses, QObject *parent)
    : QObject{parent}
{
    m_student = student;
    m_courses = courses;
    m_student_tab = new QTabWidget;
}

QWidget* StudentTableGenerator::generateStudentInfoTable() {
    QWidget* result = new QWidget(m_student_tab);
    QGridLayout* infoLayout = new QGridLayout(result);

    infoLayout->addWidget(new QLabel("Imię", result), 0, 0);
    QLabel* lblNameValue = new QLabel(result);
    lblNameValue->setText(m_student->firstName());
    infoLayout->addWidget(lblNameValue, 0, 1);

    infoLayout->addWidget(new QLabel("Nazwisko", result), 1, 0);
    QLabel* lblLastNameValue = new QLabel(result);
    lblLastNameValue->setText(m_student->lastName());
    infoLayout->addWidget(lblLastNameValue, 1, 1);

    infoLayout->addWidget(new QLabel("Numer", result), 2, 0);
    QLabel* lblNumberValue = new QLabel(result);
    lblNumberValue->setText(m_student->number());
    infoLayout->addWidget(lblNumberValue, 2, 1);

    infoLayout->addWidget(new QLabel("Data urodzenia", result), 3, 0);
    QLabel* lblDateOfBirth = new QLabel(result);
    lblDateOfBirth->setText(m_student->dateOfBirth().toString(Qt::DateFormat::LocalDate));
    infoLayout->addWidget(lblDateOfBirth, 3, 1);

    infoLayout->addWidget(new QLabel("Adres", result), 4, 0);
    QLabel* lblAddress = new QLabel(result);
    lblAddress->setText(m_student->address()->showAddress());
    infoLayout->addWidget(lblAddress, 4, 1);

    infoLayout->addItem(new QSpacerItem(500, 200), 5, 0, 1, 2);

    result->setLayout(infoLayout);
    return result;
}

QTableWidget* StudentTableGenerator::generateStudentGradesTableWidget() {
    QTableWidget* gradesTab = new QTableWidget(m_student_tab);
    gradesTab->setColumnCount(2);
    gradesTab->setColumnWidth(0, 800);
    gradesTab->setColumnWidth(1, 250);
    QVector<Grade*> grades = m_student->grades();
    gradesTab->setRowCount(grades.size());
    for (int i = 0; i < grades.size(); ++i) {
        gradesTab->setRowHeight(i, 50);
        QTableWidgetItem* itemSubject = new QTableWidgetItem(grades[i]->subjectName());
        itemSubject->setFlags(itemSubject->flags() ^ Qt::ItemIsEditable);
        gradesTab->setItem(i, 0, itemSubject);
        QTableWidgetItem* itemValue = new QTableWidgetItem(QString::number(grades[i]->value()));
        itemValue->setFlags(itemValue->flags() ^ Qt::ItemIsEditable);
        gradesTab->setItem(i, 1, itemValue);
    }
    gradesTab->verticalHeader()->setVisible(false);
    gradesTab->setHorizontalHeaderLabels(QStringList({"Przedmiot", "Ocena"}));
    gradesTab->horizontalHeader()->setSectionResizeMode(QHeaderView::Fixed);
    return gradesTab;
}

QTableWidget* StudentTableGenerator::generateStudentCoursesTableWidget() {
    QTableWidget* coursesTab = new QTableWidget(m_student_tab);
    coursesTab->setColumnCount(3);
    coursesTab->setColumnWidth(0, 300);
    coursesTab->setColumnWidth(1, 300);
    coursesTab->setColumnWidth(2, 200);
    coursesTab->setRowCount(m_courses.size());
    for (int i = 0; i < m_courses.size(); ++i) {
        coursesTab->setRowHeight(i, 50);
        coursesTab->setItem(i, 0, TableWidgetGenerator::getFilledItem(m_courses[i]->subjectName()));
        coursesTab->setItem(i, 1, TableWidgetGenerator::getFilledItem(m_courses[i]->lecturerName()));
        QPushButton* btnMore = new QPushButton("Więcej", coursesTab);
        coursesTab->setCellWidget(i, 2, btnMore);
    }
    coursesTab->verticalHeader()->setVisible(false);
    coursesTab->setHorizontalHeaderLabels(QStringList({"Przedmiot", "Prowadzący", ""}));
    coursesTab->horizontalHeader()->setSectionResizeMode(QHeaderView::Fixed);
    return coursesTab;
}

QTabWidget* StudentTableGenerator::getStudentTab() {
    QWidget* studentInfo = generateStudentInfoTable();
    QTableWidget* gradesTab = generateStudentGradesTableWidget();
    QTableWidget* coursesTab = generateStudentCoursesTableWidget();
    int index = m_student_tab->currentIndex();
    m_student_tab->clear();
    m_student_tab->addTab(studentInfo, "Informacje");
    m_student_tab->addTab(gradesTab, "Oceny");
    m_student_tab->addTab(coursesTab, "Kursy");
    m_student_tab->setCurrentIndex(index);
    m_student_tab->setAutoFillBackground(true);
    return m_student_tab;
}