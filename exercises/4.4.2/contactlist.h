#ifndef __CONTACT_LIST_H__
#define __CONTACT_LIST_H__

#include <QList>
#include <assert.h>
#include "contact.h"

class ContactList
{
public:
    void add(Contact c);
    void remove(Contact c);
    QStringList getPhoneList(int category);
    ///< return name\tphoneNumber for each contact matching
    QStringList getMailingList(int category);
    ///< similar, with address data

    inline int count() const { return m_Contacts.count(); };
    inline Contact at(int i) const { assert(i >= 0 && i < count());
                                     return m_Contacts.at(i); };

private:
    QList<Contact> m_Contacts;
};

#endif
