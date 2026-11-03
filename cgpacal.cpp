#include <iostream>
int main() {
    std::cout << "Check Your CGPA!" << std::endl;
    double cgpa1, cgpa2, cgpa3, cgpa4;
    std::cout << "Enter your CGPA for lvl 100: ";
    std::cin >> cgpa1;
    std::cout << "Enter your CGPA for lvl 200: ";
    std::cin >> cgpa2;
    std::cout << "Enter your CGPA for lvl 300: ";
    std::cin >> cgpa3;
    std::cout << "Enter your CGPA for lvl 400: ";
    std::cin >> cgpa4;
std::cout << "Your CGPA is: " << (cgpa1 + cgpa2 + cgpa3 * 2 + cgpa4*2) / 6 << std::endl;
    return 0;
}
