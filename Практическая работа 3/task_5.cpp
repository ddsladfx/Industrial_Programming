#include <iostream>
#include <iomanip>

using namespace std;

int main() {
    long long n;
    cin >> n;
    int hours = n / 3600 % 24;
    int minutes = n / 60 % 60;
    int seconds = n % 60;
    cout << hours << ":" << setfill('0') << setw(2) << minutes
         << ":" << setw(2) << seconds << '\n';
    return 0;
}
