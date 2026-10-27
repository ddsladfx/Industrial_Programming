#include <iostream>
#include <iomanip>

using namespace std;

int main() {
    long long a, b;
    char operation;
    cin >> a >> operation >> b;
    switch (operation) {
        case '+': cout << a + b; break;
        case '-': cout << a - b; break;
        case '*': cout << a * b; break;
        case '/':
            if (b == 0) cout << "Division by zero";
            else cout << setprecision(15) << static_cast<long double>(a) / b;
            break;
        default: cout << "Unknown operation";
    }
    cout << '\n';
    return 0;
}
