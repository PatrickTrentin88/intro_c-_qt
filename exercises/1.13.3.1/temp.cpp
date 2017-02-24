#include<QApplication>
#include<QInputDialog>
#include<QMessageBox>
#include<QTextStream>

#include<limits>

double toCelsius(double fahrenheitTemp);
double toFahrenheit(double celsiusTemp);

int main(int argc, char* argv[])
{
    bool ok;
    double vc, vf;
    QString text;

    QApplication app(argc, argv);

    vc = QInputDialog::getDouble(0, "Celsius to Fahrenheit Converter",
                                 "Celsius Temperature:",
                                 0, -273.15, std::numeric_limits<double>::max(),
                                 2, &ok, Qt::Dialog);

    if (ok) {

        vf = toFahrenheit(vc);
        text = QString("%1 °c equals %2 °f").arg(vc).arg(vf);

        QMessageBox::information(0, "Result:", text, QMessageBox::Ok);

    } else {
        /* nothing to do */
    }

    QTextStream out(stdout);
    for (int i = 0; i <= 100; i+=5) {
        vf = toFahrenheit(i);
        out << QStringLiteral("%1").arg((double)i, 6, 'f', 2)
            << QObject::tr(" °c --> ")
            << QStringLiteral("%1").arg(vf, 6, 'f', 2)
            << QObject::tr(" °f")
            << endl;
    }

}

// WARNONG: overflow!
double toCelsius(double fahrenheitTemp)
{
    return (fahrenheitTemp - 32) * 5.0 / 9.0;
};

// WARNONG: overflow!
double toFahrenheit(double celsiusTemp)
{
    return celsiusTemp * 9.0 / 5.0 + 32;
};
