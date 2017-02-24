#include<QTextStream>
#include<cstdlib>

int main(int argc, char* argv[])
{
    unsigned int seed;
    QTextStream out(stdout);
    QTextStream in(stdin);

    out << "Enter seed: " << flush;
    in >> seed;
    out << endl;

    srand(seed);

    for (int i = 0; i < 25; ++i) {
        out << QStringLiteral("%1: %2")
               .arg(i, 3)
               .arg(rand(), 15)
            << endl;
    }
}
