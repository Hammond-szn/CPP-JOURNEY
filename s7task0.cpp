#include
using namespace std;
int main() {
    int x = 17;
    int* p = &x;
    cout << "Value of x: " << x << endl;
    cout << "Address of x: " << &x << endl;
    cout << "Value of p (address of x): " << p << endl;
}