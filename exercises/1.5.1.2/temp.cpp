#include <iostream>

double toCelsius(double fahrenheitTemp);

double toFahrenheit(double celsiusTemp);

int main()
{
    double v;
    std::string fmt;
    std::cout << "Input Temperature: " << std::flush;
    std::cin >> v;
    std::cout << "Celsius or Fahrenheit? [C/F] " << std::flush;
    std::cin >> fmt;
    std::cout << std::endl;
    if (fmt == "C") {
        std::cout << v << " °C = " << toFahrenheit(v) << " °F" << std::endl;
    } else {
        std::cout << v << " °F = " << toCelsius(v) << " °C" << std::endl;
    }
}

double toCelsius(double fahrenheitTemp)
{
    return (fahrenheitTemp - 32) * 5.0 / 9.0;
};

double toFahrenheit(double celsiusTemp)
{
    return celsiusTemp * 9.0 / 5.0 + 32;
};
