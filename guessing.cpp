#include <iostream>
int main() {
    std::cout << "WElcome GUESSER!" << std::endl;
    int number;
    std::cout << "Enter a number between 1 and 10: ";
    std::cin >> number;
    std::cout << "You entered: " << number ;
    std::cout << "ADD 5: " << number + 5 ;
    std::cout << "DEDUCT 3: " << (number + 5) - 3 ;
    std::cout << "MULTIPLY by 2: " << ((number + 5) - 3) * 2 ;
    std::cout << "DIVIDE by 4: " << (((number + 5) - 3) * 2) / 4 ; 

    int add = number + 5;
    int deduct = add - 3;
    int multiply = deduct * 2;
    int divide = multiply / 4;
    std::cout << "The final result is: " << divide << std::endl;
    return 0;
}