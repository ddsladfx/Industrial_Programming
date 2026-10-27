#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main() {
    ifstream input("input.txt", ios::binary);
    if (!input) { cerr << "Cannot open input.txt\n"; return 1; }
    ofstream output("output.txt", ios::binary);
    if (!output) { cerr << "Cannot open output.txt\n"; return 1; }
    string letters = "useragreement";
    char ch;
    while (input.get(ch)) {
        char lower = ch;
        if (lower >= 'A' && lower <= 'Z') lower = lower - 'A' + 'a';
        if (letters.find(lower) == string::npos) output.put(ch);
    }
    return 0;
}
