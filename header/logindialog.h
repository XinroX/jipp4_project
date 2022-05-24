#ifndef LOGINDIALOG_H
#define LOGINDIALOG_H

#include <QDialog>
#include <QDebug>
#include <QMessageBox>
#include <QVector>
#include <QFile>
#include <QTextStream>
#include <QVBoxLayout>
#include <QSizePolicy>
#include <QThread>
#include "person.h"
#include "dbreader.h"

namespace Ui {
class LoginDialog;
}

class LoginDialog : public QDialog
{
    Q_OBJECT

public:
    explicit LoginDialog(QWidget *parent = nullptr);
    ~LoginDialog();
    int chooseDialog();
    Person* getUser();
    DBReader* getDB();

private slots:
    void loginClicked();

private:
    Person* person;
    DBReader* db;
    Ui::LoginDialog *ui;
    int m_dialog;
    int m_id;
    
    
    void check();
    
    
    QLayout* m_layout;
    
private slots:


    bool checkCredentials(const QString& login, const QString& password);
    void init();
};

#endif // LOGINDIALOG_H
