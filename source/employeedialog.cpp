#include "employeedialog.h"
#include "ui_employeedialog.h"

EmployeeDialog::EmployeeDialog(Person* person, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::EmployeeDialog)
{
    ui->setupUi(this);
    this->setAttribute(Qt::WA_DeleteOnClose);
    employee = person;
    this->setWindowTitle(employee->firstName() + " " + employee->lastName());
    dbThread = new QThread(this);
    this->db = new DBReader;
    this->db->moveToThread(dbThread);
    this->db->setup();
    if (this->db->open()) {
        connect(dbThread, &QThread::started, this, [=](){
            loadForm = new LoadForm(this);
            loadForm->start();
            loadForm->show();
        });
        connect(dbThread, &QThread::started, db, &DBReader::readAll);
        connect(db, &DBReader::ready, dbThread, &QThread::quit);
        connect(dbThread, &QThread::finished, this, [=](){
            m_students = db->students();
            m_lecturers = db->lecturers();
            m_courses = db->courses();
            m_subjects = db->subjects();
            if (!db->getMaxStudentNumber().isNull()) {
                studentNumber = db->getMaxStudentNumber();
            }
            delete dbThread;
            delete db;
            delete loadForm;
            dbThread = new QThread(this);
            dbWriter = new DBWriter(&m_mutex);
            dbWriter->moveToThread(dbThread);
            dbWriter->setup();
            if (dbWriter->open()) {
                connect(dbThread, &QThread::started, dbWriter, &DBWriter::start);
                Connector::ConnectLecturersToDBWriter(m_lecturers, dbWriter);
                Connector::ConnectStudentsToDBWriter(m_students, dbWriter);
                connect(dbThread, &QThread::finished, dbWriter, &DBWriter::deleteLater);
                connect(dbThread, &QThread::finished, dbThread, &QThread::deleteLater);
                connect(this, &EmployeeDialog::finished, dbThread, &QThread::quit);
                dbThread->start();
            }
            
        });
        connect(dbThread, &QThread::finished, this, &EmployeeDialog::init);
        dbThread->start();
        
    }
}

EmployeeDialog::~EmployeeDialog()
{
    delete ui;
    delete studentsTab;
    delete lecturersTab;
    delete coursesTab;
    delete subjectsTab;
}

void EmployeeDialog::init() {
    studentsTab = TableWidgetGenerator::generateStudentsTable(m_students);
    lecturersTab = TableWidgetGenerator::generateLecturersTable(m_lecturers, m_subjects);
    coursesTab = TableWidgetGenerator::generateCoursesTable(m_courses);
    subjectsTab = TableWidgetGenerator::generateSubjectsTable(m_subjects);
    studentsTab->setParent(ui->tabEmployee);
    lecturersTab->setParent(ui->tabEmployee);
    coursesTab->setParent(ui->tabEmployee);
    subjectsTab->setParent(ui->tabEmployee);
    ui->tabEmployee->addTab(studentsTab, "Studenci");
    ui->tabEmployee->addTab(lecturersTab, "Wykładowcy");
    ui->tabEmployee->addTab(coursesTab, "Kursy");
    ui->tabEmployee->addTab(subjectsTab, "Przedmioty");
    addButtons();
    qInfo() << ui->tabEmployee->currentIndex();
    studentsTab->setHorizontalHeaderLabels(QStringList() << "Imię" << "Nazwisko" << "Numer" << "Data urodzenia" << "Adres" << "");
    lecturersTab->setHorizontalHeaderLabels(QStringList() << "Imię" << "Nazwisko" << "Data urodzenia" << "Adres" << "Przedmioty" << "");
    coursesTab->setHorizontalHeaderLabels(QStringList() << "Nazwa" << "Prowadzący" << "Studenci");
    ui->tabEmployee->setCurrentIndex(0);
    qInfo() << ui->tabEmployee->currentIndex();
}

void EmployeeDialog::reinit() {
    delete studentsTab;
    delete lecturersTab;
    delete coursesTab;
    delete subjectsTab;
    qInfo() << actualIndex;
    ui->tabEmployee->clear();
    init();
    ui->tabEmployee->setCurrentIndex(actualIndex);
}

void EmployeeDialog::addButtons() {
    studentsTab->setColumnCount(6);
    for(int i = 0; i < studentsTab->rowCount(); ++i) {
        QWidget* buttonsWidget = new QWidget(studentsTab);
        QGridLayout* layout = new QGridLayout(buttonsWidget);
        buttonsWidget->setAutoFillBackground(true);
        QPushButton* btnEdit = new QPushButton(buttonsWidget);
        btnEdit->setText("Edytuj");
        btnEdit->setProperty("index", i);
        connect(btnEdit, &QPushButton::clicked, this, &EmployeeDialog::editStudent);
        layout->addWidget(btnEdit, 0, 0);
        QPushButton* btnDelete = new QPushButton(buttonsWidget);
        btnDelete->setText("Usuń");
        btnDelete->setProperty("index", i);
        connect(btnDelete, &QPushButton::clicked, this, &EmployeeDialog::deleteStudent);
        layout->addWidget(btnDelete, 1, 0);
        buttonsWidget->setLayout(layout);
        studentsTab->setCellWidget(i, 5, buttonsWidget);
    }
    studentsTab->setRowCount(studentsTab->rowCount() + 1);
    QPushButton* btnAddStudent = new QPushButton(studentsTab);
    btnAddStudent->setText("Dodaj");
    connect(btnAddStudent, &QPushButton::clicked, this, &EmployeeDialog::addStudent);
    studentsTab->setCellWidget(studentsTab->rowCount() - 1, 0, btnAddStudent);
    studentsTab->setSpan(studentsTab->rowCount() - 1, 0, 1, 6);
    lecturersTab->setColumnCount(6);
    for (int i = 0; i < lecturersTab->rowCount(); ++i) {
        QWidget* buttonsWidget = new QWidget(lecturersTab);
        QGridLayout* layout = new QGridLayout(buttonsWidget);
        buttonsWidget->setAutoFillBackground(true);
        QPushButton* btnEdit = new QPushButton(buttonsWidget);
        btnEdit->setText("Edytuj");
        btnEdit->setProperty("index", i);
        connect(btnEdit, &QPushButton::clicked, this, &EmployeeDialog::editLecturer);
        layout->addWidget(btnEdit, 0, 0);
        QPushButton* btnDelete = new QPushButton(buttonsWidget);
        btnDelete->setText("Usuń");
        btnDelete->setProperty("index", i);
        connect(btnDelete, &QPushButton::clicked, this, &EmployeeDialog::deleteLecturer);
        layout->addWidget(btnDelete, 1, 0);
        buttonsWidget->setLayout(layout);
        lecturersTab->setCellWidget(i, 5, buttonsWidget);
    }
    lecturersTab->setRowCount(lecturersTab->rowCount() + 1);
    QPushButton* btnAddLecturer = new QPushButton(lecturersTab);
    btnAddLecturer->setText("Dodaj");
    connect(btnAddLecturer, &QPushButton::clicked, this, &EmployeeDialog::addLecturer);
    lecturersTab->setCellWidget(lecturersTab->rowCount() - 1, 0 , btnAddLecturer);
    lecturersTab->setSpan(lecturersTab->rowCount() - 1, 0, 1, 6);
}

void EmployeeDialog::editStudent() {
    actualIndex = ui->tabEmployee->currentIndex();
    ChangeDialog* chgDialog = new ChangeDialog(m_students[sender()->property("index").toInt()]);
    if (chgDialog == nullptr) {
        return;
    }
    connect(chgDialog, &ChangeDialog::rejected, chgDialog, &ChangeDialog::deleteLater);
    connect(chgDialog, &ChangeDialog::accepted, chgDialog, &ChangeDialog::deleteLater);
    connect(chgDialog, &ChangeDialog::accepted, this, &EmployeeDialog::reinit);
    chgDialog->open();
}

void EmployeeDialog::deleteStudent() {
    actualIndex = ui->tabEmployee->currentIndex();
    int index = sender()->property("index").toInt();
    QMessageBox::StandardButton mbStudent = QMessageBox::question(this, "Usuwanie", "Czy na pewno chcesz usunąć tego studenta?");
    if (mbStudent == QMessageBox::Yes) {
        if (dbWriter->deleteStudent(m_students[index])) {
                    foreach(Course *course, m_courses) {
                    course->deleteStudent(m_students[index]);
                }
            delete m_students[index];
            m_students.removeAt(index);
                    foreach (Student *student, m_students) {
                    qInfo() << student->firstName() << " " << student->lastName();
                }
            reinit();
        }
    }
}

void EmployeeDialog::editLecturer() {
    actualIndex = ui->tabEmployee->currentIndex();
    ChangeDialog* chgDialog = new ChangeDialog(m_lecturers[sender()->property("index").toInt()]);
    if (chgDialog == nullptr) {
        return;
    }
    connect(chgDialog, &ChangeDialog::rejected, chgDialog, &ChangeDialog::deleteLater);
    connect(chgDialog, &ChangeDialog::accepted, chgDialog, &ChangeDialog::deleteLater);
    connect(chgDialog, &ChangeDialog::accepted, this, &EmployeeDialog::reinit);
    chgDialog->open();
    
}

void EmployeeDialog::deleteLecturer() {
    actualIndex = ui->tabEmployee->currentIndex();
    int index = sender()->property("index").toInt();
    QMessageBox::StandardButton mbLecturer = QMessageBox::question(this, "Usuwanie", "Czy na pewno chcesz usunąć tego wykładowcę?");
    if (mbLecturer == QMessageBox::Yes) {
        if (dbWriter->deleteLecturer(m_lecturers[index])) {
                    foreach (Course *course, m_courses) {
                    course->deleteLecturer(m_lecturers[index]);
                }
                    foreach (Subject *subject, m_subjects) {
                    subject->deleteLecturer(m_lecturers[index]);
                }
            delete m_lecturers[index];
            m_lecturers.removeAt(index);
                    foreach (Lecturer *lecturer, m_lecturers) {
                    qInfo() << lecturer->firstName() << " " << lecturer->lastName();
                }
            reinit();
        }
    }
}

void EmployeeDialog::addStudent() {
    AddStudentDialog* dialog = new AddStudentDialog(&studentNumber, this);
    connect(dialog, &AddStudentDialog::accepted, dialog, &AddStudentDialog::deleteLater);
    connect(dialog, &AddStudentDialog::accepted, this, [=](){
        actualIndex = ui->tabEmployee->currentIndex();
        Student* student = dialog->getStudent();
        if (dbWriter->insertStudent(student)) {
            m_students.append(dialog->getStudent());
            reinit();
        }
        else {
            delete student;
        }
    });
    connect(dialog, &AddStudentDialog::rejected, dialog, &AddStudentDialog::deleteLater);
    dialog->open();
}

void EmployeeDialog::addLecturer() {
    AddLecturerDialog* dialog = new AddLecturerDialog(this);
    connect(dialog, &AddLecturerDialog::accepted, dialog, &AddLecturerDialog::deleteLater);
    connect(dialog, &AddLecturerDialog::rejected, dialog, &AddLecturerDialog::deleteLater);
    connect(dialog, &AddLecturerDialog::accepted, this, [=](){
        actualIndex = ui->tabEmployee->currentIndex();
        Lecturer* lecturer = dialog->getLecturer();
        if (dbWriter->insertLecturer(lecturer)) {
            m_lecturers.append(dialog->getLecturer());
            reinit();
        }
        else {
            delete lecturer;
        }
    });
    dialog->open();
}


