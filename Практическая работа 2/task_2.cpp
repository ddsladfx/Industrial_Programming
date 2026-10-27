#include <iostream>

using namespace std;

int main() {
    int left = 1, right = 1023;
    cout << "Think of a number from 1 to 1023.\n";
    cout << "Reply: < if your number is smaller, > if larger, = if correct.\n";
    for (int step = 1; step <= 10 && left <= right; step++) {
        int middle = (left + right) / 2;
        cout << "Step " << step << ": " << middle << '\n';
        char answer;
        if (!(cin >> answer)) return 0;
        if (answer == '=') {
            cout << "Found: " << middle << '\n';
            return 0;
        } else if (answer == '<') {
            right = middle - 1;
        } else if (answer == '>') {
            left = middle + 1;
        } else {
            cout << "Invalid answer\n";
            return 0;
        }
    }
    cout << "Answers are inconsistent\n";
    return 0;
}
