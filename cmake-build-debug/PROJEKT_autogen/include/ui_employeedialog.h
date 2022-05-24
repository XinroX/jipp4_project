/********************************************************************************
** Form generated from reading UI file 'employeedialog.ui'
**
** Created by: Qt User Interface Compiler version 5.15.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_EMPLOYEEDIALOG_H
#define UI_EMPLOYEEDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_EmployeeDialog
{
public:
    QVBoxLayout *verticalLayout;
    QTabWidget *tabEmployee;

    void setupUi(QDialog *EmployeeDialog)
    {
        if (EmployeeDialog->objectName().isEmpty())
            EmployeeDialog->setObjectName(QString::fromUtf8("EmployeeDialog"));
        EmployeeDialog->resize(1162, 617);
        EmployeeDialog->setMinimumSize(QSize(1162, 617));
        EmployeeDialog->setMaximumSize(QSize(1162, 617));
        verticalLayout = new QVBoxLayout(EmployeeDialog);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        tabEmployee = new QTabWidget(EmployeeDialog);
        tabEmployee->setObjectName(QString::fromUtf8("tabEmployee"));

        verticalLayout->addWidget(tabEmployee);


        retranslateUi(EmployeeDialog);

        QMetaObject::connectSlotsByName(EmployeeDialog);
    } // setupUi

    void retranslateUi(QDialog *EmployeeDialog)
    {
        EmployeeDialog->setWindowTitle(QCoreApplication::translate("EmployeeDialog", "Dialog", nullptr));
    } // retranslateUi

};

namespace Ui {
    class EmployeeDialog: public Ui_EmployeeDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_EMPLOYEEDIALOG_H
