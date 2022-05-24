#include "subjecteditdialog.h"
#include "ui_subjecteditdialog.h"

SubjectEditDialog::SubjectEditDialog(Subject* subject, QVector<Lecturer*> lecturers, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::SubjectEditDialog)
{
    ui->setupUi(this);
    m_subject = subject;
    m_lecturers = lecturers;
    init();
}

SubjectEditDialog::~SubjectEditDialog()
{
    delete ui;
}

void SubjectEditDialog::init() {
    ui->txtName->setText(m_subject->name());
    foreach (Lecturer* lecturer, m_subject->lecturers()) {
        ui->listLecturers->addItem(lecturer->firstName() + " " + lecturer->lastName());
    }
    foreach (Lecturer* lecturer, m_lecturers) {
        if (!m_subject->lecturers().contains(lecturer)) {
            ui->cmbLecturers->addItem(lecturer->firstName() + " " + lecturer->lastName());
        }
    }
}
