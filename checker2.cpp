#include <iostream>
int main() {
    std::cout << "Welcome to MadClub!" << std::endl;

    int age;
    std:: cout << "Enter Your Age"<< std::endl;
    std:: cin>>age ;
    if (age<18) {
        std::cout<< "You are not eligible to join MadClub!";}

    if (age>=18) {
        
    std::string name;
    char sex;

    std::cout<< "Enter your Name :";
    std::cin >> name;
    std::cout<< "Gender(M/F):";
    std::cin>> sex;
    
    if (sex =='F') {
        std::cout<< "Hey sexy mama";
    }
    else if (sex =='M') {
        std::cout<< "Welcome Papi";
    }
    
    }

    return 0;
}
    
