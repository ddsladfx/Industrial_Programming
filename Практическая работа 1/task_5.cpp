#include <iostream>

using namespace std;

int main() {
    int n;
    cin >> n;
    long long missing = 1LL * n * (n + 1LL) / 2;
    for (int i = 0; i < n; i++) {
        int number;
        cin >> number;
        missing -= number;
    }
    cout << missing << '\n';
    return 0;
}
