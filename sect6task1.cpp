#include <iostream>
using namespace std;

int main() {

    double marks[5];
    cout << "Enter marks for 5 subjects: ";
    cin >> marks[0] >> marks[1] >> marks[2] >> marks[3] >> marks[4];
cout << "The marks entered are: ";
    for (int i = 0; i < 5; i++) {
        cout << marks[i] << " ";
    }
    cout << endl;

    return 0;


}