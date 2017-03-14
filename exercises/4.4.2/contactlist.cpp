#include "contactlist.h"

#include <QTextStream>

void ContactList::add(Contact c)
{
    if (!m_Contacts.contains(c)) {
        m_Contacts.append(c);
    }
};


void ContactList::remove(Contact c)
{
    m_Contacts.removeOne(c);
};

QStringList ContactList::getPhoneList(int category)
{
    QStringList sl;
    for (size_t i = 0; i < (size_t) m_Contacts.count(); ++i)
    {
        QString s;
        QTextStream ts(&s);
        if (m_Contacts[i].getCategory() == category) {
            ts << m_Contacts[i].getFirstName() << "\t"
               << m_Contacts[i].getPhoneNumber();
            sl << s;
        }
    }
    return sl;
};

QStringList ContactList::getMailingList(int category)
{
    QStringList sl;
    for (size_t i = 0; i < (size_t) m_Contacts.count(); ++i)
    {
        QString s;
        QTextStream ts(&s);
        if (m_Contacts[i].getCategory() == category) {
            ts << m_Contacts[i].getFirstName() << " "
               << m_Contacts[i].getLastName() << "\t"
               << m_Contacts[i].getStreetAddress() << ", "
               << m_Contacts[i].getCity() << " - "
               << m_Contacts[i].getZipCode();
            sl << s;
        }
    }
    return sl;
};
