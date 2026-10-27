#include <iostream>

using namespace std;

int main() {
    long long h, a, b;
    cin >> h >> a >> b;
    if (a >= h) {
        cout << 1 << '\n';
    } else if (a <= b) {
        cout << "Impossible\n";
    } else {
        long long rise = a - b;
        cout << 1 + (h - a + rise - 1) / rise << '\n';
    }
    return 0;
}
