#include <iostream>
using namespace std;
void square(int n0) {
    int result = n0 * n0;
    cout << "The result is: " << result << endl;
}
double avgnum(double n1, double n2, double n3) {
    double avg;
    avg = (n1 + n2 + n3) / 3;
    return avg;
}
int main() {
    int num;
    double num1, num2, num3;
    cout << "Enter the number to be squared: ";
    cin >> num;
    square(num);
  cout << "Enter the first number: "; cin >> num1;
  cout << "Enter the second number: "; cin >> num2;
  cout << "Enter the third number: "; cin >> num3;
  double avg = avgnum(num1, num2, num3);
  cout << "The average is: " << avg << endl;

    return 0;
}