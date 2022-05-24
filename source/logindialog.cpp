#include "logindialog.h"
#include "ui_logindialog.h"

LoginDialog::LoginDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::LoginDialog)
{
    ui->setupUi(this);
    init();
}

LoginDialog::~LoginDialog()
{
    delete ui;
    delete db;
}

void LoginDialog::init() {
    db = new DBReader();
    db->setup();
    connect(ui->btnLogin, &QPushButton::clicked, this, &LoginDialog::loginClicked);
    connect(ui->btnExit, &QPushButton::clicked, this, &LoginDialog::reject);
    m_dialog = -1;
    if (!db->open()) {
        QMessageBox::critical(this, "Błąd", "Wystąpił błąd podczas łaczenia z serwerem");
        reject();
        return;
    }
}



bool LoginDialog::checkCredentials(const QString& login, const QString& password){
    person = static_cast<Person*>(db->findStudent(login, password));
    if (person != nullptr) {
        m_dialog = 0;
        accept();
        return true;
    }
    person = db->findEmployee(login, password);
    if (person != nullptr) {
        m_dialog = 1;
        accept();
        return true;
    }
    return false;
}

void LoginDialog::loginClicked() {
    check();
}



int LoginDialog::chooseDialog() {
    return m_dialog;
}

Person* LoginDialog::getUser() {
    return person;
}

DBReader* LoginDialog::getDB() {
    return db;
}

void LoginDialog::check() {
    QString login = ui->txtLogin->text();
    QString password = ui->txtPassword->text();
    if (login.isEmpty() || password.isEmpty()) {
        QMessageBox::critical(this, "Błąd", "Proszę wprowadzić dane");
        return;
    }
    if (!checkCredentials(login, password)) {
        QMessageBox::critical(this, "Błąd", "Niepoprawna nazwa użytkownika lub hasło");
        return;
    }
}