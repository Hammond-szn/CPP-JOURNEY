#include <iostream>
int main() {
    std::cout << "Check Your grade!" << std::endl;
    double grade;
    std::cout << "Enter your grade: ";
    std::cin >> grade;

    if (grade >= 90) {
        std::cout << "Your grade is A." << std::endl;
    } else if (grade >= 80) {
        std::cout << "Your grade is B." << std::endl;
    } else if (grade >= 70) {
        std::cout << "Your grade is C." << std::endl;
    }
    else if (grade >= 60) {
        std::cout << "Your grade is D." << std::endl;
    }
    else if (grade >= 50) {
        std::cout << "Your grade is F ." << std::endl;
        
    }

    return 0;
}