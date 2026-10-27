#include <iostream>

using namespace std;

int main() {
    long long a, b;
    cin >> a >> b;
    while (a > b) {
        // Не делим, если после деления уже нельзя будет получить b.
        if (a % 2 == 0 && a / 2 >= b) {
            cout << ":2\n";
            a /= 2;
        } else {
            cout << "-1\n";
            a--;
        }
    }
    return 0;
}
