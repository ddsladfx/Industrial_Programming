#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main() {
    ifstream first("input1.txt"), second("input2.txt");
    if (!first || !second) { cerr << "Cannot open input files\n"; return 1; }
    string x, y;
    getline(first, x);
    getline(second, y);
    // Проверяем Y внутри X, как сказано в начале условия.
    cout << (x.find(y) != string::npos ? "yes" : "no") << '\n';
    return 0;
}
