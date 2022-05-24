#ifndef CONNECTOR_H
#define CONNECTOR_H

#include <QObject>
#include "dbwriter.h"
class Connector : public QObject
{
    Q_OBJECT
public:
    explicit Connector(QObject *parent = nullptr);
    static void ConnectStudentsToDBWriter(QVector<Student*> students, DBWriter* db);
    static void ConnectLecturersToDBWriter(QVector<Lecturer*> lecturers, DBWriter* db);
signals:
    
};

#endif // CONNECTOR_H
