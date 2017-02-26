#include<QApplication>
#include<QInputDialog>
#include<QMessageBox>
#include<QTextStream>
#include<limits>

/**
 * globals
 */

const double litXgal = 3.785411784;
const double kmXmile = 1.609344;

/**
 * help functions declaration
 */

double mpg2lpkm(double v);
double lpkm2mpg(double v);

/**
 * main
 */

int main(int argc, char* argv[])
{
    QApplication app(argc, argv);
    QTextStream out(stdout);
    bool ok;

    /**
     * for test purposes
     */

    for (int i = 0; i <= 100; i+=5) {
        double lpkm = mpg2lpkm(i);
        out << QString("%1 m/g = %2 l/100km\n")
                .arg((double)i, 6, 'f', 2)
                .arg(lpkm, 6, 'f', 2)
            << flush;
    }

    for (int i = 0; i <= 100; i+=5) {
        double mpg = lpkm2mpg(i);
        out << QString("%1 l/100km = %2 m/g\n")
                .arg((double)i, 6, 'f', 2)
                .arg(mpg, 6, 'f', 2)
            << flush;
    }

    /**
     * select conversion direction
     */
    QStringList items, titles, labels;
    items << "m/g --> l/100km"
          << "l/100km --> m/g";

    QString item = QInputDialog::getItem(0,
                    QObject::tr("Converter Selector"),
                    QObject::tr("Select the desired converter"),
                    items, 0, false, &ok);

    if (!ok || item.isEmpty()) {
        return 0;
    }

    double val;
    double res;
    QString text;
    if (item == items[0]) {
        val = QInputDialog::getDouble(0,
                QObject::tr("Mile per Gallons Converter"),
                QObject::tr("miles per gallon:"),
                0, std::numeric_limits<double>::min(),
                std::numeric_limits<double>::max(), 2, &ok,
                Qt::Dialog);
        res = mpg2lpkm(val);
        text = QString("%1 m/g = %2 l/100km")
                .arg(val, 0, 'f', 2)
                .arg(res, 0, 'f', 2);
        QMessageBox::information(0, "Liters per 100km:", text, QMessageBox::Ok);
    } else {
        val = QInputDialog::getDouble(0,
                QObject::tr("Liters per 100km Converter"),
                QObject::tr("liters per 100km:"),
                0, std::numeric_limits<double>::min(),
                std::numeric_limits<double>::max(), 2, &ok,
                Qt::Dialog);
        res = lpkm2mpg(val);
        text = QString("%1 l/100km = %2 m/g")
                .arg(val, 0, 'f', 2)
                .arg(res, 0, 'f', 2);
        QMessageBox::information(0, "Miles per gallon:", text, QMessageBox::Ok);
    }

    

}

/**
 * help functions definition
 */

double mpg2lpkm (double v) {
    return (v == 0.0 ? 0.0 : (litXgal * 100) / (v * kmXmile));
}

double lpkm2mpg (double v) {
    return (v == 0.0 ? 0.0 : (litXgal * 100) / (v * kmXmile));
}

