#include <iostream>

using namespace std;

int main() {
    int n, m, w;
    cin >> n >> m >> w;
    bool mushrooms[32][32] = {};
    for (int i = 0; i < w; i++) {
        int row, column;
        cin >> row >> column;
        mushrooms[row - 1][column - 1] = true;
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (mushrooms[i][j]) {
                cout << '*';
            } else {
                int count = 0;
                for (int di = -1; di <= 1; di++) {
                    for (int dj = -1; dj <= 1; dj++) {
                        int row = i + di, column = j + dj;
                        if (row >= 0 && row < n && column >= 0 && column < m) {
                            if (mushrooms[row][column]) count++;
                        }
                    }
                }
                cout << count;
            }
        }
        cout << '\n';
    }
    return 0;
}
