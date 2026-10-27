#include <iostream>

using namespace std;

int main() {
    long long n, m;
    cin >> n >> m;
    cout << (n % m == 0 || m % n == 0) << '\n';
    return 0;
}
