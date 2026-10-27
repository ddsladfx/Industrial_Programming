#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int n, k, limit;
    cin >> n >> k >> limit;
    vector<long long> cost(n);
    for (long long& value : cost) cin >> value;
    // Каждый элемент описывает отдельный вид, доступно до limit экземпляров.
    vector<long long> best(k + 1);
    vector<bool> possible(k + 1, false);
    possible[0] = true;
    for (long long value : cost) {
        vector<long long> next = best;
        vector<bool> nextPossible = possible;
        for (int count = 0; count <= k; count++) {
            if (!possible[count]) continue;
            for (int take = 1; take <= limit && count + take <= k; take++) {
                long long total = best[count] + take * value;
                if (!nextPossible[count + take] || total > next[count + take]) {
                    next[count + take] = total;
                    nextPossible[count + take] = true;
                }
            }
        }
        best = next;
        possible = nextPossible;
    }
    if (possible[k]) cout << best[k] << '\n';
    else cout << "Impossible\n";
    return 0;
}
