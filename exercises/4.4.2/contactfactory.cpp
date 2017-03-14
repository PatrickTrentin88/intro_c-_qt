#include "contactfactory.h"
#include <stdlib.h>

ContactFactory::ContactFactory()
{
    m_firstNames << "Irena" << "Martina" << "Giulia" << "Derna";
    m_lastNames << "Klaser" << "Dal Ceggio" << "Simeoni" << "Miccoli";
    m_streetAddresses << "Piazza Telve, 21"
                      << "Via Boh, 17"
                      << "Via al McDonald's, 7"
                      << "Via della chiesa, 0";
    m_cities << "Telve"
             << "Borgo Valsugana"
             << "Verona"
             << "Trieste";
    m_phoneNumbers << "+39 333 55 77 313"
                   << "+39 388 66 88 424"
                   << "+39 330 15 42 213"
                   << "+39 666 66 66 666";
    m_zipCodes << "38051"
               << "38123"
               << "43212"
               << "51223";
    srand(777);
};

void ContactFactory::createRandomContacts(ContactList &cl, int n)
{
    for (int i = 0; i < n; ++i)
    {
        *this >> cl;
    }
};

QString ContactFactory::getRandomFirstName() const
{
    return m_firstNames.at(rand() % m_firstNames.count());
};

QString ContactFactory::getRandomLastName() const
{
    return m_lastNames.at(rand() % m_lastNames.count());
};

QString ContactFactory::getRandomStreetAddress() const
{
    return m_streetAddresses.at(rand() % m_streetAddresses.count());
};

QString ContactFactory::getRandomCity() const
{
    return m_cities.at(rand() % m_cities.count());
};

QString ContactFactory::getRandomZipCode() const
{
    return m_zipCodes.at(rand() % m_zipCodes.count());
};

QString ContactFactory::getRandomPhoneNumber() const
{
    return m_phoneNumbers.at(rand() % m_phoneNumbers.count());
};

ContactFactory& operator >>(ContactFactory &cf, ContactList &cl)
{
    Contact c(cf.getRandomFirstName(),
              cf.getRandomLastName(),
              cf.getRandomStreetAddress(),
              cf.getRandomZipCode(),
              cf.getRandomCity(),
              cf.getRandomPhoneNumber());
    cl.add(c);
    return cf;
};
