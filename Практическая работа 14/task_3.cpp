#include <iostream>
#include <string>
using namespace std;

class MinStack {
    struct Node {
        long long value, minimum;
        Node* next;
    };
    Node* top = nullptr;

public:
    MinStack() = default;
    MinStack(const MinStack&) = delete;
    MinStack& operator=(const MinStack&) = delete;

    bool empty() const { return top == nullptr; }

    void push(long long value) {
        long long minimum = value;
        if (!empty() && top->minimum < minimum) minimum = top->minimum;
        top = new Node{value, minimum, top};
    }

    long long pop() {
        Node* old = top;
        long long value = old->value;
        top = old->next;
        delete old;
        return value;
    }

    long long minimum() const { return top->minimum; }

    ~MinStack() {
        while (!empty()) pop();
    }
};

int main() {
    MinStack numbers;
    string command;
    // Команды читаются до конца ввода.
    while (cin >> command) {
        if (command == "push") {
            long long value;
            if (!(cin >> value)) break;
            numbers.push(value);
        } else if (command == "empty") {
            cout << (numbers.empty() ? "yes" : "no") << '\n';
        } else if (command == "pop" || command == "min") {
            if (numbers.empty()) cout << "error\n";
            else if (command == "pop") cout << numbers.pop() << '\n';
            else cout << numbers.minimum() << '\n';
        }
    }
    return 0;
}
