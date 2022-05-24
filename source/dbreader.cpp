#include "dbreader.h"
#include "address.h"

DBReader::DBReader(QObject *parent)
    : QObject{parent}
{
    
}

void DBReader::setup() {
    db = QSqlDatabase::addDatabase("QPSQL");
    db.setHostName("192.168.1.33");
    db.setPort(5432);
    db.setDatabaseName("jipp");
    db.setUserName("jipp");
    db.setPassword("123");
}

DBReader::~DBReader() {
    db.close();
    QSqlDatabase::removeDatabase(db.connectionName());
}

void DBReader::showThread() {
    qInfo() << "DBREADER: " << QThread::currentThread();
}

QString DBReader::getMaxStudentNumber() {
    QSqlQuery query;
    query.prepare("SELECT MAX(number) FROM student");
    bool ok = query.exec();
    if (!ok) {
        return QString();
    }
    if (!query.next()) {
        return QString();
    }
    return query.value(0).toString();
}


bool DBReader::open() {
    return db.open();
}

void DBReader::close() {
    db.close();
}


void DBReader::readStudents() {
    QSqlQuery query(db);
    QString queryContent = "SELECT s.id, s.first_name, s.last_name, s.login, s.date_of_birth, s.number, a.id, a.country, a.city, a.zip_code, a.street, a.house_number, a.apartment_number FROM student AS s INNER JOIN address AS a ON a.id=s.address_id";
    query.prepare(queryContent);
    bool ok = query.exec();
    if (!ok) {
        return;
    }
    while (query.next()) {
        int id = query.value(0).toInt();
        QString firstName = query.value(1).toString();
        QString lastName = query.value(2).toString();
        QString login = query.value(3).toString();
        QDate dateOfBirth = Tools::formatDate(query.value(4).toString());
        QString number = query.value(5).toString();
        int addressId = query.value(6).toInt();
        QString country = query.value(7).toString();
        QString city = query.value(8).toString();
        QString zipCode = query.value(9).toString();
        QString street = query.value(10).toString();
        QString houseNumber = query.value(11).toString();
        Address* address;
        if (!query.value(12).isNull()) {
            QString apartmentNumber = query.value(12).toString();
            address = new Address(addressId, country, city, zipCode, street, houseNumber, apartmentNumber);
        }
        else {
            address = new Address(addressId, country, city, zipCode, street, houseNumber);
        }
        m_students.append(new Student(id, firstName, lastName, dateOfBirth, *address, number));
        delete address;

    }
}

void DBReader::readLecturers() {
    QSqlQuery query(db);
    QString queryContent = "SELECT l.id, l.first_name, l.last_name, l.date_of_birth, a.id, a.country, a.city, a.zip_code, a.street, a.house_number, a.apartment_number FROM lecturer AS l INNER JOIN address AS a ON a.id=l.address_id";
    query.prepare(queryContent);
    bool ok = query.exec();
    if (!ok) {
        return;
    }

    while (query.next()) {
        int id = query.value(0).toInt();
        QString firstName = query.value(1).toString();
        QString lastName = query.value(2).toString();
        QDate dateOfBirth = Tools::formatDate(query.value(3).toString());
        int addressId = query.value(4).toInt();
        QString country = query.value(5).toString();
        QString city = query.value(6).toString();
        QString zipCode = query.value(7).toString();
        QString street = query.value(8).toString();
        QString houseNumber = query.value(9).toString();
        Address* address;
        if (!query.value(10).isNull()) {
            QString apartmentNumber = query.value(10).toString();
            address = new Address(addressId, country, city, zipCode, street, houseNumber, apartmentNumber);
        }
        else {
            address = new Address(addressId, country, city, zipCode, street, houseNumber);
        }
        m_lecturers.append(new Lecturer(id, firstName, lastName, dateOfBirth, *address));
        delete address;
    }
}


void DBReader::readSubjects() {
    QSqlQuery query(db);
    QString queryContent = "SELECT * FROM subject";
    query.prepare(queryContent);
    bool ok = query.exec();
    if (!ok) {
        return;
    }

    while (query.next()) {
        int id = query.value(0).toInt();
        QString name = query.value(1).toString();
        m_subjects.append(new Subject(id, name));
    }
}

void DBReader::addLecturersToSubjects() {
    QSqlQuery query(db);
    QString queryContent = "SELECT subject_id, lecturer_id FROM subjects_lecturers";
    query.prepare(queryContent);
    bool ok = query.exec();
    if (!ok) {
        return;
    }

    while (query.next()) {
        Lecturer* lecturer = nullptr;
        Subject* subject = nullptr;
        int subjectId = query.value(0).toInt();
        int lecturerId = query.value(1).toInt();
        foreach (Lecturer* temp, m_lecturers) {
            if (temp->id() == lecturerId) {
                lecturer = temp;
            }
        }
        foreach (Subject* temp, m_subjects) {
            if (temp->id() == subjectId) {
                subject = temp;
            }
        }
        if (lecturer != nullptr && subject != nullptr) {
           subject->addLecturer(lecturer);
        }
    }
}

void DBReader::readCourses() {
    QSqlQuery query(db);
    QString queryContent = "SELECT * FROM course";
    query.prepare(queryContent);
    bool ok = query.exec();
    if (!ok) {
        return;
    }

    while (query.next()) {
        int id = query.value(0).toInt();
        Subject* subject = nullptr;
        int subjectId = query.value(1).toInt();
        foreach (Subject* temp, m_subjects) {
            if (temp->id() == subjectId) {
                subject = temp;
            }
        }
        QString description;
        if (query.value(2).isNull()) {
            description = "";
        }
        else {
            description = query.value(2).toString();
        }
        m_courses.append(new Course(id, subject, description));
    }
}


void DBReader::addStudentsToCourses() {
    foreach (Course* course, m_courses) {
        QSqlQuery query(db);
        QString queryContent = "SELECT student_id FROM students_courses WHERE course_id=:id";
        query.prepare(queryContent);
        query.bindValue(":id", course->id());
        bool ok = query.exec();
        if (!ok) {
            continue;
        }
        while (query.next()) {
            int studentId = query.value(0).toInt();
            foreach (Student* student, m_students) {
                if (student->id() == studentId) {
                    course->addStudent(student);
                }
            }
        }
    }
}

void DBReader::addLecturersToCourses() {
    foreach (Course* course, m_courses) {
        QSqlQuery query(db);
        QString queryContent = "SELECT lecturer_id FROM course WHERE id=:id";
        query.prepare(queryContent);
        query.bindValue(":id", course->id());
        bool ok = query.exec();
        if (!ok) {
            continue;
        }
        if (query.next()) {
            int lecturerId = query.value(0).toInt();
            foreach (Lecturer* lecturer, m_lecturers) {
                if (lecturer->id() == lecturerId) {
                    course->addLecturer(lecturer);
                }
            }
        }
    }
}

Student* DBReader::findStudent(const QString &login, const QString &password) {
    QSqlQuery query(db);
    QString queryContent = "SELECT s.id, s.first_name, s.last_name, s.date_of_birth, s.number, a.id, a.country, a.city, a.zip_code, a.street, a.house_number, a.apartment_number FROM student AS s INNER JOIN address AS a ON a.id=s.address_id WHERE s.login=:login AND s.password=md5(:password)";
    query.prepare(queryContent);
    query.bindValue(":login", login);
    query.bindValue(":password", password);
    bool ok = query.exec();
    if (!ok) {
        return nullptr;
    }
    if (query.numRowsAffected() == 0) {
        return nullptr;
    }
    if (query.next()) {
        int id = query.value(0).toInt();
        QString firstName = query.value(1).toString();
        QString lastName = query.value(2).toString();
        QDate dateOfBirth = Tools::formatDate(query.value(3).toString());
        QString number = query.value(4).toString();
        int addressId = query.value(5).toInt();
        QString country = query.value(6).toString();
        QString city = query.value(7).toString();
        QString zipCode = query.value(8).toString();
        QString street = query.value(9).toString();
        QString houseNumber = query.value(10).toString();
        Address* address;
        if (!query.value(11).isNull()) {
            QString apartmentNumber = query.value(11).toString();
            address = new Address(addressId, country, city, zipCode, street, houseNumber, apartmentNumber);
        }
        else {
            address = new Address(addressId, country, city, zipCode, street, houseNumber);
        }
        Student* result = new Student(id, firstName, lastName, dateOfBirth, *address, number);
        getGradesForStudent(result);
        delete address;
        return result;
    }
    return nullptr;
}

Lecturer* DBReader::findLecturer(const QString &login, const QString &password) {
    QSqlQuery query(db);
    QString queryContent = "SELECT l.id, l.first_name, l.last_name, l.date_of_birth, a.id, a.country, a.city, a.zip_code, a.street, a.house_number, a.apartment_number FROM lecturer AS l INNER JOIN address AS a ON a.id=l.address_id WHERE l.login=:login AND l.password=md5(:password)";
    query.prepare(queryContent);
    query.bindValue(":login", login);
    query.bindValue(":password", password);
    bool ok = query.exec();
    if (!ok) {
        return nullptr;
    }
    if (query.numRowsAffected() == 0) {
        return nullptr;
    }
    if (query.next()) {
        int id = query.value(0).toInt();
        QString firstName = query.value(1).toString();
        QString lastName = query.value(2).toString();
        QDate dateOfBirth = Tools::formatDate(query.value(3).toString());
        int addressId = query.value(4).toInt();
        QString country = query.value(5).toString();
        QString city = query.value(6).toString();
        QString zipCode = query.value(7).toString();
        QString street = query.value(8).toString();
        QString houseNumber = query.value(9).toString();
        Address* address;
        if (!query.value(10).isNull()) {
            QString apartmentNumber = query.value(10).toString();
            address = new Address(addressId, country, city, zipCode, street, houseNumber, apartmentNumber);
        }
        else {
            address = new Address(addressId, country, city, zipCode, street, houseNumber);
        }
        Lecturer* result = new Lecturer(id, firstName, lastName, dateOfBirth, *address);
        delete address;
        return result;
    }
    return nullptr;
}

Employee* DBReader::findEmployee(const QString &login, const QString &password) {
    QSqlQuery query(db);
    QString queryContent = "SELECT e.id, e.first_name, e.last_name, e.date_of_birth, a.id, a.country, a.city, a.zip_code, a.street, a.house_number, a.apartment_number FROM employee AS e INNER JOIN address AS a ON e.address_id=a.id WHERE login=:login AND password=md5(:password)";
    query.prepare(queryContent);
    query.bindValue(":login", login);
    query.bindValue(":password", password);
    bool ok = query.exec();
    if (!ok) {
        return nullptr;
    }
    if (query.numRowsAffected() == 0) {
        return nullptr;
    }
    if (query.next()) {
        int id = query.value(0).toInt();
        QString firstName = query.value(1).toString();
        QString lastName = query.value(2).toString();
        QDate dateOfBirth = Tools::formatDate(query.value(3).toString());
        int addressId = query.value(4).toInt();
        QString country = query.value(5).toString();
        QString city = query.value(6).toString();
        QString zipCode = query.value(7).toString();
        QString street = query.value(8).toString();
        QString houseNumber = query.value(9).toString();
        Address* address;
        if (!query.value(10).isNull()) {
            QString apartmentNumber = query.value(10).toString();
            address = new Address(addressId, country, city, zipCode, street, houseNumber, apartmentNumber);
        }
        else {
            address = new Address(addressId, country, city, zipCode, street, houseNumber);
        }
        Employee* result = new Employee(id, firstName, lastName, dateOfBirth, *address);
        delete address;
        return result;
    }
    return nullptr;
}

void DBReader::getGradesForStudent(Student* student) {
    QSqlQuery query(db);
    QString queryContent = "SELECT g.id, g.value, s.name FROM grade AS g INNER JOIN subject AS s ON s.id=g.subject_id WHERE g.student_id=:id";
    query.prepare(queryContent);
    query.bindValue(":id", student->id());
    bool ok = query.exec();
    if (!ok) {
        return;
    }
    while (query.next()) {
        int id = query.value(0).toInt();
        float value = query.value(1).toFloat();
        QString subjectName = query.value(2).toString();
        student->addGrade(new Grade(id, subjectName, value));
    }
}

QVector<Course*> DBReader::getCoursesForStudent(Student *student) {
    QVector<Course*> result;
    foreach (Course* course, m_courses) {
        if (course->containsStudent(student)) {
            result.append(course);
        }
    }
    return result;

}
void testCourses(QVector<Course*> courses) {
    foreach (Course* course, courses) {
        qInfo() << course->subjectName();
        foreach (Student* student, course->students()) {
            qInfo() << student->firstName() + " " + student->lastName();
        }
    }
}
void DBReader::readAll() {
    readStudents();
    readLecturers();
    readSubjects();
    readCourses();
    addLecturersToSubjects();
    addStudentsToCourses();
    addLecturersToCourses();
    testCourses(m_courses);
    emit ready();
}

QTableWidget* DBReader::getStudentsTable() {
    return TableWidgetGenerator::generateStudentsTable(m_students);
}

QTableWidget* DBReader::getLecturersTable() {
    return TableWidgetGenerator::generateLecturersTable(m_lecturers, m_subjects);
    
}

QTableWidget* DBReader::getCoursesTable() {
    return TableWidgetGenerator::generateCoursesTable(m_courses);
}

ChangeDialog* DBReader::getStudentChangeDialog(int index) {
    if (index >= 0 && index < m_students.size()) {
        return new ChangeDialog(m_students[index]);
    }
    return nullptr;
}

ChangeDialog* DBReader::getLecturerChangeDialog(int index) {
    if (index >= 0 && index < m_lecturers.size()) {
        return new ChangeDialog(m_lecturers[index]);
    }
    return nullptr;
}


void DBReader::deleteStudent(int index) {
    if (index >= 0 && index < m_students.size()) {
        delete m_students[index];
        m_students.removeAt(index);
    }
}

void DBReader::deleteLecturer(int index) {
    if (index >= 0 && index < m_lecturers.size()) {
        Lecturer* temp = m_lecturers[index];
        m_lecturers.remove(index);
        delete temp;
    }
}

QVector<Student*> DBReader::students() {
    return m_students;
}

QVector<Lecturer*> DBReader::lecturers() {
    return m_lecturers;
}

QVector<Subject*> DBReader::subjects() {
    return m_subjects;
}

QVector<Course*> DBReader::courses() {
    return m_courses;
}

