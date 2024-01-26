/*
* Time Complexity:
 * Worst-case: O(N^2)
 * Average-case: O(N^2)
 * Best-case: O(N)
 *
 * Auxiliary Space: O(1)
 *
 * !STABLE!
 */

#include <iostream>
#include <cinttypes>

void InsertionSort(int64_t data[], size_t n) {
    for (size_t i = 1; i < n; ++i) {
        auto key = data[i];
        int64_t j = i - 1;

        while (j >= 0 && data[j] > key) {
            data[j + 1] = data[j];
            j -= 1;
        }
        data[j + 1] = key;
    }
}

void Print(int64_t data[], size_t n) {
    for (size_t i = 0; i < n; ++i) {
        std::cout << data[i] << " ";
    }
    std::cout << std::endl;
}

int main() {
    size_t n;
    std::cin >> n;

    auto* data = new int64_t[n];
    for (size_t i = 0; i < n; ++i) {
        std::cin >> data[i];
    }

    InsertionSort(data, n);
    Print(data, n);

    delete[] data;
}
