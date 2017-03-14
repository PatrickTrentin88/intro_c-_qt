#ifndef __CONTACT_H__
#define __CONTACT_H__

#include <QTextStream>
#include <QString>

class Contact
{
public:
    Contact(QString firstName, QString lastName, QString streetAddress,
            QString zipCode, QString city, QString phoneNumber);

    QString toString() const;

    int getCategory() { return category; };
    QString getFirstName() { return firstName; };
    QString getLastName() { return lastName; };
    QString getStreetAddress() { return streetAddress; };
    QString getZipCode() { return zipCode; };
    QString getCity() { return city; };
    QString getPhoneNumber() { return phoneNumber; };

    friend bool operator == (const Contact &c1, const Contact &c2);

    friend QTextStream& operator << (QTextStream &ts, const Contact &c);

private:
    int category;
    QString firstName;
    QString lastName;
    QString streetAddress;
    QString zipCode;
    QString city;
    QString phoneNumber;
};

#endif
