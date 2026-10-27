#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool canSplit(const vector<long long>& calories, int days, long long difference) {
    int groups = 1;
    long long first = calories[0];
    for (size_t i = 1; i < calories.size(); i++) {
        if (calories[i] - first > difference) {
            groups++;
            first = calories[i];
        }
    }
    // При необходимости группу можно разделить на непустые части.
    return groups <= days;
}

int main() {
    int n, d;
    cin >> n >> d;
    vector<long long> calories(n);
    for (long long& value : calories) cin >> value;
    sort(calories.begin(), calories.end());
    long long left = 0, right = calories.back() - calories.front();
    while (left < right) {
        long long middle = left + (right - left) / 2;
        if (canSplit(calories, d, middle)) right = middle;
        else left = middle + 1;
    }
    cout << left << '\n';
    return 0;
}
