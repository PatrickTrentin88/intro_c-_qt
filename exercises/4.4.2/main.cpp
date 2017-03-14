#include "contact.h"
#include "contactlist.h"
#include "contactfactory.h"

#include <QTextStream>

int main(int argc, char *argv[])
{
    QTextStream out(stdout);
    ContactFactory cf;
    ContactList cl;

    cf.createRandomContacts(cl, 10);
    for (int i = 0; i < cl.count(); ++i) {
        Contact c = cl.at(i);
        out << c << "\n";
    }
};
