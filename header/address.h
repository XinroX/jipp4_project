#ifndef ADDRESS_H
#define ADDRESS_H

#include <QObject>
#include <QString>
#include <QVariant>
#include <QDebug>
#include <QSqlQuery>

class Address : public QObject
{
    Q_OBJECT
public:
    explicit Address(const int& id, const QString& country, const QString& city, const QString& zip_code, const QString& street, const QString& house_number, const QString& apartment_number, QObject *parent = nullptr);
    explicit Address(const int& id, const QString& country, const QString& city, const QString& zip_code, const QString& street, const QString& house_number, QObject *parent = nullptr);
    explicit Address(const Address& address, QObject* parent = nullptr);
    explicit Address(const QString& country, const QString& city, const QString& zip_code, const QString& street, const QString& house_number, QObject* parent = nullptr);
    explicit Address(const QString& country, const QString& city, const QString& zip_code, const QString& street, const QString& house_number, const QString& apartment_number, QObject* parent = nullptr);
public:
    int id() const;
    QString country() const;
    QString city() const;
    QString zipCode() const;
    QString street() const;
    QString houseNumber() const;
    QString apartmentNumber() const;

    void setCountry(const QString& country);
    void setCity(const QString& city);
    void setZipCode(const QString& zip_code);
    void setStreet(const QString& street);
    void setHouseNumber(const QString& house_number);
    void setApartmentNumber(const QString& apartment_number);
signals:
    void update(QSqlQuery query);

private:
    int m_id;
    QString m_country;
    QString m_city;
    QString m_zip_code;
    QString m_street;
    QString m_house_number;
    QString m_apartment_number;
    void updateAddress();

public:
    QString showAddress();
};

#endif // ADDRESS_H
