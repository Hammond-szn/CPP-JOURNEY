#include <iostream>
int main() {
    std::cout << "YO BUDGET WELL OH!" << std::endl;

    int budget;
    std::cout << "Enter your budget: ";
    std::cin >> budget;
    double rent, utilities, groceries, transportation, entertainment;
    std::cout << "Enter your rent expense: ";
    std::cin >> rent;
    std::cout << "Enter your utilities expense: ";
    std::cin >> utilities;
    std::cout << "Enter your groceries expense: ";
    std::cin >> groceries;
    std::cout << "Enter your transportation expense: ";
    std::cin >> transportation;
    std::cout << "Enter your entertainment expense: ";
    std::cin >> entertainment;
    std::cout << "Your total expenses are: " << (rent + utilities + groceries + transportation + entertainment) << std::endl;
    std::cout << "Your remaining balance is: " << (budget - (rent + utilities + groceries + transportation + entertainment)) << std::endl;
    return 0;


}
