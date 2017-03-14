#ifndef __CONTACT_FACTORY_H__
#define __CONTACT_FACTORY_H__

#include "contactlist.h"

class ContactFactory {
public:
    ContactFactory();

    void createRandomContacts(ContactList& cl, int n=10);

    friend ContactFactory& operator >>(ContactFactory &cf, ContactList &cl);
private:
    QString getRandomFirstName() const;
    QString getRandomLastName() const;
    QString getRandomStreetAddress() const;
    QString getRandomZipCode() const;
    QString getRandomCity() const;
    QString getRandomPhoneNumber() const;

    QStringList m_firstNames;
    QStringList m_lastNames;
    QStringList m_streetAddresses;
    QStringList m_cities;
    QStringList m_zipCodes;
    QStringList m_phoneNumbers;
};

#endif
