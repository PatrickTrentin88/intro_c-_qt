#include <string>
#include <iostream>

int main() {
    const int THISYEAR = 2017;
    std::string yourName;
    int birthYear;

    std::cout << "What is your name? " << std::flush;
    getline(std::cin, yourName);

    std::cout << "What year were you born? ";
    std::cin >> birthYear;

    std::cout << "Your name is " << yourName
              << " and you are approximately "
              << (THISYEAR - birthYear)
              << " years old." << std::endl;
}
