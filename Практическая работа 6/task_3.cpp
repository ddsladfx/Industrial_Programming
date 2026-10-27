#include <iostream>
#include <string>

using namespace std;

int main() {
    string current;
    int n;
    cin >> current >> n;
    for (int step = 1; step < n; step++) {
        string next;
        for (int i = 0; i < static_cast<int>(current.size()); ) {
            int j = i + 1;
            while (j < static_cast<int>(current.size()) && current[j] == current[i]) j++;
            next += to_string(j - i);
            next += current[i];
            i = j;
        }
        current = next;
    }
    cout << current << '\n';
    return 0;
}
