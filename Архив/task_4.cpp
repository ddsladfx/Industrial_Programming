#include <iostream>
#include <vector>

int main() {
    const std::vector<int> A = {-3, 1, 4, 4, 9};
    const std::vector<int> B = {-2, 2, 4, 10};
    const int a = static_cast<int>(A.size());
    const int b = static_cast<int>(B.size());
    int i = 0, j = 0; // В C++ индексы начинаются с 0.

    for (int count = 1; count <= a + b; ++count) {
        int value;
        if (i == a) {             // A закончился.
            value = B[j++];
        } else if (j == b) {      // B закончился.
            value = A[i++];
        } else if (A[i] <= B[j]) {
            value = A[i++];
        } else {
            value = B[j++];
        }
        std::cout << value << (count == a + b ? "" : " ");
    }
    std::cout << '\n';
}
