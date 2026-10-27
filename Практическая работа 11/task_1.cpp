#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;
    if (n <= 0 || m <= 0) return 0;
    vector<vector<long long>> best(n, vector<long long>(m));
    vector<vector<char>> previous(n, vector<char>(m));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            long long value;
            cin >> value;
            if (i == 0 && j == 0) best[i][j] = value;
            else if (i == 0) {
                best[i][j] = best[i][j - 1] + value;
                previous[i][j] = 'L';
            } else if (j == 0 || best[i - 1][j] >= best[i][j - 1]) {
                best[i][j] = best[i - 1][j] + value;
                previous[i][j] = 'U';
            } else {
                best[i][j] = best[i][j - 1] + value;
                previous[i][j] = 'L';
            }
        }
    }
    vector<pair<int, int>> path;
    int row = n - 1, column = m - 1;
    while (true) {
        path.push_back({row, column});
        if (row == 0 && column == 0) break;
        if (previous[row][column] == 'U') row--;
        else column--;
    }
    reverse(path.begin(), path.end());
    for (auto cell : path) cout << cell.first << " " << cell.second << '\n';
    return 0;
}
