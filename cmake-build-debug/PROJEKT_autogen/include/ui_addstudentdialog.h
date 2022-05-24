/********************************************************************************
** Form generated from reading UI file 'addstudentdialog.ui'
**
** Created by: Qt User Interface Compiler version 5.15.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ADDSTUDENTDIALOG_H
#define UI_ADDSTUDENTDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QStackedWidget>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_AddStudentDialog
{
public:
    QVBoxLayout *verticalLayout;
    QStackedWidget *stackedWidget;
    QWidget *page_3;
    QVBoxLayout *verticalLayout_3;
    QGridLayout *gridLayout_2;
    QLineEdit *txtApartmentNumber;
    QLabel *label_11;
    QComboBox *cmbCountry;
    QLabel *label_12;
    QLineEdit *txtLastName;
    QLineEdit *txtZipCode;
    QLabel *label_13;
    QLabel *label_14;
    QLineEdit *txtStreet;
    QLabel *label_15;
    QLabel *label_16;
    QLineEdit *txtName;
    QLabel *label_17;
    QLabel *label_18;
    QLineEdit *txtHouseNumber;
    QLabel *label_19;
    QLabel *label_20;
    QHBoxLayout *horizontalLayout_2;
    QComboBox *cmbDay;
    QComboBox *cmbMonth;
    QComboBox *cmbYear;
    QLineEdit *txtCity;
    QWidget *page_4;
    QDialogButtonBox *buttonBox;

    void setupUi(QDialog *AddStudentDialog)
    {
        if (AddStudentDialog->objectName().isEmpty())
            AddStudentDialog->setObjectName(QString::fromUtf8("AddStudentDialog"));
        AddStudentDialog->resize(423, 407);
        verticalLayout = new QVBoxLayout(AddStudentDialog);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        stackedWidget = new QStackedWidget(AddStudentDialog);
        stackedWidget->setObjectName(QString::fromUtf8("stackedWidget"));
        page_3 = new QWidget();
        page_3->setObjectName(QString::fromUtf8("page_3"));
        verticalLayout_3 = new QVBoxLayout(page_3);
        verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));
        gridLayout_2 = new QGridLayout();
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        txtApartmentNumber = new QLineEdit(page_3);
        txtApartmentNumber->setObjectName(QString::fromUtf8("txtApartmentNumber"));
        txtApartmentNumber->setMaxLength(10);

        gridLayout_2->addWidget(txtApartmentNumber, 9, 1, 1, 1);

        label_11 = new QLabel(page_3);
        label_11->setObjectName(QString::fromUtf8("label_11"));

        gridLayout_2->addWidget(label_11, 8, 0, 1, 1);

        cmbCountry = new QComboBox(page_3);
        cmbCountry->setObjectName(QString::fromUtf8("cmbCountry"));

        gridLayout_2->addWidget(cmbCountry, 4, 1, 1, 1);

        label_12 = new QLabel(page_3);
        label_12->setObjectName(QString::fromUtf8("label_12"));

        gridLayout_2->addWidget(label_12, 5, 0, 1, 1);

        txtLastName = new QLineEdit(page_3);
        txtLastName->setObjectName(QString::fromUtf8("txtLastName"));

        gridLayout_2->addWidget(txtLastName, 1, 1, 1, 1);

        txtZipCode = new QLineEdit(page_3);
        txtZipCode->setObjectName(QString::fromUtf8("txtZipCode"));

        gridLayout_2->addWidget(txtZipCode, 6, 1, 1, 1);

        label_13 = new QLabel(page_3);
        label_13->setObjectName(QString::fromUtf8("label_13"));

        gridLayout_2->addWidget(label_13, 9, 0, 1, 1);

        label_14 = new QLabel(page_3);
        label_14->setObjectName(QString::fromUtf8("label_14"));

        gridLayout_2->addWidget(label_14, 7, 0, 1, 1);

        txtStreet = new QLineEdit(page_3);
        txtStreet->setObjectName(QString::fromUtf8("txtStreet"));

        gridLayout_2->addWidget(txtStreet, 7, 1, 1, 1);

        label_15 = new QLabel(page_3);
        label_15->setObjectName(QString::fromUtf8("label_15"));

        gridLayout_2->addWidget(label_15, 4, 0, 1, 1);

        label_16 = new QLabel(page_3);
        label_16->setObjectName(QString::fromUtf8("label_16"));

        gridLayout_2->addWidget(label_16, 0, 0, 1, 1);

        txtName = new QLineEdit(page_3);
        txtName->setObjectName(QString::fromUtf8("txtName"));
        txtName->setFrame(true);

        gridLayout_2->addWidget(txtName, 0, 1, 1, 1);

        label_17 = new QLabel(page_3);
        label_17->setObjectName(QString::fromUtf8("label_17"));

        gridLayout_2->addWidget(label_17, 6, 0, 1, 1);

        label_18 = new QLabel(page_3);
        label_18->setObjectName(QString::fromUtf8("label_18"));

        gridLayout_2->addWidget(label_18, 1, 0, 1, 1);

        txtHouseNumber = new QLineEdit(page_3);
        txtHouseNumber->setObjectName(QString::fromUtf8("txtHouseNumber"));
        txtHouseNumber->setMaxLength(10);

        gridLayout_2->addWidget(txtHouseNumber, 8, 1, 1, 1);

        label_19 = new QLabel(page_3);
        label_19->setObjectName(QString::fromUtf8("label_19"));

        gridLayout_2->addWidget(label_19, 2, 0, 1, 1);

        label_20 = new QLabel(page_3);
        label_20->setObjectName(QString::fromUtf8("label_20"));
        label_20->setAlignment(Qt::AlignBottom|Qt::AlignHCenter);

        gridLayout_2->addWidget(label_20, 3, 0, 1, 2);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        cmbDay = new QComboBox(page_3);
        cmbDay->setObjectName(QString::fromUtf8("cmbDay"));
        cmbDay->setSizeAdjustPolicy(QComboBox::AdjustToContents);

        horizontalLayout_2->addWidget(cmbDay);

        cmbMonth = new QComboBox(page_3);
        cmbMonth->setObjectName(QString::fromUtf8("cmbMonth"));
        cmbMonth->setSizeAdjustPolicy(QComboBox::AdjustToContentsOnFirstShow);

        horizontalLayout_2->addWidget(cmbMonth);

        cmbYear = new QComboBox(page_3);
        cmbYear->setObjectName(QString::fromUtf8("cmbYear"));

        horizontalLayout_2->addWidget(cmbYear);


        gridLayout_2->addLayout(horizontalLayout_2, 2, 1, 1, 1);

        txtCity = new QLineEdit(page_3);
        txtCity->setObjectName(QString::fromUtf8("txtCity"));

        gridLayout_2->addWidget(txtCity, 5, 1, 1, 1);


        verticalLayout_3->addLayout(gridLayout_2);

        stackedWidget->addWidget(page_3);
        page_4 = new QWidget();
        page_4->setObjectName(QString::fromUtf8("page_4"));
        stackedWidget->addWidget(page_4);

        verticalLayout->addWidget(stackedWidget);

        buttonBox = new QDialogButtonBox(AddStudentDialog);
        buttonBox->setObjectName(QString::fromUtf8("buttonBox"));
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);

        verticalLayout->addWidget(buttonBox);


        retranslateUi(AddStudentDialog);

        QMetaObject::connectSlotsByName(AddStudentDialog);
    } // setupUi

    void retranslateUi(QDialog *AddStudentDialog)
    {
        AddStudentDialog->setWindowTitle(QCoreApplication::translate("AddStudentDialog", "Dodaj studenta", nullptr));
        label_11->setText(QCoreApplication::translate("AddStudentDialog", "Numer domu", nullptr));
        label_12->setText(QCoreApplication::translate("AddStudentDialog", "Miasto", nullptr));
        txtLastName->setInputMask(QString());
        txtZipCode->setInputMask(QCoreApplication::translate("AddStudentDialog", "99-999;_", nullptr));
        label_13->setText(QCoreApplication::translate("AddStudentDialog", "Numer lokalu", nullptr));
        label_14->setText(QCoreApplication::translate("AddStudentDialog", "Ulica:", nullptr));
        txtStreet->setInputMask(QString());
        label_15->setText(QCoreApplication::translate("AddStudentDialog", "Pa\305\204stwo:", nullptr));
        label_16->setText(QCoreApplication::translate("AddStudentDialog", "Imi\304\231:", nullptr));
        txtName->setInputMask(QString());
        label_17->setText(QCoreApplication::translate("AddStudentDialog", "Kod pocztowy:", nullptr));
        label_18->setText(QCoreApplication::translate("AddStudentDialog", "Nazwisko:", nullptr));
        label_19->setText(QCoreApplication::translate("AddStudentDialog", "Data urodzenia:", nullptr));
        label_20->setText(QCoreApplication::translate("AddStudentDialog", "Adres:", nullptr));
        txtCity->setInputMask(QString());
    } // retranslateUi

};

namespace Ui {
    class AddStudentDialog: public Ui_AddStudentDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ADDSTUDENTDIALOG_H
