#include "dbwriter.h"
#include "address.h"

DBWriter::DBWriter(QMutex* mutex, QObject *parent)
    : QObject{parent}
{
    m_mutex = mutex;
}

void DBWriter::setup() {
    db = QSqlDatabase::addDatabase("QPSQL");
    db.setHostName("192.168.1.33");
    db.setPort(5432);
    db.setDatabaseName("jipp");
    db.setUserName("jipp");
    db.setPassword("123");
}

void DBWriter::updatePerson(const QSqlQuery& query) {
    queries.append(query);
}

bool DBWriter::open() {
    return db.open();
}

void DBWriter::close() {
    db.close();
}

DBWriter::~DBWriter() {
    db.close();
    QSqlDatabase::removeDatabase(db.connectionName());
}

void DBWriter::start() {
    timer = new QTimer(this);
    connect(timer, &QTimer::timeout, this, &DBWriter::executeQuery);
    timer->setInterval(100);
    timer->start();
}

void DBWriter::executeQuery() {
    //qInfo() << "Działa?";
    if (!queries.isEmpty()) {
        qInfo() << queries.length();
        QSqlQuery query = queries[0];
        qInfo() << query.exec();
        queries.removeAt(0);
        qInfo() << query.numRowsAffected() << " XD";
        qInfo() << query.lastError().text();
    }
}

void DBWriter::addQuery(QSqlQuery query) {
    queries.append(query);
    qInfo() << "Dodano query";
}

bool DBWriter::insertStudent(Student *student) {
    QMutexLocker locker(m_mutex);
    QSqlQuery query;
    Address* address = student->address();
    if (address->apartmentNumber().isNull() || address->apartmentNumber().isEmpty()) {
        query.prepare("INSERT INTO address(country,city,zip_code,street,house_number) VALUES(:country,:city,:zip_code,:street,:house_number) RETURNING id");
        query.bindValue(":country", address->country());
        query.bindValue(":city", address->city());
        query.bindValue(":zip_code", address->zipCode());
        query.bindValue(":street", address->street());
        query.bindValue(":house_number", address->houseNumber());
    }
    else {
        query.prepare("INSERT INTO address(country,city,zip_code,street,house_number,apartment_number) VALUES(:country,:city,:zip_code,:street,:house_number,:apartment_number) RETURNING id");
        query.bindValue(":country", address->country());
        query.bindValue(":city", address->city());
        query.bindValue(":zip_code", address->zipCode());
        query.bindValue(":street", address->street());
        query.bindValue(":house_number", address->houseNumber());
        query.bindValue(":apartment_number", address->apartmentNumber());
    }
    bool ok = query.exec();
    if (!ok) {
        QMessageBox::critical(nullptr, "Błąd adres", "Wystąpił błąd podczas aktualizacji danych. Spróbuj ponownie później.");
        return false;
    }
    query.next();
    int address_id = query.value(0).toInt();
    query.clear();
    query.prepare("INSERT INTO student(first_name,last_name,login,password,date_of_birth,address_id,number) VALUES(:first_name,:last_name,:login,md5(:password),:date_of_birth,:address_id,:number)");
    query.bindValue(":first_name", student->firstName());
    query.bindValue(":last_name", student->lastName());
    query.bindValue(":login", student->login());
    query.bindValue(":password", student->password());
    query.bindValue(":date_of_birth", Tools::dateToString(student->dateOfBirth()));
    query.bindValue(":address_id", address_id);
    query.bindValue(":number", student->number());

    ok = query.exec();
    if (!ok) {
        QMessageBox::critical(nullptr, "Błąd student", "Wystąpił błąd podczas aktualizacji danych. Spróbuj ponownie później.");
        return false;
    }
    return true;
}

bool DBWriter::insertLecturer(Lecturer *lecturer) {
    QMutexLocker locker(m_mutex);
    QSqlQuery query;
    Address* address = lecturer->address();
    if (address->apartmentNumber().isNull() || address->apartmentNumber().isEmpty()) {
        query.prepare("INSERT INTO address(country,city,zip_code,street,house_number) VALUES(:country,:city,:zip_code,:street,:house_number) RETURNING id");
        query.bindValue(":country", address->country());
        query.bindValue(":city", address->city());
        query.bindValue(":zip_code", address->zipCode());
        query.bindValue(":street", address->street());
        query.bindValue(":house_number", address->houseNumber());
    }
    else {
        query.prepare("INSERT INTO address(country,city,zip_code,street,house_number,apartment_number) VALUES(:country,:city,:zip_code,:street,:house_number,:apartment_number) RETURNING id");
        query.bindValue(":country", address->country());
        query.bindValue(":city", address->city());
        query.bindValue(":zip_code", address->zipCode());
        query.bindValue(":street", address->street());
        query.bindValue(":house_number", address->houseNumber());
        query.bindValue(":apartment_number", address->apartmentNumber());
    }
    bool ok = query.exec();
    if (!ok) {
        QMessageBox::critical(nullptr, "Błąd", "Wystąpił błąd podczas aktualizacji danych. Spróbuj ponownie później.");
        return false;
    }
    query.next();
    int address_id = query.value(0).toInt();
    query.clear();
    query.prepare("INSERT INTO lecturer(first_name,last_name,login,password,date_of_birth,address_id) VALUES(:first_name,:last_name,:login,md5(:password),:date_of_birth,:address_id)");
    query.bindValue(":first_name", lecturer->firstName());
    query.bindValue(":last_name", lecturer->lastName());
    query.bindValue(":login", lecturer->login());
    query.bindValue(":password", lecturer->password());
    query.bindValue(":date_of_birth", Tools::dateToString(lecturer->dateOfBirth()));
    query.bindValue(":address_id", address_id);
    ok = query.exec();
    if (!ok) {
        QMessageBox::critical(nullptr, "Błąd", "Wystąpił błąd podczas aktualizacji danych. Spróbuj ponownie później.");
        return false;
    }
    return true;
}

bool DBWriter::deleteLecturer(Lecturer *lecturer) {
    QSqlQuery query;
    query.prepare("DELETE FROM subjects_lecturers WHERE lecturer_id=:id");
    query.bindValue(":id", lecturer->id());
    bool ok = query.exec();
    if (!ok) {
        QMessageBox::critical(nullptr, "Błąd", "Nie udało się");
        return false;
    }
    query.clear();
    query.prepare("DELETE FROM lecturers_courses WHERE lecturer_id=:id");
    query.bindValue(":id", lecturer->id());
    ok = query.exec();
    if (!ok) {
        QMessageBox::critical(nullptr, "Błąd", "Nie udało się");
        return false;
    }
    query.clear();
    query.prepare("DELETE FROM lecturer WHERE id=:id");
    query.bindValue(":id", lecturer->id());
    ok = query.exec();
    if (!ok) {
        QMessageBox::critical(nullptr, "Błąd", "Nie udało się");
        return false;
    }
    return true;
}

bool DBWriter::deleteStudent(Student *student) {
    QSqlQuery query;
    query.prepare("DELETE FROM grade WHERE student_id=:id");
    query.bindValue(":id", student->id());
    bool ok = query.exec();
    if (!ok) {
        QMessageBox::critical(nullptr, "Błąd", "Nie udało się");
        return false;
    }
    query.clear();
    query.prepare("DELETE FROM students_courses WHERE student_id=:id");
    query.bindValue(":id", student->id());
    ok = query.exec();
    if (!ok) {
        QMessageBox::critical(nullptr, "Błąd", "Nie udało się");
        return false;
    }
    query.clear();
    query.prepare("DELETE FROM student WHERE id=:id");
    query.bindValue(":id", student->id());
    ok = query.exec();
    if (!ok) {
        QMessageBox::critical(nullptr, "Błąd", "Nie udało się");
        return false;
    }
    return true;
}