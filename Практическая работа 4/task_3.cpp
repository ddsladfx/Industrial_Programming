#include <iostream>
#include <string>

using namespace std;

int main() {
    int x;
    cin >> x;
    if (x < 1 || x > 3999) {
        cout << "Number must be from 1 to 3999\n";
        return 0;
    }
    int values[] = {1000, 900, 500, 400, 100, 90, 50, 40, 10, 9, 5, 4, 1};
    string symbols[] = {"M", "CM", "D", "CD", "C", "XC", "L", "XL", "X", "IX", "V", "IV", "I"};
    for (int i = 0; i < 13; i++) {
        while (x >= values[i]) {
            cout << symbols[i];
            x -= values[i];
        }
    }
    cout << '\n';
    return 0;
}
