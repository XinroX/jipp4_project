#ifndef SUBJECTEDITDIALOG_H
#define SUBJECTEDITDIALOG_H

#include <QDialog>
#include "subject.h"

namespace Ui {
class SubjectEditDialog;
}

class SubjectEditDialog : public QDialog
{
    Q_OBJECT
    
public:
    explicit SubjectEditDialog(Subject* subject, QVector<Lecturer*> lecturers, QWidget *parent = nullptr);
    ~SubjectEditDialog();
    
private:
    Ui::SubjectEditDialog *ui;
    
    Subject* m_subject;
    QVector<Lecturer*> m_lecturers;
    void init();
};

#endif // SUBJECTEDITDIALOG_H
