#include <iostream>

using namespace std;

int main() {
    long long a, b;
    cin >> a >> b;
    a = a + b;
    b = a - b;
    a = a - b;
    cout << a << " " << b << '\n';
    return 0;
}
