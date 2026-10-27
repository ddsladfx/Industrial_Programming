#include <iostream>
#include <climits>

using namespace std;

int main() {
    int n;
    cin >> n;
    if (n < 0) {
        cout << "n must be non-negative\n";
        return 0;
    }
    unsigned long long factorial = 1, result = 1;
    for (int i = 1; i <= n; i++) {
        // Проверяем, поместится ли результат в целочисленный тип.
        if (factorial > ULLONG_MAX / i) {
            cout << "Overflow\n";
            return 0;
        }
        factorial *= i;
        if (result > ULLONG_MAX / factorial) {
            cout << "Overflow\n";
            return 0;
        }
        result *= factorial;
    }
    cout << result << '\n';
    return 0;
}
