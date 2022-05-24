#include "coursedialog.h"
#include "ui_coursedialog.h"

CourseDialog::CourseDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::CourseDialog)
{
    ui->setupUi(this);
}

CourseDialog::CourseDialog(Course *course, QWidget *parent)
{
    this->course = course;
}

void CourseDialog::initStudentView() {
    init();
}

void CourseDialog::init() {
    QGridLayout* layout = new QGridLayout(this);
    QLabel* lblCourseName = new QLabel("Nazwa");
    layout->addWidget(lblCourseName, 0, 0);
    QLabel* lblCourseNameValue = new QLabel(course->subjectName());
    layout->addWidget(lblCourseNameValue, 0, 1);
    QLabel* lblLecturerName = new QLabel("Prowadzący");
    layout->addWidget(lblLecturerName, 1, 0);
    QLabel* lblLecturerNameValue = new QLabel(course->lecturerName());
    layout->addWidget(lblLecturerNameValue, 1, 1);
    QLabel* lblDescription = new QLabel("Opis");
    layout->addWidget(lblDescription, 2, 0);
    QLabel* lblDescriptionValue = new QLabel(course->description());
    layout->addWidget(lblDescriptionValue, 2, 1);
}

CourseDialog::~CourseDialog()
{
    delete ui;
}
