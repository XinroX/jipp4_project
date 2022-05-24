#include "studentdialog.h"
#include "ui_studentdialog.h"
#include "address.h"

StudentDialog::StudentDialog(Person* student, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::StudentDialog)
{
    ui->setupUi(this);
    DBReader* db = new DBReader;
    db->setup();
    if (db->open()) {
        db->readAll();
        this->student = qobject_cast<Student*>(student);
        m_courses = db->getCoursesForStudent(this->student);
        init();
    }
}

StudentDialog::~StudentDialog()
{
    delete ui;
}

void StudentDialog::init() {
    addInfoTab();
    addGradesTab();
    addCoursesTab();
}


void StudentDialog::addInfoTab() {
    QWidget* infoTab = new QWidget(this);
    ui->tabStudent->addTab(infoTab, "Informacje");
    QGridLayout* infoLayout = new QGridLayout(this);
    
    infoLayout->addWidget(new QLabel("Imię", infoTab), 0, 0);
    QLabel* lblNameValue = new QLabel(infoTab);
    lblNameValue->setText(student->firstName());
    infoLayout->addWidget(lblNameValue, 0, 1);
    
    infoLayout->addWidget(new QLabel("Nazwisko", infoTab), 1, 0);
    QLabel* lblLastNameValue = new QLabel(infoTab);
    lblLastNameValue->setText(student->lastName());
    infoLayout->addWidget(lblLastNameValue, 1, 1);
    
    infoLayout->addWidget(new QLabel("Numer", infoTab), 2, 0);
    QLabel* lblNumberValue = new QLabel(infoTab);
    lblNumberValue->setText(student->number());
    infoLayout->addWidget(lblNumberValue, 2, 1);
    
    infoLayout->addWidget(new QLabel("Data urodzenia", infoTab), 3, 0);
    QLabel* lblDateOfBirth = new QLabel(infoTab);
    lblDateOfBirth->setText(student->dateOfBirth().toString(Qt::DateFormat::LocalDate));
    infoLayout->addWidget(lblDateOfBirth, 3, 1);
    
    infoLayout->addWidget(new QLabel("Adres", infoTab), 4, 0);
    QLabel* lblAddress = new QLabel(infoTab);
    lblAddress->setText(student->address()->showAddress());
    infoLayout->addWidget(lblAddress, 4, 1);
    
    infoLayout->addItem(new QSpacerItem(500, 200), 5, 0, 1, 2);
    
    infoTab->setLayout(infoLayout);
}

void StudentDialog::addGradesTab() {
    QTableWidget* gradesTab = new QTableWidget(this);
    ui->tabStudent->addTab(gradesTab, "Oceny");
    gradesTab->setColumnCount(2);
    gradesTab->setColumnWidth(0, 800);
    gradesTab->setColumnWidth(1, 250);
    QVector<Grade*> grades = student->grades();
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
}

void StudentDialog::addCoursesTab() {
    QTableWidget* coursesTab = new QTableWidget(this);
    ui->tabStudent->addTab(coursesTab, "Kursy");
    coursesTab->setColumnCount(3);
    coursesTab->setColumnWidth(0, 300);
    coursesTab->setColumnWidth(1, 300);
    coursesTab->setColumnWidth(2, 200);
    coursesTab->setRowCount(m_courses.size());
    for (int i = 0; i < m_courses.size(); ++i) {
        coursesTab->setRowHeight(i, 50);
        QTableWidgetItem* itemSubjectName = new QTableWidgetItem(m_courses[i]->subjectName());
        itemSubjectName->setFlags(itemSubjectName->flags() ^ Qt::ItemIsEditable);
        coursesTab->setItem(i, 0, itemSubjectName);
        QTableWidgetItem* itemLecturerName = new QTableWidgetItem(m_courses[i]->lecturerName());
        itemLecturerName->setFlags(itemLecturerName->flags() ^ Qt::ItemIsEditable);
        coursesTab->setItem(i, 1, itemLecturerName);
        QPushButton* btnMore = new QPushButton("Więcej", coursesTab);
        btnMore->setProperty("ID", i);
        coursesTab->setCellWidget(i, 2, btnMore);
        connect(btnMore, &QPushButton::clicked, this, &StudentDialog::btnMoreClicked);
    }
    coursesTab->verticalHeader()->setVisible(false);
    coursesTab->setHorizontalHeaderLabels(QStringList({"Nazwa", "Prowadzący", ""}));
    coursesTab->horizontalHeader()->setSectionResizeMode(QHeaderView::Fixed);
}

void StudentDialog::btnMoreClicked() {
    int index = sender()->property("ID").toInt();
    if (index >= 0 && index < m_courses.size() && courseDialog == nullptr) {
        courseDialog = new CourseDialog(m_courses[index], this);
        courseDialog->initStudentView();
        //courseDialog->mapFromGlobal()===
        courseDialog->open();
        connect(courseDialog, &CourseDialog::rejected, [=](){
            delete courseDialog;
            courseDialog = nullptr;
        });
    }
}

