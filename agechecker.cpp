#include <iostream>
#include <string>

int main() {
    std::cout << "WELCOME! to MadClub" << std::endl;
    int age;
    std::cout << "Enter your age: ";
    std::cin >> age;

    while (age < 0) {
        std::cout << "Invalid age. Please enter a valid age: ";
        std::cin >> age;
    }

    if (age >= 18) {
        std::string name;
        char sex;

        std::cout << "Enter your name: ";
        std::cin >> name;
        std::cout << "Enter your sex (M/F): ";
        std::cin >> sex;

        std::cout << "You are eligible to join MadClub!" << std::endl;
        std::cout << "Name: " << name << std::endl;
        std::cout << "Sex: " << sex << std::endl;
    } else {
        std::cout << "You are not eligible to join MadClub!" << std::endl;
    }

    return 0;
}