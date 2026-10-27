#include <iostream>
using namespace std;

void moveIngredients(int n, int from, int to, int spare) {
    if (n == 0) return;
    moveIngredients(n - 1, from, spare, to);
    cout << "Ingredient " << n << " move from " << from << " to " << to << '\n';
    moveIngredients(n - 1, spare, to, from);
}

int main() {
    int n;
    cin >> n;
    if (n < 0) return 0;
    moveIngredients(n, 1, 3, 2);
    return 0;
}
