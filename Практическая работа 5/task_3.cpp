#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> students(n);
    for (int i = 0; i < n; i++) cin >> students[i];
    int gone = 0;
    bool changed = true;
    while (changed) {
        changed = false;
        vector<int> remaining;
        for (int i = 0; i < static_cast<int>(students.size()); ) {
            int j = i + 1;
            while (j < static_cast<int>(students.size()) && students[j] == students[i]) j++;
            if (j - i >= 2) {
                gone += j - i;
                changed = true;
            } else {
                remaining.push_back(students[i]);
            }
            i = j;
        }
        students = remaining;
    }
    cout << gone << '\n';
    return 0;
}
