/********************************************************************************
** Form generated from reading UI file 'subjecteditdialog.ui'
**
** Created by: Qt User Interface Compiler version 5.15.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SUBJECTEDITDIALOG_H
#define UI_SUBJECTEDITDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QTextEdit>

QT_BEGIN_NAMESPACE

class Ui_SubjectEditDialog
{
public:
    QDialogButtonBox *buttonBox;
    QTextEdit *txtName;
    QListWidget *listLecturers;
    QComboBox *cmbLecturers;

    void setupUi(QDialog *SubjectEditDialog)
    {
        if (SubjectEditDialog->objectName().isEmpty())
            SubjectEditDialog->setObjectName(QString::fromUtf8("SubjectEditDialog"));
        SubjectEditDialog->resize(419, 456);
        buttonBox = new QDialogButtonBox(SubjectEditDialog);
        buttonBox->setObjectName(QString::fromUtf8("buttonBox"));
        buttonBox->setGeometry(QRect(230, 420, 166, 25));
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);
        txtName = new QTextEdit(SubjectEditDialog);
        txtName->setObjectName(QString::fromUtf8("txtName"));
        txtName->setGeometry(QRect(40, 20, 321, 31));
        listLecturers = new QListWidget(SubjectEditDialog);
        listLecturers->setObjectName(QString::fromUtf8("listLecturers"));
        listLecturers->setGeometry(QRect(40, 70, 321, 211));
        cmbLecturers = new QComboBox(SubjectEditDialog);
        cmbLecturers->setObjectName(QString::fromUtf8("cmbLecturers"));
        cmbLecturers->setGeometry(QRect(60, 300, 291, 25));

        retranslateUi(SubjectEditDialog);

        QMetaObject::connectSlotsByName(SubjectEditDialog);
    } // setupUi

    void retranslateUi(QDialog *SubjectEditDialog)
    {
        SubjectEditDialog->setWindowTitle(QCoreApplication::translate("SubjectEditDialog", "Dialog", nullptr));
    } // retranslateUi

};

namespace Ui {
    class SubjectEditDialog: public Ui_SubjectEditDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SUBJECTEDITDIALOG_H
