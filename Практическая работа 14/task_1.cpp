#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main() {
    string text;
    getline(cin, text);
    vector<char> brackets;
    for (char ch : text) {
        if (ch == '(' || ch == '[' || ch == '{') brackets.push_back(ch);
        else if (ch == ')' || ch == ']' || ch == '}') {
            if (brackets.empty()) { cout << "no\n"; return 0; }
            char opening = brackets.back();
            if ((ch == ')' && opening != '(') || (ch == ']' && opening != '[') ||
                (ch == '}' && opening != '{')) {
                cout << "no\n";
                return 0;
            }
            brackets.pop_back();
        }
    }
    cout << (brackets.empty() ? "yes" : "no") << '\n';
    return 0;
}
