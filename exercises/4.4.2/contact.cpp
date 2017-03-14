#include "contact.h"

Contact::Contact(QString firstName, QString lastName, QString streetAddress,
            QString zipCode, QString city, QString phoneNumber):
    firstName(firstName),
    lastName(lastName),
    streetAddress(streetAddress),
    zipCode(zipCode),
    city(city),
    phoneNumber(phoneNumber)
{
    /* nothing to do */
};

QString Contact::toString() const
{
    QString s;
    QTextStream qss(&s);
    qss << firstName     << ", "
        << lastName      << ", "
        << streetAddress << ", "
        << zipCode       << ", "
        << city          << ", "
        << phoneNumber;
    return s;
};

bool operator == (const Contact &c1, const Contact &c2)
{
    return c1.category      == c2.category
        && c1.firstName     == c2.firstName
        && c1.lastName      == c2.lastName
        && c1.streetAddress == c2.streetAddress
        && c1.zipCode       == c2.zipCode
        && c1.city          == c2.city
        && c1.phoneNumber   == c2.phoneNumber;
};

QTextStream& operator << (QTextStream& ts, const Contact &c)
{
    ts << c.toString();
    return ts;
};
