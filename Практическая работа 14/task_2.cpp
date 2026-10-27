#define _SILENCE_CXX17_CODECVT_HEADER_DEPRECATION_WARNING
#include <iostream>
#include <string>
#include <set>
#include <locale>
#include <codecvt>
using namespace std;

bool isLetter(char32_t ch) {
    return (ch >= U'a' && ch <= U'z') || (ch >= U'A' && ch <= U'Z') ||
           (ch >= U'а' && ch <= U'я') || (ch >= U'А' && ch <= U'Я') ||
           ch == U'ё' || ch == U'Ё';
}

char32_t lowerLetter(char32_t ch) {
    if (ch >= U'A' && ch <= U'Z') return ch - U'A' + U'a';
    if (ch >= U'А' && ch <= U'Я') return ch - U'А' + U'а';
    if (ch == U'Ё') return U'ё';
    return ch;
}

int main() {
    wstring_convert<codecvt_utf8<char32_t>, char32_t> utf8;
    set<u32string> seen;
    string line;
    while (getline(cin, line)) {
        u32string text = utf8.from_bytes(line), word;
        for (size_t i = 0; i <= text.size(); i++) {
            if (i < text.size() && isLetter(text[i])) word += lowerLetter(text[i]);
            else if (i < text.size() && text[i] == U'-' && !word.empty() &&
                     i + 1 < text.size() && isLetter(text[i + 1])) {
                // В примере «всё-таки» считается одним словом.
                word += U'-';
            } else if (!word.empty()) {
                if (seen.insert(word).second) cout << utf8.to_bytes(word) << '\n';
                word.clear();
            }
        }
    }
    return 0;
}
