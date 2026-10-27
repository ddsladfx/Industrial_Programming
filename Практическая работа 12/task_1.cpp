#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;
    if (n <= 0 || m <= 0) return 0;
    vector<vector<char>> maze(n, vector<char>(m));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) cin >> maze[i][j];
    }
    if (maze[0][0] == '1') { cout << -1 << '\n'; return 0; }
    if (maze[0][0] == 'E') { cout << 0 << '\n'; return 0; }
    vector<vector<bool>> visited(n, vector<bool>(m, false));
    queue<pair<int, int>> cells;
    cells.push({0, 0});
    visited[0][0] = true;
    int files = 0;
    bool exitFound = false;
    int dr[] = {-1, 1, 0, 0}, dc[] = {0, 0, -1, 1};
    while (!cells.empty()) {
        int row = cells.front().first, column = cells.front().second;
        cells.pop();
        if (maze[row][column] == 'P') files++;
        for (int i = 0; i < 4; i++) {
            int r = row + dr[i], c = column + dc[i];
            if (r < 0 || r >= n || c < 0 || c >= m) continue;
            if (maze[r][c] == '1' || visited[r][c]) continue;
            // Вход в E завершает маршрут: через выход не проходим.
            if (maze[r][c] == 'E') { exitFound = true; continue; }
            visited[r][c] = true;
            cells.push({r, c});
        }
    }
    cout << (exitFound ? files : -1) << '\n';
    return 0;
}
