#include <iostream>
#include <fstream>
#include <string>
using namespace std;

string toBinary(string number) {
    if (number == "0") return "0";
    string result;
    // Делим десятичную запись столбиком: число может содержать 255 цифр.
    while (!number.empty()) {
        string quotient;
        int remainder = 0;
        for (char ch : number) {
            int value = remainder * 10 + ch - '0';
            int digit = value / 2;
            if (digit != 0 || !quotient.empty()) quotient += char('0' + digit);
            remainder = value % 2;
        }
        result = char('0' + remainder) + result;
        number = quotient;
    }
    return result;
}

int main() {
    ifstream input("input.txt");
    if (!input) { cerr << "Cannot open input.txt\n"; return 1; }
    ofstream output("output.txt");
    if (!output) { cerr << "Cannot open output.txt\n"; return 1; }
    string text;
    getline(input, text);
    for (size_t i = 0; i < text.size(); ) {
        if (text[i] >= '0' && text[i] <= '9') {
            size_t j = i;
            while (j < text.size() && text[j] >= '0' && text[j] <= '9') j++;
            output << toBinary(text.substr(i, j - i));
            i = j;
        } else {
            output << text[i];
            i++;
        }
    }
    return 0;
}
