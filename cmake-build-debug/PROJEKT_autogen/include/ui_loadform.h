/********************************************************************************
** Form generated from reading UI file 'loadform.ui'
**
** Created by: Qt User Interface Compiler version 5.15.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_LOADFORM_H
#define UI_LOADFORM_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_LoadForm
{
public:

    void setupUi(QWidget *LoadForm)
    {
        if (LoadForm->objectName().isEmpty())
            LoadForm->setObjectName(QString::fromUtf8("LoadForm"));
        LoadForm->resize(400, 300);

        retranslateUi(LoadForm);

        QMetaObject::connectSlotsByName(LoadForm);
    } // setupUi

    void retranslateUi(QWidget *LoadForm)
    {
        LoadForm->setWindowTitle(QCoreApplication::translate("LoadForm", "Form", nullptr));
    } // retranslateUi

};

namespace Ui {
    class LoadForm: public Ui_LoadForm {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_LOADFORM_H
