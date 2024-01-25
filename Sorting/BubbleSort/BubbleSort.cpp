/*
 * Time complexity :
 * - Worst case : O(N^2)
 * - Average Case : O(N^2)
 * - Best Case : O(N^2)
 *
 * Auxiliary Space: : O(1)
 *
 * !STABLE!
 */

#include <iostream>
#include <cinttypes>

void BubbleSort(int64_t data[], size_t n) {
    for (size_t i = 0; i < n - 1; ++i) {
        for (size_t j = 0; j < n - i - 1; ++j) {
            if (data[j] > data[j + 1]) {
                std::swap(data[j], data[j + 1]);
            }
        }
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

    BubbleSort(data, n);
    Print(data, n);

    delete[] data;
}
