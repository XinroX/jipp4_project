/********************************************************************************
** Form generated from reading UI file 'changedialog.ui'
**
** Created by: Qt User Interface Compiler version 5.15.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CHANGEDIALOG_H
#define UI_CHANGEDIALOG_H

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

class Ui_ChangeDialog
{
public:
    QVBoxLayout *verticalLayout;
    QStackedWidget *stackedWidget;
    QWidget *page;
    QVBoxLayout *verticalLayout_2;
    QGridLayout *gridLayout;
    QLineEdit *txtApartmentNumber;
    QLabel *label_9;
    QComboBox *cmbCountry;
    QLabel *label_6;
    QLineEdit *txtLastName;
    QLineEdit *txtZipCode;
    QLabel *label_10;
    QLabel *label_8;
    QLineEdit *txtStreet;
    QLabel *label_4;
    QLabel *label;
    QLineEdit *txtName;
    QLabel *label_7;
    QLabel *label_2;
    QLineEdit *txtHouseNumber;
    QLabel *label_3;
    QLabel *label_5;
    QHBoxLayout *horizontalLayout;
    QComboBox *cmbDay;
    QComboBox *cmbMonth;
    QComboBox *cmbYear;
    QLineEdit *txtCity;
    QWidget *page_2;
    QDialogButtonBox *buttonBox;

    void setupUi(QDialog *ChangeDialog)
    {
        if (ChangeDialog->objectName().isEmpty())
            ChangeDialog->setObjectName(QString::fromUtf8("ChangeDialog"));
        ChangeDialog->resize(428, 440);
        verticalLayout = new QVBoxLayout(ChangeDialog);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        stackedWidget = new QStackedWidget(ChangeDialog);
        stackedWidget->setObjectName(QString::fromUtf8("stackedWidget"));
        page = new QWidget();
        page->setObjectName(QString::fromUtf8("page"));
        verticalLayout_2 = new QVBoxLayout(page);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        gridLayout = new QGridLayout();
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        txtApartmentNumber = new QLineEdit(page);
        txtApartmentNumber->setObjectName(QString::fromUtf8("txtApartmentNumber"));
        txtApartmentNumber->setMaxLength(10);

        gridLayout->addWidget(txtApartmentNumber, 9, 1, 1, 1);

        label_9 = new QLabel(page);
        label_9->setObjectName(QString::fromUtf8("label_9"));

        gridLayout->addWidget(label_9, 8, 0, 1, 1);

        cmbCountry = new QComboBox(page);
        cmbCountry->setObjectName(QString::fromUtf8("cmbCountry"));

        gridLayout->addWidget(cmbCountry, 4, 1, 1, 1);

        label_6 = new QLabel(page);
        label_6->setObjectName(QString::fromUtf8("label_6"));

        gridLayout->addWidget(label_6, 5, 0, 1, 1);

        txtLastName = new QLineEdit(page);
        txtLastName->setObjectName(QString::fromUtf8("txtLastName"));

        gridLayout->addWidget(txtLastName, 1, 1, 1, 1);

        txtZipCode = new QLineEdit(page);
        txtZipCode->setObjectName(QString::fromUtf8("txtZipCode"));

        gridLayout->addWidget(txtZipCode, 6, 1, 1, 1);

        label_10 = new QLabel(page);
        label_10->setObjectName(QString::fromUtf8("label_10"));

        gridLayout->addWidget(label_10, 9, 0, 1, 1);

        label_8 = new QLabel(page);
        label_8->setObjectName(QString::fromUtf8("label_8"));

        gridLayout->addWidget(label_8, 7, 0, 1, 1);

        txtStreet = new QLineEdit(page);
        txtStreet->setObjectName(QString::fromUtf8("txtStreet"));

        gridLayout->addWidget(txtStreet, 7, 1, 1, 1);

        label_4 = new QLabel(page);
        label_4->setObjectName(QString::fromUtf8("label_4"));

        gridLayout->addWidget(label_4, 4, 0, 1, 1);

        label = new QLabel(page);
        label->setObjectName(QString::fromUtf8("label"));

        gridLayout->addWidget(label, 0, 0, 1, 1);

        txtName = new QLineEdit(page);
        txtName->setObjectName(QString::fromUtf8("txtName"));
        txtName->setFrame(true);

        gridLayout->addWidget(txtName, 0, 1, 1, 1);

        label_7 = new QLabel(page);
        label_7->setObjectName(QString::fromUtf8("label_7"));

        gridLayout->addWidget(label_7, 6, 0, 1, 1);

        label_2 = new QLabel(page);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        gridLayout->addWidget(label_2, 1, 0, 1, 1);

        txtHouseNumber = new QLineEdit(page);
        txtHouseNumber->setObjectName(QString::fromUtf8("txtHouseNumber"));
        txtHouseNumber->setMaxLength(10);

        gridLayout->addWidget(txtHouseNumber, 8, 1, 1, 1);

        label_3 = new QLabel(page);
        label_3->setObjectName(QString::fromUtf8("label_3"));

        gridLayout->addWidget(label_3, 2, 0, 1, 1);

        label_5 = new QLabel(page);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        label_5->setAlignment(Qt::AlignBottom|Qt::AlignHCenter);

        gridLayout->addWidget(label_5, 3, 0, 1, 2);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        cmbDay = new QComboBox(page);
        cmbDay->setObjectName(QString::fromUtf8("cmbDay"));
        cmbDay->setSizeAdjustPolicy(QComboBox::AdjustToContents);

        horizontalLayout->addWidget(cmbDay);

        cmbMonth = new QComboBox(page);
        cmbMonth->setObjectName(QString::fromUtf8("cmbMonth"));
        cmbMonth->setSizeAdjustPolicy(QComboBox::AdjustToContentsOnFirstShow);

        horizontalLayout->addWidget(cmbMonth);

        cmbYear = new QComboBox(page);
        cmbYear->setObjectName(QString::fromUtf8("cmbYear"));

        horizontalLayout->addWidget(cmbYear);


        gridLayout->addLayout(horizontalLayout, 2, 1, 1, 1);

        txtCity = new QLineEdit(page);
        txtCity->setObjectName(QString::fromUtf8("txtCity"));

        gridLayout->addWidget(txtCity, 5, 1, 1, 1);


        verticalLayout_2->addLayout(gridLayout);

        stackedWidget->addWidget(page);
        page_2 = new QWidget();
        page_2->setObjectName(QString::fromUtf8("page_2"));
        stackedWidget->addWidget(page_2);

        verticalLayout->addWidget(stackedWidget);

        buttonBox = new QDialogButtonBox(ChangeDialog);
        buttonBox->setObjectName(QString::fromUtf8("buttonBox"));
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);

        verticalLayout->addWidget(buttonBox);


        retranslateUi(ChangeDialog);

        QMetaObject::connectSlotsByName(ChangeDialog);
    } // setupUi

    void retranslateUi(QDialog *ChangeDialog)
    {
        ChangeDialog->setWindowTitle(QCoreApplication::translate("ChangeDialog", "Dialog", nullptr));
        label_9->setText(QCoreApplication::translate("ChangeDialog", "Numer domu", nullptr));
        label_6->setText(QCoreApplication::translate("ChangeDialog", "Miasto", nullptr));
        txtLastName->setInputMask(QCoreApplication::translate("ChangeDialog", ">A<aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa", nullptr));
        txtZipCode->setInputMask(QCoreApplication::translate("ChangeDialog", "99-999;_", nullptr));
        label_10->setText(QCoreApplication::translate("ChangeDialog", "Numer lokalu", nullptr));
        label_8->setText(QCoreApplication::translate("ChangeDialog", "Ulica:", nullptr));
        txtStreet->setInputMask(QCoreApplication::translate("ChangeDialog", ">A<aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa", nullptr));
        label_4->setText(QCoreApplication::translate("ChangeDialog", "Pa\305\204stwo:", nullptr));
        label->setText(QCoreApplication::translate("ChangeDialog", "Imi\304\231:", nullptr));
        txtName->setInputMask(QCoreApplication::translate("ChangeDialog", ">A<aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa", nullptr));
        label_7->setText(QCoreApplication::translate("ChangeDialog", "Kod pocztowy:", nullptr));
        label_2->setText(QCoreApplication::translate("ChangeDialog", "Nazwisko:", nullptr));
        label_3->setText(QCoreApplication::translate("ChangeDialog", "Data urodzenia:", nullptr));
        label_5->setText(QCoreApplication::translate("ChangeDialog", "Adres:", nullptr));
        txtCity->setInputMask(QCoreApplication::translate("ChangeDialog", ">A<aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa", nullptr));
    } // retranslateUi

};

namespace Ui {
    class ChangeDialog: public Ui_ChangeDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CHANGEDIALOG_H
