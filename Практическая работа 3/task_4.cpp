#include <iostream>

using namespace std;

int main() {
    long long n;
    cin >> n;
    // Остаток приводим к 0 или 1, в том числе для отрицательных n.
    cout << n + 2 - (n % 2 + 2) % 2 << '\n';
    return 0;
}
