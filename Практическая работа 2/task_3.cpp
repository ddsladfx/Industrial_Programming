#include <iostream>
#include <string>
#include <climits>

using namespace std;

int main() {
    int base;
    string number;
    cin >> base >> number;
    if (base < 1 || base > 10) {
        cout << "Invalid base\n";
        return 0;
    }

    unsigned long long decimal = 0;
    for (char digit : number) {
        if (base == 1) {
            // В унарной системе число равно количеству единиц.
            if (digit != '1') {
                cout << "Invalid digit\n";
                return 0;
            }
            decimal++;
        } else {
            int value = digit - '0';
            if (value < 0 || value >= base) {
                cout << "Invalid digit\n";
                return 0;
            }
            if (decimal > (ULLONG_MAX - value) / base) {
                cout << "Overflow\n";
                return 0;
            }
            decimal = decimal * base + value;
        }
    }

    string binary;
    do {
        binary = char('0' + decimal % 2) + binary;
        decimal /= 2;
    } while (decimal > 0);
    cout << binary << '\n';
    return 0;
}
