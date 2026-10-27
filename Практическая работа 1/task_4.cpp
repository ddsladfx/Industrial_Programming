#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n, m;
    cin >> n >> m;
    vector<int> a(n), b(m);
    for (int i = 0; i < n; i++) cin >> a[i];
    for (int i = 0; i < m; i++) cin >> b[i];

    int i = 0, j = 0;
    // Само слияние выполняется за один цикл из n + m шагов.
    for (int k = 0; k < n + m; k++) {
        if (k > 0) cout << " ";
        if (i < n && (j == m || a[i] <= b[j])) {
            cout << a[i];
            i++;
        } else {
            cout << b[j];
            j++;
        }
    }
    cout << '\n';
    return 0;
}
