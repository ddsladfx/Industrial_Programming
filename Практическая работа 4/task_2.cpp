#include <iostream>

using namespace std;

int main() {
    long long n, m, k;
    cin >> n >> m >> k;
    if (k > 0 && k < n * m && (k % n == 0 || k % m == 0)) {
        cout << "YES\n";
    } else {
        cout << "NO\n";
    }
    return 0;
}
